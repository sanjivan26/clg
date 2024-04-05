s=list(input("string"))
while s.remove(" ")!="":
    if s.count(s[0])%2==s[0]:
        print(s[0], )
    s.remove(s[0])   