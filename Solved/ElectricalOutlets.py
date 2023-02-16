def EOut():
    N = int(input())
    for i in range(N):
        total = int(0)
        K = input().split()
        for j in range( int(K[0]) ):
            total += int( K[j+1] )

        print(total - (int(K[0])-1) )


if __name__ == "__main__":
    EOut()