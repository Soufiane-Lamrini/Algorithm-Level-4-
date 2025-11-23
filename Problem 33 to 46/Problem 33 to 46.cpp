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

sDate DecreaseDateByOneDay(sDate Date) {
    if (Date.Jour == 1)
        if (Date.Mois == 1)
        {
            Date.Jour = 31;
            Date.Mois = 12;
            Date.Anne--;
        }
        else {
            Date.Mois--;
            Date.Jour = NumberOfDaysInAMonth(Date.Mois, Date.Anne);
        }
    else {
        Date.Jour--;
    }
    return Date;
}

sDate DecreaseDateByXDays(sDate Date, short NombDay) {
    for (int i = 0; i < NombDay; i++) {
        Date = DecreaseDateByOneDay(Date);
    }
    return Date;
}

sDate DecreaseDateByOneWeek(sDate Date) {
    for (int i = 0; i < 7; i++) {
        Date = DecreaseDateByOneDay(Date);
    }
    return Date;
}

sDate DecreaseDateByXWeeks(sDate Date, short NombWeeks) {
    for (int i = 0; i < NombWeeks; i++) {
        Date = DecreaseDateByOneWeek(Date);
    }
    return Date;
}

sDate DecreaseDateByOneMonth(sDate Date) {
    if (Date.Mois == 1) {
        Date.Mois = 12;
        Date.Anne--;
    }
    else {
        Date.Mois--;
    }
    if (Date.Jour > NumberOfDaysInAMonth(Date.Mois, Date.Anne)) {
        Date.Jour = NumberOfDaysInAMonth(Date.Mois, Date.Anne);
    }
    return Date;
}

sDate DecreaseDateByXMonths(sDate Date, short NumMonths) {
    for (int i = 0; i < NumMonths; i++) {
        Date = DecreaseDateByOneMonth(Date);
    }
    return Date;
}

sDate DecreaseDateByOneYear(sDate Date) {
    Date.Anne--;
    return Date;
}

sDate DecreaseDateByXYears(sDate Date, short NumYears) {
    for (int i = 0; i < NumYears; i++) {
        Date = DecreaseDateByOneYear(Date);
    }
    return Date;
}

sDate DecreaseDateByXYearsFaster(sDate Date, short NumYears) {
    Date.Anne -= NumYears;
    if (Date.Jour > NumberOfDaysInAMonth(Date.Mois, Date.Anne)) {
        Date.Jour = NumberOfDaysInAMonth(Date.Mois, Date.Anne);
    }
    return Date;
}

sDate DecreaseDateByOneDecade(sDate Date) {
    for (int i = 0; i < 10; i++) {
        Date.Anne--;
    }
    if (Date.Jour > NumberOfDaysInAMonth(Date.Mois, Date.Anne)) {
        Date.Jour = NumberOfDaysInAMonth(Date.Mois, Date.Anne);
    }
    return Date;
}

sDate DecreaseDateByXDecadesFaster(sDate Date, short NumDecades) {
    Date.Anne -= NumDecades * 10;
    if (Date.Jour > NumberOfDaysInAMonth(Date.Mois, Date.Anne)) {
        Date.Jour = NumberOfDaysInAMonth(Date.Mois, Date.Anne);
    }
    return Date;
}

sDate DecreaseDateByXDecades(sDate Date, short NumDecades) {
    for (int i = 0; i < NumDecades; i++) {
        Date = DecreaseDateByOneDecade(Date);
    }
    return Date;
}

sDate DecreaseDateByOneCentury(sDate Date) {
    Date.Anne -= 100;
    return Date;
}

sDate DecreaseDateByOneMillennium(sDate Date) {
    Date.Anne -= 1000;
    return Date;
}

int main() {
    sDate Date = ReadDate();

    Date = DecreaseDateByOneDay(Date);
    cout << "La date apres la diminution d'un jour sera: " << Date.Jour << "/" << Date.Mois << "/" << Date.Anne << endl;

    Date = DecreaseDateByXDays(Date, 10);
    cout << "La date apres la diminution de 10 jours sera: " << Date.Jour << "/" << Date.Mois << "/" << Date.Anne << endl;

    Date = DecreaseDateByOneWeek(Date);
    cout << "La date apres la diminution d'une semaine sera: " << Date.Jour << "/" << Date.Mois << "/" << Date.Anne << endl;

    Date = DecreaseDateByXWeeks(Date, 10);
    cout << "La date apres la diminution de 10 semaines sera: " << Date.Jour << "/" << Date.Mois << "/" << Date.Anne << endl;

    Date = DecreaseDateByOneMonth(Date);
    cout << "La date apres la diminution d'un mois sera: " << Date.Jour << "/" << Date.Mois << "/" << Date.Anne << endl;

    Date = DecreaseDateByXMonths(Date, 5);
    cout << "La date apres la diminution de 5 mois sera: " << Date.Jour << "/" << Date.Mois << "/" << Date.Anne << endl;

    Date = DecreaseDateByOneYear(Date);
    cout << "La date apres la diminution d'une annee sera: " << Date.Jour << "/" << Date.Mois << "/" << Date.Anne << endl;

    Date = DecreaseDateByXYears(Date, 10);
    cout << "La date apres la diminution de 10 annees sera: " << Date.Jour << "/" << Date.Mois << "/" << Date.Anne << endl;

    Date = DecreaseDateByXYearsFaster(Date, 10);
    cout << "La date apres la diminution rapide de 10 annees sera: " << Date.Jour << "/" << Date.Mois << "/" << Date.Anne << endl;

    Date = DecreaseDateByOneDecade(Date);
    cout << "La date apres la diminution d'une decennie sera: " << Date.Jour << "/" << Date.Mois << "/" << Date.Anne << endl;

    Date = DecreaseDateByXDecades(Date, 10);
    cout << "La date apres la diminution de 10 decennies sera: " << Date.Jour << "/" << Date.Mois << "/" << Date.Anne << endl;

    Date = DecreaseDateByXDecadesFaster(Date, 10);
    cout << "La date apres la diminution rapide de 10 decennies sera: " << Date.Jour << "/" << Date.Mois << "/" << Date.Anne << endl;

    Date = DecreaseDateByOneCentury(Date);
    cout << "La date apres la diminution d'un siecle sera: " << Date.Jour << "/" << Date.Mois << "/" << Date.Anne << endl;

    Date = DecreaseDateByOneMillennium(Date);
    cout << "La date apres la diminution d'un millenaire sera: " << Date.Jour << "/" << Date.Mois << "/" << Date.Anne << endl;

    system("pause");
    return 0;
}
