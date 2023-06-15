# Actividad 5.2 - Programación Paralela y Concurrente
# Fernanda Cantú A01782232 & Alina Rosas A01252720
# defmodule Hw.Primes do
#   def sum_primes(limit) do
#   end
#     # Recibe el limite de los numeros primos a sumar

#     # Regresa la suma de los numeros primos menores al limite
#     # Formula para figure out si un numero es un primo o no??
#   defp is_prime(num)
#   end

#   def sum_primes_parallel(lim, thr) do

#   end

#   defp limits(inf, sup) do
#   end

# end

defmodule Hw.Primes do
  def sum_primes(limit) do
    primes = find_primes(limit)
    Enum.sum(primes)
  end

  defp find_primes(limit) do
    Enum.filter(2..limit, &is_prime/1)
  end

  defp is_prime(n) do
    for i <- 2..(n-1), rem(n, i) == 0, do: false
    true
  end
end
