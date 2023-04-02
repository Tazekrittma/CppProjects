#include <stdio.h>
#include <conio.h>
#include <string.h>

#include <iostream>
#define N 11

using namespace std;


typedef char String [100];


class Boisson
{
	protected:		
		String nom;
		String date;
		int volume;

	unsigned nbinstances;

	public:
		Boisson(String name, String dat, int vol);//constructeur complet
		Boisson();								  //constructeur vide
		virtual void afficher(bool lf=false);              //affichage de propriétées
		void getnom(String name);
		~Boisson();
		
	friend class Distributeur;		
};



Boisson::Boisson(String name, String dat, int vol)
{
	strcpy(nom,name);
	strcpy(date,dat);
	volume=vol;
	Boisson::nbinstances++;
}

Boisson::Boisson()
{
	strcpy(nom,"");
	strcpy(date,"");
	volume=0;
	Boisson::nbinstances++;
}

Boisson :: ~Boisson()
{
	Boisson::nbinstances--;
}

void Boisson::afficher(bool lf)
{
	cout<<"nom= "<<nom<<" date= "<< date<< " volume= "<< volume;
	if (lf==true)
	{
		cout<<endl;
	}
	
}

void Boisson::getnom(String name1)
{	
	strcpy (name1,nom);
}

class Distributeur
{
	private:
		String modele;
		unsigned nb;
		Boisson * stock[N];
		unsigned quantite[N];
	public:
		Distributeur(String mod);
		~Distributeur();
		bool ajouter(Boisson * b, unsigned n);
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
	for(int i=0;i<nb;i++)
	{
		delete stock[i];
	}

//	cout<<"nb d'instances restantes="<< Boisson::nbinstances<<endl;

	//	getch();
}

unsigned Distributeur::lister()
{   
	unsigned sum=0;

	for(int i=0;i<nb;i++)
	{
		stock[i]->afficher(false);
		cout<<" quantite= "<<quantite[i]<<endl;
		sum+=quantite[i];
	}
	cout<<" le nombre totale de boisson disponible est "<<sum<<endl;
	cout<<" le nombre de types de boisson disponible est "<<nb<<endl;

	return sum;
}

bool Distributeur :: ajouter(Boisson * b, unsigned n)   //Ajout de Boisson
{	
	bool flag=false;
	int j=0;           

	for(int i=0; i<nb;i++)  //recherche si le boison est deja dans le constructeur
	{   
		String nom1;stock[i]->getnom(nom1); //get des nom des boissons
	    String nom2;b->getnom(nom2);

		if (strcmp(nom1	,nom2)== 0)
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

bool Distributeur :: commander(String name)
{
	bool flag8=false;
	cout<<"\nle nom de boisson commande est "<<name<<endl;
	for(int i=0;i<nb;i++)
	{
		String nom8; stock[i]->getnom(nom8);
		if (strcmp(nom8	,name)== 0)
		{
			flag8=true;
			cout<<"Anciene quantite de "<<name<<"est "<<quantite[i]<<endl;
			quantite[i]--;
			cout<<"Nouvelle quantite de "<<name<<"est "<<quantite[i]<<endl;			
		}
		
		return flag8;
	}
}

class BoissonChaude : public Boisson
{
	protected:
		int temperature;
		bool sucre;
	public:
		BoissonChaude(String name, String date, int vol, int q, int temp, bool suc);
		virtual void afficher(bool lf=false);
};

BoissonChaude :: BoissonChaude (String name, String date, int vol, int q, int temp, bool suc) : Boisson(name, date, vol)
{
	temperature=temp;
	sucre=suc;
}

void BoissonChaude :: afficher(bool lf)
{
	Boisson :: afficher (false);
	cout<<" temperature= "<< temperature;
	cout<<" sucre ";
	if (sucre == true) cout<< "oui";
	else cout << "Non";
	if (lf==true)
	{
		cout<<endl;
	}
	
}


void main()
{
//	Boisson ::nbinstances = 0;

	Boisson * the= new Boisson("Riome","17/01/2023",200);
	Boisson *coffe= new Boisson("Alba","10/02/2023",150);
	Boisson *ice= new Boisson("Seo","02/02/2023",200);
	
/*
	the->afficher(true);
	coffe->afficher(true);
	ice->afficher(true);
*/

	//Distributeur
	Distributeur dis("A400");  // test d'ajout d'une boisson
	bool flag2=dis.ajouter(the,5);
	bool flag3=dis.ajouter(coffe,7);
	if(flag3==true) cout<<"\nboisson ajoute\n"<<endl;

	unsigned a=dis.lister();           // test de lister
	bool flag4=dis.commander("Lime");

	if(flag4==true) cout<<"boisson Boisson disponible"<<endl; // test de commande dune boisson
	else cout<<"boisson non disponible\n"<<endl;
	
	BoissonChaude havae("havae","2/12/1963",200,3,32,false); // test de boisson chaude
	BoissonChaude moka("moka","05/02/1998",20,8,45,false);
	havae.afficher(true);
	moka.afficher(true);

	bool flag11=dis.ajouter(&havae,1); // test dajout des boisson chaudes
	bool flag12=dis.ajouter(&moka,9);

	if(flag11==true) cout<<"\nboisson chaude 1 ajoute"<<endl;
	if(flag12==true) cout<<"boisson chaude 2 ajoute\n"<<endl;

	unsigned b=dis.lister(); // test du destributeur lister

	getch();
}

