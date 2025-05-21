import itertools
import string
import time

def generar_placas():
    letras = string.ascii_uppercase  # 'A' a 'Z'
    numeros = [str(i) for i in range(10)]  # '0' a '9'

    placas = []

    inicio = time.time()

    for letras_comb in itertools.product(letras, repeat=3):
        for numeros_comb in itertools.product(numeros, repeat=3):
            placa = ''.join(letras_comb) + '-' + ''.join(numeros_comb)
            placas.append(placa)

    fin = time.time()
    tiempo_total = fin - inicio

    print(f"Total de placas generadas: {len(placas)}")
    print(f"Tiempo de ejecución: {tiempo_total:.2f} segundos")

    return placas

if __name__ == "__main__":
    placas_generadas = generar_placas()
