def count(t,num):
    no=0
    for i in t:
        if i==num:
            no+=1
    return no

def counter(t):
    l=[]
    print("The count of each element is")
    for i in t:
        if i not in l:
            no=0
            print(i,":",count(t,i),"times")
            l.append(i)

def single(t):
    l=[]
    l2=[]
    for i in t:
        if i not in l:
            if count(t,i)==1:
                l2.append(i)
            l.append(i)
    return l2        

t=tuple(map(int,input().split())) 

counter(t)

l2=[single(t)]
print("The elements occuring only once are : ",end="")
for i in l2:
    print(i,end=", ")
