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

struct sPeriod
{
    sDate DateDebut;
    sDate DateFin;
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

bool EstDernierJourDuMois(sDate Date)
{
    return (Date.Jour == NombreDeJoursDansMois(Date.Mois, Date.Annee));
}

bool EstDernierMoisDeLAnnee(short Mois)
{
    return (Mois == 12);
}

sDate IncrementerDateUnJour(sDate Date)
{
    if (EstDernierJourDuMois(Date))
    {
        if (EstDernierMoisDeLAnnee(Date.Mois))
        {
            Date.Mois = 1;
            Date.Jour = 1;
            Date.Annee++;
        }
        else
        {
            Date.Jour = 1;
            Date.Mois++;
        }
    }
    else
    {
        Date.Jour++;
    }
    return Date;
}

int CalJours(sDate Date1, sDate Date2, bool InclureDernierJour = false)
{
    int Jours = 0;


    while (Date1AvantDate2(Date1, Date2))
    {
        Jours++;
        Date1 = IncrementerDateUnJour(Date1);
    }
    return (InclureDernierJour? ++Jours: Jours);
}

int CalJoursPeriod(sPeriod Period, bool InclureDernierJour = false)
{
    return CalJours(Period.DateDebut, Period.DateFin, InclureDernierJour);
}
sPeriod LirePeriod()
{
    sPeriod Period;

    cout << "Saisir la date Debut: \n";
    Period.DateDebut = LireDate();

    cout << "Saisir la date de fin: \n";
    Period.DateFin = LireDate();

    return Period;
}
int main()
{
    cout << "Saisir la period 1:" << endl;
    sPeriod Period1 = LirePeriod();
   
    cout << "Le nombre de jour de cette period est: " << CalJoursPeriod(Period1) << endl;

    cout << "Le nombre de jour de cette period en incluant le dernier jour : " << CalJoursPeriod(Period1, true) << endl;

    system("pause>0");
    return 0;
}
