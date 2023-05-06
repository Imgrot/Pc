import os
import random

def Defender(personaje, mounstruo):
    os.system("cls")
    print("_____Tu turno_____")
    print("Te has protegido, recibirás la mitad del daño del siguiente ataque!")
     
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
            daño /= 2
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
                        input("Al estar defendiendo, resististe el efecto del Congelamiento")

        else:
            daño = mounstruo["Ataque"] - personaje["Defensa"]
            daño /= 2
            if daño >=1:
                if random.randint(1,100)<80:
                    personaje["Vida"] -= daño
                    input("Te han inflingido {} puntos de daño!".format(daño))
                    
                    if personaje["Vida"] <=0:
                        input("Has muerto...")
                        personaje["Estado"] = "Muerto"
                        return personaje, mounstruo
                    if mounstruo["Nombre"] == "Slime de Hielo" or mounstruo["Nombre"] == "Lobo Congelante":
                        if personaje["Estado"] == "Vivo":
                            if random.randint(1,100) <=33:
                                input("Al estar defendiendo, resististe el efecto del Congelamiento")
                else:
                    input("Te defendiste de todo el daño recibido")
                    if mounstruo["Nombre"] == "Slime de Hielo" or mounstruo["Nombre"] == "Lobo Congelante":
                        if personaje["Estado"] == "Vivo":
                            if random.randint(1,100) <=33:
                                input("Al estar defendiendo, resististe el efecto del Congelamiento")
            else:
                input("Te defendiste de todo el daño recibido")
                if mounstruo["Nombre"] == "Slime de Hielo" or mounstruo["Nombre"] == "Lobo Congelante":
                    if personaje["Estado"] == "Vivo":
                        if random.randint(1,100) <=33:
                            input("Al estar defendiendo, resististe el efecto del Congelamiento")

    if personaje["Maná"]<personaje["Maná Máximo"]:          #Regeneración de Maná por turno
        if (personaje["Maná"]+personaje["Maná Regen"])>personaje["Maná Máximo"]:
            calcMana= (personaje["Maná"]+personaje["Maná Regen"]) - personaje["Maná Máximo"] 
            personaje["Maná"] += personaje["Maná Regen"] - calcMana
        else:
            personaje["Maná"] += personaje["Maná Regen"]

    return personaje, mounstruo