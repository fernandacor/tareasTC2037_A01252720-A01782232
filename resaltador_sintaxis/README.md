# ResaltadorSintaxis
* Fernanda Cantú - A01782232
* Alina Rosas - A01252720

## Instructions
The elixir code already includes a css input file that defines the attributes of each lexical category to be highlighted and includes an html output file in which the result of the syntax highlighter will be displayed. 

The first thing to do is to install the package that you will find in the documentation.

1) Open Git Bash and type iex to launch the elixir shell.  

2) Call the funtion:

```elixir
ResaltadorSintaxis.lexer()
```

3) Every time a change is made you have to compile the file:

```elixir
recompile
```

4) To test with different files, you have to change the file path inside the `input_file` variable inside the Elixir code.

5) After each execution, in case there are no errors, the HTML file called "resaltadorsintaxis.html" will be updated with the highlighted syntax.

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
This syntax highlighter is made for documents in the C# language since it is a language we know and have worked with. We know the variables to use and the different lexical categories of the language. We had a couple of problems when making this lexer because our initial logic did not work very well with the logic that was being sought for the further expansion of the code, so we had to make changes and modifications to implement regex.run and that the program would work successfully. One of the most important points being that it reads and identifies the words and symbols with their respective tokens before replacing and categorizing them twice, which was one of the errors we had with the original code.

We use recursive functions to read the file line by line and to generate the output file. Regular expressions were also used to construct and define the tokens. As well as a predefined function that creates the header and footer of the html file. We consider that for the amount of lines of code that this file has, the time it takes to execute is not that long.

## Algorithmic Complexity
First we know that there are 4 main functions with additional code and other sub-functions within them. After doing a quick analysis by function we were able to conclude the following: 

* The **lexer(input_file)** function has a constant time complexity **O(1)** since it performs a fixed number of operations (regardless of the size of the input file).

* The total complexity of the **highlighter** function is **O(n)**, where n is the number of lines in the file.

* The complexity of the **check_line** function would be the sum of the complexities of all regular expressions, resulting in a linear complexity **O(m)**.

* The complexity of the **build** function is linear **O(m)**.

Overall, we have concluded that the complexity of the code depends on the number of lines in the file (n) and the size of each line (m). So, in the worst case, the complexity would be approximately **O(n * m)**, where n is the number of lines and m is the average size of each line.

## Ethical implementation

We believe that when it comes to programming, there are many ethical issues that must be followed more than anything else because of the amount of information found on the Internet and the new AI tools. However, we believe that ethics is not necessarily at odds with this as developers forums are extremely useful when you are stuck on a file or can not solve a bug.  Therefore we consider that having open repositories with useful user manuals can promote collaboration and learning among developers, supporting each other from personal knowledge instead of having to turn to AI tools that are usually not very useful for these topics. This way we can learn by collaborating in a reliable and ethical manner.
