import re
if (re.search("$[A-Z|a-z|0-9|.|-|_][@][A-Z|a-z|0-9|-|_][.]..{2,}$",input())) : print("valid")