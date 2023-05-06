import os
from CRUD.Items import Items
from CRUD.Skills import Skills
from CRUD.Chars import Chars

def menuGM():
    loop = True
    while loop:
        os.system("cls")
        item = Items()
        skill = Skills()
        chars = Chars()

        print("Bienvenido al menú de Maestro del Juego!     ")
        print("Qué desea hacer?")
        print("1.- Revisar acceso a Habilidades")
        print("2.- Revisar acceso a Poderes")
        print("3.- Revisar Equipamentos")
        print("4.- Ingresar un Arma")
        print("5.- Ingresar una Armadura")
        print("6.- Agregar una habilidad")
        print("7.- Listar Jugadores")
        print("8.- Salir")
        choice = input("   --------->     ")
        os.system("cls")

        if choice == "1":
            input(skill.selectSkills())
        elif choice == "2":
            input(skill.selectPowers())
        elif choice == "3":
            item.selectWeapons()
            item.selectArmors()
            print("Operación exitosa!")
            input("Presione Enter para continuar...")
        elif choice == "4":
            nombre = input("Ingrese el nombre del equipo:    ")
            ataque = int(input("Cuánto ataque provee?:    "))
            defensa = int(input("Cuánta defensa provee?:    "))
            critico = int(input("Cuánto crítico provee?:    "))
            mh = int(input("Cuánto espacio en la mano principal usa?:    "))
            oh = int(input("Cuánto espacio en la mano secundaria usa?:    "))
            item.insertWeapon(nombre, ataque, defensa, critico, mh, oh)
            input("Operación exitosa!")

        elif choice == "5":
            nombre=input("Ingrese el nombre del equipo:   ")
            defensa=int(input("Ingrese la defensa que provee:   "))
            slot=input("Ingrese el Slot al que pertenece:   ")
            item.insertArmor(nombre, defensa, slot)
            input("Operación exitosa!")
        
        elif choice == "6":
            name=input("Ingrese un nombre para su habilidad:    ")
            skill.addSkill(name)
            input("Operación exitosa!")

        elif choice == "7":
            input(chars.selectChars())

        elif choice == "8":
            input("Presione Enter para salir      ")
            break

        else:
            input("Opción Inválida")