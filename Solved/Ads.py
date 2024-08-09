
LEGAL_CHAR = set(['?','!',',','.',' '])

def main():
    H, W = map(int,input().split())
    
    matrix = list()
    for _ in range(H):
        matrix.append(list(input()))


    x = y  = 0
    for x in range(H):
        for y in range(W):
            if matrix[x][y] == '+':
                check_image(matrix, x, y)


    result = [''.join(line) for line in matrix]
    return result

# returns size of image
def find_image_size(matrix, start_x, start_y):
    x = start_x
    y = start_y
    size_x = 0
    size_y = 0
    while x < len(matrix) and matrix[x][y] == '+':
        size_x += 1
        x += 1
    x = start_x
    while y < len(matrix[x]) and matrix[x][y] == '+':
        size_y += 1
        y += 1
    
    return size_x, size_y
    



def check_image(matrix, start_x, start_y):
    size_x, size_y = find_image_size(matrix, start_x, start_y)
    for x in range(start_x+1, start_x+size_x-1):
        for y in range(start_y+1, start_y+size_y-1):
            if matrix[x][y] == '+':
                check_image(matrix, x, y)
            elif matrix[x][y].isalnum() or matrix[x][y] in LEGAL_CHAR:
                pass
            else:
                wipe_image(matrix, start_x, start_y, size_x, size_y)
                break


def wipe_image(matrix, start_x, start_y, size_x, size_y):
    for x in range(start_x, start_x+size_x):
        for y in range(start_y, start_y + size_y):
            matrix[x][y] = ' '


if __name__ == "__main__":
    result = main()
    for line in result:
        print(line)



#---TESTS---------TESTS-------TESTS-----

import pytest

def test_case_1(monkeypatch):
    inputs = iter([
        "8 20",  # H = 8, W = 20
        " apples are great!  ",
        "++++++++++++++++++++",
        "+ oranges are      +",
        "+ way better!      +",
        "+ #oranges>apples  +",
        "++++++++++++++++++++",
        " check out our      ",
        " fresh apples!      "
    ])  
    monkeypatch.setattr('builtins.input', lambda: next(inputs))
    results = main()
    expected = [" apples are great!  ",
                "                    ",
                "                    ",
                "                    ",
                "                    ",
                "                    ",
                " check out our      ",
                " fresh apples!      "]
    assert results == expected


def test_case_2(monkeypatch):
    inputs = iter( ['7 7',
                    '+++++++', 
                    '+     +', 
                    '+ +++ +', 
                    '+ +=+ +', 
                    '+ +++ +', 
                    '+     +', 
                    '+++++++'])  
    monkeypatch.setattr('builtins.input', lambda: next(inputs))
    results = main()
    expected = ['+++++++', 
                '+     +', 
                '+     +', 
                '+     +', 
                '+     +', 
                '+     +', 
                '+++++++']
    assert results == expected


def test_case_3(monkeypatch):
    inputs = iter([ '7 7',
                    '+++++++', 
                    '+  =  +', 
                    '+ +++ +', 
                    '+ + + +', 
                    '+ +++ +', 
                    '+     +', 
                     '+++++++'])  
    monkeypatch.setattr('builtins.input', lambda: next(inputs))
    results = main()
    expected = ['       ', 
                '       ', 
                '       ', 
                '       ', 
                '       ', 
                '       ', 
                '       ']
    assert results == expected


def test_find_image_size():
    matrix = ['+++++++', '+  =  +', '+ +++ +', '+ + + +', '+ +++ +', '+     +', '+++++++']
    for line in matrix:
        line = list(line)
    result = find_image_size(matrix, 2, 2)
    assert result == (3, 3)
    result = find_image_size(matrix, 0, 0)
    assert result == (7,7)

def test_wipe_image():
    matrix = ['+++++++', '+  =  +', '+ +++ +', '+ + + +', '+ +++ +', '+     +', '+++++++']
    matrix = [list(line) for line in matrix]
    wipe_image(matrix, 2, 2, 3, 3)
    result = [''.join(line) for line in matrix]
    assert result == ["+++++++", '+  =  +', '+     +', '+     +', '+     +', '+     +', '+++++++']

    matrix = ['+++++++', '+  =  +', '+ +++ +', '+ + + +', '+ +++ +', '+     +', '+++++++']
    matrix = [list(line) for line in matrix]
    wipe_image(matrix, 0, 0, 7, 7)
    result = [''.join(line) for line in matrix]
    assert result == ['       ', '       ', '       ', '       ', '       ', '       ', '       ']