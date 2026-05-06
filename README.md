1. Título del Proyecto
Comparando Algoritmos de Ordenamiento

2. Descripción
Es un programa en C++ diseñado para generar un array de números aleatorios dentro de un rango definido y comparar la eficiencia de distintos algoritmos de ordenamiento (Bubble Sort, Selection Sort, Insertion Sort y el Quick Sort) midiendo el tiempo de ejecución en nanosegundos y la cantidad de pasos realizados.

3.Ejemplos
-Ejemplo 1:
Entrada:
Cantidad de números: 10
Rango mínimo: 1
Rango máximo: 50
Salida esperada:
/*
Array generado:
[ 1 32 6 10 23 3 49 14 18 18 ]

Resultados comparativos (Ordenados por tiempo):
----------------------------------------------------------------------
Posicion  Algoritmo           Pasos               Tiempo (ns)
----------------------------------------------------------------------
1o        Insertion Sort      41                  700 ns
2o        Selection Sort      54                  800 ns
3o        Quick Sort          39                  800 ns
4o        Bubble Sort         61                  2400 ns
*/

-Ejemplo 2:
Entrada:
Cantidad de números: 100
Rango mínimo: 10
Rango máximo: 500
Salida esperada: 
/*
Array generado:
[ 334 243 422 168 266 356 352 418 158 343 217 296 114 48 18 195 101 443 352 189 181 448 426 94 96 434 303 281 225 367 40
8 162 403 36 117 252 222 254 156 264 28 473 376 286 247 26 63 468 409 472 165 317 39 26 296 44 430 114 33 204 275 37 125
 19 163 215 60 95 435 281 309 284 120 71 396 292 307 242 153 386 112 340 209 498 168 237 240 253 300 388 395 147 78 98 4
95 433 346 273 136 377 ]

Resultados comparativos (Ordenados por tiempo):
----------------------------------------------------------------------
Posicion  Algoritmo           Pasos               Tiempo (ns)
----------------------------------------------------------------------
1o        Quick Sort          1052                11400 ns
2o        Insertion Sort      5053                15800 ns
3o        Selection Sort      5049                27700 ns
4o        Bubble Sort         7427                59100 ns

*/
