print("Ejercicios y apunte de la clase del día 05_05_2025")

l = ('a', "Hola", 8.79) #tuple
print(l[1])

[15, 'a', "Hola",8.70] #lista

x = 29
print(f"x = {x + 10}")

nombre = input("Cual es tu nombre? ")
print(f"hola {nombre}")
edad = int(input("Cual es tu edad? "))
print(f"tu edad es {edad}")

lista = []
for i in range(5):
    valor = input("dame un valor ")
    lista.append(valor)

print(lista)

lista1 = ['p', "paraguas", 69, 3]
print(lista1)
lista1.remove('p')
print(lista1)
lista1.pop()
print(lista1)

lista2 = ['a', 'b', 'c']
lista3 = ['e', 'f', 'g']
print(lista2 + lista3)

import matplotlib.pyplot as plt #as es para el alias
x = [1,2,3,4,5]
y = [2,4,1,3,5]

plt.plot(x, y)
plt.title("Gráfica")
