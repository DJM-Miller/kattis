def main():
    count = 0
    for x in range(5):
        if "FBI" in input():
            print(x+1)
            count+=1

    if count == 0:
        print("HE GOT AWAY!")



    pass


if __name__ == "__main__":
    main()