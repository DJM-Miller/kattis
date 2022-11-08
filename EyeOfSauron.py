

def __main__():
    stack = []
    mystring = input()
    eye = False
    for i in range(len(mystring)):
        if eye==False:
            if mystring[i] == '|':
                stack.append(mystring[i])
            if mystring[i] == '(':
                i += 1
                eye = True
                if mystring[i] != ')':
                    print("fix")
                    return
        else:
            if not stack:
                print("fix")
                return
            elif mystring[i] == ')':
                pass
            elif mystring[i] == '|':
                stack.pop()
            
    if not stack:
        print("correct")
        return
    else:
        print("fix")
        return


__main__()