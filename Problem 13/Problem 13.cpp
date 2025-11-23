#include <iostream>
#include <string>

using namespace std;

struct sDate {
    int Anne;
    int Mois;
    int Jour;
};

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
    Date.Anne = ReadNombre("Saisir l'annee ",1900, 1000000);
    Date.Mois = ReadNombre("Saisir le mois ",1,12);
    Date.Jour = ReadNombre("Saisir le jour ",1,31);
    return Date;
}

bool Date1EstAvantDate2(sDate Date1, sDate Date2)
{
    return (Date1.Anne < Date2.Anne) ? true : ((Date1.Anne == Date2.Anne) ? (Date1.Mois < Date2.Mois) ? true : (Date1.Mois == Date2.Mois) ? (Date1.Jour < Date2.Jour) : true : false);
}
int main()
{
    cout << "Saisir la date 1: " << endl;
    sDate Date1 = LireDate();
    cout << "Saisir la date 2: " << endl;
    sDate Date2 = LireDate();
       
    if (Date1EstAvantDate2(Date1, Date2))
        cout << "Date 1 est avant Date 2" << endl;
    else
        cout << "Date 2 est avant Date 1" << endl;
    system("pause");
    return 0;
}
