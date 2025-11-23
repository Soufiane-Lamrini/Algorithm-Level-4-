#include <iostream>
#include <ctime>

using namespace std;

// Structure pour représenter une date
struct sDate {
    short Annee;
    short Mois;
    short Jour;
};

// Vérifie si une année est bissextile
bool EstBissextile(short Annee) {
    return (Annee % 4 == 0 && Annee % 100 != 0) || (Annee % 400 == 0);
}

// Renvoie le nombre de jours dans un mois
short NombreJoursDansMois(short Mois, short Annee) {
    if (Mois < 1 || Mois > 12) return 0;
    int jours[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
    return (Mois == 2) ? (EstBissextile(Annee) ? 29 : 28) : jours[Mois - 1];
}

// Lire une date depuis l'utilisateur
sDate LireDate() {
    sDate Date;
   
        cout << "Saisir l'annee : ";
        cin >> Date.Annee;

        cout << "Saisir le mois : ";
        cin >> Date.Mois;

        cout << "Saisir le jour : ";
        cin >> Date.Jour;

    

    return Date;
}

bool DateValide(sDate Date)
{
    if (Date.Jour < 1 || Date.Jour>31)
        return false;

   
    if (Date.Mois > 12 || Date.Mois < 1)
        return false;

    if (Date.Mois == 2)
    {
        if (EstBissextile(Date.Annee))
        {
            if (Date.Jour > 29)
                return false;
        }
        else
        {
            if (Date.Jour > 28)
                return false;
        }
        
    }
    if (Date.Jour > NombreJoursDansMois(Date.Mois, Date.Annee))
    {
        return false;
    }
    return true;
}

// Fonction principale
int main() {
    
    sDate Date;
    cout << "Saisir la date a verifier: " << endl;
      
    Date = LireDate();
    if (DateValide(Date))
        cout << "La date est valide" << endl;
    else
        cout << "La date est incorrect" << endl;
    system("pause>0");
    return 0;
}
