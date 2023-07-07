def main():
    s1 = input()
    s2 = input()
    s = list(s1 + s2)
    #s = s.sort()
    for x in sorted(s):
        print(x,end="")
    print()
    pass


if __name__ == "__main__":
    main()