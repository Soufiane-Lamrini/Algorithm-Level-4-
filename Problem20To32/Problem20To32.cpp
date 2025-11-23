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
    if (Mois < 1 || Mois > 12)
        return 0;
    int days[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
    return (Mois == 2) ? (isLeapYear(Anne) ? 29 : 28) : days[Mois - 1];
}

int ReadNombre(string message, short from, short to) {
    int Nombre;
    do {
        cout << message << endl;
        cin >> Nombre;
    } while (Nombre < from || Nombre > to);
    return Nombre;
}

sDate ReadDate() {
    sDate Date;
    Date.Anne = ReadNombre("Saisir l'annee ", 0, 1000000);
    Date.Mois = ReadNombre("Saisir le mois ", 1, 12);
    short maxJour = NumberOfDaysInAMonth(Date.Mois, Date.Anne);
    Date.Jour = ReadNombre("Saisir le jour ", 1, maxJour);
    return Date;
}

bool JourEstDernierJourMois(sDate Date) {
    return (Date.Jour == NumberOfDaysInAMonth(Date.Mois, Date.Anne));
}

bool MoisEstDernierMoisAnne(sDate Date) {
    return (Date.Mois == 12);
}

sDate IncreaseDateByOneDay(sDate Date) {
    if (JourEstDernierJourMois(Date))
        if (MoisEstDernierMoisAnne(Date)) {
            Date.Jour = 1;
            Date.Mois = 1;
            Date.Anne++;
        }
        else {
            Date.Jour = 1;
            Date.Mois++;
        }
    else {
        Date.Jour++;
    }
    return Date;
}

sDate IncreaseDateByXDays(sDate Date, short NombDay) {
    for (int i = 0; i < NombDay; i++) {
        Date = IncreaseDateByOneDay(Date);
    }
    return Date;
}

sDate IncreaseDateByOneWeek(sDate Date) {
    for (int i = 0; i < 7; i++) {
        if (JourEstDernierJourMois(Date))
            if (MoisEstDernierMoisAnne(Date)) {
                Date.Jour = 1;
                Date.Mois = 1;
                Date.Anne++;
            }
            else {
                Date.Jour = 1;
                Date.Mois++;
            }
        else {
            Date.Jour++;
        }
    }
    return Date;
}

sDate IncreaseDateByXWeeks(sDate Date, short NombWeeks) {
    for (int i = 0; i < NombWeeks; i++) {
        Date = IncreaseDateByOneWeek(Date);
    }
    return Date;
}

sDate IncreaseDateByOneMonth(sDate Date) {
    if (MoisEstDernierMoisAnne(Date)) {
        Date.Mois = 1;
        Date.Anne++;
    }
    else {
        Date.Mois++;
    }
    if (Date.Jour > NumberOfDaysInAMonth(Date.Mois, Date.Anne)) {
        Date.Jour = NumberOfDaysInAMonth(Date.Mois, Date.Anne);
    }
    return Date;
}

sDate IncreaseDateByXMonths(sDate Date, short NumMonths) {
    for (int i = 0; i < NumMonths; i++) {
        Date = IncreaseDateByOneMonth(Date);
    }
    return Date;
}

sDate IncreaseDateByOneYear(sDate Date) {
    Date.Anne++;
    return Date;
}

sDate IncreaseDateByXYears(sDate Date, short NumYears) {
    for (int i = 0; i < NumYears; i++) {
        Date = IncreaseDateByOneYear(Date);
    }
    return Date;
}

sDate IncreaseDateByXYearsFaster(sDate Date, short NumYears) {
    Date.Anne += NumYears;
    if (Date.Jour > NumberOfDaysInAMonth(Date.Mois, Date.Anne)) {
        Date.Jour = NumberOfDaysInAMonth(Date.Mois, Date.Anne);
    }
    return Date;
}

sDate IncreaseDateByOneDecade(sDate Date) {
    for (int i = 0; i < 10; i++) {
        Date.Anne++;
    }
    if (Date.Jour > NumberOfDaysInAMonth(Date.Mois, Date.Anne)) {
        Date.Jour = NumberOfDaysInAMonth(Date.Mois, Date.Anne);
    }
    return Date;
}

sDate IncreaseDateByXDecadesFaster(sDate Date, short NumDecades) {
    Date.Anne += NumDecades * 10;
    if (Date.Jour > NumberOfDaysInAMonth(Date.Mois, Date.Anne)) {
        Date.Jour = NumberOfDaysInAMonth(Date.Mois, Date.Anne);
    }
    return Date;
}

sDate IncreaseDateByXDecades(sDate Date, short NumDecades) {
    for (int i = 0; i < NumDecades; i++) {
        Date = IncreaseDateByOneDecade(Date);
    }
    return Date;
}

sDate IncreaseDateByOneCentury(sDate Date) {
    Date.Anne += 100;
    return Date;
}

sDate IncreaseDateByOneMillennium(sDate Date) {
    Date.Anne += 1000;
    return Date;
}

int main() {
    sDate Date = ReadDate();

    Date = IncreaseDateByOneDay(Date);
    cout << "La date apres le jour ajoutee sera: " << Date.Jour << "/" << Date.Mois << "/" << Date.Anne << endl;

    Date = IncreaseDateByXDays(Date, 10);
    cout << "La date apres les jours ajoutee sera: " << Date.Jour << "/" << Date.Mois << "/" << Date.Anne << endl;

    Date = IncreaseDateByOneWeek(Date);
    cout << "La date apres la semaine ajoutee sera: " << Date.Jour << "/" << Date.Mois << "/" << Date.Anne << endl;

    Date = IncreaseDateByXWeeks(Date, 10);
    cout << "La date apres les semaines ajoutees sera: " << Date.Jour << "/" << Date.Mois << "/" << Date.Anne << endl;

    Date = IncreaseDateByOneMonth(Date);
    cout << "La date apres le mois ajoutee sera: " << Date.Jour << "/" << Date.Mois << "/" << Date.Anne << endl;

    Date = IncreaseDateByXMonths(Date, 10);
    cout << "La date apres les mois ajoutees sera: " << Date.Jour << "/" << Date.Mois << "/" << Date.Anne << endl;

    Date = IncreaseDateByOneYear(Date);
    cout << "La date apres l'annee ajoutee sera: " << Date.Jour << "/" << Date.Mois << "/" << Date.Anne << endl;

    Date = IncreaseDateByXYears(Date, 10);
    cout << "La date apres les annees ajoutees sera: " << Date.Jour << "/" << Date.Mois << "/" << Date.Anne << endl;

    Date = IncreaseDateByXYearsFaster(Date, 10);
    cout << "La date apres les annees ajoutees (rapide) sera: " << Date.Jour << "/" << Date.Mois << "/" << Date.Anne << endl;

    Date = IncreaseDateByOneDecade(Date);
    cout << "La date apres un decennie ajoutee sera: " << Date.Jour << "/" << Date.Mois << "/" << Date.Anne << endl;

    Date = IncreaseDateByXDecades(Date, 10);
    cout << "La date apres les decennies ajoutees sera: " << Date.Jour << "/" << Date.Mois << "/" << Date.Anne << endl;

    Date = IncreaseDateByXDecadesFaster(Date, 10);
    cout << "La date apres les decennies ajoutees (rapide) sera: " << Date.Jour << "/" << Date.Mois << "/" << Date.Anne << endl;

    Date = IncreaseDateByOneCentury(Date);
    cout << "La date apres un siecle ajoutee sera: " << Date.Jour << "/" << Date.Mois << "/" << Date.Anne << endl;

    Date = IncreaseDateByOneMillennium(Date);
    cout << "La date apres un millenaire ajoutee sera: " << Date.Jour << "/" << Date.Mois << "/" << Date.Anne << endl;

    system("pause");
    return 0;
}
