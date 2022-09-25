n = int(input())

for x in range(n) :
    edgecount = 0
    for y in range(n) :
        z = input().split()
        if z == 1 :
            edgecount+1
    if edgecount < 3 :
        print(x, end=' ')