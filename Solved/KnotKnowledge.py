def main():
    x = input()
    inknot = list(map(int,input().split()))
    knowknot = list(map(int,input().split()))
    for i in inknot:
        if i not in knowknot:
            print(i)
    pass


if __name__ == "__main__":
    main()