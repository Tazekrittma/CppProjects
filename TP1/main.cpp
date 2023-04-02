#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <iostream>
#include <windows.h>


using namespace std;




class Horloge
{
	protected:
		unsigned Th,Tm,Ts;
		unsigned Ah,Am;
	public:
		Horloge();
		~Horloge();

		void afficher();
		void getTime();
		void setAlarme(unsigned heure,unsigned minute);
		bool getAlarme();
		void setTime(unsigned heure, unsigned minute, unsigned jour);
};

 Horloge :: Horloge()
{
	Th=0;Tm=0;Ts=0;Ah=0;Am=0;
}

 Horloge :: ~Horloge()
 {
	cout<<"objet dtruit"<<endl;
 }

 void Horloge :: afficher()
 {
	cout<<Th<<":"<<Tm<<":"<<Ts<<endl;
 }

 void Horloge :: getTime()
 {
	SYSTEMTIME time1;
	GetLocalTime(&time1);

	Th=time1.wHour;
	Tm=time1.wMinute;
	Ts=time1.wSecond;
 }

 void Horloge :: setAlarme(unsigned heure,unsigned minute)
 {
	Ah = heure;
	Am = minute;
 }

 bool Horloge :: getAlarme()
 {
	if ((Th == Ah) && (Tm == Am))
	{
		return true;
	}
	else return false;
 }

 void Horloge :: setTime(unsigned heure, unsigned minute, unsigned sec)
 {
	SYSTEMTIME time2;

	GetLocalTime(&time2);

	time2.wHour=heure;
	time2.wMinute=minute;
	time2.wSecond=sec;

	SetLocalTime(&time2);
 }

void main()
{
	Horloge temp;

	temp.setAlarme(12,13);
	temp.setTime(12,  12,  12);

	while(true)
	{
		temp.getTime();
		temp.afficher();
		Sleep(1000);

		if (kbhit()) // quitter
		{
			if (getch() == 27) break;
		}

		if( temp.getAlarme() == true) //Alarm
		{
			Beep(1000,500);
		}

	}
}