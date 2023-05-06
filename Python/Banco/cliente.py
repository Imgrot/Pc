class Cuenta:
    def __init__(self, nombreCliente, rutCliente, direccion, clave, estadoCuenta, saldo):
        self.__nombreCliente = nombreCliente
        self.__rutCliente = rutCliente
        self.__direccion = direccion
        self.__clave = clave
        self.__estadoCuenta = estadoCuenta
        self.__saldo = saldo
    
    def get_nombre(self):               ## Nombre
        return self.__nombreCliente

    def set_nombre(self, nombreCliente):
        self.__nombreCliente = nombreCliente

    def get_rut(self):                  ## Rut
        return self.__rutCliente

    def set_rut(self, rutCliente):
        self.__rutCliente = rutCliente

    def get_direccion(self):               ## Direccion
        return self.__direccion

    def set_direccion(self, direccion):
        self.__direccion = direccion

    def get_clave(self):               ## Clave
        return self.__clave

    def set_clave(self, clave):
        self.__clave = clave

    def get_estado_cuenta(self):               ## Estado Cuenta
        return self.__estadoCuenta

    def set_estado_cuenta(self, estadoCuenta):
        self.__estadoCuenta = estadoCuenta

    def get_saldo(self):               ## Saldo
        return self.__saldo

    def set_saldo(self, saldo):
        self.__saldo = saldo

    def girar_saldo(self, monto):             # Girar Saldo
        saldo_actual = self.get_saldo()
        cuenta = self.get_estado_cuenta()

        if cuenta == 'Activa':                  #Filtro de estado de cuenta
            if monto <= saldo_actual:           #Filtro de monto ingresado
                saldo_actual -= monto
                print("Usted ha girado: ' {} '".format(monto))
                print("Su saldo actual es: '{}'".format (saldo_actual))
                return True

            else:
                print("Monto inválido")
                return False
        elif cuenta == 'Inactiva':
            print("Cuenta inactiva, no es posible girar saldo.")
            return False

    def sacar_saldo(self, monto):             # Girar Saldo
        saldo = self.get_saldo()
        if monto > 0:
            if monto < saldo:
                saldo_actual = self.get_saldo()
                saldo_actual -= monto
                self.set_saldo(saldo_actual)
                return True
        else:
            return False
       
    def consulta_saldo (self):
        print("Su saldo actual es: '{}'".format(self.get_saldo()))

    def depositar_saldo (self, monto):
        estado = self.get_estado_cuenta()
        if estado == 'Activa':
            if monto > 0:
                nuevo_saldo = monto + self.get_saldo()
                self.set_saldo(nuevo_saldo)
                return True           
            else:
                print("Monto Inválido")
                return False
        elif estado == 'Inactiva':
            print("Cuenta Inactiva, no es posible Depositar")
            return False
        

    
#x = Cuenta('Aukan', '2003u4iy34', 'vgfshdbf', '4567', 'Activa', 5678)
#print(x.depositar_saldo(69))
#print(x.get_saldo())