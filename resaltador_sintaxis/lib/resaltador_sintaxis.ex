# Activity 3.4 - Syntax Highlighter
# Fernanda Cantú A01782232 & Alina Rosas A01252720

defmodule ResaltadorSintaxis do
  @doc """
  The program receives a file with C# code and returns an HTML file with the same code but with syntax highlighting.
  The program uses regular expressions to identify the different elements of the code and then replace them with the
  corresponding HTML tags.
  """

  # Function that receives the name of the input file and builds the output file
  def lexer(input_file) do
    output_file = "resaltadorsintaxis.html"

    File.write(output_file, header_html())
    content = File.read!(input_file)
    highlighter(content, output_file)
    File.write(output_file, footer_html(), [:append])
  end

  # Function that reads the document line by line
  defp highlighter(content, output_file) do
    content
    |> String.split("\n")
    |> Enum.map(&String.trim_trailing/1)
    |> Enum.map(fn line -> check_line(line, output_file) end)
  end

  # Function to check each line and see if there are matches with the regular expressions
  defp check_line("", output_file), do: File.write(output_file, "<br>", [:append])
  defp check_line(line, output_file) do
    comment_regex = ~r/^(\/\/.*$|\/\*.*?\*\/)/m
    string_regex = ~r/^('[^']*')/
    punctuation_regex = ~r/^(\(|\)|\{|\}|\[|\]|\.|\,|\;|\:|\=|\%|\<|\>)/
    numbers_regex = ~r/^(\+|\-)?([0-9])(\.[0-9]+)?(f)?/
    datatypes_regex = ~r/^\b(int|float|double|bool|char|long|string)\b/
    reserved_regex = ~r/^(static|void|public|private|protected|true|false|class)/
    cond_regex = ~r/^\b(using|if|else|for|case|switch|while|break|in|do|then|return)\b/
    variable_regex = ~r/^[a-z_$][a-zA-Z0-9_$]*(?=(\.)*)/
    id_regex = ~r/^([A-Z_$][a-zA-Z0-9_$]*)/
    function_regex = ~r/^([a-zA-Z_$][a-zA-Z0-9_$]*(?=(\(|\<)))/
    space_regex = ~r/^\s+/
    other_regex = ~r/^\S+/

    cond do
      Regex.match?(punctuation_regex, line) ->
        build(line, punctuation_regex, "punctuation", output_file)
      Regex.match?(comment_regex, line) ->
        build(line, comment_regex, "comment", output_file)
      Regex.match?(string_regex, line) ->
        build(line, string_regex, "string", output_file)
      Regex.match?(reserved_regex, line) ->
        build(line, reserved_regex, "reserved", output_file)
      Regex.match?(cond_regex, line) ->
        build(line, cond_regex, "cond", output_file)
      Regex.match?(numbers_regex, line) ->
        build(line, numbers_regex, "numbers", output_file)
      Regex.match?(datatypes_regex, line) ->
        build(line, datatypes_regex, "datatypes", output_file)
      Regex.match?(function_regex, line) ->
        build(line, function_regex, "functions", output_file)
        Regex.match?(variable_regex, line) ->
          build(line, variable_regex, "variables", output_file)
      Regex.match?(id_regex, line) ->
        build(line, id_regex, "id", output_file)
          Regex.match?(space_regex, line) ->
            build(line, space_regex, "space", output_file)
      true ->
        build(line, other_regex, "other", output_file)
    end
  end

  # Function to build the output file
  defp build(line, regex, class, output_file) do
    [hd|_] = Regex.run(regex, line)
    span_replace = "<span class=\"#{class}\">#{hd}</span>"
    File.write(output_file, span_replace, [:append])
    line = Regex.replace(regex, line, "", global: false)
    check_line(line, output_file)
  end

  # Function that contains the header for the HTML document
  defp header_html() do
    """
    <!DOCTYPE html>
      <html>
      <head>
        <meta charset="UTF-8">
        <title>Resaltador de Sintaxis</title>
        <link rel="stylesheet" href="resaltadorsintaxis.css">
      </head>
      <body>
      <h1>Resaltador de Sintaxis para C#</h1>
      <h3> Creado por: Fernanda Cantú A01782232 y Alina Rosas A01252720</h3>
      <hr>
      <pre>
    """
  end

  # Function that contains the footer for the HTML document
  defp footer_html() do
    """
      </pre>
      </body>
      </html>
    """
  end
end

# {time} = :timer.tc(fn -> ResaltadorSintaxis.lexer("prueba_resaltador.cs") end)
# IO.puts("Time when sequential: #{time}")
