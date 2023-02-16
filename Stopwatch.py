def Stopwatch():
    N = int(input())

    if N % 2 == 1:
        print("still running")
        return

    total = 0
    for i in range(int(N/2)):
        start = int(input())
        end = int(input())
        total += end - start

    print(total)
    

Stopwatch()