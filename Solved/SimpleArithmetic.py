from decimal import Decimal
def main():
    x = input()
    a = Decimal(x.split()[0])
    b = Decimal(x.split()[1])
    c = Decimal(x.split()[2])
    print(Decimal(a*(b/c)))
            

    pass


if __name__ == "__main__":
    main()


