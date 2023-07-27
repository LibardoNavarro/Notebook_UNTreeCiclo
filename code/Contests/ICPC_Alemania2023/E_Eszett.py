string=input()
eses=string.count("S")
if eses==0:
    print(string.lower())
else:
    n=len(string)
    string=string.lower()
    print(string)
    for i in range(n-1):
        if string[i]=="s" and string[i+1]=="s":
            print(string[:i]+"B"+string[i+2:])
    