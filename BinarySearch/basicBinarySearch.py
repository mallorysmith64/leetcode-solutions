def binary_search(arr, target):
    l = 0
    r = len(arr) - 1

    while l <= r:
        mid = l + (r- 1) // 2
        if arr[mid] == target:
            return mid
        elif arr[mid] < target:
            l = mid + 1
        else:
            r = mid - 1
    return -1

mylist = [1, 2, 3, 4, 5, 6, 7, 8, 9]
x = 4
result = binary_search(mylist, x)
      
if result != -1:
  print("Found at index", result)
else:
  print("Not found")