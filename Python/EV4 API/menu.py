from conexion import Link
import os
import requests
import json

def menu():
    x=Link()
    entrega = requests.get("https://api.covid19api.com/summary").text

    lista_pais=[]    
    API = json.loads(entrega)
    dGlobal = API["Global"]

    for info_pais in API["Countries"]:
        lista_pais.append([info_pais["ID"],info_pais["CountryCode"],info_pais["Slug"],info_pais["NewConfirmed"],info_pais["TotalConfirmed"],info_pais["NewDeaths"],info_pais["TotalDeaths"],info_pais["NewRecovered"],info_pais["TotalRecovered"],info_pais["Date"]])
    #for y in lista_pais:
    #    x.insertar(y[0], y[1], y[2], y[3], y[4], y[5], y[6], y[7], y[8], y[9])
    
    contador = 0
    loop = True
    while loop:
        os.system("cls")
        if contador == 0:
            print("Bienvenido al sistema de consulta de casos actuales del Covid-19.")
            input("Presione Enter para continuar...")
            contador = 1
            os.system("cls")
        
        print("1.-Consultar el numero de casos reportados por país.")
        print("2.-Consultar las estadísticas por país.")
        print("3.-Consultar la suma de casos en los países.")
        print("4.-Salir.")
        choice = int(input("¿Qué operación desea realizar?:  "))
        os.system("cls")

        if choice == 1:               
            print("Usted eligió: Consultar el numero de casos reportados por país.")
            country = input("Inserte el Nombre o Código del país a buscar:    ")

            if len(country) > 2:
                for y in lista_pais:
                    if y[2] == country.lower():
                        pais = country.lower()
                        contagios = x.showCasosTotnom(pais)
                        print("Los casos totales en {} son : {}".format(country, contagios))
                        break                

            elif len(country) <= 2:
                for y in lista_pais:
                    if y[1] == country.upper():
                        pais = country.upper()
                        contagios = x.showCasosTotcod(pais)
                        print("Los casos totales en {} son : {}.".format(pais, contagios))
                        break               
            input("Presione Enter para continuar...")

        elif choice == 2:
            print("Usted eligió: Consultar las estadísticas por país.")
            country = input("Inserte el Nombre o Código del país a buscar:    ")
            os.system("cls")

            if len(country) > 2:
                for y in lista_pais:
                    if y[2] == country.lower():
                        pais = country.lower()
                        stats = x.showAllnom(pais)
                        print("El ID de su país es: {}".format(stats[0]))
                        print("El nombre de su país es: {}".format(stats[2]))
                        print("Su total de contagios es: {}".format(stats[4]))
                        print("Su total de muertes por contagio es: {}".format(stats[6]))
                        print("Info. actualizada a la fecha: {}".format(stats[9]))
                        break                

            elif len(country) <= 2:
                for y in lista_pais:
                    if y[1] == country.upper():
                        pais = country.upper()
                        stats = x.showAllcod(pais)
                        print("El ID de su país es: {}".format(stats[0]))
                        print("El nombre de su país es: {}".format(stats[2]))
                        print("Su total de contagios es: {}".format(stats[4]))
                        print("Su total de muertes por contagio es: {}".format(stats[6]))
                        print("Info. actualizada a la fecha: {}".format(stats[9]))
                        break               
            input("Presione Enter para continuar...")

        elif choice == 3:
            print("Usted eligió: Consultar la suma de casos en los países.")
            print("La cantidad de casos globales es de: {}.".format(dGlobal["TotalConfirmed"]))
            print("La cantidad de muertes totales es de: {}.".format(dGlobal["TotalDeaths"]))
            print("La cantidad de recuperados es de: {}.".format(dGlobal["TotalRecovered"]))
            print("Info. actualizada a la fecha:  {}".format(dGlobal["Date"]))
            input("Pulse Enter para continuar...")

        elif choice == 4:
            break
        else:
            print("Opción errónea, intente de nuevo...")
            input("Presione Enter para continuar...")
