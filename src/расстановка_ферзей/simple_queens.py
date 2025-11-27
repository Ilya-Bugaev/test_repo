import itertools


def queens_itertools(n):
    if n <= 0:
        return 0
    
    count = 0
    
    #Генерируем все возможные расстановки с повторениями
    for placement in itertools.product(range(n), repeat=n):
        valid = True
        #Проверяем расстановку
        for i in range(n):
            for j in range(i + 1, n):
                #Конфликт по вертикали или диагонали
                if placement[i] == placement[j] or abs(placement[i] - placement[j]) == abs(i - j):
                    valid = False
                    break
            if not valid:
                break
        
        if valid:
            count += 1
    
    return count

n = int(input('Введите значение N:'))
print(queens_itertools(n))
