# Tratamiento de Datos: Montaje experimental de movimiento armónico amortiguado

## Descripción
Realiza derivación numérica de datos de posición y tiempo obtenidos de un laboratorio de movimiento armónico amortiguado, obteniendo la velocidad y con ella el momentum punto a punto. Posteriormente grafica posición, velocidad y momentum contra tiempo.

## Estructura
- `main.cpp`: flujo principal del programa (define el archivo de entrada y llama las funciones).
- `simular.cpp`: lee el archivo, deriva las posiciones y genera un archivo (`.dat`) con los nuevos datos.
- `graficar.cpp`: genera una imagen estática (`.png`) de las posiciones, velocidades y momentums en función del tiempo.
- `include/funciones.h`: contiene los prototipos de las funciones.
- `scripts/`: carpeta donde se guardan los scripts `.gp` de Gnuplot.

## Uso
Compila y ejecuta el proyecto con:
```bash
make
```

El programa lee directamente los datos de un archivo `.dat` ubicado en results\listas, luego generará los siguientes archivos:
- `derivadas_grafico.png`: gráfica estática 2D.
- Grafica de x, v y momentum.

## Requisitos
- **Compilador:** G++  
- **Gráficas:** Gnuplot  
- **LaTex:** pdfLaTex
