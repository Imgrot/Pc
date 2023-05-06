import pymysql

class Link:
    def __init__(self):
        self.connection = pymysql.connect(
			host='localhost',
			user='root',
			password='',
			db='CasosCovid'
        )
        self.cursor = self.connection.cursor()

    def insertar(self, id, idPais, paisMinus, nuevosConfirm, totalConfirm, nuevasMuertes, totalMuertes, nuevosRecup, totalRecup, fecha):
        sql = "INSERT INTO paises (id, idPais, paisMinus, nuevosConfirm, totalConfirm, nuevasMuertes, totalMuertes, nuevosRecup, totalRecup, fecha) VALUES ('{}','{}','{}',{},{},{},{},{},{},'{}')".format(id, idPais, paisMinus, nuevosConfirm, totalConfirm, nuevasMuertes, totalMuertes, nuevosRecup, totalRecup, fecha)
        try:
            self.cursor.execute(sql)
            self.connection.commit()
        except Exception as e:
            raise

    def showAll(self):
        sql = 'SELECT * FROM paises'
        try:
            self.cursor.execute(sql)
            resultado = self.cursor.fetchall()
            return resultado
        except Exception as e:
            raise

    def showOne(self, dato):
        sql = 'SELECT * FROM paises where paisMinus = "{}"'.format(dato)
        try:
            self.cursor.execute(sql)
            resultado = self.cursor.fetchone()
            return resultado
        except Exception as e:
            raise

    def showCasosTotnom(self, pais):
        sql = 'SELECT totalConfirm FROM paises where paisMinus = "{}"'.format(pais)                
        try:
            self.cursor.execute(sql)
            resultado = self.cursor.fetchone()
            return resultado
        except Exception as e:
            raise

    def showCasosTotcod(self, id):
        sql = 'SELECT totalConfirm FROM paises where idPais = "{}"'.format(id)          
        try:
            self.cursor.execute(sql)
            resultado = self.cursor.fetchone()
            return resultado
        except Exception as e:
            raise
    
    def showAllnom(self, pais):
        sql = 'SELECT * FROM paises where paisMinus = "{}"'.format(pais)                
        try:
            self.cursor.execute(sql)
            resultado = self.cursor.fetchone()
            return resultado
        except Exception as e:
            raise

    def showAllcod(self, id):
        sql = 'SELECT * FROM paises where idPais = "{}"'.format(id)          
        try:
            self.cursor.execute(sql)
            resultado = self.cursor.fetchone()
            return resultado
        except Exception as e:
            raise

#x=Link()
#prin = x.showOne("ukraine")
#print(prin)
#x.insertar("3e90baa0-57be-43b3-81b8-ae3bd1181b61", "Afghanistan", "AF", "afghanistan", 0, 183572, 0, 7731, 0, 0, "2022-07-18T18:58:00.69Z")
#print(chow)