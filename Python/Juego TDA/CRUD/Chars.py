import pymysql

class Chars:
    def __init__(self):                                 #Login de la DB
        self.connection = pymysql.connect(
			host='localhost',
			user='root',
			password='',
			db='juego'
        )
        self.cursor = self.connection.cursor()

    def createChar(self, playerName, charName, race):   #Creación de personaje
        status = 'Vivo'
        sql = "INSERT INTO personajes (playerName, charName, race, level, status) VALUES ('{}', '{}', '{}', 1, {}".format(playerName, charName, race, status)
        try:
            self.cursor.execute(sql)
            self.connection.commit()
        except Exception as e:
            raise

    def selectChar(self, name):                         #Seleccionar Personaje
        sql = "SELECT * FROM personajes WHERE charName = '{}'".format(name)
        try:
            self.cursor.execute(sql)
            resultado = self.cursor.fetchone()
            return resultado
        except Exception as e:
            raise
    
    def selectChars(self):                               #Seleccionar Personajes
        sql = "SELECT * FROM personajes"
        try:
            self.cursor.execute(sql)
            resultado = self.cursor.fetchall()
            return resultado
        except Exception as e:
            raise