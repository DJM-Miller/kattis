def main():
    str = input()
    x = ":)"
    y = ":("
    if x in str and y in str:
        print("double agent")
    elif x in str:
        print("alive")
    elif y in str:
        print("undead")
    else:
        print("machine")
    pass


if __name__ == "__main__":
    main()