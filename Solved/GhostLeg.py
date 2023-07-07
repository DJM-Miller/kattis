def main():
    n,m = map(int,input().split())
    rungs = list()
    for i in range(m):
        rungs.append(int(input()))
    pos = list(x+1 for x in range(n))
    #print(pos)
    for x in range(n):
        for r in rungs:
            if pos[x] == r:
                #print("+1")
                pos[x]+=1
            elif pos[x]-1 ==r:
                #print("-1")
                pos[x]-=1

    #print("**********************")
    x = 1
    while(x<n+1):
        for p in range(n):
            if x == pos[p]:
                print(p+1)
        x+=1
    #print(pos)
    


    pass


if __name__ == "__main__":
    main()