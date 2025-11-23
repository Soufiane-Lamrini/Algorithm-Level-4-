#pragma warning(disable : 4996)

#include <iostream>
#include <ctime>
using namespace std;

struct sDate
{
    short Annee;
    short Mois;
    short Jour;
};

bool EstAnneeBissextile(short Annee)
{
    return (Annee % 4 == 0 && Annee % 100 != 0) || (Annee % 400 == 0);
}

bool Date1AvantDate2(sDate Date1, sDate Date2)
{
    return (Date1.Annee < Date2.Annee) ? true :
        ((Date1.Annee == Date2.Annee) ?
            (Date1.Mois < Date2.Mois ? true :
                (Date1.Mois == Date2.Mois ? Date1.Jour < Date2.Jour : false))
            : false);
}

bool Date1EgalDate2(sDate Date1, sDate Date2)
{
    return (Date1.Annee == Date2.Annee) ?
        ((Date1.Mois == Date2.Mois) ?
            ((Date1.Jour == Date2.Jour) ? true : false)
            : false)
        : false;
}
bool Date1ApresDate2(sDate Date1, sDate Date2)
{
    return (!Date1AvantDate2(Date1, Date2) && !Date1EgalDate2(Date1, Date2));
}
short NombreDeJoursDansMois(short Mois, short Annee)
{
    if (Mois < 1 || Mois > 12) return 0;
    int jours[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
    return (Mois == 2) ? (EstAnneeBissextile(Annee) ? 29 : 28) : jours[Mois - 1];
}

sDate LireDate()
{
    sDate Date;
    bool valide = false;

    while (!valide)
    {
        cout << "Saisir l'annee : ";
        cin >> Date.Annee;

        cout << "Saisir le mois : ";
        cin >> Date.Mois;

        cout << "Saisir le jour : ";
        cin >> Date.Jour;

        if (Date.Annee >= 1 &&
            Date.Mois >= 1 && Date.Mois <= 12 &&
            Date.Jour >= 1 && Date.Jour <= NombreDeJoursDansMois(Date.Mois, Date.Annee))
        {
            valide = true;
        }
        else
        {
            cout << "\nDate invalide. Veuillez reessayer.\n\n";
        }
    }

    return Date;
}

int main()
{

    cout << "Saisir la date 1: \n";
    sDate Date1 = LireDate();

    cout << "Saisir la date 2: \n";
    sDate Date2 = LireDate();


    if (Date1AvantDate2(Date1, Date2))
    {
        cout << "Date 1 est avant Date 2" << endl;
    }
    else 
    {
        cout << "Date 1 est n'a pas avant Date 2" << endl;
    }
    system("pause>0");
    return 0;
}
