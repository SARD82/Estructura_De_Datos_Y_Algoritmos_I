#Santiago Durán Rendón

def crear_matriz(filas, columnas):

    matriz = []

    for x in range(filas):

        fila = []

        for y in range(columnas):

            valor = int(input(f"Ingrese el valor fila {x + 1}, columna {y + 1}: "))
            fila.append(valor)
        matriz.append(fila)

    return matriz

def imprimir_matriz(matriz):

    for f in matriz:

        for v in f:

            print(f"{v} ", end = "")
        print("")

    # No es necesario retornar nada ???

def sumar_matrices(m1, m2):

    matriz = []

    f1 = len(m1)
    c1 = len(m1[0])

    f2 = len(m2)
    c2 = len(m2[0])

    if(f1 == f2 and c1 == c2):

        print("")
        print("-------------------------------")
        print("sumando matrices")
        print(f"matriz resultante: {f1} x {c1}")
        print("--------------------------------")
        print("")

        for x in range(f1):

            fila = []

            for y in range(c1):
                suma = m1[x][y] + m2[x][y]
                fila.append(suma)
            matriz.append(fila)

    else:
        print("No se puede realizar la suma de matrices")
    
    return matriz

def multiplicar_matrices(m1, m2):

    matriz = []

    f1 = len(m1)
    c1 = len(m1[0])
    f2 = len(m2)
    c2 = len(m2[0])

    if(c1 == f2):

        print("")
        print("-------------------------------")
        print("Multiplicando matrices")
        print(f"matriz resultante: {f1} x {c2}")
        print("--------------------------------")
        print("")

        for x in range(f1):

            fila = []

            for y in range(c2):
                
                multiplicacion = 0

                for k in range(f2):

                    multiplicacion += m1[x][k] * m2[k][y]

                fila.append(multiplicacion)
            matriz.append(fila)
    else:
        print("No se puede realizar la multiplicación de matrices")
    
    return matriz

def determinante_matriz(matriz):

    n = len(matriz)
    
    if n != len(matriz[0]):
        print("La matriz debe ser cuadrada para calcular el determinante")
        return None
    
    if n == 1:
        return matriz[0][0]
    
    if n == 2:
        return matriz[0][0] * matriz[1][1] - matriz[0][1] * matriz[1][0]
    
    det = 0
    for j in range(n):
        det += matriz[0][j] * cofactor(matriz, 0, j)
    
    return det

def cofactor(matriz, fila, columna):

    submatriz = []
    n = len(matriz)
    
    for i in range(n):
        if i != fila:
            nueva_fila = []
            for j in range(n):
                if j != columna:
                    nueva_fila.append(matriz[i][j])
            submatriz.append(nueva_fila)
    
    # Calcular el cofactor: (-1)^(i+j) * determinante de la submatriz
    return ((-1) ** (fila + columna)) * determinante_matriz(submatriz)

def matriz_inversa(matriz):

    n = len(matriz)
    if n != len(matriz[0]):
        print("La matriz debe ser cuadrada para calcular la inversa")
        return None
    
    det = determinante_matriz(matriz)
    
    if det == 0:
        print("La matriz no tiene inversa porque su determinante es 0")
        return None
    
    cofactores = []
    for i in range(n):
        fila = []
        for j in range(n):
            fila.append(cofactor(matriz, i, j))
        cofactores.append(fila)
    
    transpuesta = []
    for i in range(n):
        fila = []
        for j in range(n):
            fila.append(cofactores[j][i])
        transpuesta.append(fila)
    
    inversa = []
    for i in range(n):
        fila = []
        for j in range(n):
            fila.append(transpuesta[i][j] / det)
        inversa.append(fila)
    
    return inversa

def main():

    print("Funciones")

    a = crear_matriz(2, 2)
    b = crear_matriz(2, 2)

    print("")
    imprimir_matriz(a)
    print("")
    imprimir_matriz(b)
    print("")

    c = sumar_matrices(a, b)
    imprimir_matriz(c)
    print("")

    d = multiplicar_matrices(a, b)
    print("")
    imprimir_matriz(d)
    print("")

    print("\n--------------------------------")
    print("Matriz para calcular determinante:")
    print("--------------------------------\n")
    matriz_det = crear_matriz(3,3)
    print("")
    imprimir_matriz(matriz_det)
    print("--------------------------------")
    det = determinante_matriz(matriz_det)
    print(f"\nEl determinante de la matriz es: {det}")

    print("\n==============================")
    print("\nMatriz para calcular inversa:")
    print("--------------------------------")
    matriz_inv = crear_matriz(3,3)
    print("\n--------------------------------")
    print("\nMatriz original:")
    print("")
    imprimir_matriz(matriz_inv)
    print("--------------------------------\n")
    inv = matriz_inversa(matriz_inv)
    if inv is not None:
        print("\nMatriz inversa:")
        imprimir_matriz(inv)
        print("--------------------------------")


main()