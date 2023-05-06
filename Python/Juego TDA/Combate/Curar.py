import os
import random

def Curar(personaje, mounstruo):
    os.system("cls")
    print("_____Tu turno_____")
    if personaje["Maná"]> 0:
        calcHP = personaje["Vida"] + 10
        if calcHP > personaje["Vida Máxima"]:
            hpRestored = 10 - ((calcHP) - personaje["Vida Máxima"])
            personaje["Vida"] += hpRestored
            input("Te has curado {} puntos de Vida!".format(hpRestored))
        else:
            personaje["Vida"]+=10
            input("Te has curado 10 puntos de Vida!")
        personaje["Maná"] -= 5
    elif personaje["Maná"] == 0:
        input("No te queda Maná...")


    #turno mounstruo
    print("_____Turno Enemigo_____")
    hit=random.randint(1,100)
    hit -= personaje["Evasión"]
    if personaje["Estado"] == "Congelado":
        hit=100
        print("Estás congelado, no puedes evadir...")
    if hit < 20:
        input("Esquivaste el golpe...")

    else:
        crit = random.randint(1,100)

        if crit <= personaje["Critico"]:
            daño = 2*(mounstruo["Ataque"]) - mounstruo["Defensa"]
            personaje["Vida"] -= daño
            print("Golpe Crítico!")
            input("Te han inflingido {} puntos de daño!".format(daño))

            if personaje["Vida"] <=0:
                input("Has muerto...")
                personaje["Estado"] = "Muerto"
                return personaje, mounstruo
            if mounstruo["Nombre"] == "Slime de Hielo" or mounstruo["Nombre"] == "Lobo Congelante":
                if personaje["Estado"] == "Vivo":
                    if random.randint(1,100) <=33:
                        personaje["Estado"] = "Congelado"
                        input("Te han congelado!")
                


        else:
            daño = mounstruo["Ataque"] - personaje["Defensa"]
            personaje["Vida"] -= daño
            input("Te han inflingido {} puntos de daño!".format(daño))

            if personaje["Vida"] <=0:
                input("Has muerto...")
                personaje["Estado"] = "Muerto"
                return personaje, mounstruo
            if mounstruo["Nombre"] == "Slime de Hielo" or mounstruo["Nombre"] == "Lobo Congelante":
                if personaje["Estado"] == "Vivo":
                    if random.randint(1,100) <=33:
                        personaje["Estado"] = "Congelado"
                        input("Te han congelado!")
                

    if personaje["Maná"]<personaje["Maná Máximo"]:          #Regeneración de Maná por turno
        if (personaje["Maná"]+personaje["Maná Regen"])>personaje["Maná Máximo"]:
            calcMana= (personaje["Maná"]+personaje["Maná Regen"]) - personaje["Maná Máximo"] 
            personaje["Maná"] += personaje["Maná Regen"] - calcMana
        else:
            personaje["Maná"] += personaje["Maná Regen"]

    return personaje, mounstruo