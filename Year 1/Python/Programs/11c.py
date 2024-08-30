file=open("example.txt")
lines=file.readlines()
print(lines[0],"\n",lines[1],sep="")
print(lines[2][:4],"\n")
for i in range(6,len(lines)):
    print(lines[i],"\n")