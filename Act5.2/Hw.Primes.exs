# Actividad 5.2 - Programación Paralela y Concurrente
# Fernanda Cantú A01782232 & Alina Rosas A01252720
# 14/06/2023

defmodule Hw.Primes do
  # Function that sums all the prime numbers in a given range
  def sum_primes(start, finish) do
    primes = find_primes(start, finish)
    Enum.sum(primes)
  end

  # Function that finds all the prime numbers in a given range
  defp find_primes(start, finish) do
    Enum.filter(start.. finish, &is_prime/1)
  end

  # Function that checks if a number is prime
  defp is_prime(n) when n <= 1, do: false
  defp is_prime(2), do: true
  defp is_prime(n) do
    Enum.all?(2..round(:math.sqrt(n)), fn i -> rem(n, i) != 0 end)
  end

  # Function that sums ranges
  def range_sum({start, finish}) do
    Enum.to_list(start..finish)
    |> Enum.filter(&is_prime/1)
    |> Enum.sum()
  end

  # Function that creates a list of tuples with the ranges to be summed
  defp make_ranges(start, finish, cores) do
    range_size = div(finish - start + 1, cores)
    Enum.map(0..(cores - 1), fn i ->
      range_start = start + (i * range_size)
      range_finish = range_start + range_size - 1
      {range_start, range_finish}
    end)
  end

  # Function that sums all the prime numbers in a given range in parallel
  def sum_primes_parallel(start, finish, cores) do
    make_ranges(start, finish, cores)
    |> Enum.map(&Task.async(fn -> range_sum(&1) end))
    |> Enum.map(&Task.await(&1))
    |> Enum.sum()
  end

  # Function that calculates the time it takes to sum all the prime numbers sequentially
  def seq_prime_sum() do
    {time, result} = :timer.tc(fn -> Hw.Primes.sum_primes(2, 5000000) end)
    IO.puts("Time when sequential: #{time}")
    IO.puts("Sequential result: #{result}")
    time
  end

  # Function that calculates the time it takes to sum all the prime numbers in parallel
  def par_prime_sum(cores) do
    {time, result} = :timer.tc(fn -> Hw.Primes.sum_primes_parallel(1, 5000000, cores) end)
    IO.puts("Time when parallel with #{cores} cores: #{time}")
    IO.puts("Parallel result: #{result}")
    time
  end

  # Function that calculates the speedup between the times of the sequential and parallel functions
  def speedup do
    cores = System.schedulers_online()
    t1 = seq_prime_sum()
    tp = par_prime_sum(cores)
    speedup = t1 / tp
    IO.puts("Speedup: #{speedup}")
  end
end

# {time, result} = :timer.tc(fn -> Hw.Primes.sum_primes(2, 10000) end)
# IO.puts("Time when sequential: #{time}")
# IO.puts("Sequential result: #{result}")

# {time, result} = :timer.tc(fn -> Hw.Primes.sum_primes_parallel(1, 10000, 8) end)
# IO.puts("Time when parallel with 8 cores: #{time}")
# IO.puts("Parallel result: #{result}")


