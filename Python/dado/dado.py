import random

N = int(input("¿Cuantos lanzamientos desea realizar?"))
C = 0
for I in range(N-1):

    X = random.randint(1, 6)

    if X == 3:
        C = C + 1

print("El numero 3 salió un total de {} veces!.".format(C))
