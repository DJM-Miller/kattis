P = int(input())
for x in range(P):
    K = input().split()
    N = int(K[1])
    total = 0

    for x in range(1, N+1):
        total += x
    print(K[0], total, end=" ")    
    
    i = 0
    x = 1
    total = 0
    while( i < N):
        if x % 2 == 1:
            total += x
            i += 1
        x += 1
    print(total, end=" ")

    i = 0
    x = 1
    total = 0
    while( i < N):
        if x % 2 == 0:
            total += x
            i += 1
        x += 1
    print(total)