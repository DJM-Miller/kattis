def main():
    x,y = map(int, input().split())
    y -= 45
    if y < 0:
        y += 60
        x -= 1
    if x < 0:
        x = 23
    print(f"{x} {y}")
    pass


if __name__ == "__main__":
    main()