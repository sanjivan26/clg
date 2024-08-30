import re 
if (re.search('^[a-b|A-B][0-9]{3}[_][A-Z|a-z]{2,}$',input())): print("valid")