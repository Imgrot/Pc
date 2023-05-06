n_uno = int(input("Ingrese su primer numero: "))

contador = 1
suma_uno = 0
suma_dos = 0
print("Sus multiplos son: ", end=" ")
while contador < n_uno:
    resto = n_uno % contador
    if resto == 0:
        suma_uno = suma_uno + contador
        print("{}".format(contador), end=", ")  
    contador = contador +  1
print(" ")
print("Y su suma es: {}.".format(suma_uno))
print(" ")

# empieza numero 2
contador = 1
print("En cuanto al numero {}".format(suma_uno))
print("Sus multiplos son: ", end=" ")
while contador < suma_uno:
    resto = suma_uno % contador
    if resto == 0:
        suma_dos = suma_dos + contador
        print("{}".format(contador), end=", ")  
    contador = contador +  1
print(" ")
print("Y su suma es: {}.".format(suma_dos))

if n_uno == suma_dos:
    print("Estos numeros son amigos!.")
else:
    print("Estos numeros no son amigos...")
    print("ponte las pilas weon")