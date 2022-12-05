from itertools import combinations

def Perket():
    N = int(input())
    ing_list = []
    for i in range(N):
        x,y = input().split()
        ing_list.append((int(x),int(y)))

    combo_set = set()
    for i in range(len(ing_list)+1):
        for subset in combinations(ing_list,i):
            combo_set.add(subset)
    

    smallest_diff = 1000000000
    for combo in combo_set:
        temp_bitter = 0
        temp_sour = 1
        for ing in combo:
                temp_sour *= ing[0]
                temp_bitter += ing[1]

        if(smallest_diff > abs(temp_bitter - temp_sour)) and len(combo) > 0:
            smallest_diff = abs(temp_bitter-temp_sour)

    if(N != 0):
        print(smallest_diff)
    else:
        print(0)
            

    

if __name__ == "__main__":
    Perket()