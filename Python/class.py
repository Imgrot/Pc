class Staff:

    def __init__ (self, name, adress, phone):
        self.name = name
        self.adress = adress
        self.phone = phone

class StaffAnidado(Staff):
    super().__init__(name, adress, phone, puesto, spec):
        self.puesto = puesto
        self.spec = spec
    

    # def cookingStaff(self, name, adress, phone):
    #     pass
    
    # def cleaningStaff(self, name, adress, phone):
    #     pass



telefono = 3
nombre = "wolo"
direccion = "evergreen st 374"
puesto = "cocinero"
spec = "sous-chef"
# x = Staff(nombre, direccion, telefono)
# print(x.uname)
y  = StaffAnidado(nombre, direccion, telefono)
print(y.name)