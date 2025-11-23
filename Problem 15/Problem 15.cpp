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
    return (Mois == 2) ? (isLeapYear(Mois) ? 29 : 28) : days[Mois - 1];
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
sDate LireDate()
{
    sDate Date;
    Date.Anne = ReadNombre("Saisir l'annee ", 0, 1000000);
    Date.Mois = ReadNombre("Saisir le mois ", 1, 12);
    Date.Jour = ReadNombre("Saisir le jour ", 1, 31);
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
int main()
{
    cout << "Saisir la date : " << endl;
    sDate Date1 = LireDate();


    if (JourEstDernierJourMois(Date1))
        cout << "Ce jour est le dernier jour de le mois." << endl;
    else
        cout << "Ce jour n'est pas le dernier jour de le mois." << endl;
    if (MoisEstDernierMoisAnne(Date1))
        cout << "Ce mois est le dernier dans l'anne" << endl;
    else
        cout << "Ce mois n'est pas le dernier dans l'anne" << endl;

    system("pause");
    return 0;
}