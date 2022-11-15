def aDifProb():
    while True:
        try:
            x,y = input().split()
            print(abs(int(x)-int(y)))
        except:
            break



if __name__ == "__main__":
    aDifProb()