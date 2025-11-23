#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Structure pour représenter une date
struct sDate {
    int annee;
    int mois;
    int jour;
};

// Fonction pour lire une date depuis l'utilisateur
string lireDate(string message)
{
    string date;
    cout << message << endl;
    getline(cin >> ws, date); // ws pour ignorer les espaces blancs avant la saisie
    return date;
}

// Fonction pour découper une date avec un séparateur
vector<string> decouperDate(string date, string separateur)
{
    short position = 0;
    string mot;
    vector<string> morceauxDate;

    while ((position = date.find(separateur)) != string::npos)
    {
        mot = date.substr(0, position);
        if (mot != "")
        {
            morceauxDate.push_back(mot);
        }
        date.erase(0, position + separateur.length());
    }

    if (date != "")
    {
        morceauxDate.push_back(date);
    }

    return morceauxDate;
}

// Fonction pour remplir une structure Date à partir d'une chaîne
sDate remplirDateDepuisString(string chaineDate, string separateur)
{
    vector<string> vDate = decouperDate(chaineDate, separateur);
    sDate date;
    if (vDate.size() != 3) {
        cout << "Format de date invalide !" << endl;
        exit(1);
    }
    date.jour = stoi(vDate[0]);
    date.mois = stoi(vDate[1]);
    date.annee = stoi(vDate[2]);
    return date;
}

// Fonction pour convertir une structure Date en chaîne
string dateEnChaine(sDate date, string separateur)
{
    return to_string(date.jour) + separateur + to_string(date.mois) + separateur + to_string(date.annee);
}

// Fonction principale
int main() {
    sDate date;
    string chaineDate = lireDate("Saisir une date au format jj/mm/aaaa :");
    date = remplirDateDepuisString(chaineDate, "/");

    cout << "Jour : " << date.jour << endl;
    cout << "Mois : " << date.mois << endl;
    cout << "Annee : " << date.annee << endl;

    chaineDate = dateEnChaine(date, "/");
    cout << "Date complete : " << chaineDate << endl;

    system("pause>0"); // attend que l’utilisateur appuie sur une touche
    return 0;
}
