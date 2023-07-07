def main():
    x,y = map(int,input().split())
    park = list()
    outlist = list([0]*5)
    #print(outlist)
    #count = 0
    for i in range(x):
        park.append(input())
    #print(park)
    for i in range(y-1):
        for j in range(x-1):
            str = park[j][i] + park[j+1][i] + park[j][i+1] + park[j+1][i+1]
            if '#' in str:
                pass
            else:
                outlist[str.count('X')]+=1
                #count+=1
    #print(count)
    for x in outlist:
        print(x)
    pass


if __name__ == "__main__":
    main()