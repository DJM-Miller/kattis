def main():
    str = input()
    code = input()
    for x in range(0,len(code),3):
        print(str[int(code[x:x+3])-1], end="")
    pass


if __name__ == "__main__":
    main()