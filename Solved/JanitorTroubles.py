def main():
    a,b,c,d = map(int, input().split())
    s = (a+b+c+d)/2
    x = (s-a)*(s-b)*(s-c)*(s-d)
    print(pow(x,0.5))
    pass


if __name__ == "__main__":
    main()