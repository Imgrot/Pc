from conexion import Link
from cliente import Cuenta
from login import comprobar_user, login, cifrar
import os
def menu():
    loop = True
    while loop:
        os.system("cls")
        print("Bienvenido a el Menú principal")
        print("Aqui podra revisar el estado de su cuenta Vista.")
        print("1.- Crear Cuentas.")
        print("2.- Consultar/Modificar el Cliente.")
        print("3.- Depositar en una cuenta.")
        print("4.- Realizar un giro.")
        print("5.- Consultar el saldo de una cuenta por cliente.")
        print("6.- Mostrar el estado de la cuenta.")
        print("7.- salir del menú.")
        opcion = int(input("Elija una Opción:"))
        
        if opcion == 1:         #Crear cuenta
            nomCli= input("Ingrese su nombre: ")
            os.system("cls")
            rutCli = input("Ingrese su rut (sin puntos, guión, ni dígito verificador): ")
            direccion = input("Ingrese su Dirección: ")
            clave = input("Ingrese una contraseña para utilizar (usar hasta 32 caracteres): ")
            claveCifrada = cifrar(clave, 'md5')
            crearCuenta = Link()
            crearCuenta.registro_clientes(nomCli, rutCli, direccion, claveCifrada)
            os.system("cls")
            print("Usted ha creado su cuenta con éxito!.")
            input("Presione la tecla Enter para continuar...")           
            os.system("cls")
            crearCuenta.cerrar_conexion()
        
        elif opcion == 2:       #Modificar user
            x = Link()
            os.system("cls")
            
            rutUsuario = input("Ingrese su RUT (sin puntos, guión, ni dígito verificador): ")
            claveUsuario = input("Ingrese su contraseña: ")
            claveCifrada = cifrar(claveUsuario , 'md5')
            usuario = login(rutUsuario, claveCifrada)
            while True:
                if usuario == False:
                    input("Usuario o clave incorrectos, intente de nuevo.")
                    os.system("cls")
                    rutUsuario = input("Ingrese su RUT (sin puntos, guión, ni dígito verificador): ")
                    claveUsuario = input("Ingrese su contraseña: ")
                    claveCifrada = cifrar(claveUsuario , 'md5')
                    usuario = login(rutUsuario, claveCifrada)
                else:
                    break

            os.system("cls")

            print("Que procedimiento desea llevar a cabo?")
            print("1.- Consultar acerca de su cuenta")
            print("2.- Modificar aspectos de su cuenta")
            eleccion = int(input("Elija una opción (Escriba 1 o 2):  "))

            while eleccion != 1 and eleccion != 2:
                input("Opción inválida, intente de nuevo.")
                os.system("cls")
                print("Que procedimiento desea llevar a cabo?")
                print("1.- Consultar acerca de su cuenta")
                print("2.- Modificar aspectos de su cuenta")
                eleccion = input("Elija una opción (Escriba 1 o 2):  ")

            if eleccion == 1:
                datos = x.showOne(rutUsuario)
                os.system("cls")
                print("Su nombre de registro es: '{}'".format(datos[0]))
                print("Su rut de registro es: '{}'".format(datos[1]))
                print("Su dirección de registro es: '{}'".format(datos[2]))
                print("El estado de su cuenta es: '{}'".format(datos[4]))
                print("Su saldo actualmente es de: '{}'".format(datos[5]))
                input("Presione Enter para continuar...")
                os.system("cls")

            
            elif eleccion == 2:
                os.system("cls")
                print("Que dato desea modificar?")
                print("1.- Dirección de estadía")
                print("2.- Contraseña actual")
                print("3.- El estado de su cuenta")
                choice = int(input("Escoja una opción (Escriba 1, 2, o 3):  "))
                while choice != 1 and choice != 2 and choice != 3:
                    print("La opción escogida no es válida...")
                    input("Presione Enter para continuar...")
                    os.system("cls")
                    print("Que dato desea modificar?")
                    print("1.- Dirección de estadía")
                    print("2.- Contraseña actual")
                    print("3.- El estado de su cuenta")
                    choice = input("Escoja una opción (Escriba 1, 2, o 3):  ")
                os.system("cls")

                if choice == 1:
                    nuevaDir = input("Escriba su nueva Dirección:  ")
                    x.alter_direccion(nuevaDir, rutUsuario)
                    print("La operación ha sido un éxito!.")
                    input("Presione Enter para continuar...")
                    os.system("cls")

                elif choice == 2:
                    nuevaClave = input("Escriba su nueva Contraseña (sin puntos, guión, ni dígito verificador):  ")
                    claveNueva = cifrar(nuevaClave, 'md5')
                    x.alter_clave(claveNueva, rutUsuario)
                    print("La operación ha sido un éxito!.")
                    input("Presione Enter para continuar...")
                    os.system("cls")

                elif choice == 3:
                    status = usuario[4]

                    if status == 'Inactiva':
                        print("El estado de su cuenta es 'Activa'")
                        print("Desea desactivarla?")
                        nuevo_status = input("Escribir si / no:  ")

                        while nuevo_status != 'si' and nuevo_status != 'no':
                            input("Opción inválida, intente de nuevo...")
                            os.system("cls")
                            print("El estado de su cuenta es 'Activa'")
                            print("Desea desactivarla?")
                            nuevo_status = input("Escribir si / no:  ")
                        if nuevo_status == 'si':
                            x.alter_estado_I(rutUsuario)
                    elif status == 'Activa':
                        print("El estado de su cuenta es 'Inactiva'")
                        print("Desea activarla?")
                        nuevo_status = input("Escribir si / no:  ")

                        while nuevo_status != 'si' and nuevo_status != 'no':
                            input("Opción inválida, intente de nuevo...")
                            os.system("cls")
                            print("El estado de su cuenta es 'Inactiva'")
                            print("Desea activarla?")
                            nuevo_status = input ("Escribir si / no:  ")
                        if nuevo_status == 'si':
                            x.alter_estado_A(rutUsuario)     
            os.system("cls")
            x.cerrar_conexion()

        elif opcion == 3:                           #Depositar
            x = Link()
            os.system("cls")
            rutUsuario = input("Ingrese su RUT (sin puntos, guión, ni dígito verificador): ")
            claveUsuario = input("Ingrese su contraseña: ")
            claveCifrada = cifrar(claveUsuario , 'md5')
            usuario = login(rutUsuario, claveCifrada)
            while True:
                if usuario == False:
                    input("Usuario o clave incorrectos, intente de nuevo.")
                    os.system("cls")
                    rutUsuario = input("Ingrese su RUT (sin puntos, guión, ni dígito verificador): ")
                    claveUsuario = input("Ingrese su contraseña: ")
                    claveCifrada = cifrar(claveUsuario , 'md5')
                    usuario = login(rutUsuario, claveCifrada)
                else:
                    break
              
            print("Desea depositar a terceros o a si mismo?.")
            print("1.- A terceros.")
            print("2.- A usted.")
            while True:
                eleccion = int(input("Elija su opción (1 o 2):  "))
                if eleccion == 1 or eleccion == 2:
                    break
                else:
                    input("Opción inválida, intente de nuevo.")
                    os.system("cls")
                print("Desea depositar a terceros o a si mismo?.")
                print("1.- A terceros.")
                print("2.- A usted.")
            os.system("cls")

            mis_datos = Cuenta(usuario[0], usuario[1], usuario[2], usuario[3], usuario[4], usuario[5])

            if eleccion == 1:
                while True:
                    global rutDestino
                    rutDestino = input("Ingrese el RUT del destinatario (sin puntos, guión, ni dígito verificador): ")
                    confirmar_usuario = comprobar_user(rutDestino)
                    if confirmar_usuario == 1:
                        os.system("cls")
                        break
                    else:
                        input("El RUT ingresado no existe, intente de nuevo.")
                        os.system("cls")

                datos_destinatario = x.showOne(rutDestino)
                destinatario = Cuenta(datos_destinatario[0],datos_destinatario[1],datos_destinatario[2],datos_destinatario[3],datos_destinatario[4],datos_destinatario[5])

                monto_a_depositar = int(input("Cuanto desea transferir?: "))
                if mis_datos.sacar_saldo(monto_a_depositar) == True and destinatario.depositar_saldo(monto_a_depositar) == True:          
                    x.update(mis_datos.get_rut(), mis_datos.get_saldo())
                    x.update(destinatario.get_rut(), destinatario.get_saldo())
                    print('Usted ha realizado con éxito su transferncia de "{}" a la cuenta "{}"'.format(monto_a_depositar, rutDestino))
                else:
                    print("No fue posible transferir esta cantidad")
                
                input("Presione Enter para continuar...")
                x.ingresar_transaciones(mis_datos.get_rut(),rutDestino,'transferencia', monto_a_depositar)
                os.system("cls")

            if eleccion == 2:
                monto_a_depositar = int(input("Cuanto desea depositar?:  "))
                mis_datos.depositar_saldo(monto_a_depositar)
                x.update(mis_datos.get_rut(), mis_datos.get_saldo())
                print("Usted se ha depositado '{}' a su cuenta con éxito!.".format(monto_a_depositar))
                input("Presione Enter para continuar...")
                x.ingresar_transaciones(mis_datos.get_rut(),'','deposito', monto_a_depositar)
                os.system("cls")

            
            x.cerrar_conexion()


        elif opcion == 4:                           #Girar
            x = Link()
            os.system("cls")
            rutUsuario = input("Ingrese su RUT (sin puntos, guión, ni dígito verificador): ")
            claveUsuario = input("Ingrese su contraseña: ")
            claveCifrada = cifrar(claveUsuario , 'md5')
            usuario = login(rutUsuario, claveCifrada)
            while True:
                if usuario == False:
                    input("Usuario o clave incorrectos, intente de nuevo.")
                    os.system("cls")
                    rutUsuario = input("Ingrese su RUT (sin puntos, guión, ni dígito verificador): ")
                    claveUsuario = input("Ingrese su contraseña: ")
                    claveCifrada = cifrar(claveUsuario , 'md5')
                    usuario = login(rutUsuario, claveCifrada)
                else:
                    break
            os.system("cls")
            monto = int(input("¿Que monto desea girar?:  "))
            mis_datos = Cuenta(usuario[0], usuario[1], usuario[2], usuario[3], usuario[4], usuario[5])
            if mis_datos.girar_saldo(monto) == True:
                x.update(mis_datos.get_rut(), mis_datos.get_saldo())
            else:
                print("No se ha podido girar esa cantidad...")
            input("Presione Enter para continuar...")
            x.ingresar_transaciones(mis_datos.get_rut(),'','giro', monto)
            os.system("cls")
            x.cerrar_conexion()
            

        elif opcion == 5:       #Consultar saldo
            x = Link()
            os.system("cls")
            rutUsuario = input("Ingrese su RUT (sin puntos, guión, ni dígito verificador): ")
            claveUsuario = input("Ingrese su contraseña: ")
            claveCifrada = cifrar(claveUsuario , 'md5')
            usuario = login(rutUsuario, claveCifrada)
            while True:
                if usuario == False:
                    input("Usuario o clave incorrectos, intente de nuevo.")
                    os.system("cls")
                    rutUsuario = input("Ingrese su RUT (sin puntos, guión, ni dígito verificador): ")
                    claveUsuario = input("Ingrese su contraseña: ")
                    claveCifrada = cifrar(claveUsuario , 'md5')
                    usuario = login(rutUsuario, claveCifrada)
                else:
                    break
            os.system("cls")

            mis_datos = Cuenta(usuario[0], usuario[1], usuario[2], usuario[3], usuario[4], usuario[5])

            mis_datos.consulta_saldo()
            input("Presione Enter para continuar...")
            os.system("cls")
            x.cerrar_conexion()

        elif opcion == 6:       #Mostrar estado de cuenta + transacciones
            x = Link()
            os.system("cls")
            rutUsuario = input("Ingrese su RUT (sin puntos, guión, ni dígito verificador): ")
            claveUsuario = input("Ingrese su contraseña: ")
            claveCifrada = cifrar(claveUsuario , 'md5')
            usuario = login(rutUsuario, claveCifrada)
            while True:
                if usuario == False:
                    input("Usuario o clave incorrectos, intente de nuevo.")
                    os.system("cls")
                    rutUsuario = input("Ingrese su RUT (sin puntos, guión, ni dígito verificador): ")
                    claveUsuario = input("Ingrese su contraseña: ")
                    claveCifrada = cifrar(claveUsuario , 'md5')
                    usuario = login(rutUsuario, claveCifrada)
                else:
                    break
            os.system("cls")
            x.mostrar_transacciones(rutUsuario)
            input("Presione Enter para continuar...")
            os.system("cls")


        elif opcion == 7:       #Salir del menú
            loop = False
        else:
            input("Opcion incorrecta, intente de nuevo")
            os.system("cls")