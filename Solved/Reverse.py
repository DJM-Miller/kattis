def main():
    n = int(input())
    x = list()
    for i in range(n):
        x.append(int(input()))
    #x.sort()
    for i in range(n):
        print(x[-(i+1)])
    pass


if __name__ == "__main__":
    main()