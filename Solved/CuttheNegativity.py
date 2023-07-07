def main():
    N = int(input())
    mylist = list()
    for x in range(N):
        mylist.append(list(map(int,input().split())))
    flylist = list()
    for y in range(N):
        for x in range(N):
            if(mylist[y][x] != -1):
                flylist.append(f"{y+1} {x+1} {mylist[y][x]}")
    print(len(flylist))
    for x in flylist:
        print(x)
    pass


if __name__ == "__main__":
    main()