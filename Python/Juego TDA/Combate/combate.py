from Entities.elegirMounstruo import monsterSelect
from Entities.player import player
from Combate.combatMenu import combatMenu
from Combate.Atacar import Atacar
from Combate.Defender import Defender
from Combate.Curar import Curar
import os
import random

def combate():
    os.system("cls")

    enemigo=random.randint(0,3)
    personaje=player()
    mounstruo = monsterSelect(enemigo)
    
    input("Un {} apareció!    ".format(mounstruo["Nombre"]))

    loop = True
    while loop:
        os.system("cls")

        if personaje["Estado"]=="Congelado":
            if random.randint(1,100) >= 50:
                personaje["Estado"] = "Vivo"
                input("Te has descongelado!")

        opcion = combatMenu(personaje, mounstruo)

        if opcion == "1":       #Atacar
            mounstruo,personaje=Atacar(mounstruo,personaje)
            if personaje["Estado"] == "Muerto":
                return personaje["Estado"]

        elif opcion == "2":     #Defenderte
            
            personaje, mounstruo = Defender(personaje, mounstruo)
            if personaje["Estado"] == "Muerto":
                return personaje["Estado"]

        elif opcion == "3":     #Curarte 10 HP
            
            personaje, mounstruo = Curar(personaje, mounstruo)
            if personaje["Estado"] == "Muerto":
                return personaje["Estado"]

        elif opcion == "4":     #Escapar
            os.system("cls")
            input("Has escapado del combate!")
            break
        else:
            input("Opción inválida")