num = int(input('Размениваемое число:'))

l_surname = len('Бугаев')
l_name = len('Илья')
l_patronymic = len('Александрович')


coins = [l_surname, l_name, l_patronymic]
coins.sort(reverse = True)


def change(num):
    available = coins.copy()
    changes = [[0]] * num
    # Заполняем массив разменов для всех чисел от 1 до num
    for i in range(1, num + 1):
        if i in coins:
            changes[i-1] = [i] # Размен - одна монета этого номинала
        else:
            for n in available:
                # Проверяем, можно ли представить число как сумму двух доступных номиналов
                if i - n in available or i - n == 0:
                    changes[i - 1] = changes[n - 1] + changes[i - n - 1]

                    # Если новое число не в списке доступных, добавляем его
                    if i + n not in available:
                        available.append(i)
                    break
    if changes[-1] != [0]:
        return changes[-1]
    else:
        return False


coin_exchange = change(num)
if not coin_exchange:
    print('-42!')
else:
    print('Вариант размена:', coin_exchange)
    print(coin_exchange.count(l_name), 'по', l_name)
    print(coin_exchange.count(l_surname), 'по', l_surname)
    print(coin_exchange.count(l_patronymic), 'по', l_patronymic)
