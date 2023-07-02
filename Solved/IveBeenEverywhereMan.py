def main():
    #Change name and put code here
    N = int(input())
    while(N > 0):
        X = int(input())
        myset = set()
        for i in range(X):
            myset.add(input())
        print(len(myset))   
        N -= 1
    pass



if __name__ == "__main__":
    main()