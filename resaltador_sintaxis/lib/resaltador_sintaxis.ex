defmodule ResaltadorSintaxis do
  def build(input_file) do
    output_file = "resaltadorsintaxis.html"

    case File.read(input_file) do # Lee el archivo de cs
      {:ok, content} -> #:ok = exito leyendo / content = donde se guarda el contenido del cs
        lines = String.split(content, "\n") # Separa el contenido del cs por lineas
        Enum.each(lines, &check_line/1) # Por cada linea, ejecuta la funcion check_line

        highlighted_content =
          content
          |> highlight_strings()
          |> highlight_comments()
          |> highlight_punctuation()
          |> highlight_numbers()
          |> highlight_reserved()
          |> highlight_cond()
          |> highlight_builtinfunctions()
          |> datatypes()
          # |> highlight_variables()
          # |> highlight_functions()

        html_content = header_html() <> highlighted_content <> footer_html()

        case File.write(output_file, html_content) do
          :ok -> #if es exitoso:
            IO.puts("HTML generated correctly.")
        end
    end
  end

  defp check_line(line) do
  defp highlight_punctuation(content) do
    punctuation_regex = ~r/(\(|\)|\{|\}|\[|\]|\,|\;|\:|\=)/
    Regex.replace(punctuation_regex, content, "<span class=\"punctuation\">\\1</span>")
  end

  defp highlight_comments(content) do
    comment_regex = ~r/^(\/\/.*$|\/\*.*?\*\/)/m
    Regex.run(~r/(int|do)/, content fn m -> "<span class=\"comment\">\\1</span>" end)
    Regex.replace(comment_regex, content, "<span class=\"comment\">\\1</span>")
  end

  defp highlight_strings(content) do
    string_regex = ~r/('[^']*')/
    Regex.replace(string_regex, content, "<span class=\"string\">\\1</span>")
  end


  defp highlight_reserved(content) do
    reserved_regex = ~r/(static|void|public|private|protected|MonoBehaviour|public class|private class)/
    Regex.replace(reserved_regex, content, "<span class=\"reserved\">\\1</span>")
  end

  defp highlight_cond(content) do
    cond_regex = ~r/(using|if|else|for|case|switch|while|break)/
    Regex.replace(cond_regex, content, "<span class=\"cond\">\\1</span>")
  end

  defp highlight_builtinfunctions(content) do
    builtinfunctions_regex = ~r/(Start|Update|Play|GetComponent|FindGameObjectWithTag|OnTriggerEnter2D|Log|SetBool|Destroy|SetGameState)/
    Regex.replace(builtinfunctions_regex, content, fn match -> "<span class=\"builtinfunctions\">#{match}</span>" end)
  end

  defp highlight_numbers(content) do
    numbers_regex = ~r/(\+|\-)?([0-9])(\.[0-9]+)?(f)?/
    Regex.replace(numbers_regex, content, "<span class=\"numbers\">\\1\\2\\3\\4</span>")
  end

  defp datatypes(content) do
    datatypes_regex = ~r/(int|float|double|bool|char|long|GameManager|AudioSource|Animator|GameObject|string|Sprite|Image)/
    Regex.replace(datatypes_regex, content, "<span class=\"datatypes\">\\1</span>")
  end

  #FUNCTION TO HIGHLIGHT VARIABLES
  # defp highlight_variables(content) do
  #  variables_regex = ~r/([a-z]+[0-9]*)/
  #  Regex.replace(variables_regex, content, "<span class=\"variables\">\\1</span>")
  # end

  # #FUNCTION TO HIGHLIGHT FUNCTION NAMES
  # defp highlight_functions(content) do
  #  functions_regex = ~r/([a-z]+[0-9]*)/
  #  Regex.replace(functions_regex, content, "<span class=\"functions\">\\1</span>")
  # end

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

  defp footer_html() do
    """
        </pre>
      </body>
    </html>
    """
  end
end
