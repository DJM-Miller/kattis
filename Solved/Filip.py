def main():
    x,y = input().split()
    x = x[-1] + x[-2] + x[-3]
    y = y[-1] + y[-2] + y[-3]
    print(max(int(x),int(y)))
    


    pass


if __name__ == "__main__":
    main()