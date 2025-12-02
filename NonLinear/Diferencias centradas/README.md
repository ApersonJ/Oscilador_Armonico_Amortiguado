# Tratamiento de Datos: Montaje experimental de movimiento armónico amortiguado

## Descripción
Realiza derivación numérica de datos de posición y tiempo obtenidos de un laboratorio de movimiento armónico amortiguado, obteniendo la velocidad y con ella el momentum punto a punto. Posteriormente grafica posición y velocidad contra tiempo y momentum contra posición.

## Estructura
- `main.cpp`: flujo principal del programa (define el archivo de entrada y llama las funciones).
- `simular.cpp`: lee el archivo, deriva las posiciones y genera un archivo (`.dat`) con los nuevos datos.
- `graficar.cpp`: genera una imagen estática (`.png`) de las posiciones y velocidades en función del tiempo y otra del momentum en función de la posición.
- `include/funciones.h`: contiene los prototipos de las funciones.
- `scripts/`: carpeta donde se guardan los scripts `.gp` de Gnuplot.

## Uso
Compila y ejecuta el proyecto con:
```bash
make
```

El programa lee directamente los datos de un archivo `.dat` ubicado en results\listas, luego generará los siguientes archivos:
- `velocidad_posicion_grafica.png`: gráfica estática 2D.
- `momentum_grafica.png`: gráfica estática 2D.

## Requisitos
- **Compilador:** G++  
- **Gráficas:** Gnuplot  
- **LaTex:** pdfLaTex
