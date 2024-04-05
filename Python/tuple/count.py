s=input()
l=[s[0],s.count(s[0])]
for i in set(s):
    if s.count(i)>l[1]:
        l=[i,s.count(i)]
print(tuple(l))        