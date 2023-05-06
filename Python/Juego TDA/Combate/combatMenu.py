import os
import random

def combatMenu(personaje, mounstruo):
    
    os.system("cls")
    print("Stat -------  Héroe ------ {}".format(mounstruo["Nombre"]))
    print("Vida          {}/{}           {}/{}".format(personaje["Vida"], personaje["Vida Máxima"], mounstruo["Vida"], mounstruo["Vida Máxima"]))
    print("Ataque         {}              {}".format(personaje["Ataque"], mounstruo["Ataque"]))
    print("Defensa        {}              {}".format(personaje["Defensa"], mounstruo["Defensa"]))
    print("Mana          {}/{}".format(personaje["Maná"], personaje["Maná Máximo"]))
    print("Estado         {}".format(personaje["Estado"]))
    print("")
    if personaje["Estado"] == "Vivo":
        print("Que deseas hacer?")
        print("[1] Atacar")
        print("[2] Defenderte")
        print("[3] Curarte 10 de Vida (5 Maná)")
        print("[4] Huir")
        opcion = input("------>  ")
        while opcion != "1" and opcion != "2" and opcion != "3" and opcion != "4" or (opcion == "3" and personaje["Maná"] < 5):
            os.system("cls")
            input("Opción ingresada inválida")
            if personaje["Maná"] < 5:
                input("Su Maná está demasiado bajo...")
            os.system("cls")
            print("Stat -------  Héroe ------ {}".format(mounstruo["Nombre"]))
            print("Vida          {}/{}           {}/{}".format(personaje["Vida"], personaje["Vida Máxima"], mounstruo["Vida"], mounstruo["Vida Máxima"]))
            print("Ataque         {}              {}".format(personaje["Ataque"], mounstruo["Ataque"]))
            print("Defensa        {}              {}".format(personaje["Defensa"], mounstruo["Defensa"]))
            print("Mana          {}/{}".format(personaje["Maná"], personaje["Maná Máximo"]))
            print("Estado         {}".format(personaje["Estado"]))
            print("")
            print("Que deseas hacer?")
            print("[1] Atacar")
            print("[2] Defender")
            print("[3] Curarte 10 de Vida (5 Maná)")
            print("[4] Huir")
            opcion = input("------>  ")
    elif personaje["Estado"] == "Congelado":
        print("Estás congelado!")
        input("No puedes realizar ninguna acción este turno...  ")
        opcion = "1"

    return opcion
