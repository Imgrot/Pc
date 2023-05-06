from calculos import calculo
import os

def menu():
    loop = 'true'
    while loop == "true":
        os.system("cls")
        ip = input("Ingrese su dirección de IPv4 (considere los puntos en ella): ")

        valor_1 = []
        valor_2 = []
        valor_3 = []
        valor_4 = []
        cont = 0

        for y in ip:
            if y == ".":
                cont = cont + 1
                continue

            if cont == 0:
                valor_1.append(y)
            
            if cont == 1:
                valor_2.append(y)

            if cont == 2:
                valor_3.append(y)

            if cont == 3:
                valor_4.append(y)

        ip_1 = calculo((int("".join(valor_1))))
        ip_2 = calculo((int("".join(valor_2))))
        ip_3 = calculo((int("".join(valor_3))))
        ip_4 = calculo((int("".join(valor_4))))

        #print("Su IPv4 en binario es: " + "".join(ip_1) + "." + "".join(ip_2) + "." + "".join(ip_3) + "." + "".join(ip_4))
        print("Su IPv4 en binario es: {}.{}.{}.{}".format("".join(ip_1), "".join(ip_2), "".join(ip_3), "".join(ip_4)))
        input("Presione Enter para continuar...")
        os.system("cls")
        choice = input("Desea convertir otra IPv4 a Binario? (si / no).  ")
        if choice == 'no':
            break