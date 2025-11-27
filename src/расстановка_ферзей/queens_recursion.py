def solve_n_queens(n):
    
    def backtrack(row, columns, diagonals1, diagonals2):
        nonlocal count
        
        #Если разместили ферзей во всех строках - нашли решение
        if row == n:
            count += 1
            return
        
        for col in range(n):
            #Проверка диагоналей
            diag1 = row - col
            diag2 = row + col
            
            #Если столбец или диагонали уже заняты - пропускаем
            if columns[col] or diagonals1[diag1] or diagonals2[diag2]:
                continue
            
            #Размещаем ферзя
            columns[col] = True
            diagonals1[diag1] = True
            diagonals2[diag2] = True
            
            #Переходим к следующей строке
            backtrack(row + 1, columns, diagonals1, diagonals2)
            
            #Откатываем изменения
            columns[col] = False
            diagonals1[diag1] = False
            diagonals2[diag2] = False
    
    count = 0
    columns = [False] * n  #столбцы
    #Диагонали:
    diagonals1 = [False] * (2 * n - 1)
    diagonals2 = [False] * (2 * n - 1)
    
    backtrack(0, columns, diagonals1, diagonals2)
    return count

n = int(input())
print(solve_n_queens(n))
