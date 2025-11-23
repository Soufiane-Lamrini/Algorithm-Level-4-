#pragma warning(disable : 4996)

#include <iostream>
#include <ctime>

using namespace std;

struct sDate
{
	short Annee;
	short Mois;
	short Jour;
};

bool EstAnneeBissextile(short Annee)
{
	return (Annee % 4 == 0 && Annee % 100 != 0) || (Annee % 400 == 0);
}

bool Date1AvantDate2(sDate Date1, sDate Date2) {
	return (Date1.Annee < Date2.Annee) ? true :
		((Date1.Annee == Date2.Annee) ?
			(Date1.Mois < Date2.Mois ? true :
				(Date1.Mois == Date2.Mois ? Date1.Jour < Date2.Jour : false))
			: false);
}

short NombreDeJoursDansMois(short Mois, short Annee)
{
	if (Mois < 1 || Mois > 12) return 0;
	int jours[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	return (Mois == 2) ? (EstAnneeBissextile(Annee) ? 29 : 28) : jours[Mois - 1];
}

bool EstDernierJourDuMois(sDate Date)
{
	return (Date.Jour == NombreDeJoursDansMois(Date.Mois, Date.Annee));
}

bool EstDernierMoisDeLAnnee(short Mois)
{
	return (Mois == 12);
}

sDate IncrementerDateUnJour(sDate Date)
{
	if (EstDernierJourDuMois(Date))
	{
		if (EstDernierMoisDeLAnnee(Date.Mois))
		{
			Date.Mois = 1;
			Date.Jour = 1;
			Date.Annee++;
		}
		else
		{
			Date.Jour = 1;
			Date.Mois++;
		}
	}
	else
	{
		Date.Jour++;
	}
	return Date;
}

int DifferenceEnJours(sDate Date1, sDate Date2, bool InclureDernierJour = false)
{
	int Jours = 0;
	while (Date1AvantDate2(Date1, Date2))
	{
		Jours++;
		Date1 = IncrementerDateUnJour(Date1);
	}
	return InclureDernierJour ? ++Jours : Jours;
}

short OrdreJourSemaine(short Jour, short Mois, short Annee) {
	short a, y, m;
	a = (14 - Mois) / 12;
	y = Annee - a;
	m = Mois + (12 * a) - 2;
	return (Jour + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;
}

short OrdreJourSemaine(sDate Date)
{
	return OrdreJourSemaine(Date.Jour, Date.Mois, Date.Annee);
}

string NomCourtJour(short OrdreJour)
{
	string NomsJours[] = {"Lun", "Mar", "Mer", "Jeu", "Ven", "Sam", "Dim" };
	return NomsJours[OrdreJour];
}

bool EstFinDeSemaine(sDate Date)
{
	return OrdreJourSemaine(Date) == 6; // Dimanche
}

bool EstWeekend(sDate Date)
{
	short Ordre = OrdreJourSemaine(Date);
	return (Ordre == 5 || Ordre == 6); // Dimanche ou Samedi
}

bool EstJourTravaille(sDate Date)
{
	return !EstWeekend(Date);
}

short JoursJusquaFinDeSemaine(sDate Date)
{
	return 6 - OrdreJourSemaine(Date);
}

short JoursJusquaFinDuMois(sDate Date)
{
	sDate FinMois;
	FinMois.Jour = NombreDeJoursDansMois(Date.Mois, Date.Annee);
	FinMois.Mois = Date.Mois;
	FinMois.Annee = Date.Annee;
	return DifferenceEnJours(Date, FinMois, true);
}

short JoursJusquaFinAnnee(sDate Date)
{
	sDate FinAnnee;
	FinAnnee.Jour = 31;
	FinAnnee.Mois = 12;
	FinAnnee.Annee = Date.Annee;
	return DifferenceEnJours(Date, FinAnnee, true);
}

sDate ObtenirDateSysteme()
{
	sDate Date;
	time_t t = time(0);
	tm* maintenant = localtime(&t);
	Date.Annee = maintenant->tm_year + 1900;
	Date.Mois = maintenant->tm_mon + 1;
	Date.Jour = maintenant->tm_mday;
	return Date;
}

int main() {
	sDate DateAuj = ObtenirDateSysteme();

	cout << "\nAujourd'hui c'est " << NomCourtJour(OrdreJourSemaine(DateAuj)) << " , " << DateAuj.Jour << "/" << DateAuj.Mois << "/" << DateAuj.Annee << endl;

	cout << "\nEst-ce la fin de semaine ?\n";
	if (EstFinDeSemaine(DateAuj))
		cout << "Oui, c'est samedi, fin de semaine.";
	else
		cout << "Non, ce n'est pas la fin de semaine.";

	cout << "\n\nEst-ce le week-end ?\n";
	if (EstWeekend(DateAuj))
		cout << "Oui, c'est le week-end.";
	else
		cout << "Non, aujourd'hui c'est " << NomCourtJour(OrdreJourSemaine(DateAuj)) << ", ce n'est pas le week-end.";

	cout << "\n\nEst-ce un jour ouvrable ?\n";
	if (EstJourTravaille(DateAuj))
		cout << "Oui, c'est un jour ouvrable.";
	else
		cout << "Non, ce n'est pas un jour ouvrable.";

	cout << "\n\nJours restants jusqu'à la fin de la semaine : " << JoursJusquaFinDeSemaine(DateAuj) << " jour(s).";
	cout << "\nJours restants jusqu'à la fin du mois : " << JoursJusquaFinDuMois(DateAuj) << " jour(s).";
	cout << "\nJours restants jusqu'à la fin de l'année : " << JoursJusquaFinAnnee(DateAuj) << " jour(s).";

	system("pause>0");
	return 0;
}
