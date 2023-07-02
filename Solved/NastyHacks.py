def main():
    N = int(input())
    for x in range(N):
        x,y,z = map(int,input().split())
        if(x < y-z):
            print("advertise")
        elif(x > y-z):
            print("do not advertise")
        else:
            print("does not matter")
    pass


if __name__ == "__main__":
    main()