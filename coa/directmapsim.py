import random
import math as m

def dec(x):
    return int(x,2)

def nbit(x,n):
    i = x %(10**n-1)
    return i%10


class dmcache:
    def __init__(lines,linesize):
        dmcache.offsetlimit=8
        dmcache.setlimit=lines
        dmcache.taglimit=linesize
        dmcache.datablock=[[0,0,0]for i in range(dmcache.setlimit)] #validity, tag, data

    def fetch(address):
        #dmcache.addlen=m.log2(dmcache.taglimit)+m.log2(dmcache.setlimit)+m.log2(dmcache.offsetlimit)
        address=int(input("Enter address of data"))
        offset=address%(m.log2(dmcache.offsetlimit))
        set=address%(m.log2(dmcache.setlimit))
        tag=address%(m.log2(dmcache.taglimit))

        #hit
        if dmcache.datablock[0][dec(set)%dmcache.setlimit]==1 and dmcache.datablock[1][dec(set)%dmcache.setlimit]==tag:
            return nbit(dmcache.datablock[1][dec(set)%dmcache.setlimit],offset)
        
        #miss => fetch
        else:
             #to write code to fetch from cache lvl 2
             print()

class main:
    def __init__(cache,linewidth,wordlines,bitlines):
        cache.linewidth=linewidth
        cache.wordlines=wordlines
        cache.bitlines=bitlines
        cache.datamatrix = [[random.choice([1,0])for i in range(bitlines)]for i in range(wordlines)]

        cache.wordlinelimit=m.log2(wordlines)
        cache.linenumberlimit=m.log2(bitlines/linewidth)
        cache.taglimit=m.log2(wordlines)

    def get_address():
        cache.addlen=cache.taglimit+cache.linenumberlimit+cache.wordlinelimit
        cache.address[cache.addlen]=int(input("Enter address of data"))



linewidth=int(input("Enter linewidth (ideally a power of 2)"))
wordlines=int(input("Enter number of rows in cache (ideally a power of 2)"))
bitlines=int(input("Enter number of columns in cache (ideally a multiple of linewidth)"))


cache=dmcache(linewidth,wordlines,bitlines)
cache.get_address()

