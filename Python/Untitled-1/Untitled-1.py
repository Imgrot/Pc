import pymysql

class DataBase:
	def __init__(self):
		self.connection = pymysql.connect(
			host='localhost',
			user='root',
			password='',
			db='cuentavista'
		)

		self.cursor = self.connection.cursor() #prueba coneccion

		print("Conexión exitosa")



	def select_all_clientes(self):
		sql = 'SELECT * FROM clientes'

		try:
			self.cursor.execute(sql)
			cuentavista = self.cursor.fetchall()

			for clientes in cuentavista:
				print("Nombre Cliente: ", clientes[0])
				print("Rut Cliente: ", clientes[1])
				print("Numero Cuenta: ", clientes[2])
				print("Clave: ", clientes[3])
				print("Estado Cuenta: ", clientes[4])
				print("Saldo: ", clientes[5])
				print("___________\n")

		except Exception as e:
			raise

database = DataBase()
database.select_all_clientes()