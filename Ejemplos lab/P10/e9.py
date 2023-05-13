#variables globales

cont = 0
def increment():
    cont = 5

increment()
print (cont)


cont = 0
def increment():
    global cont
    cont = 5

increment()
print(cont)