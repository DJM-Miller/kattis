def FizzBuzz():
    x = input().split()
    
    for i in range(int(x[2])):
        check = False
        a =  (i+1) / float(x[0])
        b =  (i+1) / float(x[1])
        if( a - int(a) == 0 ):
            print("Fizz",end='')
            check = True
        if( b - int(b) == 0 ):
            print("Buzz",end='')
            check = True
        if ( not check ):
            print(i+1, end='') 
        print()


if __name__ == "__main__":
    FizzBuzz()