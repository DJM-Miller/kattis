def main():
    n,m = map(int,input().split())
    for x in range(min(n,m),max(n,m)+1):
        print(x+1)
    pass


if __name__ == "__main__":
    main()