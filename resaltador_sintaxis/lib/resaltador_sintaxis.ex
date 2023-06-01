defmodule ResaltadorSintaxis do
  @moduledoc """
  Documentation for `ResaltadorSintaxis`.
  """

  @doc """
  Hello world.

  ## Examples

      iex> ResaltadorSintaxis.hello()
      :world

  """
  def build() do #FUNCIONA
    input_file_path = "prueba_resaltador.cs" #FUNCIONA
    output_file_path = "resaltadorsintaxis.html" #FUNCIONA

    case File.read(input_file_path) do # Lee el archivo de cs #FUNCIONA
      {:ok, content} -> #:ok = exito leyendo / content = donde se guarda el contenido del cs #FUNCIONA
        highlighted_content = highlight_punctuation(content)
        highlighted_content = highlight_reserved(highlighted_content)
        highlighted_content = highlight_cond(highlighted_content)
        highlighted_content = highlight_builtinfunctions(highlighted_content)

        html_content = pre_html() <> highlighted_content <> post_html()

        case File.write(output_file_path, html_content) do #FUNCIONA
          :ok -> #if es exitoso: #FUNCIONA
            IO.puts("Contenido del archivo CS ha sido impreso en el archivo HTML exitosamente.") #FUNCIONA

          {:error, reason} -> #FUNCIONA
            IO.puts("Error al escribir en el archivo HTML: #{reason}") #FUNCIONA
        end #FUNCIONA

      {:error, reason} -> #FUNCIONA
        IO.puts("Error al leer el archivo CS: #{reason}") #FUNCIONA
    end #FUNCIONA
  end #FUNCIONA

  defp highlight_punctuation(content) do
    punctuation_regex = ~r/(\(|\)|\{|\}|\[|\]|\,|\.|\;|\:)/
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
    builtinfunctions_regex = ~r/(Start|Update|GetComponent|.FindGameObjectWithTag|OnTriggerEnter2D|.Log|.SetBool|Destroy)/
    Regex.replace(builtinfunctions_regex, content, "<span class=\"builtinfunctions\">\\1</span>")
  end

  defp pre_html() do #FUNCIONA
    """
    <!DOCTYPE html>
    <html>
      <head>
        <meta charset="utf-8">
        <title>Resaltador de Sintaxis</title>
        <link rel="stylesheet" href="resaltadorsintaxis.css">
      </head>
      <body>
        <pre>
    """ #FUNCIONA
  end #FUNCIONA

  defp post_html() do #FUNCIONA
    """
        </pre>
      </body>
    </html>
    """ #FUNCIONA
  end #FUNCIONA
end #FUNCIONA
