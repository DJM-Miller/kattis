def probs():
    num = int(input())
    if(num < 149):
        print(99)
    else:
        if(((num%100)-49) >= 0):
            print(num + (99-num%100))
        else:
            print(num - num%100 - 1)


if __name__ == "__main__":
    probs()