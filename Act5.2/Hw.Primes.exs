# Actividad 5.2 - Programación Paralela y Concurrente
# Fernanda Cantú A01782232 & Alina Rosas A01252720
# 14/06/2023

defmodule Hw.Primes do
  def sum_primes(limit) do
    primes = find_primes(limit)
    Enum.sum(primes)
  end

  defp find_primes(limit) do
    Enum.filter(2..limit, &is_prime/1)
  end

  defp is_prime(n) do
    for i <- 2..trunc(:math.sqrt(n)), rem(n, i) == 0, do: false
    true
  end

  def sum_primes_parallel(limit, threads) do
    ranges = make_ranges(limit, threads)
    ranges
    |> Enum.map(fn {start, stop} -> Task.async(fn -> range_sum(start, stop) end) end)
    |> Enum.map(fn task -> Task.await(task) end)
    |> Enum.sum()
  end

  defp make_ranges(limit, threads) do
    step = div(limit, threads)
    0..(threads - 1)
    |> Enum.map(fn i -> {i * step + 1, min((i + 1) * step, limit)} end)
  end

  defp range_sum(start, stop) do
    primes = find_primes(stop)
    Enum.filter(primes, &(&1 >= start))
    |> Enum.sum()
  end
  end
