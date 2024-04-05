s=list(input())
w=str(set(s))
mincount=len(s)
for i in range(len(s)):
    if s[i] in w:
        s1=str(w).replace(",","").replace("{","").replace("}","")
        print(s1)
        cur=0
        s1.replace(s[i],"")
        for j in s[i:len(s)-1]:
            if j in s1:
                s1.replace(j,"")
            cur+=1
            if(s1==""):
                print(cur)
                if(cur<mincount):
                    mincount=cur
                break    
print(mincount)                    

