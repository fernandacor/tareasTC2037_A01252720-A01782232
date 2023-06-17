# Actividad 5.2 - Programación Paralela y Concurrente (14/06/23)
- Fernanda Cantú A01782232
- Alina Rosas A01252720
## Objetivo
Realizar un programa donde se muestren funciones que reciben un rango y suma los números primos. La primera función se realiza de forma secuencial, mientras que la segunda función se realiza utilizando programación paralela. El objetivo es demostrar que la programación paralela es más eficiente, comparando los tiempos de ejecución entre ambas funciones.

## Análisis de tiempo
Para calcular el tiempo que tarda en ejecutar cada versión del programa, se utiliza la siguiente fórmula para calcular el speedup: <br>
$S_p = \frac{T_1}{T_p}$

Se agregó una función llamada $speedup$ que regresa el tiempo y resultado de cada programa y el speedup. Para ello, se agregó la función System.schedulers_online(), la cúal devuelve el número de cores disponibles en la computadora, y los aprovecha para la ejecución en paralelo.

Tras hacer múltiples pruebas tomando en cuenta el límite como 5,000,000 y 8 cores, se pudo observar que la función que se ejecuta de forma paralela es aproximadamente 4 veces más rápida.

