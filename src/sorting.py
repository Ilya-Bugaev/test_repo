# Функция сортировки пузырьком

def bubble_sort(numa):
    flag = True
    while flag:
        flag = False
        for i in range(len(nums)- 1):
            if nums[i] > nums[i + 1]:
                nums[i], nums[i + 1] = nums[i + 1], nums[i]
                flag = True

    return nums

nums = [10,5,3,5,6,2,234,64,9]
nums_sorted = bubble_sort(nums)
print(nums_sorted)
