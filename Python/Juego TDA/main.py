from CRUD.rootLogin import Login
from mainMenu import mainMenu

x = Login()

print("Bienvenido")
usuario = input("Ingrese su nombre de usuario:     ")
contraseña = input("Ingrese su contraseña:     ")

if x.login(usuario, contraseña) == True:
    mainMenu()