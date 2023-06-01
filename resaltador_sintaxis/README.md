# ResaltadorSintaxis
* Fernanda Cantú - A01782232
* Alina Rosas - A01252720

## Instructions
The elixir code already includes a css input file that defines the attributes of each lexical category to be highlighted and includes an html output file in which the result of the syntax highlighter will be displayed. 

The first thing to do is to install the package that you will find in the documentation.

1) Open Git Bash and type iex to launch the elixir shell.  

2) Call the funtion:

```elixir
ResaltadorSintaxis.build()
```

3) Every time a change is made you have to compile the file:

```elixir
recompile
```

4) To test with different files, you have to change the file path inside the `input_filename_path` variable inside the elixir code.

5) After each execution, in case there are no errors, an html file will be displayed with the syntax highlighter otherwise it will return an error.

## Installation

If [available in Hex](https://hex.pm/docs/publish), the package can be installed
by adding `resaltador_sintaxis` to your list of dependencies in `mix.exs`:

```elixir
def deps do
  [
    {:resaltador_sintaxis, "~> 0.1.0"}
  ]
end
```

Documentation can be generated with [ExDoc](https://github.com/elixir-lang/ex_doc)
and published on [HexDocs](https://hexdocs.pm). Once published, the docs can
be found at <https://hexdocs.pm/resaltador_sintaxis>.

## Conclusion 
This syntax highlighter is made for documents in the C# language since it is a language we know and have worked with. We know the variables to use and the different lexical categories of the language. To create this highlighter our solution was... (explicacion).  The algorithms that were implemented are... (algoritmos). We consider that for the amount of lines of code that this file has, the time it takes to execute is not that long. 

## Algorithmic Complexity

## Ethical implementation
