def main():
    x = input()
    y = x[0],x[3],x[6],x[9],x[12]
    z = list()
    for x in y:
        z.append(y.count(x))
    print(max(z))

    pass


if __name__ == "__main__":
    main()