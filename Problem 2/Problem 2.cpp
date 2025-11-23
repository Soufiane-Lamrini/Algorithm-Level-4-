#include <iostream>
#include <string>

using namespace std;

bool isBissextile(int Nombre)
{
    if (Nombre % 4 == 0)
    {
        return true;
    }
    else if (Nombre % 100)
    {
        return false;
    }
    else if (Nombre % 400 == 0)
    {
        return true;
    }
    else
        return false;
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
    if (isBissextile(Nombre))
    {
        cout << " Bissextile." << endl;
    }
    else
        cout << "n'est pas une annee bissextile" << endl;

}
