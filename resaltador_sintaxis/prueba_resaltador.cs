using System.Collections;
using System.Collections.Generic;

// Programa donde se aprecian la mayoría de los elementos resaltados
// por el resaltador de síntaxis hecho en Elixir creado por
// las mejores estudiantes Alina Rosas y Fernanda Cantú

public class Prueba_Resaltador : MonoBehaviour
{
    public int = 0123;
    private string = 'Hola Prof :D'
    public float = 0.123;
    private bool granTrabajo = true;

    void Start()
    {
        specialShot = GetComponent<SpecialShot>();
        basicShot = GetComponent<BasicShot>();
    }

    void Update()
    {
        if (granTrabajo == true)
        {
            Debug.Log("¡¡Has hecho un gran trabajo!!");
            return;
        }
        else
        {
            Debug.Log("No te preocupes");
        }
    }
}
