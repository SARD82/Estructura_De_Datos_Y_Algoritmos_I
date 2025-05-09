#Solo corre en colab
!pip install yfinance --upgrade --no-cache-dir

import yfinance as yf
import matplotlib.pyplot as plt
from datetime import datetime, timedelta

ticker = "TSLA"
periodo= '1y'
accion = yf.Ticker("TSLA")

datos = accion.history(period=periodo)

print(datos)

#Crear gráfico
plt.figure(figsize=(12, 6))
plt.plot(datos['Close'], label='Precio de cierre', color='blue')

#Configurar título y etiquetas
plt.title(f'Precio de {ticket} = ultimo {periodo}', fontsize=16)
plt.xlabel('fecha', fontsize=12)
plt.ylabel('precio (USD)', fontsize=12)
plt.grid(True, linestyle='--', alpha=0.7)

#Rotar fechas para mejor visualización
plt.xticks(rotation=45)

#Ajustar layout para que no se corten las etiquetas
plt.tight_layout()

#Mostar gráfico
plt.show()

#numpy numeros en python