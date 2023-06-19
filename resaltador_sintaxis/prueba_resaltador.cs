// Actividad Integradora 3.4 - Archivo de Prueba en C# para el Resaltador de Sintaxis
// Fernanda Cantú A01782232 & Alina Rosas A01252720

using System.Collections;
using System.Collections.Generic;

// Programa donde se aprecian la mayoría de los elementos resaltados
// por el resaltador de síntaxis hecho en Elixir creado por
// las mejores estudiantes Alina Rosas y Fernanda Cantú

public class Prueba_Resaltador : MonoBehaviour
{
    public int num = 0123;
    private string p4l4br4s = 'Hola Prof :D';
    public float flotante = -0.123f;
    public float flot2 = +898.765f;
    private bool granTrabajo = true;
    protected char prueba = 'Fernanda 123' Alina 456; // Sabemos que esto no es un char, solo es para probar varias cosas

    void Start()
    {
        specialShot = GetComponent<SpecialShot>();
        basicShot = GetComponent<BasicShot>();
    }

    void Update()
    {
        if (granTrabajo == true)
        {
            Debug.Log('¡¡Has hecho un gran trabajo!!');
            return;
        }
        else
        {
            Debug.Log('No te preocupes, todo estará bien');
        }

        while (true)
        {
            do something;
        }

        switch (num)
        {
            case 0:
                print('0');
                break;
            case 1:
                print('1');
                break;
        }
    }
}