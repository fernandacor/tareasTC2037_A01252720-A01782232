defmodule ResaltadorSintaxis do

  def build() do
    input_file = "prueba_resaltador.cs"
    output_file = "resaltadorsintaxis.html"

    case File.read(input_file) do # Lee el archivo de cs
      {:ok, content} -> #:ok = exito leyendo / content = donde se guarda el contenido del cs
        highlighted_content =
          content
          |> highlight_punctuation()
          |> highlight_reserved()
          |> highlight_comments()
          |> highlight_cond()
          |> highlight_builtinfunctions()
          |> highlight_numbers()
          |> datatypes()
          |> highlight_strings()

        html_content = header_html() <> highlighted_content <> footer_html()

        case File.write(output_file, html_content) do
          :ok -> #if es exitoso:
            IO.puts("HTML generated correctly.")
        end
    end
  end

  defp highlight_punctuation(content) do
    punctuation_regex = ~r/(\(|\)|\{|\}|\[|\]|\,|\;|\:|\=)/
    Regex.replace(punctuation_regex, content, "<span class=\"punctuation\">\\1</span>")
  end

  defp highlight_reserved(content) do
    reserved_regex = ~r/(static|void|public|private|protected|MonoBehaviour)/
    Regex.replace(reserved_regex, content, "<span class=\"reserved\">\\1</span>")
  end

  defp highlight_cond(content) do
    cond_regex = ~r/(using|if|else)/
    Regex.replace(cond_regex, content, "<span class=\"cond\">\\1</span>")
  end

  defp highlight_builtinfunctions(content) do
    builtinfunctions_regex = ~r/(Start|Update|Play|GetComponent|FindGameObjectWithTag|OnTriggerEnter2D|Log|SetBool|Destroy|SetGameState)/
    Regex.replace(builtinfunctions_regex, content, fn match -> "<span class=\"builtinfunctions\">#{match}</span>" end)
  end

  defp highlight_comments(content) do
    comment_regex = ~r/(\/\/.*$|\/\*.*?\*\/)/m
    Regex.replace(comment_regex, content, "<span class=\"comment\">\\1</span>")
  end

  defp highlight_numbers(content) do
    # numbers_regex = ~r/(0|1|2|3|4|5|6|7|8|9)/
    numbers_regex = ~r/(?<!\w)([0-9]+)(?!\w)/
    Regex.replace(numbers_regex, content, "<span class=\"numbers\">\\1</span>")
  end

  defp datatypes(content) do
    datatypes_regex = ~r/(int|float|double|bool|char|long|GameManager|AudioSource|Animator|GameObject|string|Sprite|Image)/
    Regex.replace(datatypes_regex, content, "<span class=\"datatypes\">\\1</span>")
  end

  defp highlight_strings(content) do
    string_regex = ~r/('[^']*')/
    Regex.replace(string_regex, content, fn match -> "<span class=\"string\">#{match}</span>" end)
  end

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
