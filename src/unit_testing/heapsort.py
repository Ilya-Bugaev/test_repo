def heapsort(arr):
    
    def swap(ind1, ind2):
        arr[ind1], arr[ind2] = arr[ind2], arr[ind1]
    
    def sift_down(parent, limit):
        while True:
            child = parent * 2 + 1  # Левый дочерний узел
            if child < limit:
                # Если правый дочерний узел существует и больше левого
                if child + 1 < limit and arr[child] < arr[child + 1]:
                    child += 1  # Перейти к правому дочернему узлу
                # Если родитель меньше дочернего узла
                if arr[parent] < arr[child]:
                    swap(parent, child) 
                    parent = child  
                else:
                    break
            else:
                break

    length = len(arr)

    for index in range((length // 2) - 1, -1, -1):
        sift_down(index, length)


    for index in range(length - 1, 0, -1):
        swap(index, 0)  # Перемещение корня в конец
        sift_down(0, index)  # Восстановление кучи

    return arr


            
