import random

for I in range(10):
    numero = int(random.randint(1, 20))
    print("{}".format(numero), end=" ")
    for x in range(numero):        
        print("*", end = "")
    print(" ")