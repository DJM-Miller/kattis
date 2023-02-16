best = 0
best_stu = 0
for x in range(5):
    nums = input().split()
    total = 0
    for i in range(4):
        total += int(nums[i])
    if total > best:
        best = total
        best_stu = x+1
        
print(best_stu, best)