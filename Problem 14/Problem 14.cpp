#include<iostream>
using namespace std; 
struct stDate
{
	short Anne;
	short Mois;
	short Jour;
};

bool IsDate1EqualDate2(stDate Date1, stDate Date2) 
{ 
	return  (Date1.Anne == Date2.Anne) ? ((Date1.Mois == Date2.Mois) ? ((Date1.Jour == Date2.Jour) ? true : false) : false) : false; 
} 
short ReadDay()
{ 
	short Day;    
	cout << "\nEnterz le jour? ";  
	cin >> Day; 
	return Day; 
} 
short ReadMonth()
{ 
	short Month;     
	cout << "Enterz le Mois? ";     
	cin >> Month; 
	return Month; 
} 
short ReadYear()
{ 
	short Year;    
	cout << "Enterz l'anne? ";
	cin >> Year;
	return Year;
}
stDate ReadFullDate()
{
	stDate Date;  
	Date.Jour = ReadDay();   
	Date.Mois = ReadMonth();    
	Date.Anne = ReadYear();
	return Date; 
} 
int main() 
{ 
	stDate Date1 = ReadFullDate();
	stDate Date2 = ReadFullDate();
	if (IsDate1EqualDate2(Date1, Date2))     
		cout << "\nOui, Date1 et egale la Date2."; 
	else        
		cout << "\nNo, Date1 n'est egale pas Date2."; 
	system("pause>0"); 
	return 0; 
}