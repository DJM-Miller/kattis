Num = input()
coeffiecients = (4,3,2,7,6,5,4,3,2,1)
total = 0
j = 0

for i in range(len(Num)):
    if i == 6:
        i+=1
    else:
        total += int(Num[i]) * coeffiecients[j]
        j+=1


if total % 11 == 0:
    print(1)
else:
    print(0)