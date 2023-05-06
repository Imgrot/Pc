import pymysql

class Link:
    def __init__(self):
        self.connection = pymysql.connect(
			host='localhost',
			user='root',
			password='',
			db='cuentavista'
        )
        self.cursor = self.connection.cursor()

    def showAll(self):
        sql = 'SELECT * FROM clientes'
        try:
            self.cursor.execute(sql)
            resultado = self.cursor.fetchall()
            #for elemento in resultado:
                #print(elemento)
            return resultado
        except Exception as e:
            raise
    
    def showOne(self, rut):
        sql = 'SELECT * FROM clientes where rutCliente = "{}"'.format(rut)
        try:
            self.cursor.execute(sql)
            resultado = self.cursor.fetchone()
            return resultado
        except Exception as e:
            raise


    def update(self,rut, monto):
        sql = "UPDATE clientes SET saldo = {} WHERE rutCliente = '{}'".format(monto, rut)
        try:
            self.cursor.execute(sql)
            self.connection.commit()
        except Exception as e:
            raise

    def alter_direccion(self, direccion, rut):
        sql = "UPDATE clientes SET direccion = '{}' WHERE rutCliente = '{}'".format(direccion, rut)
        try:
            self.cursor.execute(sql)
            self.connection.commit()
        except Exception as e:
            raise
    def alter_clave(self, clave, rut):
        sql = "UPDATE clientes SET clave = '{}' WHERE rutCliente = '{}'".format(clave, rut)
        try:
            self.cursor.execute(sql)
            self.connection.commit()
        except Exception as e:
            raise
    def alter_estado_I(self, rut):
        sql = "UPDATE clientes SET estadoCuenta = 'Inactiva' WHERE rutCliente = '{}'".format(rut)
        try:
            self.cursor.execute(sql)
            self.connection.commit()
        except Exception as e:
            raise
    def alter_estado_A(self, rut):
        sql = "UPDATE clientes SET estadoCuenta = 'Activa' WHERE rutCliente = '{}'".format(rut)
        try:
            self.cursor.execute(sql)
            self.connection.commit()
        except Exception as e:
            raise


    def consulta_saldo(self,rut):
        sql = "SELECT saldo from clientes WHERE rutCliente = '{}'".format(rut)
        try:
            self.cursor.execute(sql)
            saldo = self.cursor.fetchone()
            return saldo
        except Exception as e:
            raise


    def delete(self, id):
        sql = "DELETE FROM clientes WHERE idcuenta = '{}'".format(id)
        try:
            self.cursor.execute(sql)
            self.connection.commit()
            print('cuenta borrada')
        except Exception as e:
            raise


    def registro_clientes(self, nomCliente, rutCliente, direccion, clave):
        sql = "INSERT INTO clientes(nombreCliente, rutCliente, direccion, clave, estadoCuenta, saldo) VALUES ('{}', '{}', '{}', '{}', 'Activa', 0)".format(nomCliente,rutCliente,direccion,clave)
        try:
            self.cursor.execute(sql)
            self.connection.commit()
        except Exception as e:
            raise

    def cerrar_conexion(self):
        self.connection.close()
        print("Se ha cerrado la conexión")


    ## TABLA TRANSACCIONES ##

    def ingresar_transaciones(self, rutCliente, rutDestino, transaccion, monto):
        sql = "Insert into transacciones(rutCliente, rutDestino, transaccion, monto) VALUES ('{}', '{}', '{}', {})".format(rutCliente, rutDestino, transaccion, monto)
        try:
            self.cursor.execute(sql)
            self.connection.commit()
        except Exception as e:
            raise

    def mostrar_transacciones(self, rutCliente):
        sql = "SELECT * from transacciones WHERE rutCliente = '{}'".format(rutCliente)        
        try:
            self.cursor.execute(sql)
            tablas = self.cursor.fetchall()
            for y in tablas:
                print("N° de transacción: {}".format(y[0]))
                print("Cuenta de origen: {}".format(y[1]))
                print("El tipo de transacción fue: {}".format(y[2]))
                if y[2] == 'deposito':
                    print("El rut de destino fue:  {}".format(y[3]))
                print("La fecha y hora del proceso fueron: {}".format(y[4]))
                print("El monto de la transaccion fue de:  {}".format(y[5]))
                print("<-------------------------------->")
            return tablas
        except Exception as e:
            raise


#x = Link()
#x.registro_clientes('Aukan', '2003u4iy34', 'vgfshdbf', '4567')

#x = Link()
#x.ingresar_transaciones('20079933-k', '34235546-8', 'deposito')
#x.mostrar_transacciones('20079933-k')
