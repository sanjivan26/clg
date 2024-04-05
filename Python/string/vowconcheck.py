s=input()
vow=con=0
if s.isalpha():
    print("THe String contains only letters")
    for i in range(len(s)):
        if s[i] in ["a","e","i","o","u","A","E","I","O","U"]:
            vow+=1
        else:
            con+=1
    print("It has %d vowels and %d consonants" %(vow,con))        
else:
    print("The string has values other than letters")        
