def missing_numbers():
    n = int(input())
    if n == 1:
        print(1)
        return

    stuff = input()
    count = 1
    x = 1
    y = 0
    while(x < n):
        if(x < 10):
            if x != int(stuff[y]):
                print(x)
                return
            x += 1
            y += 1
        else:
            if x != (int(stuff[y])*10 + int(stuff[y+1])):
                print(x)
                return
            x += 1
            y += 2
        if(x == n):
            print(x)
            return

if __name__ == "__main__":
    missing_numbers()