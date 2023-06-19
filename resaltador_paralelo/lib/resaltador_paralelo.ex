# Actividad Integradora 5.3 - Resaltador de Sintaxis Paralelo
# Fernanda Cantú A01782232 & Alina Rosas A01252720

defmodule ResaltadorParalelo do
  def parallel (files) do
    input_files = files
    |> Enum.map(&Task.async(fn -> lexer(&1) end))
    |> Enum.map(&Task.await(&1))
  end

  # Función que recibe el nombre del archivo de entrada y construye el archivo de salida
  def lexer(input_file) do
    output_file = "resaltadorparalelo.html"

    File.write(output_file, header_html())
    content = File.read!(input_file)
    highlighter(content, output_file)
    File.write(output_file, footer_html(), [:append])
  end

  # Función para leer el documento línea por línea
  defp highlighter(content, output_file) do
    content
    |> String.split("\n")
    |> Enum.map(&String.trim_trailing/1)
    |> Enum.map(fn line -> check_line(line, output_file) end)
  end

  # Función para checar cada línea y ver si hay coincidencias con las expresiones regulares
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

  # Función para construir el archivo de salida
  defp build(line, regex, class, output_file) do
    [hd|_] = Regex.run(regex, line)
    span_replace = "<span class=\"#{class}\">#{hd}</span>"
    File.write(output_file, span_replace, [:append])
    line = Regex.replace(regex, line, "", global: false)
    check_line(line, output_file)
  end

  # Funcion que contiene el header del documento HTML
  defp header_html() do
    """
    <!DOCTYPE html>
      <html>
      <head>
        <meta charset="UTF-8">
        <title>Resaltador de Sintaxis</title>
        <link rel="stylesheet" href="resaltadorparalelo.css">
      </head>
      <body>
      <h1>Resaltador de Sintaxis para C#</h1>
      <h3> Creado por: Fernanda Cantú A01782232 y Alina Rosas A01252720</h3>
      <hr>
      <pre>
    """
  end

  # Funcion que contiene el footer del documento HTML
  defp footer_html() do
    """
      </pre>
      </body>
      </html>
    """
  end
end
