def select_all(self):
    sql='select * from articulo'
    self.cursor.execute(sql)
    articulos=self.cursor.fetchall()

    for articulo in articulos:
        print("codigo: ",articulo[0])
        print("detalle: ",articulo[1])
        print("precio",articulo[2])
       print("________________")

database=DataBase()
database.select_all()
