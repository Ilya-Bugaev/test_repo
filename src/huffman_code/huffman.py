def encode(msg: str) -> tuple[str, dict[str, str]]:
    # Если строка пустая
    if not msg:
        return "", {}
    
    # Если все символы одинаковые
    if len(set(msg)) == 1:
        char = msg[0]
        codes = {char: "0"}
        encoded_msg = "0" * len(msg)
        return encoded_msg, codes
    
    # Подсчет частот символов
    chars = set(msg)
    h = [(msg.count(symb), symb) for symb in chars]
    st = h.copy()
    st.sort(reverse=True)
    h.sort()
    data = []

    # Построение дерева Хаффмана
    while len(h) > 1:
        left = h.pop(0)
        right = h.pop(0)
        new_element = (left[0] + right[0], left[1] + right[1])
        h.append(new_element)
        data.append((left[1], right[1], new_element[1]))
        h.sort()

    # Генерация кодов Хаффмана
    codes = {}
    
    root = data[-1][2] if data else st[0][1]
    
    def generate_codes(node, code=""):
        if len(node) == 1:
            codes[node] = code
        else:
            for left, right, parent in data:
                if parent == node:
                    generate_codes(left, code + "0")
                    generate_codes(right, code + "1")
                    break
    
    generate_codes(root)
    
    encoded_msg = "".join(codes[char] for char in msg)
    
    return encoded_msg, codes



def decode(encoded: str, table: dict[str, str]) -> str:
    if not all(bit in '01' for bit in encoded):
        raise ValueError("Закодированное сообщение должно содержать только символы '0' и '1'")
    
    if not encoded:
        return ""
    
    if not table:
        raise ValueError("Таблица кодов не может быть пустой")
    
    # Создаем обратный словарь (код -> символ)
    reverse_table = {code: char for char, code in table.items()}
    
    decoded_chars = []
    current_code = ""
    
    # Последовательно обрабатываем каждый бит в закодированном сообщении
    for bit in encoded:
        current_code += bit
        
        # Если текущая последовательность битов соответствует какому-то коду
        if current_code in reverse_table:
            decoded_chars.append(reverse_table[current_code])
            current_code = ""
    
    # Если после обработки остались необработанные биты - ошибка декодирования
    if current_code:
        raise ValueError(f"Невозможно декодировать сообщение: нераспознанный код '{current_code}'")
    
    return "".join(decoded_chars)


def encode_file(input_path: str, output_path: str) -> None:
    with open(input_path, encoding='utf-8') as f:
        text = f.read()
    
    encoded_bits, table = encode(text)
    
    # Преобразуем битовую строку в байты
    padding = 8 - len(encoded_bits) % 8
    if padding == 8:
        padding = 0
    encoded_bits += '0' * padding
    
    encoded_bytes = bytearray()
    for i in range(0, len(encoded_bits), 8):
        byte = encoded_bits[i:i+8]
        encoded_bytes.append(int(byte, 2))
    
    # Сохраняем в файл
    with open(output_path, 'wb') as f:
        f.write(len(table).to_bytes(2, 'big'))
        
        # Сохраняем таблицу: для каждого символа - длина кода + код
        for char, code in table.items():
            char_bytes = char.encode('utf-8')
            f.write(len(char_bytes).to_bytes(1, 'big'))
            f.write(char_bytes)
            f.write(len(code).to_bytes(1, 'big'))
            code_padding = 8 - len(code) % 8
            if code_padding == 8:
                code_padding = 0
            code += '0' * code_padding
            for i in range(0, len(code), 8):
                code_byte = code[i:i+8]
                f.write(int(code_byte, 2).to_bytes(1, 'big'))
        
        f.write(padding.to_bytes(1, 'big'))
        
        f.write(encoded_bytes)



def decode_file(input_path: str, output_path: str) -> None:
    with open(input_path, 'rb') as f:
        table_size = int.from_bytes(f.read(2), 'big')
        table = {}
        
        # Восстанавливаем таблицу
        for _ in range(table_size):
            char_len = int.from_bytes(f.read(1), 'big')
            char_bytes = f.read(char_len)
            char = char_bytes.decode('utf-8')
            code_len = int.from_bytes(f.read(1), 'big')
            code_bytes_len = (code_len + 7) // 8  
            code_bits = []
            for _ in range(code_bytes_len):
                byte = int.from_bytes(f.read(1), 'big')
                code_bits.append(bin(byte)[2:].zfill(8))
            code = ''.join(code_bits)[:code_len]  
            table[char] = code
        
        padding = int.from_bytes(f.read(1), 'big')
        
        encoded_bytes = f.read()
    
    # Преобразуем байты обратно в битовую строку
    bits = []
    for byte in encoded_bytes:
        bits.append(bin(byte)[2:].zfill(8))
    encoded_bits = ''.join(bits)
    
    # Убираем дополнение
    if padding > 0:
        encoded_bits = encoded_bits[:-padding]
    
    decoded_text = decode(encoded_bits, table)
    
    with open(output_path, 'w', encoding='utf-8') as f:
        f.write(decoded_text)


