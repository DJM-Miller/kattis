def main():
    str = input()
    words = str.split()
    for x in words:
        if words.count(x) > 1:
            print("no")
            return
    print("yes")
    pass


if __name__ == "__main__":
    main()