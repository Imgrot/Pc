from CRUD.Chars import Chars
import os

def crearPersonaje():
    chars = Chars()

    print("Bienvenido a la pantalla de")
    input("creación de personajes!     ")
    os.system("cls")

    playerName = input ("Ingrese su nombre:    ")
    os.system("cls")

    charName = input("Ingrese el nombre de su personaje:   ")
    os.system("cls")

    print("Elija una raza:   ")
    print("1.- Humano")
    print("2.- Orco")
    print("3.- Elfo")
    print("4.- Enano")
    race = input("  ------>   ")
    
    while race != "1" and race != "2" and race != "3" and race != "4":
        os.system("cls")
        input ("Opción inválida!")
        os.system("cls")
        print("Elija una raza:   ")
        print("1.- Humano")
        print("2.- Orco")
        print("3.- Elfo")
        print("4.- Enano")
        race = input("  ------>   ")
    os.system("cls")

    chars.createChar(playerName, charName, race)
    input("Su personaje fue creado con éxito!")

    
