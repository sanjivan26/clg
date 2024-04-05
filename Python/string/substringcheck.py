s=input("String")
r=input("Substring")

for i in range(len(s)):
    flag=0
    for j in range(len(r)):
        if s[i+j]!=r[j]:
            flag=1
    if flag==0:
        print("The given substring is valid")
        break        