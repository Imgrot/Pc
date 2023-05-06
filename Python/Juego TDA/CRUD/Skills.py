import pymysql

class Skills:
    def __init__(self):
        self.connection = pymysql.connect(
			host='localhost',
			user='root',
			password='',
			db='juego'
        )
        self.cursor = self.connection.cursor()

    def selectSkills(self):
        sql = 'SELECT * FROM habilidades'
        try:
            self.cursor.execute(sql)
            resultado = self.cursor.fetchall()
            return resultado
        except Exception as e:
            raise    
    
    def addSkill(self, name):
        sql = "alter table habilidades add column {} tinyint(1)".format(name)
        try:
            self.cursor.execute(sql)
            self.connection.commit()
        except Exception as e:
            raise
        
    def selectPowers(self):
        sql = 'SELECT * FROM poderesEnanos'
        try:
            self.cursor.execute(sql)
            resultado = self.cursor.fetchall()
            return resultado
        except Exception as e:
            raise    