using System;
using System.Diagnostics.Eventing.Reader;

namespace ConsoleApp1
{
    internal class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("Ingrese una temperatura: ");
            string temperatura = Console.ReadLine();
            int temp;

            bool comprobacion = int.TryParse(temperatura, out temp);
            

            /*
            int temp = int.Parse(temperatura);
            string estadoAgua;
            
            if (temp < 0)
                estadoAgua = "Sólido";
            else if (temp > 99)
                estadoAgua = "Gaseoso";
            else
                estadoAgua = "Lìquido";

            Console.WriteLine("El estado del agua es: " + estadoAgua);
            Console.WriteLine("Este if fue en 4 lineas");
            */

            case (comprobacion)
                { 
                InvalidCastException()
                    estadoAgua = temp < 0 ? "Sólido" : temp > 99 ? "Gaseoso" : "Lìquido";
                    Console.WriteLine("El estado del agua es: " + estadoAgua);
                    Console.WriteLine("Este if fue en una linea");
                    Console.Read();
                }
        }   
    }
}
