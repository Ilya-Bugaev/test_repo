from itertools import permutations

def queens_itertools(n):

    count = 0
    
    # Генерируем все перестановки чисел от 0 до n-1
    # Каждая перестановка - это расстановка ферзей (позиция в перестановке = строка, значение = столбец)
    for per in permutations(range(n)):
        flag = True
        
        # Проверяем диагонали для всех пар ферзей
        for i in range(n):
            for j in range(i + 1, n):
                if abs(i - j) == abs(per[i] - per[j]): #Два ферзя на одной диагонали
                    flag = False
                    break
        
        if flag:
            count += 1
    
    return count

n = int(input())
print(queens_itertools(n))
