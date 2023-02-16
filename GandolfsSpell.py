line1 = input()
line2 = input().split()
for word in line2:
    word.strip()

spell = True
if len(line1) != len(line2):
     spell = False
     
if spell:

    letter_set = set()
    let_word_dict = dict()
    for x in range(len(line1)):
        if (line1[x] in letter_set) and (let_word_dict[line1[x]] != line2[x]):
                spell = False
                break
        elif (line1[x] not in letter_set):
            letter_set.add(line1[x])
            let_word_dict[line1[x]] = line2[x]

    word_set = set()
    for x in let_word_dict:
        if let_word_dict[x] in word_set:
            spell = False
            break
        else:
            word_set.add(let_word_dict[x])




if spell:
    print("True")
else:
    print("False")




