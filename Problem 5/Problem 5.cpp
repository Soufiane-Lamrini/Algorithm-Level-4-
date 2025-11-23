#include <iostream>
#include <string>

using namespace std;

bool estBissextile(int Anne)
{
    return (Anne % 4 == 0 && Anne % 100 != 0) || (Anne % 400 == 0);
}
int CalNombreJour(int Anne, int Mois)
{
    if (Mois < 1 || Mois>12)
    {
        return 0;
    }
     if (Mois == 2)
    {
         return (estBissextile(Anne)) ? 29 : 28;       
    }
     short arr31Days[7] = { 1,3,5,7,8,10,12 };
     for (short i = 1; i <= 7; i++)
     {
         if (arr31Days[i - 1] == Mois)
             return 31;
     }
     return 30;
}

int CalNombreHeures(int Anne, int Mois)
{
    return CalNombreJour(Anne, Mois) * 24;
}
int CalNombreMinutes(int Anne, int Mois)
{
    return CalNombreHeures(Anne, Mois) * 60;
}
int CalNombreSecound(int Anne, int Mois)
{
    return CalNombreMinutes(Anne, Mois) * 60;
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
    cout << "Le nombre est: ";

    cout << "Nombre des secoundes est : " << CalNombreSecound(Anne, Mois) << endl;
    cout << "Nombre des Minutes est   : " << CalNombreMinutes(Anne, Mois) << endl;
    cout << "Nombre des Heures est    : " << CalNombreHeures(Anne, Mois) << endl;
    cout << "Nombre des Jour est      : " << CalNombreJour(Anne, Mois) << endl;
}
