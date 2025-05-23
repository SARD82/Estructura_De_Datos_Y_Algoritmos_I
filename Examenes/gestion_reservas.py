#Durán Rendón Santiago SARD 
# Muy buena materia, dejo mi repositorio de github con todos mis trabajos durante este semestre https://github.com/SARD82/Estructura_De_Datos_Y_Algoritmos_I

reservas_activas = []
canceladas = []  # Pila

def es_hora_valida(hora):
    partes = hora.split(":") #split para dividir la cadena de texto y pasarlo a una lista directamente
    if len(partes) != 2:
        return False
    try:
        h, m = int(partes[0]), int(partes[1]) #Si no se ejecuta el if anterior pasa a este bloque de código que es el try(intenta jajaja)
        return 0 <= h <= 23 and 0 <= m <= 59 
    except:
        return False #Si hace el try y no funciona pasa a este bloque de código y retorna el falso para evitar que usuarios ingresen letras en lugar de números :)

def agregar_reserva():
    nombre = input("Ingrese el nombre del cliente: ")
    if any(r['nombre'] == nombre for r in reservas_activas):
        print("Error: Ya existe una reserva con ese nombre.")
        return

    hora = input("Ingrese la hora de la reserva (HH:MM): ")
    if not es_hora_valida(hora):
        print("Error: Formato de hora inválido.")
        return

    try:
        personas = int(input("Ingrese el número de personas: "))
    except ValueError:
        print("Error: Debe ingresar un número válido de personas.")
        return

    reservas_activas.append({'nombre': nombre, 'hora': hora, 'personas': personas})
    print("Reserva agregada con éxito.")

def cancelar_reserva():
    nombre = input("Ingrese el nombre del cliente: ")
    for r in reservas_activas:
        if r['nombre'] == nombre:
            reservas_activas.remove(r)
            canceladas.append(r)
            print(f"Reserva de '{nombre}' cancelada y almacenada en la pila de cancelaciones.")
            return
    print("Error: No se encontró ninguna reserva con ese nombre.")

def mostrar_reservas():
    if not reservas_activas:
        print("No hay reservas activas.")
        return
    print("Reservas Activas:")
    for i, r in enumerate(sorted(reservas_activas, key=lambda x: x['hora']), start=1):
        print(f"{i}. [Hora: {r['hora']}] {r['nombre']} – {r['personas']} personas")

def revertir_cancelacion():
    if not canceladas:
        print("Error: No hay cancelaciones para revertir.")
        return
    reserva = canceladas.pop()
    reservas_activas.append(reserva)
    print(f"Última reserva cancelada ('{reserva['nombre']}') revertida y añadida nuevamente a la lista.")

while True:
    print("\n1. Agregar una nueva reserva")
    print("2. Cancelar una reserva")
    print("3. Mostrar reservas activas")
    print("4. Revertir última cancelación")
    print("5. Salir")
    
    opcion = input("\nOpción: ")

    if opcion == '1':
        agregar_reserva()
    elif opcion == '2':
        cancelar_reserva()
    elif opcion == '3':
        mostrar_reservas()
    elif opcion == '4':
        revertir_cancelacion()
    elif opcion == '5':
        print("Saliendo del programa.")
        break   #Break para salir del programa y romper el while true
    else:
        print("Opción no válida. Intente de nuevo.")