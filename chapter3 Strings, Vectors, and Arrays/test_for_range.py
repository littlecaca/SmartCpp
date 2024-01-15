nums = [1, 2]
count = 100


for n in nums:
    count -= 1
    if count > 0:
        nums.append(count)
    print(n, end=" ")
