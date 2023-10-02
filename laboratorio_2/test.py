import matplotlib.pyplot as plt

# Leer el archivo de texto
with open('shell_resul.txt', 'r') as file:
    # Leer todas las líneas del archivo
    lines = file.readlines()

    # Convertir cada línea a float y guardarla en una lista
    tiempos = [float(line.strip()) for line in lines]

# Crear un gráfico lineal con los tiempos de ejecución

size=['10','100','500','1000','5000','10000','50000','100000']
plt.plot(size, tiempos, marker='o')

# Añadir títulos y etiquetas
plt.title('Tiempos de Ejecución')
plt.xlabel('Tamanio de entrada')
plt.ylabel('Tiempo (s)')

# Mostrar el gráfico
plt.show()





