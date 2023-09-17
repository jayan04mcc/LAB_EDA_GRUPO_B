import matplotlib.pyplot as plt
import numpy as np

dimensiones = ['dim10', 'dim50', 'dim100', 'dim500', 'dim1000', 'dim2000', 'dim5000']

# Iterar a través de las dimensiones
for dim in dimensiones:
    # Crear una lista vacía para almacenar los datos de cada archivo
    datos = []

    # Abrir y leer el archivo correspondiente a la dimensión actual
    with open(f'{dim}', 'r') as archivo:
        # Lee las líneas del archivo y convierte cada línea en un número decimal
        datos = [float(linea.strip()) for linea in archivo]

    # Ahora, "datos" es una lista de números decimales

    # Crear un nuevo gráfico para cada dimensión
    plt.hist(datos, bins=20, edgecolor='black')  # Ajusta el número de barras (bins) según tus preferencias

    # Configurar etiquetas y título
    plt.xlabel('Valores')
    plt.ylabel('Frecuencia')
    plt.title(f'Histograma de {dim} Datos')

    # Guardar el histograma como un archivo PNG
    plt.savefig(f'{dim}_histogram.png')

    # Limpiar el gráfico actual para el próximo
    plt.clf()

# No es necesario llamar a plt.show() en este caso, ya que estamos guardando los gráficos como archivos PNG
