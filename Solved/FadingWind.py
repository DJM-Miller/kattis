def main():
    dist = 0
    h,k,v,s = map(int,input().split())
    while(h > 0):
        v += s
        v -= max(1,int(v/10))
        if v >= k:
            h +=1
        elif v > 0 and v < k:
            h -= 1
            if h == 0:
                v = 0
        if v <= 0:
            h = 0
            v = 0
        if s > 0:
            s -= 1
        dist += v
    print(dist)
    pass


if __name__ == "__main__":
    main()