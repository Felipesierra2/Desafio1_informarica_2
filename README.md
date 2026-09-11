Sweet Crush

Proyecto desarrollado en C++ como parte del curso de programación.

Sweet Crush es un juego basado en la eliminación de fichas, eliminacion por combinación, cambiar dimensiones en tiempo de ejecución.
El tablero se almacena usando memoria dinamica y una cominación concatenada de 3 bits que representan cada ficha

Esta representación permite manipular las fichas dentro de una secuencia de bytes, aprovechando los bits disponibles evitando usar un byte completo para almacenar solo una ficha

Características

- Almacenamiento dinamico del tablero.
- Las fichas ocupan 3 bits.
- Almacenamiento de fichas dentro de una secuencia de bytes.
- Manipulación de bits en el limite de dos bytes
- Conversión entre posiciones de fila/columna y posiciones lineales.
- Lectura y escritura de fichas directamente sobre la memoria.
- Redimensión dinámica del tablero.


Estructura del proyecto

El proyecto se encuentra organizado mediante funciones encargadas de diferentes responsabilidades, entre ellas:

- Cálculo de la cantidad de bytes necesarios.
- Creación e inicialización de la memoria dinámica.
- Conversión de fila y columna a posición lineal.
- Almacenamiento de fichas.
- Recuperación de fichas.
- Representación visual del tablero.
- Redimensión del tablero.

Autor

Andrés Felipe Sierra Fernández
David Guardiola

Proyecto académico desarrollado para el curso de programación.
