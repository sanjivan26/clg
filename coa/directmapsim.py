import math as m
import streamlit as st
import pandas as pd

dispsize = 5

def dec(x):
    return int(str(x),2)

def nbit(x,n):
    i = x %(10**n-1)
    return i%10

#data from question
byteoffset=8

#for l1 cache
l1linesize = 9#digits      #64 bytes
l1lines = 128

#for victim cache
vlines = 4#digits

#for l2 cache
l2lines = 256

#main memory size
mainsize = 16#digits

#defining the l1 cache
class dmcache:
    def __init__(self,lines,linesize,vlines):
        self.offsetlimit=m.log2(byteoffset * linesize)
        self.setlimit=m.log2(lines)
        self.taglimit=mainsize / (linesize * m.log2(lines))
        self.datablock=[[0,0,0]for i in range(lines)] #validity, tag, data
        #defining the victim cache
        self.vdatablock=[[0,0,0]for i in range(vlines)] #validity, tag, data
        self.vcur = -1

    def fetch(self,address):
        offset = self.address%self.offsetlimit
        address//self.offsetlimit
        set = address%self.setlimit
        address//self.setlimit
        tag = address%self.taglimit
        decset = dec(set)

        if self.datablock[decset][0]==1:
            if decset<3:
                df = pd.DataFrame(self.datablock[0:dispsize],columns = ["validity", "tag", "data"],index = ["Previous columns"*(decset-1),"Required column","Next columns"*(dispsize - decset)])
            elif decset>self.setlimit-3:
                df = pd.DataFrame(self.datablock[self.setlimit-dispsize:self.setlimit],columns = ["validity", "tag", "data"],index = ["Previous columns"*(self.setlimit-dispsize+1),"Required column","Next columns"*(self.setlimit-decset)])
            else:
                df = pd.DataFrame(l1.datablock[decset-2:decset+2],columns = ["validity", "tag", "data"],index = ["Previous columns","Previous columns","Required column","Next columns","Next columns"])
                
            if self.datablock[decset][1]==tag:
                #cache hit
                st.write("The tag in given address was found in the datablock of the cache")
                st.write(df)
                st.write("The data in given address was : ",self.datablock[decset][2])
                return 1
            else:
                #cache miss
                st.write("The tag in given address was not found in the datablock of the cache")
                st.write(df)
                return 0
        else:
            #cache miss
            st.write("The tag in given address was not found in the datablock of the cache")
            st.write(df)
            return 0

l1=dmcache(l1lines,l1linesize,vlines)
df = pd.DataFrame(l1.datablock[5:10],columns = ["validity", "tag", "data"],index = ["Previous columns","Previous columns","Required column","Next columns","Next columns"])
print(df)




#user interface
#st.title("Cache levels simulation")
#st.number_input("Enter the address here",min_value=int("0"*mainsize),max_value=int('1'*mainsize))
