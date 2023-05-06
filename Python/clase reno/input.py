import os
os.system("cls")
n = int(input("ingrese un numero menor a 10: "))

while n >= 10:
    os.system("cls")
    input("el numero no es menor a 10. Pulse Enter para continuar.")
    n = int(input ("ingrese un numero menor a 10: "))

os.system("cls")
print("el numero ingresado fue: {}".format(n))


