def main():
    n = int(input())
    total = list()
    total.append(0)
    for x in range(n):
        i = int(input())
        total.append(total[-1]+i)
    z = min(total)
    if(z<0):
        print(-z)
    else:
        print(z)

    pass


if __name__ == "__main__":
    main()