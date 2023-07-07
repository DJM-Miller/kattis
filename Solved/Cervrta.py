def main():
    x = [None]*3
    y = [None]*3
    for i in range(3):
        x[i],y[i] = map(int,input().split())
    if(x[0] == x[1]):
        xout = x[2]
    elif(x[0] == x[2]):
        xout = x[1]
    else:
        xout = x[0]
    if(y[0] == y[1]):
        yout = y[2]
    elif(y[0] == y[2]):
        yout = y[1]
    else:
        yout = y[0]
    print(f"{xout} {yout}")

    pass


if __name__ == "__main__":
    main()