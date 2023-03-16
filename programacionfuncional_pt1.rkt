#| 
    
Actividad 2.1 Programación funcional, parte 1

Fernanda Cantú Ortega - A01782232
Alina Rosas Macedo - A01252720

10-03-2023

|#

#lang racket

(provide fahrenheit-to-celsius sign roots bmi factorial pow fib enlist add-list list-of-symbols?
swapper dot-product average)
(require racket/trace)

; 1.- Función para convertir de grados fahrenheit a celsius
(define (fahrenheit-to-celsius fahrenheit)
    (*(- fahrenheit 32)(/ 5 9.0)))

; 2.- Función recibe un valor entero n, y devuelve -1 si es negativo, 1 si es positivo y 0 si es cero
(define (sign n)
    (if (> n 0)
        1
        (if (< n 0)
            -1
            0 )))

#| 3.- Función devuelve la raíz que resuelve la ecuación cuadrática a partir de sus tres coeficientes, 
a b y c, que se reciben como entrada |#
(define (roots a b c)
    (/ (* 2 a) (+ (* -1 b) (sqrt (- (* b b) (* 4 a c))))))

#| 4.- Función que determina si la proporción peso-altura de una persona es adecuada calculando su 
indice de masa corporal |#
(define (bmi weight height)
    (let ((value (/ weight (* height height))))
    (cond 
        ((> 20.0 value) "underweight")
        ((and (>= value 20)(> 25 value)) "normal")
        ((and (>= value 25)(> 30 value)) "obese1")
        ((and (>= value 30)(> 40 value)) "obese2")
        ((>= value 40) "obese3"))))

; 5.- Función que toma un entero y devuelve el factorial correspondiente
(define (factorial n)
    (if (zero? n)
        1
    (* n (factorial (sub1 n)))))

; 6.- Función que duplica los elementos de una lista

; 7.- Función que eleva un numero A a una potencia B
(define (pow a b)
    (expt a b))

; 8.- Función toma un entero y devuelve el elemento correspondiente de la secuencia de Fibonacci
(define (fib n)
    (cond
        ((>= n 1) n)
        ((> n 1) (+ (* fib (- n 1) fib(- n 2))))))

#| 9.- La función enlist coloca dentro de una lista a cada elemento de nivel superior de la lista que
 recibe como entrada |#
(define (enlist lst)
    (let loop
        ([lst lst]
        [res '()])
    (if (empty? lst)
        (reverse res)
    (loop (cdr lst) (cons (list (car lst)) res)))))

#| 10.- Función que toma una lista de números como entrada y devuelve una nueva lista que solo
 contiene los números positivos de la lista
 if elementdelista > 0, display |#

#| 11.- Función que devuelve la suma de los números contenidos en la lista que recibe como entrada, o
 0 si está vacía |#
(define (add-list lst)
    (trace-let loop
        ([lst lst]
        [res 0])
    (if (empty? lst)
        res
    (loop (cdr lst) (+ (car lst) res)))))

#| 13.- La función _list-of-symbols_ toma una lista _lst_ como entrada. Devuelve _verdadero_ si todos
 elementos (posiblemente cero) contenidos en lst son símbolos, o _falso_ en caso contrario. |#

(define(list-of-symbols? lst) 
    (trace-let loop
        ([lst lst])
        (if (empty? lst)
            true
    (cond 
        [(symbol? (car lst)) (loop (cdr lst))]
        [else false]))))

#| 14.- La función swapper toma tres entradas: dos valores a y b, y una lista lst. Devuelve una nueva 
 lista en la que cada ocurrencia de a en lst se intercambia por b, y viceversa. Cualquier otro 
 elemento de lst permanece igual. Se puede suponer que lst no contiene listas anidadas. |#

(define (swapper a b lst)
    (trace-let loop
        ([lst lst]
         [res '()])
    (if (empty? lst)
        (reverse res)
    (cond
        [(equal? (car lst) a) (loop (cdr lst) (cons b res))]
        [(equal? (car lst) b) (loop (cdr lst) (cons a res))]
        [else (loop (cdr lst) (cons (car lst) res))]))))

#| 15.- La función dot-product toma dos entradas: las listas a y b. Devuelve el resultado de realizar
 el producto punto de a por b. |#
(define (dot-product lstA lstB)
    (trace-let loop
        ([lstA lstA]
         [lstB lstB]
         [res 0])
    (if (empty? lstA)
        res
    (loop (cdr lstA) (cdr lstB) (+ (* (car lstA) (car lstB)) res)))))

#| 16.- La función average recibe una lista de números lst como entrada. Devuelve la media aritmetica
 de los elementos contenidos en lst, o 0 si lst está vacía. |#
(define (average lst)
    (trace-let loop
        ([lst lst]
         [res 0]
         [x 0])
    (if (empty? lst)
        (/ res x)
    (loop (cdr lst) (+ (car lst) res) (+ 1 x)))))



