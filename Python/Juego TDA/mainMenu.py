from Combate.combate import combate
from Creación.crearChar import crearPersonaje
from gmLogin import logGM
import os

def mainMenu():
    loop = True
    estado = "Vivo"
    while loop:
        os.system("cls")

        print("1.- Buscar un combate")
        print("2.- Revivir")
        print("3.- Crear Personaje")
        print("4.- Acceder como GM")
        print("5.- salir")
        choice = input("Elija una opcion:  ")

        os.system("cls")

        if choice == "1":
            if estado == "Vivo":
                estado = combate()
            elif estado == "Muerto":
                input("Estás muerto!")

        elif choice == "2":
            if estado == "Vivo":
                input("Usted ya está vivo!")
            elif estado == "Muerto":
                revive=input("Deseas revivir? (si / no):    ")
                if revive=="si":
                    estado = "Vivo"

        elif choice == "3":
            crearPersonaje()

        elif choice == "4":
            logGM()

        else:
            input("Pulse ENTER para salir...     ")
            os.system("cls")
            break

mainMenu()
