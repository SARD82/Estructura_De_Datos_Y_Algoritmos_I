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
        print(f"(self.marca), (self.modelo), (self.año)")

mi_coche = vehiculo("toyota", "Prius", 2023)
mi_coche.mostrar_info()
