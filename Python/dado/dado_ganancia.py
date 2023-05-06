import random

N = int(input("¿Cuantos lanzamientos desea realizar:  ?"))
ganancia = 0
C = 0
for I in range(N-1):
    X = random.randint(1, 6)
    if X == 6:
        ganancia = ganancia + 100
    elif X == 3:
        ganancia = ganancia + 500
        C = C + 1
    elif X == 2 or X == 4 or X == 5:
        ganancia = ganancia - 200

if ganancia > 0:
    print("Usted ganó {} pesos!".format(ganancia))
elif ganancia < 0:
    print("Usted perdió {} pesos!".format(ganancia))
else:
    print("Usted no ganó nada.")