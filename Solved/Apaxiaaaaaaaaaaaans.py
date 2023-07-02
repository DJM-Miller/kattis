def main():
    str = input()
    mystr = str[0]
    for x in str:
        if x != mystr[-1]:
            mystr += x
    print(mystr)

    pass


if __name__ == "__main__":
    main()