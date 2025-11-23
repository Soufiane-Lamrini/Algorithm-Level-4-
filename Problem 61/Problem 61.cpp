#include <iostream>
#include <ctime>

using namespace std;

// Structure pour représenter une date
struct tDate {
    short Annee;
    short Mois;
    short Jour;
};

// Structure pour représenter une période (deux dates)
struct tPeriode {
    tDate DateDebut;
    tDate DateFin;
};

// Vérifie si une année est bissextile
bool EstBissextile(short Annee) {
    return (Annee % 4 == 0 && Annee % 100 != 0) || (Annee % 400 == 0);
}

// Compare deux dates : Date1 est-elle avant Date2 ?
bool EstAvant(tDate Date1, tDate Date2) {
    return (Date1.Annee < Date2.Annee) ? true :
        ((Date1.Annee == Date2.Annee) ?
            (Date1.Mois < Date2.Mois ? true :
                (Date1.Mois == Date2.Mois ? Date1.Jour < Date2.Jour : false))
            : false);
}

// Compare deux dates : sont-elles égales ?
bool EstEgal(tDate Date1, tDate Date2) {
    return (Date1.Annee == Date2.Annee &&
        Date1.Mois == Date2.Mois &&
        Date1.Jour == Date2.Jour);
}

// Compare deux dates : Date1 est-elle après Date2 ?
bool EstApres(tDate Date1, tDate Date2) {
    return (!EstAvant(Date1, Date2) && !EstEgal(Date1, Date2));
}

// Renvoie le nombre de jours dans un mois
short NombreJoursDansMois(short Mois, short Annee) {
    if (Mois < 1 || Mois > 12) return 0;
    int jours[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
    return (Mois == 2) ? (EstBissextile(Annee) ? 29 : 28) : jours[Mois - 1];
}

// Lire une date depuis l'utilisateur
tDate LireDate() {
    tDate Date;
    bool valide = false;

    while (!valide) {
        cout << "Saisir l'annee : ";
        cin >> Date.Annee;

        cout << "Saisir le mois : ";
        cin >> Date.Mois;

        cout << "Saisir le jour : ";
        cin >> Date.Jour;

        if (Date.Annee >= 1 &&
            Date.Mois >= 1 && Date.Mois <= 12 &&
            Date.Jour >= 1 && Date.Jour <= NombreJoursDansMois(Date.Mois, Date.Annee)) {
            valide = true;
        }
        else {
            cout << "\nDate invalide. Veuillez réessayer.\n\n";
        }
    }

    return Date;
}

// Enumération pour comparaison des dates
enum ComparaisonDate { Avant = -1, Egal = 0, Apres = 1 };

// Fonction pour comparer deux dates
ComparaisonDate ComparerDates(tDate D1, tDate D2) {
    if (EstAvant(D1, D2)) return Avant;
    if (EstEgal(D1, D2)) return Egal;
    return Apres;
}

// Vérifie si deux périodes se chevauchent
bool SeChevauchent(tPeriode P1, tPeriode P2) {
    if (ComparerDates(P1.DateDebut, P2.DateFin) == Apres ||
        ComparerDates(P1.DateFin, P2.DateDebut) == Avant)
        return false;
    return true;
}

// Lire une période
tPeriode LirePeriode() {
    tPeriode Periode;
    cout << "Saisir la date de debut :\n";
    Periode.DateDebut = LireDate();
    cout << "Saisir la date de fin :\n";
    Periode.DateFin = LireDate();
    return Periode;
}

// Est-ce le dernier jour du mois ?
bool EstDernierJourDuMois(tDate Date) {
    return (Date.Jour == NombreJoursDansMois(Date.Mois, Date.Annee));
}

// Est-ce le dernier mois de l'année ?
bool EstDernierMois(short Mois) {
    return (Mois == 12);
}

// Incrémenter une date d’un jour
tDate AjouterUnJour(tDate Date) {
    if (EstDernierJourDuMois(Date)) {
        if (EstDernierMois(Date.Mois)) {
            Date.Mois = 1;
            Date.Jour = 1;
            Date.Annee++;
        }
        else {
            Date.Jour = 1;
            Date.Mois++;
        }
    }
    else {
        Date.Jour++;
    }
    return Date;
}

// Calculer le nombre de jours entre deux dates
int DifferenceEnJours(tDate D1, tDate D2, bool InclureDernierJour = false) {
    int nbJours = 0;
    while (EstAvant(D1, D2)) {
        nbJours++;
        D1 = AjouterUnJour(D1);
    }
    return InclureDernierJour ? ++nbJours : nbJours;
}

// Calcul de la durée d’une période
int DureePeriode(tPeriode P, bool InclureDernierJour = false) {
    return DifferenceEnJours(P.DateDebut, P.DateFin, InclureDernierJour);
}

// Vérifie si une date est dans une période
bool EstDansPeriode(tDate D, tPeriode P) {
    return !(ComparerDates(D, P.DateDebut) == Avant ||
        ComparerDates(D, P.DateFin) == Apres);
}

// Calculer le nombre de jours de chevauchement entre deux périodes
short NombreJoursChevauchement(tPeriode P1, tPeriode P2) {
    if (!SeChevauchent(P1, P2)) return 0;

    tDate DateDebut = (EstApres(P1.DateDebut, P2.DateDebut)) ? P1.DateDebut : P2.DateDebut;
    tDate DateFin = (EstAvant(P1.DateFin, P2.DateFin)) ? P1.DateFin : P2.DateFin;

    return DifferenceEnJours(DateDebut, DateFin, true);
}

// Fonction principale
int main() {
    cout << "Saisir la periode 1 :\n";
    tPeriode Periode1 = LirePeriode();

    cout << "Saisir la periode 2 :\n";
    tPeriode Periode2 = LirePeriode();

    if (SeChevauchent(Periode1, Periode2))
        cout << "Les deux periodes se chevauchent sur : "
        << NombreJoursChevauchement(Periode1, Periode2)
        << " jour(s)" << endl;
    else
        cout << "Les deux periodes ne se chevauchent pas." << endl;

    system("pause>0");
    return 0;
}
