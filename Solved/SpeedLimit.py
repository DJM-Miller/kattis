def main():
    try:
        while True:
            num = input()
            if (not num) or (int(num) < 0):
                break
            prev_time = 0
            tot = 0
            for i in range(int(num)):
                x,y = map(int,input().split())
                tot += x * (y-prev_time)
                prev_time = y
            print(str(tot) + " miles")
    except EOFError:
        pass



if __name__ == "__main__":
    main()