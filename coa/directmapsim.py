import math as m
import pandas as pd
from random import randint
import streamlit as st

dispsize = 5

def dec(x):
    return int(str(x),2)

def nbit(x,n):
    i = x %(10**n-1)
    return i%10

#data from question
byteoffset=8#bits

#for l1 cache
l1linesize = 64#bytes    #64 bytes
l1lines = 128#lines

#for victim cache
vlines = 4#digits

#for l2 cache
l2lines = 256#lines

#main memory size
mainsize = 64*1024*8#bits (19 digits)

#defining the l1 cache
class dmcache: #9 7 6
    def __init__(self,lines,linesize,vlines):
        self.offsetlimit=int(m.log2(byteoffset * linesize))
        self.setlimit=int(m.log2(lines))
        self.taglimit=int(m.log2(mainsize / (lines*linesize*byteoffset)))
        self.datablock=[[0,0,0]for i in range(lines)] #validity, tag, data
        #defining the victim cache
        self.vdatablock=[[0,0,0]for i in range(vlines)] #validity, tag, data
        self.vcur = -1

    def fetch(self,address):
        offset = (address[-1*self.offsetlimit:])
        set = (address[-1*(self.offsetlimit+self.setlimit):-1*(self.offsetlimit)])
        tag = address[-1*(self.offsetlimit+self.setlimit+self.taglimit):-1*(self.offsetlimit+self.setlimit)]
        decset = dec(int(set))
        if decset<3:
            col = ["","","","",""]
            col[decset]="Required column : "
            df = pd.DataFrame(self.datablock[:dispsize],columns = ["validity", "tag", "data"],index = col)
        elif decset>self.setlimit-3:
            col = ["","","","",""]
            col[dispsize-(self.setlimit-decset)]="Required column : "
            df = pd.DataFrame(self.datablock[self.setlimit-dispsize:self.setlimit],columns = ["validity", "tag", "data"],index = col)
        else:
            df = pd.DataFrame(self.datablock[decset-2:decset+2],columns = ["validity", "tag", "data"],index = ["","","Required column : ","",""])
            
        if self.datablock[decset][0]==1 and self.datablock[decset][1]==tag:
            #cache hit
            print("The tag in given address was found in the datablock of the l1 cache")
            print(df)
            print("The data in given address was : ",self.datablock[decset][2])
            return self.datablock[decset][2]
        else:
            #cache miss
            print("The tag in given address was not found in the datablock of the l1 cache")
            print(df)

            for i in range(4):
                if self.vdatablock[i][1]==address[-1*(self.offsetlimit+self.setlimit+self.taglimit):-1*(self.offsetlimit)]:
                    col = ["","","",""]
                    col[i]="Required column : "
                    df = pd.DataFrame(self.vdatablock,columns=["validity","tag","data"],index=col)
                    print("The address was found in victim cache of the l1 cache")
                    print(df)
                    self.store(self.vdatablock[i][1]+offset,self.vdatablock[i][2])
                    return self.vdatablock[i][2]
            print("The address was not found in victim cache of the l1 cache")
            print(pd.DataFrame(self.vdatablock,columns=["validity","tag","data"],index=["","","",""]))
            return 0
        
    def store(self, address, data):
        offset = (address[-1*self.offsetlimit:])
        set = int(address[-1*(self.offsetlimit+self.setlimit):-1*(self.offsetlimit)])
        tag = address[-1*(self.offsetlimit+self.setlimit+self.taglimit):-1*(self.offsetlimit+self.setlimit)]
        decset = dec(set)

        if self.datablock[decset][0]==1:  
            flag = 0
            for i in range(4):
                if self.vdatablock[i][1]==address[-1*(self.offsetlimit+self.setlimit+self.taglimit):-1*(self.offsetlimit)]:
                    flag = 1
                    break
                    
            if flag == 0:
                print("Shifting current value to victim cache of l1 cache")
                self.vcur=(self.vcur+1)%4
                self.vdatablock[self.vcur] = self.datablock[decset]
                self.vdatablock[self.vcur][1] += address[-1*(self.offsetlimit+self.setlimit):-1*(self.offsetlimit)]
                col = ["","","",""]
                col[self.vcur]="Required column : "
                df = pd.DataFrame(self.vdatablock,columns=["validity","tag","data"])
                print(df)

        self.datablock[decset]=[1,tag,data]
        print("Data added to l1 cache")
        if decset<3:
            l=[]
            for i in range(decset):
                l.append("")
            l.append("Modified column : ")
            for i in range(dispsize - decset - 1):
                l.append("")
            df = pd.DataFrame(self.datablock[0:dispsize],columns = ["validity", "tag", "data"],index = l)
        elif decset>self.setlimit-3:
            l=[]
            for i in range(self.setlimit-dispsize):
                l.append("")
            l.append("Modified column : ")
            for i in range(self.setlimit-decset+1):
                l.append("")                
            df = pd.DataFrame(self.datablock[self.setlimit-dispsize:self.setlimit],columns = ["validity", "tag", "data"],index = l)
        else:
            df = pd.DataFrame(self.datablock[decset-2:decset+2],columns = ["validity", "tag", "data"],index = ["","","Modified column : ","",""])
        print(df)


class sacache:
    def __init__(self,lines,linesize):
        self.offsetlimit=int(m.log2(byteoffset * linesize))
        self.setlimit=int(m.log2(lines/4))    #4 way set associative cache
        self.taglimit=int(m.log2(mainsize)-self.offsetlimit-self.setlimit)
        self.datablock=[[[0,0,0]for i in range(4)]for i in range(int(lines/4))] #validity, tag, data


    def fetch(self,address):
        offset = (address[-1*self.offsetlimit:])
        set = (address[-1*(self.offsetlimit+self.setlimit):-1*(self.offsetlimit)])
        tag = address[-1*(self.offsetlimit+self.setlimit+self.taglimit):-1*(self.offsetlimit+self.setlimit)]
        decset = dec(set)

        df = pd.DataFrame(self.datablock[decset],columns=["validity","tag","data"],index=["","","",""])
        loc = -1
        for i in range(len(self.datablock[decset])):
            if self.datablock[decset][i]:
                if self.datablock[decset][i][1]==tag and self.datablock[decset][i][0]==1:
                    loc = i
                    break
        if loc!=-1:
            #cache hit
            print("The tag in given address was found in the datablock of the l2 cache")
            print(df)
            return self.datablock[decset][loc][2]
        
        else:
            #cache miss
            print("The tag in given address was not found in the datablock of the l2 cache")
            print(df)
            return 0

    def store(self, address, data):
        offset = (address[-1*self.offsetlimit:])
        set = int(address[-1*(self.offsetlimit+self.setlimit):-1*(self.offsetlimit)])
        tag = address[-1*(self.offsetlimit+self.setlimit+self.taglimit):-1*(self.offsetlimit+self.setlimit)]
        decset = dec(set)

        for i in self.datablock[decset]:
            if i[1]==tag:
                i[2]==data
                print("Data added to l2 cache from main memory")
                print(pd.DataFrame(self.datablock[decset],columns=["validity","tag","data"],index=["","","",""]))
                return 1
        for i in range(len(self.datablock[decset])):
            if self.datablock[decset][i][0]==0:
                self.datablock[decset][i] = [1,tag,data]
                print("Data added to l2 cache from main memory")
                print(pd.DataFrame(self.datablock[decset],columns=["validity","tag","data"],index=["","","",""]))
                return 1
        self.datablock[decset][randint(0,3)] = [1,tag,data]
        print("Data added to l2 cache from main memory")
        print(pd.DataFrame(self.datablock[decset],columns=["validity","tag","data"],index=["","","",""]))
        return 1

l1 = dmcache(l1lines,l1linesize,vlines)
l2 = sacache(l2lines,l1linesize)

while(1):
    address = st.text_input("Enter the address of the data to be fetched")
    result1 = l1.fetch(address)
    if(result1!=0):
        continue
    else:
        result2 = l2.fetch(address)
        if(result2!=0):
            l1.store(address,result2)
            l1.fetch(address)
            continue
        else:
            data = 'data in line of ' + address
            l2.store(address,data)
            result2 = l2.fetch(address)
            l1.store(address,result2)
            l1.fetch(address)


#0000000000000000000
