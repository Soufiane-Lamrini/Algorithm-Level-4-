#include <iostream>
#include <string>

using namespace std;

bool estBissextile(int Anne)
{
    return (Anne % 4 == 0 && Anne % 100 != 0) || (Anne % 400 == 0);
}
int CalNombreJour(int Anne)
{
    return estBissextile(Anne) ? 366 : 365;
}
int CalNombreHeures(int Anne)
{
    return CalNombreJour(Anne) * 24;
}
int CalNombreMinutes(int Anne)
{
    return CalNombreHeures(Anne) * 60;
}
int CalNombreSecound(int Anne)
{
    return CalNombreMinutes(Anne) * 60;
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
    cout << "Le nombre est: ";
   
    cout << "Nombre des secoundes est : " << CalNombreSecound(Anne) << endl;
    cout << "Nombre des Minutes est   : " << CalNombreMinutes(Anne) << endl;
    cout << "Nombre des Heures est    : " << CalNombreHeures(Anne) << endl;
    cout << "Nombre des Jour est      : " << CalNombreJour(Anne) << endl;
}
