#include <iostream>
#include <string>

using namespace std;

int CalorderJour(int Anne, int Mois, int Jour)
{
    int a = 0, y = 0, m = 0, d = 0;
    a = (14 - Mois) / 12;
    y = Anne - a;
    m = Mois + 12 * a - 2;
    return (Jour + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;
     
}

string NomJour(int OrderJour)
{
    string arr[] = {"Dim", "Lun", "Mar", "Mer", "Jeu", "Ven", "Sam"};

    return arr[OrderJour];

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
    int Anne = ReadNombre("Saisir l'annee");
    int Mois = ReadNombre("Saisir le mois");
    int Jour = ReadNombre("Saisir le jour");
    

    cout << "La date est: " << Jour << " / " << Mois << " / " << Anne << endl;
    cout << "L'ordre de jour est " << CalorderJour(Anne, Mois, Jour) << endl;
    cout << "Le nom de jour est " << NomJour(CalorderJour(Anne, Mois, Jour)) << endl;
    system("pause");
}
 