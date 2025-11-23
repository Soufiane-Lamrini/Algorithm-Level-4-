#include <iostream>
#include <string>

using namespace std;

bool estBissextile(int Nombre)
{
    return (Nombre % 4 == 0 && Nombre % 100 != 0) || (Nombre % 400 == 0);
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
    int Nombre = ReadNombre("Saisir l'annee");
    cout << "Le nombre est: ";
    if (estBissextile(Nombre))
    {
        cout << " Bissextile." << endl;
    }
    else
        cout << "n'est pas une annee bissextile" << endl;

}
