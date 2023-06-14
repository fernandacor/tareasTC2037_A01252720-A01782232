@doc """
Actividad 2.2: Programación Funcional Parte 2

Fernanda Cantú
Alina Rosas

30/04/2023
"""

# Procuren adaptarse a los nombres de modulos y funciones que se usan en los archivos de prueba

# 3.- La función rotate-left toma dos entradas: un número entero n y una lista lst.
# Devuelve la lista que resulta de rotar lst un total de n elementos a la
#izquierda. Si n es negativo, rota a la derecha.
defmodule Ariel2 do
  def rotate_left(n, lst) do
    if n < 0 do
      rotate_left(n-1, [hd(lst)] ++ tl(lst))
    else
      rotate_left(n+1, tl(lst) ++ [hd(lst)])
    end
  end
end

# defmodule Rotate do
#   def rotate_left(n, lst) do
#     if n < 0 do
#       n = abs(n)
#       (first, rest)=Enum.split(lst, length(lst) - n)
#       rest ++ first
#     else
#       (first, rest)=Enum.split(lst, n)
#       rest ++ first
#     end
#   end
# end

# No funciona en todos los casos
# Es algo de trampa usar Enum.split, el chiste es que implementemos la
# funcionalidad usando recursion.

# 4.- La función prime-factors toma un número entero n como entrada (n ¿ 0) y
# devuelve una lista que contiene los factores primos de n en orden ascendente.
# Los factores primos son los números primos que dividen a un número de manera
# exacta. Si se multiplican todos los factores primos, se obtiene el número
# original.

# defmodule ejercicio4 do
#   def prime_factors(n) do
#     if n == 1 do
#       []
#     else
#       [n | prime_factors(n / (Enum.find(2..n, &(rem(n, &1) == 0)))) ]
#     end
#   end

# defmodule PrimeFactors
#   def prime_factors(n) when n <= 1 do
#     []
#   end

#   def prime_factors(n) do
#     prime_factors(n, 2, [])
#     |> Enum.reverse()
#   end

#   defp prime_factors(1, _, factors) do
#     factors
#   end

#   defp prime_factors(n, divisor, factors) do
#     case rem(n, divisor) do
#       0 ->
#         prime_factors(div(n, divisor), divisor, [divisor | factors])
#       _ ->
#         prime_factors(n, divisor + 1, factors)
#     end
#   end
# end


# 5.- La función gcd toma dos números enteros positivos a y b como entrada, donde
# a > 0 y b > 0. Devuelve el máximo común divisor (GCD por sus siglas en inglés)
# de a y b. No se debe usar la función gcd o similar predefinida.

# defmodule ejercicios5 do
#   def gcd(a, b) do
#     if a == b do
#       a
#     else
#       if a > b do
#         gcd(a-b, b)
#       else
#         gcd(a, b-a)
#       end
#     end
#   end
# end

# defmodule GCD do
#   def gcd(a, 0) do
#     gcd(b, rem(a,b))
#   end
# end

# # 6.- La función deep-reverse toma una lista como entrada. Devuelve una lista con
# # los mismos elementos que su entrada, pero en orden inverso. Si hay listas
# # anidadas, estas también deben invertirse

# defmodule ejercicio6 do
#   def deep-reverse(lst) do
#     if Enum.empty?(lst) do
#       []
#     else
#       if Enum.empty?(hd(lst)) do
#         [hd(lst)] ++ deep-reverse(tl(lst))
#       else
#         [deep-reverse(hd(lst))] ++ deep-reverse(tl(lst))
#       end
#     end
#   end
# end

# defmodule DeepReverse do
#   def deep_reverse(list) do
#     Enum.reverse(reverse_nested_lists(list))
#   end

#   defp reverse_nested_lists(list) do
#     Enum.map(list, fn
#       inner_list when is_list(inner_list) ->
#         reverse_nested_lists(inner_list)
#         element ->
#           element
#         end)
#   end
# end

# No trabaja correctamente para listas anidadas
# Enum.reverse es medio trampa
