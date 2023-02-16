N = int(input())
counting = list()
for x in range(N):
    counting.append(int(input()))
none_missing = True
for x in range(1,max(counting)):
    if x not in counting:
        print(x)
        none_missing = False
if none_missing:
    print("good job")
    