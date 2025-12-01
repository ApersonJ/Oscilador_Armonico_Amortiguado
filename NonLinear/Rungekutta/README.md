# Proyecto: Oscilador No Lineal Amortiguado

Este proyecto implementa la simulación numérica de un **oscilador no lineal amortiguado**, donde la fuerza disipativa es cuadrática y la dinámica resulta gobernada por una ecuación diferencial ordinaria no lineal. El sistema se resuelve mediante el método **Runge–Kutta de 4to orden (RK4)**, y los resultados se visualizan utilizando **Gnuplot**.

---

## 📌 **Contenido del Proyecto**

* `src/main.cpp`: Maneja la interacción con el usuario y flujo principal.
* `src/simular.cpp`: Implementación del método RK4 y escritura de datos.
* `include/funciones.h`: Prototipos de funciones.
* `scripts/graficar.gp`: Script de Gnuplot para generar gráficos.
* `results/`: Carpeta donde se guardan archivos `.dat` y las imágenes `.png`.
* `documents/teoria.tex`: Documento LaTeX con la teoría utilizada.
* `makefile`: Automatiza la compilación, ejecución y generación de gráficos.

---

## ⚙️ **Ecuación Diferencial del Sistema**

El modelo físico está dado por:

[
m \ddot{x} + \lambda , \dot{x} |\dot{x}| + kx = 0
]

Donde:

* **m**: masa del oscilador
* **k**: constante de resorte
* **λ**: coeficiente de amortiguamiento cuadrático

El sistema se convierte a ecuaciones de primer orden y se integra numéricamente.

---

## 🚀 **Cómo Compilar y Ejecutar**

El proyecto usa un `makefile` que automatiza todo.

### **Compilar y ejecutar simulación + gráficos:**

```
En la terminal de linex escribe "make".
```

---

## 📊 **Resultados Generados**

Después de ejecutar:

* `results/oscillator.dat` → Datos numéricos de la simulación.
* `VelvsTiempo.png` → Velocidad vs tiempo.
* `XvsTiempo.png` → Posición vs tiempo.
* `Fase.png` → Diagrama de fase (v vs x).

---

## 🛠️ **Dependencias**

Asegúrate de tener instalados:

* **g++** (compilador C++)
* **Gnuplot** (para los gráficos)
* **Make** (Para la automatización del programa)
* **LaTeX** (opcional)

---

