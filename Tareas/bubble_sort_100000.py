import random
import time

def bubble_sort(arr):
    n = len(arr)
    for i in range(n):
        # Optimización: no revisar lo ya ordenado
        for j in range(0, n - i - 1):
            if arr[j] > arr[j + 1]:
                # Intercambio
                arr[j], arr[j + 1] = arr[j + 1], arr[j]

def ordenar_burbuja():
    # Puedes cambiar 100_000 por 1_000 si deseas probar más rápido
    tamaño = 100_000  
    arreglo = [random.randint(0, 1_000_000) for _ in range(tamaño)]

    inicio = time.time()
    bubble_sort(arreglo)
    fin = time.time()

    print(f"Tiempo de ejecución (Bubble Sort) para {tamaño} elementos: {fin - inicio:.2f} segundos")

    return arreglo

if __name__ == "__main__":
    ordenar_burbuja()
