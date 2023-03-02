s = input().split()
m = input().split()
Sun = int(s[1]) - int(s[0])
Moon = int(m[1]) - int(m[0])
while(Sun != Moon):
    if Sun < Moon:
        Sun += int(s[1])
    if Moon < Sun:
        Moon += int(m[1])
print(Sun)