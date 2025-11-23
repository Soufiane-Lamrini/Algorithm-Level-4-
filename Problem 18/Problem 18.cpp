#include <iostream>
#include <string>
#include <ctime>

#pragma warning (disable : 4996)?

using namespace std;

struct sDate {
    int Anne;
    int Mois;
    int Jour;
};
bool isLeapYear(short Anne) {
    return (Anne % 4 == 0 && Anne % 100 != 0) || (Anne % 400 == 0);
}
short NumberOfDaysInAMonth(short Mois, short Anne) {
    if (Mois < 1 || Mois>12)
        return  0;
    int days[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
    return (Mois == 2) ? (isLeapYear(Anne) ? 29 : 28) : days[Mois - 1];
}
int ReadNombre(string message, short from, short to)
{
    int Nombre;
    do {
        cout << message << endl;
        cin >> Nombre;
    } while (Nombre < from || Nombre > to);
    return Nombre;
}
sDate ReadDate()
{
    sDate Date;
    Date.Anne = ReadNombre("Saisir l'annee ", 0, 1000000);
    Date.Mois = ReadNombre("Saisir le mois ", 1, 12);
    short maxJour = NumberOfDaysInAMonth(Date.Mois, Date.Anne);
    Date.Jour = ReadNombre("Saisir le jour ", 1, maxJour);
    return Date;
}

bool JourEstDernierJourMois(sDate Date)
{
    return (Date.Jour == NumberOfDaysInAMonth(Date.Mois, Date.Anne));
}
bool MoisEstDernierMoisAnne(sDate Date)
{
    return (Date.Mois == 12);
}

sDate IncraseDateByOneDay(sDate Date)
{
    if (JourEstDernierJourMois(Date))
        if (MoisEstDernierMoisAnne(Date))
        {
            Date.Jour = 1;
            Date.Mois = 1;
            Date.Anne++;
        }
        else {
            Date.Jour = 1;
            Date.Mois++;
        }
    else
    {
        Date.Jour++;
    }
    return Date;
}
bool Date1EstAvantDate2(sDate Date1, sDate Date2)
{
    return (Date1.Anne < Date2.Anne) ? true : ((Date1.Anne == Date2.Anne) ? (Date1.Mois < Date2.Mois) ? true : (Date1.Mois == Date2.Mois) ? (Date1.Jour < Date2.Jour) : true : false);
}

short GetDifferenceInDays(sDate Date1, sDate Date2, bool IncludeEndDays = false)
{
    short Days = 0;
    while (Date1EstAvantDate2(Date1, Date2))
    {
        Days++;
        Date1 = IncraseDateByOneDay(Date1);
    }
    return (IncludeEndDays ? ++Days : Days);
}
sDate GetDateNow()
{
    sDate DateNow;

    time_t t = time(0);
    tm* now = localtime(&t);

    DateNow.Anne = now->tm_year + 1900;
    DateNow.Mois = now->tm_mon + 1;
    DateNow.Jour = now->tm_mday;

    return DateNow;
}
int main()
{
    cout << "Saisir votre date de naissance s'il vous plait: " << endl;
    sDate Date1 = ReadDate();
    
    sDate DateNow = GetDateNow();
    cout << "Votre age est: " << GetDifferenceInDays(Date1, DateNow) << endl;
    cout << "Votre age en inclant le dernier jour est: " << GetDifferenceInDays(Date1, DateNow, true) << endl;

    system("pause");
    return 0;
}