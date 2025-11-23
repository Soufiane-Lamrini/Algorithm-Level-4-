#include <iostream>
#include <string>

using namespace std;


bool estBissextile(int Anne)
{
    return (Anne % 4 == 0 && Anne % 100 != 0) || (Anne % 400 == 0);
}

int CalNombreJour(int Anne, int Mois)
{
    int NumberOfDays[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
    return (Mois == 2) ? (estBissextile(Anne) ? 29 : 28) : NumberOfDays[Mois];
}

int CalOrderJourDepuisDebut(int Anne, int Mois, int Jour)
{
    int NombreJour = 0;
    for (int i = 1; i < Mois; i++)
    {
        NombreJour = NombreJour +CalNombreJour(Anne, i);
    }
    NombreJour = NombreJour+Jour;
    return NombreJour;
}

int ReadNombre(string message)
{
    int Nombre;
    do {
        cout << message << endl;
        cin >> Nombre;
    } while (Nombre <= 0);
    return Nombre;
}

int main()
{
    int Anne = ReadNombre("Saisir l'annee ");
    int Mois = ReadNombre("Saisir le mois ");
    int Jour = ReadNombre("Saisir le jour ");

    cout << "Voici le nombre des jour depuis le debut: " << CalOrderJourDepuisDebut(Anne, Mois, Jour) << endl;

    system("pause");
    return 0;
}
