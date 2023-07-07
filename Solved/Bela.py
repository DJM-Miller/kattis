def main():
    dic1 = {'A':11, 'K':4, 'Q':3, 'J':20, 'T':10, '9':14, '8':0, '7':0}
    dic2 = {'A':11, 'K':4, 'Q':3, 'J':2, 'T':10, '9':0, '8':0, '7':0}
    N,S = input().split()
    total = 0
    for x in range(int(N)*4):
        str = input()
        if str[1] == S:
            total += dic1[str[0]]
        else:
            total += dic2[str[0]]
    print(total)
        


    pass


if __name__ == "__main__":
    main()