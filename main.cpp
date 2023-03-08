#include <stdio.h>
#include <conio.h>
#include <string.h>

#include <iostream>
#define N 3

using namespace std;


typedef char String [100];

class Boisson
{
	private:
		String nom;
		String date;
		int volume;
	public:
		Boisson(String name, String dat, int vol);//constructeur complet
		Boisson();								  //constructeur vide
		void afficher(bool lf=false);              //affichage de propriétées
		void getnom(String name);
};

Boisson::Boisson(String name, String dat, int vol)
{
	strcpy(nom,name);
	strcpy(date,dat);
	volume=vol;
}

Boisson::Boisson()
{
	strcpy(nom,"");
	strcpy(date,"");
	volume=0;
}

void Boisson::afficher(bool lf)
{
	cout<<"nom= "<<nom<<" date= "<< date<< " volume= "<< volume;
	if (lf==true)
	{
		cout<<endl;
	}
	
}

void Boisson::getnom(String name)
{
	strcpy (nom,name);
}

class Distributeur
{
	private:
		String modele;
		unsigned nb;
		Boisson stock[N];
		unsigned quantite[N];
	public:
		Distributeur(String mod);
		~Distributeur();
		bool ajouter(Boisson b, unsigned n);
		bool commander(String name);
		unsigned lister();             //afficher le contenu du distibuteur
};

Distributeur::Distributeur(String mod)
{
	strcpy(modele,mod);
	nb=0;
}

Distributeur :: ~ Distributeur()
{
	printf("\n Distributeur detruit\n");
	//	getch();
}

unsigned Distributeur::lister()
{   
	
	cout<<" le nombre de boisson disponible est "<<nb<<endl;
	for(int i=0;i<nb;i++)
	{
		stock[i].afficher(true);
		cout<<" quantite= "<<quantite[i]<<endl;
	}
	return nb;
}

bool Distributeur :: ajouter(Boisson b, unsigned n)
{	
	bool flag=false;
	int j=0;           

	for(int i=0; i<nb;i++)  //recherche si le boison est deja dans le constructeur
	{   
		String nom1;stock[i].getnom(nom1); //get des nom des boissons
	    String nom2;b.getnom(nom2);

		if (strcmp(nom1	,nom2)==1 )
		{
			flag=true;
			j=i;
			break;
		}
	}

	if(flag==true) //type de boisson figure de le constructeur
	{
		quantite[j]+=n;
		return true;
	}

	else
	{
		if(nb<N)
		{
			stock[nb]=b;
			quantite[nb]=n;
			nb++;
			return true;
		}
		else
			return false;
	}
}


void main()
{
	Boisson the("Riome","17/01/2023",200);
	Boisson coffe("Alba","10/02/2023",150);
	Boisson ice("Seo","02/02/2023",200);

	the.afficher(true);
	coffe.afficher(true);
	ice.afficher(true);

	//Distributeur
	Distributeur dis("A400");  // test d'ajout d'une boisson
	bool flag2=dis.ajouter(the,5);
	bool flag3=dis.ajouter(coffe,7);
	if(flag3==true) printf("\n0");

	unsigned a=dis.lister();           // test de lister
	
	getch();
}

