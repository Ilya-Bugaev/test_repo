import random

from bubble_sort import bubble_sort

from heapsort import heapsort


#обычные unit тесты
def test_empty():
    assert heapsort([]) == []
    
def test_single():
    assert heapsort([5]) == [5]
    
def test_sorted():
    assert heapsort([1, 2, 3]) == [1, 2, 3]
    
def test_reverse():
    assert heapsort([3, 2, 1]) == [1, 2, 3]
    
def test_duplicates():
    assert heapsort([2, 1, 2]) == [1, 2, 2]

#крайние случаи
def test_all_same_elements():
    #Все элементы одинаковые
    assert heapsort([7, 7, 7, 7, 7]) == [7, 7, 7, 7, 7]
    assert heapsort([0, 0, 0, 0]) == [0, 0, 0, 0]
    assert heapsort([-1, -1, -1]) == [-1, -1, -1]

def test_large_range():
        #Большой диапазон значений
        assert heapsort([1000, 1, -1000, 500, -500]) == [-1000, -500, 1, 500, 1000]

def test_large_input():
    #Большой входной массив
    arr = [random.randint(-1000, 1000) for i in range(1000)]
    assert heapsort(arr)
    
    
def test_negative():
    #Все числа отрицательные
    assert heapsort([-1, -3, -2, -5, -4]) == [-5, -4, -3, -2, -1]


#property based
def test_random_arrays():
    #Сравнение на случайных массивах
    for i in range(50):  #50 случайных тестов
        size = random.randint(3, 100)
        arr = [random.randint(-100, 100) for n in range(size)]
        
        arr_copy1 = arr.copy()
        arr_copy2 = arr.copy()
        
        heapsort_result = heapsort(arr_copy1)
        bubble_sort_result = bubble_sort(arr_copy2)
        assert heapsort_result == bubble_sort_result
