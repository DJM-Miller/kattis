def main():
    N = int(input())
    for x in range(N):
        str1 = input()
        str2 = input()
        print(str1)
        print(str2)
        for a in range(len(str1)):
            if str1[a] != str2[a]:
                print("*",end="")
            else:
                print(".",end="")
        print("\n")
    pass


if __name__ == "__main__":
    main()