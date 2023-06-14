#Using tasks to launch several processes at the same time
#8.6.23

defmodule Concur do
  def test_function(id) do
    IO.puts("I am #{id}")
  end

  def main do
    IO.puts("MAIN THREAD STARTING")
    # Create a new process
    id1 = Task.async(fn -> test_function("One") end)
    id2 = Task.async(fn -> test_function("Two") end)
    id3 = Task.async(fn -> test_function("Three") end)
    Task.await(id1)
    Task.await(id2)
    Task.await(id3)
    IO.puts("MAIN THREAD FINISHING")
  end

  def main2() do
    IO.puts("MAIN THREAD STARTING")
    # Create a new process
    ["One", "Two", "Three", "Four"]
    |> Enum.map(&Task.async(fn -> test_function(&1) end))
    |> IO.inspect()
    |> Enum.map(&Task.await(&1))
    IO.puts("MAIN THREAD FINISHING")
  end
end

defmodule Sums do
  def range_sum(start, finish) do
    Enum.sum(start..finish)
  end

  def make_ranges(start, finish, cores) do
    # que forme su propia lista

  end

  def total_sum(start, finish) do
    make_ranges(start, finish, cores)
    |> Enum.map(&Task.async(fn -> range_sum(&1) end))
    |> IO.inspect()
    |> Enum.map(&Task.await(&1))
    |> IO.inspect()
    |> Enum.sum()
  end
end
