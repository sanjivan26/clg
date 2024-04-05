d={"hi":1,"hulo":2,"yo":3,"hey":4}
print(list(d.keys())[list(d.values()).index(min(list(d.values())))])