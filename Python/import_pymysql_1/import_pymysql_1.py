import pymysql

class DataBase:
	def __init__(self):
		self.connection = pymysql.connect(
			host='localhost',
			user='root',
			password='',
			db='articulo'
		)

		self.cursor = self.connection.cursor() #prueba coneccion

		print("Conexión exitosa")

	def select_all_articulos(self):
		sql = 'SELECT * FROM articulos'

		try:
			self.cursor.execute(sql)
			articulo = self.cursor.fetchall()

			for articulos in articulo:
				print("Codigo: ", articulos[0])
				print("Detalle: ", articulos[1])
				print("Precio: ", articulos[2])
				print("___________\n")
		except Exception as e:
			raise

database = DataBase()
database.select_all_articulos()