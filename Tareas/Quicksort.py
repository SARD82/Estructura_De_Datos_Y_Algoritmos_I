import random
import time

def quicksort(arr):
    if len(arr) <= 1:
        return arr
    else:
        pivote = arr[0]
        menores = [x for x in arr[1:] if x <= pivote]
        mayores = [x for x in arr[1:] if x > pivote]
        return quicksort(menores) + [pivote] + quicksort(mayores)

def ordenar_quicksort():
    tamaño = 100_000
    arreglo = [random.randint(0, 1_000_000) for _ in range(tamaño)]

    inicio = time.time()
    arreglo_ordenado = quicksort(arreglo)
    fin = time.time()

    print(f"Tiempo de ejecución (Quicksort) para {tamaño} elementos: {fin - inicio:.2f} segundos")

    return arreglo_ordenado

if __name__ == "__main__":
    ordenar_quicksort()
