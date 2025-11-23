#include <iostream>
#include <string>

using namespace std;


string NombreToText(int Nombre)
{
    if (Nombre == 0)
    {
        return "";
    }
    else if (Nombre >= 1 && Nombre <= 19)
    {
        string arr[] = {
    "", "Un", "Deux", "Trois", "Quatre", "Cinq", "Six", "Sept", "Huit", "Neuf",
    "Dix", "Onze", "Douze", "Treize", "Quatorze", "Quinze", "Seize", "Dix-Sept", "Dix-Huit", "Dix-Neuf"
        };
        return arr[Nombre] + " ";
    }
    else if (Nombre >= 20 && Nombre <= 99)
    {

        string arr[] =
        {
                "", "", "Vingt", "Trente", "Quarante", "Cinquante", "Soixante", "Soixante-Dix", "Quatre-Vingt", "Quatre-Vingt-Dix"

        };
        return arr[Nombre / 10] + " " + NombreToText(Nombre % 10);
    }
    else if (Nombre >= 100 && Nombre <= 199)
    {
        
        return " Cent " + NombreToText(Nombre % 100);
    }
    else if (Nombre >= 200 && Nombre <= 999)
    {
        return NombreToText(Nombre / 100) + " Cent " + NombreToText(Nombre % 100);
    }
    else if (Nombre >= 1000 && Nombre <= 1999)
    {
        return " Mille " + NombreToText(Nombre % 1000);
    }
    else if (Nombre >= 2000 && Nombre <= 999999)
    {
        return NombreToText(Nombre / 1000) + " Mille " + NombreToText(Nombre % 1000);
    }
    else if (Nombre >= 1000000 && Nombre <= 1999999)
    {
        return " Million " + NombreToText(Nombre % 1000000);
    }
    else if (Nombre >= 2000000 && Nombre <= 999999999)
    {
        return NombreToText(Nombre / 1000000) + " Millions " + NombreToText(Nombre % 1000000);
    }
    else if (Nombre >= 1000000000 && Nombre <= 1999999999)
    {
        return " Millard " + NombreToText(Nombre % 1000000000);
    }
    else 
    {
        return NombreToText(Nombre / 1000000000) + " Millards " + NombreToText(Nombre % 1000000000);
    }
    
}
int ReadNombre(string message)
{
    int Nombre;
    do
    {
        cout << message << endl;
        cin >> Nombre;
    } while (Nombre < 0);
    return Nombre;

}

int main()
{
    int Nombre = ReadNombre("Saisir un nombre positive");
    cout << "Le nombre est: " << NombreToText(Nombre);

}
