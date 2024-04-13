import sys
#if len(sys.argv)<2:
#    print('Error : Insufficient arguements')
#    exit()
f=open(r"C:\VS Code\Coding\Python\file\text.txt")    
n=int(input('n'))
k=int(input('k'))
print((f.readlines(n)))
print((f.readlines()[k:]))