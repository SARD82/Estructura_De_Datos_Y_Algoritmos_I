class vehiculo:
    def __init__(self, marca, modelo, año):
        self.marca = marca
        self.modelo = modelo
        self.año = año
        self.velocida = 0

    def acelerar(self, km_h):
        self.velocidad += km_h

    def frenar(self, km_h):
        self.velocidad -= km_h
    
    def mostrar_info(self):
        print(f"{self.marca}, {self.modelo}, {self.año}")

mi_coche = vehiculo("Toyota", "Prius", 2023)
mi_coche.mostrar_info()

class CocheElectrico(vehiculo):
    def __init__(self, marca, modelo, año, capacidad_bateria):
        super().__init__(marca, modelo, año)
        self.capacidad_bateria = capacidad_bateria
        self.cargar = 100

    def info(self):
      return f"{super().mostrar_info()} Bateria: {self.capacidad_bateria} km"

mi_coche2 = CocheElectrico("Toyota", "Prius", "2020", 430)
print(mi_coche2.info())