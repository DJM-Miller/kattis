from sys import stdin, stdout
from collections import Counter

def intDivision():
    N,d = stdin.readline().split()
    d = int(d)
    mylist = list(map(int, stdin.readline().split()))

    for x in range(int(N)):
        mylist[x] = int(mylist[x]/d)

    res = Counter(mylist)
    count = 0
    
    for x in res:
        n = res[x]
        count += int((n*(n-1))/2)


    # for i in range(int(N)-1):
    #     temp = int(mylist[i]/d)
    #     j = i+1
    #     while(j < int(N)):
    #         if temp == int(mylist[j]/d):
    #             count += 1
    #         j += 1
    
        
    return count



if __name__ == "__main__":
    print(intDivision())