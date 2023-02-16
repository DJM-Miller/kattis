def CS():
    N = int(input())
    total = 0
    X = input().split()
    for i in range(N):
        if( int(X[i]) < 0):
            total += 1
    print(total)

if __name__ == "__main__":
    CS()