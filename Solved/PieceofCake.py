def main():
    x,y,z=map(int,input().split())
    print(max(y,x-y)*max(x-z,z)*4)
    pass


if __name__ == "__main__":
    main()

