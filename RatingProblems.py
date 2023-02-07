def RP():
    n = list(map(int, input().split()))
    
    total = 0
    for i in range(n[1]):
        total += int(input())
    x = (n[0] - n[1]) * 3
    total_minus = (total - x) / n[0]
    total = (total + x) / n[0]
    print(total_minus," ",total)
        


if __name__ == "__main__":
    RP()