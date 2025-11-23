#include <iostream>
#include <string>

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

sDate IncreaseDateByXDays(sDate Date, short NombDay)
{
    for (int i = 0; i < NombDay; i++)
    {
        Date = IncraseDateByOneDay(Date);
   }
    return Date;
}

int main()
{
    sDate Date = ReadDate();
    
    short NombDay = 0;
    cout << "Saisir le nombre de jour que tu veux ajoutee" << endl;
    cin >> NombDay;

    Date = IncreaseDateByXDays(Date, NombDay);
    cout << "La date apres le jour ajoutee sera: " << Date.Jour << "/" << Date.Mois << "/" << Date.Anne << endl;

    system("pause");
    return 0;
}