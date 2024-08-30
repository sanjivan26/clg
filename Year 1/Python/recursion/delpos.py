def delpos(x,pos):
  if pos==0:
    return x[1:]
  else:    
    return x[0]+delpos(x[1:],pos-1)

print(delpos(input("number"),int(input("pos"))))