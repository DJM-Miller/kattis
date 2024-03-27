def main():
    x = int(input())
    vol = 7
    for i in range(x):
        y = input()
        if y == "Skru op!" and vol < 10:
            vol += 1
        elif y == "Skru ned!" and vol > 0:
            vol -= 1
        
    print(vol)
    pass


if __name__ == "__main__":
    main()