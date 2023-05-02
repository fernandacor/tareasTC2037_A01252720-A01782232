# defmodule Programacionfuncionalpt2Test do
#   use ExUnit.Case
#   doctest Programacionfuncionalpt2

#   test "greets the world" do
#     assert Programacionfuncionalpt2.hello() == :world
#   end
# end

#    Tests for the set of problems by Ariel Ortiz
#    Applications of the general concepts of functional programming
#
#    Gilberto Echeverria
#    2022_03_04

defmodule Hw.Ariel2Test do
  use ExUnit.Case
  alias Hw.Ariel2

  # Functions

  test "test rotate_left" do
    assert Ariel2.rotate_left([], 5) == []
    assert Ariel2.rotate_left([:a, :b, :c, :d, :e, :f, :g], 0) == [:a, :b, :c, :d, :e, :f, :g]
    assert Ariel2.rotate_left([:a, :b, :c, :d, :e, :f, :g], 1) == [:b, :c, :d, :e, :f, :g, :a]
    assert Ariel2.rotate_left([:a, :b, :c, :d, :e, :f, :g], -1) == [:g, :a, :b, :c, :d, :e, :f]
    assert Ariel2.rotate_left([:a, :b, :c, :d, :e, :f, :g], 3) == [:d, :e, :f, :g, :a, :b, :c]
    assert Ariel2.rotate_left([:a, :b, :c, :d, :e, :f, :g], -3) == [:e, :f, :g, :a, :b, :c, :d]
    assert Ariel2.rotate_left([:a, :b, :c, :d, :e, :f, :g], 8) == [:b, :c, :d, :e, :f, :g, :a]
    assert Ariel2.rotate_left([:a, :b, :c, :d, :e, :f, :g], -8) == [:g, :a, :b, :c, :d, :e, :f]
    assert Ariel2.rotate_left([:a, :b, :c, :d, :e, :f, :g], 45) == [:d, :e, :f, :g, :a, :b, :c]
    assert Ariel2.rotate_left([:a, :b, :c, :d, :e, :f, :g], -45) == [:e, :f, :g, :a, :b, :c, :d]
  end

  test "test prime_factors" do
    assert Ariel2.prime_factors(1) == []
    assert Ariel2.prime_factors(6) == [2, 3]
    assert Ariel2.prime_factors(96) == [2, 2, 2, 2, 2, 3]
    assert Ariel2.prime_factors(666) == [2, 3, 3, 37]
  end

  test "test gcd" do
    assert Ariel2.gcd(0, 0) == 0
    assert Ariel2.gcd(3, 0) == 3
    assert Ariel2.gcd(0, 2) == 2
    assert Ariel2.gcd(2, 2) == 2
    assert Ariel2.gcd(10, 8) == 2
    assert Ariel2.gcd(8, 10) == 2
    assert Ariel2.gcd(270, 192) == 6
    assert Ariel2.gcd(13, 7919) == 1
    assert Ariel2.gcd(20, 16) == 4
    assert Ariel2.gcd(54, 24) == 6
    assert Ariel2.gcd(6307, 1995) == 7
  end

  test "test deep_reverse" do
    assert Ariel2.deep_reverse([]) == []
    assert Ariel2.deep_reverse([:a, :b]) == [:b, :a]
    assert Ariel2.deep_reverse([:a, :b, :c]) == [:c, :b, :a]
    assert Ariel2.deep_reverse([:a, [:b, :c, :d], 3]) == [3, [:d, :c, :b], :a]
    assert Ariel2.deep_reverse([[1, 2], 3, [4, [5, 6]]]) == [[[6, 5], 4], 3, [2, 1]]
  end
end
