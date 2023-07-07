def main():
    N = int(input())
    for i in range(N):
        x,y = map(float ,input().split())
        a = 60 * (x-1) / y
        b = 60 * (x) / y
        c = 60 * (x+1) / y
        print(f"{a:.4f} {b:.4f} {c:.4f}")
    pass


if __name__ == "__main__":
    main()