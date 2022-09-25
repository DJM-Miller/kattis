k = int(input())
for x in range(k) :
    n, y = input().split()
    total =0
    for z in range(int(y)) :
        total += z+1
    total += int(y)
    print (x+1,total)
