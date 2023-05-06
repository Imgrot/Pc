import random

N = int(input("¿Cuantos lanzamientos desea realizar?"))
C = 0
for I in range(N-1):

    X = random.randint(1, 6)
    Y = random.randint(1, 6)
    if X == Y:
        C = C + 1

print("Los dados se repitieron un total de {} veces!.".format(C))