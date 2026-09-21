# Sweet Crush

Proyecto desarrollado en C++ como parte del curso de programación.

Sweet Crush es un juego basado en la eliminación de fichas, la detección de combinaciones y la modificación de las dimensiones del tablero durante la ejecución.

El tablero se almacena usando memoria dinámica y una representación concatenada de **3 bits por ficha**. Esto permite guardar varias fichas dentro de una misma secuencia de bytes, aprovechando mejor el espacio disponible en memoria.

## Características

* Almacenamiento dinámico del tablero.
* Las fichas ocupan 3 bits.
* Almacenamiento de fichas dentro de una secuencia de bytes.
* Manipulación de bits cuando una ficha se encuentra entre dos bytes.
* Conversión entre posiciones de fila/columna y posiciones lineales.
* Lectura y escritura de fichas directamente sobre la memoria.
* Detección de combinaciones horizontales y verticales.
* Eliminación de fichas y caída de las fichas superiores.
* Generación de nuevas fichas.
* Procesamiento de cascadas.
* Sistema básico de puntuación.
* Agregar y eliminar filas durante la ejecución.
* Agregar y eliminar columnas durante la ejecución.
* Redimensión dinámica de la memoria del tablero.

## Representación del tablero

Cada ficha utiliza 3 bits para ser almacenada.

Se utilizan los valores del `0` al `5` para representar los diferentes tipos de fichas. El valor `6` se utiliza para representar una posición vacía.

Como cada ficha ocupa solamente 3 bits, una ficha puede comenzar en un byte y terminar en el siguiente. Por esto, el proyecto incluye funciones encargadas de leer y escribir los bits directamente sobre la memoria.

La posición de cada ficha dentro del tablero se obtiene convirtiendo primero su fila y columna a una posición lineal:

```text
posición = fila * columnas + columna
```

A partir de esta posición se calcula dónde comienzan sus 3 bits dentro de la secuencia de bytes.

## Funcionamiento

Al iniciar el programa, se solicitan las dimensiones del tablero y se reserva dinámicamente la cantidad de memoria necesaria.

Después se generan las fichas y se almacenan directamente en el tablero.

Durante la ejecución se pueden realizar diferentes acciones:

1. Eliminar una ficha.
2. Agregar una fila.
3. Eliminar una fila.
4. Agregar una columna.
5. Eliminar una columna.
6. Mostrar la representación de los bits.
7. Salir.

Después de algunas acciones se revisa nuevamente el tablero para encontrar combinaciones. Cuando se encuentra una combinación, las fichas se eliminan, las fichas superiores caen y se generan nuevas fichas en los espacios vacíos.

Este proceso se repite mientras sigan apareciendo nuevas combinaciones, permitiendo generar cascadas.

## Estructura del proyecto

El proyecto se encuentra organizado mediante funciones encargadas de diferentes responsabilidades, entre ellas:

* Cálculo de la cantidad de bytes necesarios.
* Creación e inicialización de la memoria dinámica.
* Conversión de fila y columna a posición lineal.
* Generación de fichas.
* Llenado del tablero.
* Almacenamiento de fichas.
* Recuperación de fichas.
* Representación visual del tablero.
* Detección de combinaciones.
* Eliminación de fichas.
* Caída de fichas.
* Rellenado del tablero.
* Procesamiento de cascadas.
* Redimensión del tablero.

La idea es mantener el `main` principalmente como encargado de coordinar las diferentes partes del programa, mientras que las operaciones específicas se realizan mediante sus respectivas funciones.

## Tecnologías utilizadas

* C++
* Qt
* Memoria dinámica
* Manipulación de bits

## Cómo ejecutar

El proyecto puede abrirse desde **Qt Creator** y ejecutarse utilizando el compilador configurado para el proyecto.

Al iniciar, el programa solicitará la cantidad de filas y columnas que tendrá el tablero.

## Autores

**Andrés Felipe Sierra Fernández**
**David Guardiola**

Proyecto académico desarrollado para el curso de programación.

