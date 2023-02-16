C = float(input())
L = int(input())
total = 0.0
for i in range(L):
    x = input().split()
    total += float(x[0]) * float(x[1])

print("{:.6f}".format(C * total))