from CRUD.rootLogin import Login
import os
from menuGM import menuGM

def logGM ():
    log = Login()
    os.system("cls")
    print("Bienvenido al inicio de sesión")
    input("de Game Master!    ")
    os.system("cls")
    user = input("Ingrese su clave de Game Master:    ")
    os.system("cls")
    clave =  input ("Ahora ingrese su clave:    ")
    os.system("cls")
    inicio = log.login(user, clave)

    while inicio == False:
        input("Clave o Usuario Incorrecto(s)...")
        exit = input("Desea salir?:    ")
        if exit == "si":
            return
        os.system("cls")
        user = input("Ingrese su clave de Game Master:    ")
        os.system("cls")
        clave =  input ("Ahora ingrese su clave:    ")
        os.system("cls")
        inicio = log.login(user, clave)
    
    menuGM()
    
