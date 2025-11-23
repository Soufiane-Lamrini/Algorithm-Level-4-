#include <iostream>
#include <string>

using namespace std;

struct sDate {
    int Anne;
    int Mois;
    int Jour;
};

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
        NombreJour = NombreJour + CalNombreJour(Anne, i);
    }
    NombreJour = NombreJour + Jour;
    return NombreJour;
}
sDate DateApresNombreJoursAjoutee(int Jours, sDate Date)
{
    short RemainingDays = Jours+ CalOrderJourDepuisDebut(Date.Anne, Date.Mois, Date.Jour);
    short MonthDays = 0;
    Date.Mois = 1;
    while (true)
    {
        MonthDays = CalNombreJour(Date.Anne, Date.Mois);
        if (RemainingDays > MonthDays)
        {
            RemainingDays -= MonthDays;
            Date.Mois++;
            if (Date.Mois > 12)
            {
                Date.Mois = 1;
                Date.Anne++;
            }
        }
        else
        {
            Date.Jour = RemainingDays;
            break;
        }
    }
    return Date;
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
sDate LireDate()
{
    sDate Date;
   Date.Anne = ReadNombre("Saisir l'annee ");
   Date.Mois = ReadNombre("Saisir le mois ");
   Date.Jour = ReadNombre("Saisir le jour ");
   return Date;
}

int main()
{
    sDate Date = LireDate();
    short Jours = ReadNombre("Saisir nombre de jour que tu veux?");

    cout << "Voici le nombre des jour que tu ajoutee: " << Jours << endl;
     Date = DateApresNombreJoursAjoutee(Jours, Date);
    cout << "La date apres le nombre jours ajoutee est: " << Date.Anne << "/" << Date.Mois << "/" << Date.Jour << endl;

    system("pause");
    return 0;
}
