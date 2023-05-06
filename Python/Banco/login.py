from conexion import Link
import os
import hashlib

os.system("cls")

def login(rut, clave):
    x = Link()
    usuarios = x.showAll()
    loop = True
    while loop:
        for y in usuarios:
            print(usuarios, clave)
            if rut == y[1] and clave == y[3]:
                loop = False
                tabla = y        

        if loop == False:
            return tabla
        elif loop == True:
            return False

def comprobar_user(rut):
    x = Link()
    usuarios = x.showAll()
    loop = True
    while loop:
        for y in usuarios:
            if rut == y[1]:
                loop = False
        if loop == False:
            return 1
        else:
            return 0

def cifrar(valor, tipo):

    if tipo == 'sha1':

        sha1= hashlib.sha1()
        sha1.update(valor.encode('utf-8'))
        resultadoCifrado = sha1.hexdigest()
        print ("resultado de cifrado sha1:", resultadoCifrado)
        return resultadoCifrado

    elif tipo == 'md5':

        md5 = hashlib.md5(b'sinclave')
        md5.update (valor.encode ('utf-8'))
        resultadoCifrado = md5.hexdigest()
        #print("resultado de cifrado md5:", resultadoCifrado)
        return resultadoCifrado

#cifrado = cifrar('345', 'md5')
#print(cifrado)

#login()