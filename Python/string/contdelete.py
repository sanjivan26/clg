s1=input()
s2=input()
flag=0
while True:
    s=s1
    s1=s1.replace(s2,"")
    if s1=="":
        print("possible")    
        break
    elif s==s1:
        print("Not possible")
        break
   