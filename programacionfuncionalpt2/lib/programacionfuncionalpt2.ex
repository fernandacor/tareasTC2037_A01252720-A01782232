defmodule Programacionfuncionalpt2 do
  @moduledoc """
  Documentation for `Programacionfuncionalpt2`.
  """

  @doc """
  Hello world.

  ## Examples

      iex> Programacionfuncionalpt2.hello()
      :world

  """
  def hello do
    :world
  end

@doc """
Actividad 2.2: Programación Funcional Parte 2

Fernanda Cantú
Alina Rosas

30/04/2023
"""

# 3.- La función rotate-left toma dos entradas: un número entero n y una lista lst.
# Devuelve la lista que resulta de rotar lst un total de n elementos a la
#izquierda. Si n es negativo, rota a la derecha.
  def rotate_left (n, lst) do
    if n > 0 do
      rotate_left(n-1, [hd(lst)] ++ tl(lst))
    else
      rotate_left(n+1, tl(lst) ++ [hd(lst)])
    end
  end

# 4.- La función prime-factors toma un número entero n como entrada (n ¿ 0) y
# devuelve una lista que contiene los factores primos de n en orden ascendente.
# Los factores primos son los números primos que dividen a un número de manera
# exacta. Si se multiplican todos los factores primos, se obtiene el número
# original.
  def prime-factor (n) do
    if n == 1 do
      []
    else
      [n | prime-factor(n / (Enum.find(2..n, &(rem(n, &1) == 0)))) ]
    end
  end

# 5.- La función gcd toma dos números enteros positivos a y b como entrada, donde
# a > 0 y b > 0. Devuelve el máximo común divisor (GCD por sus siglas en inglés)
# de a y b. No se debe usar la función gcd o similar predefinida.

  def gcd (a, b) do
    if a == b do
      a
    else
      if a > b do
        gcd(a-b, b)
      else
        gcd(a, b-a)
      end
    end

# 6.- La función deep-reverse toma una lista como entrada. Devuelve una lista con
# los mismos elementos que su entrada, pero en orden inverso. Si hay listas
# anidadas, estas también deben invertirse

  def deep-reverse (lst) do
    if Enum.empty?(lst) do
      []
    else
      if Enum.empty?(hd(lst)) do
        [hd(lst)] ++ deep-reverse(tl(lst))
      else
        [deep-reverse(hd(lst))] ++ deep-reverse(tl(lst))
      end
    end
  end
