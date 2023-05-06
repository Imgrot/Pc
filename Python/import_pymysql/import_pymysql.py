import pymysql

class DataBase:
    def __init__(self) -> None:
        self.connection=pymysql.connect(
            host='localhost', 
            user='root',
            password='' , #ojo, depende de la conf.
            db='articulo'
        )
        self.cursor=self.connection.cursor()
        print("conexión establecida")

    def select_all(self):
        sql = 'SELECT * from articulo'

        self.cursor.execute(sql)
        articulos=self.cursor.fetchall()

        for articulo in articulos:
            print("codigo: ",articulo[0])
            print("detalle: ",articulo[1])
            print("precio",articulo[2])
            print("________________")

database=DataBase()
database.select_all()