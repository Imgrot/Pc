import os
import random

def Atacar(mounstruo, personaje ):
    os.system("cls")
    if personaje["Estado"] == "Vivo":
        #turno heroe
        print("_____Tu turno_____")
        hit=random.randint(1,100)
        hit -= mounstruo["Evasión"]

        if hit < 20:
            input("Has fallado el golpe...")

        else:
            crit = random.randint(1,100)

            if crit <= personaje["Critico"]:
                daño = 2*(personaje["Ataque"]) - mounstruo["Defensa"]
                mounstruo["Vida"] -= daño
                print("Golpe Crítico!")
                input("Has hecho {} puntos de daño!".format(daño))

                if mounstruo["Vida"] <= 0:
                    input("Has ganado el combate!")
                    return "Vivo"

            else:
                daño = personaje["Ataque"] - mounstruo["Defensa"]
                mounstruo["Vida"] -= daño
                input("Has hecho {} puntos de daño!".format(daño))
                if mounstruo["Vida"] <= 0:
                    input("Has ganado el combate!")
                    return "Vivo"
        
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

    return mounstruo, personaje