file_obj = open("a.txt","r")
lines = 0
words = 0
operators = 0

list = ["int","float"]
for line in file_obj:
    wordslist = line.split()
    lines = lines + 1
    words = words + len(wordslist)
    for c in line:
        if(c.isalpha()):
            continue
        elif(c.isdigit()):
            continue
        elif(c==' '):
            continue
        else:
            operators += 1
print("lines : ", lines)
print("words : ", words - operators)
print("operators : ", operators)