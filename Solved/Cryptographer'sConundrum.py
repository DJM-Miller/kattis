def main():
    str = input()
    p = "PER"
    c = 0
    for x in range(len(str)):
        if p[x%3] != str[x]:
            c+=1
    print(c)
    pass


if __name__ == "__main__":
    main()