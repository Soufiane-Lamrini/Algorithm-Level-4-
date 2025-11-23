#include <iostream>
#include <string>

using namespace std;

int CalorderJour(int Anne, int Mois, int Jour)
{
    int a = (14 - Mois) / 12;
    int y = Anne - a;
    int m = Mois + 12 * a - 2;
    return (Jour + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;
}

bool estBissextile(int Anne)
{
    return (Anne % 4 == 0 && Anne % 100 != 0) || (Anne % 400 == 0);
}

int CalNombreJour(int Anne, int Mois)
{
    int NumberOfDays[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
    return (Mois == 2) ? (estBissextile(Anne) ? 29 : 28) : NumberOfDays[Mois];
}

string NomMois(int Mois)
{
    string ArrayMois[] = { "Jan", "Fev", "Mar", "Avr", "Mai", "Juin", "Juill", "Aout", "Sep", "Oct", "Nov", "Dec" };
    return ArrayMois[Mois - 1];
}

void AfficherCalendrie(int Anne, int Mois)
{
    int OrdrePremierJour = CalorderJour(Anne, Mois, 1);
    int NombreJour = CalNombreJour(Anne, Mois);

    printf("\n _______________%s_______________\n\n", NomMois(Mois).c_str());
    printf("  Dim  Lun  Mar  Mer  Jeu  Ven  Sam\n");

    int i;
    for (i = 0; i < OrdrePremierJour; i++)
        printf("     ");

    for (int j = 1; j <= NombreJour; j++)
    {
        printf("%5d", j);
        if (++i == 7)
        {
            printf("\n");
            i = 0;
        }
    }

    printf("\n_________________________________\n");
}

int ReadNombre(string message)
{
    int Nombre;
    do {
        cout << message << endl;
        cin >> Nombre;
    } while (Nombre <= 0);
    return Nombre;
}

int main()
{
    int Anne = ReadNombre("Saisir l'annee");
    int Mois = ReadNombre("Saisir le mois (1 à 12)");

    if (Mois < 1 || Mois > 12)
    {
        cout << "Mois invalide !" << endl;
        return 1;
    }

    AfficherCalendrie(Anne, Mois);
    system("pause");
    return 0;
}
