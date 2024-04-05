import random
from math import log2
class Cache:
    def __init__(cache,linewidth,wordlines,bitlines):
        cache.linewidth=linewidth
        cache.wordlines=wordlines
        cache.bitlines=bitlines
        cache.datamatrix = [[random.choice([1,0])for i in range(bitlines)]for i in range(wordlines)]

        cache.wordlinelimit=log2(wordlines)
        cache.linenumberlimit=log2(bitlines/linewidth)
        cache.taglimit=log2(wordlines)

    def get_address():
        cache.addlen=cache.taglimit+cache.linenumberlimit+cache.wordlinelimit
        cache.address[cache.addlen]=int(input("Enter address of data"))

    def 


linewidth=int(input("Enter linewidth (ideally a power of 2)"))
wordlines=int(input("Enter number of rows in cache (ideally a power of 2)"))
bitlines=int(input("Enter number of columns in cache (ideally a multiple of linewidth)"))


cache=Cache(linewidth,wordlines,bitlines)
cache.get_address()

