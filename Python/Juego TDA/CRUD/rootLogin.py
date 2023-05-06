import pymysql

class Login:
    def __init__(self):                     #login DB
        self.connection = pymysql.connect(
			host='localhost',
			user='root',
			password='',
			db='juego'
        )
        self.cursor = self.connection.cursor()

    def login(self, user, clave):
        sql = 'SELECT * FROM root where User = "{}"'.format(user)
        try:
            self.cursor.execute(sql)
            resultado = self.cursor.fetchone()
            if resultado[0] == user and resultado[1] == clave:
                return True
            else:
                return False
        except Exception as e:
            raise
    