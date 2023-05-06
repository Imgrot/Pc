import pymysql

class Items:
    def __init__(self):
        self.connection = pymysql.connect(
			host='localhost',
			user='root',
			password='',
			db='juego'
        )
        self.cursor = self.connection.cursor()

    def insertWeapon(self, nombre, ataque, defensa, critico, mh, oh):
        sql = "INSERT INTO armas (nombre, ataque, defensa, critico, mh, oh) VALUES ('{}', {}, {}, {}, {}, {})".format(nombre, ataque, defensa, critico, mh, oh)
        try:
            self.cursor.execute(sql)
            self.connection.commit()
            return
        except Exception as e:
            raise

    def insertArmor(self, name, defense, espacio):
        sql = "INSERT INTO armaduras (nombre, defensa, slot) VALUES ('{}', {}, '{}')".format(name, defense, espacio)
        try:
            self.cursor.execute(sql)
            self.connection.commit()
            return 
        except Exception as e:
            raise
    
    def selectWeapon(self, nombre):
        sql = 'SELECT * FROM armas where nombre = "{}"'.format(nombre)
        try:
            self.cursor.execute(sql)
            resultado = self.cursor.fetchone()
            return resultado
        except Exception as e:
            raise
    
    def selectArmor(self, nombre):
        sql = 'SELECT * FROM armaduras where nombre = "{}"'.format(nombre)
        try:
            self.cursor.execute(sql)
            resultado = self.cursor.fetchone()
            return resultado
        except Exception as e:
            raise

    def selectWeapons(self):
        sql = 'SELECT * FROM armas'
        try:
            self.cursor.execute(sql)
            resultado = self.cursor.fetchall()
            for y in resultado:
                print("Nombre del Objeto: {}".format(y[1]))
                print("Ataque: {}".format(y[2]))
                print("Defensa: {}".format(y[3]))
                print("Crítico: {}".format(y[4]))
                print("Espacio en MH: {}".format(y[5]))
                print("Espacio en OH: {}".format(y[6]))
                print("<-------------------------------->")
            return resultado
        except Exception as e:
            raise
    
    def selectArmors(self):
        sql = 'SELECT * FROM armaduras'
        try:
            self.cursor.execute(sql)
            resultado = self.cursor.fetchall()
            for y in resultado:
                print("Nombre del Objeto: {}".format(y[1]))
                print("Defensa: {}".format(y[2]))
                print("Slot: {}".format(y[3]))
                print("<-------------------------------->")
            return resultado
        except Exception as e:
            raise