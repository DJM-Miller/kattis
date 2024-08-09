def main():
    n,pos,m = map(int,input().split())
    board = list(map(int,input().split()))
    pos -= 1
    visited = set()
    count = 0
    while pos >= 0 and pos < n:
        if board[pos] == m:
            print("magic")
            break
        if pos in visited:
            print("cycle")
            break
        visited.add(pos)
        pos += board[pos]
        count += 1


    if pos < 0:
        print("left")
    if pos >= n:
        print("right")

    print(count)







if __name__ == "__main__":
    main()