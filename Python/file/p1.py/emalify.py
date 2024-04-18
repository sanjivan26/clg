import re
import sys
import os

def kys():
    exit

n=len(sys.argv)

if n!=2:
    print("Wrong number of arguements")
    kys()
if len(os.listdir(sys.argv[1]))<6:
    print("Insufficient files in input directory")
    kys()  
if len(os.listdir(sys.argv[1]))>1:
    if(int(input("Can files be deleted?"))):
        #delete files






    file2=open("folder\%s",sys.argv[2])
    for i in os.listdir(sys.argv[1]):
        file1=open("%s",i)
        for j in file1:
            if re.findall("^[a-zA-Z0-9_-\.]$",j)==[]:
                file2=open(sys.argv[2])
                file2.write(re.sub("[^a-zA-Z0-9\s]","",j)+"@snuchennai.edu.in\n")
