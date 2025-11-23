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

short NombreDeJoursDansMois(short Mois, short Annee)
{
    if (Mois < 1 || Mois > 12) return 0;
    int jours[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
    return (Mois == 2) ? (EstAnneeBissextile(Annee) ? 29 : 28) : jours[Mois - 1];
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

short OrdreJourSemaine(short Jour, short Mois, short Annee)
{
    short a = (14 - Mois) / 12;
    short y = Annee - a;
    short m = Mois + 12 * a - 2;
    return (Jour + y + y / 4 - y / 100 + y / 400 + (31 * m) / 12) % 7;
}

short OrdreJourSemaine(sDate Date)
{
    return OrdreJourSemaine(Date.Jour, Date.Mois, Date.Annee);
}

string NomCourtJour(short OrdreJour)
{
    string NomsJours[] = { "Dim", "Lun", "Mar", "Mer", "Jeu", "Ven", "Sam" };
    return NomsJours[OrdreJour];
}

bool EstWeekend(sDate Date)
{
    short Ordre = OrdreJourSemaine(Date);
    return (Ordre == 0 || Ordre == 6); 
}

sDate CalDateReturn(sDate Date1, short Jour)
{
    short WeekendCounter = 0;

    while (EstWeekend(Date1))
    {
        Date1 = IncrementerDateUnJour(Date1);
    }

    for (short i = 1; i <= Jour + WeekendCounter; i++)
    {
        if (EstWeekend(Date1))
            WeekendCounter++;
        Date1 = IncrementerDateUnJour(Date1);
    }
    while (EstWeekend(Date1))
    {
        Date1 = IncrementerDateUnJour(Date1);
    }
    
    return Date1;
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

void AfficherDate(sDate Date)
{
    cout << NomCourtJour(OrdreJourSemaine(Date)) << " " << Date.Jour << "/" << Date.Mois << "/" << Date.Annee;
}

int main()
{
    cout << "\n--- Saisie de la periode des vacances ---\n";

    cout << "Saisir la date de debut des vacances : \n";
    sDate DateDebut = LireDate();

    short Jour;
    cout << "Saisir le nombre des jours de vacances : ";
    cin >> Jour;

    cout << "\nVacances commencent : ";
    AfficherDate(DateDebut);
    cout << endl;

    sDate DateRetour = CalDateReturn(DateDebut, Jour);
    cout << "La date de retour est : ";
    AfficherDate(DateRetour);
    cout << endl;

    cout << "\nAppuyez sur Entrée pour quitter...";
    system("pause>0");
    return 0;
}
