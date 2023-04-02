#include <stdio.h>
#include <conio.h>
#include <string.h>

class Vehicule
{
	private:
		char modele[50];
		unsigned puissance;
		char circulation[20];
		char prop[25];	
	public:
		Vehicule(char *model, unsigned cv, char *date, char *nom);
		Vehicule(char *model, unsigned cv, char *date);
		Vehicule();
		void afficher();
		void setpuissance(unsigned p);
		unsigned getpuissance();
		void setproprio(char *nom);
		void getproprio (char *nom);
		char * getproprioprob();
		~ Vehicule();
		
};

Vehicule :: Vehicule(char *model, unsigned cv, char *date, char *nom)
{
	strcpy(modele,model);
	strcpy(circulation,date);
	strcpy(prop,nom);
	puissance=cv;
}

Vehicule :: Vehicule(char *model, unsigned cv, char *date)
{
	strcpy(modele,model);
	strcpy(circulation,date);
	strcpy(prop,"");
	puissance=cv;
}

Vehicule :: Vehicule()
{
	strcpy(modele,"");
	strcpy(circulation,"");
	strcpy(prop,"");
	puissance=0;
}

Vehicule :: ~ Vehicule()
{
	printf("\nvehicule detruit\n");
	//	getch();
}

void Vehicule :: afficher()
{
	printf("\n modele: %s\n puissance: %d \n circulation: %s \n prop: %s \n",modele,puissance,circulation,prop);
}

void Vehicule :: setpuissance(unsigned p)
{
	puissance=p;
}

unsigned Vehicule :: getpuissance()
{
	return puissance;
}

void Vehicule :: setproprio(char *nom)
{
	strcpy(prop,nom);
}

void Vehicule :: getproprio(char *nom)
{
	strcpy(nom,prop);
}

char* Vehicule :: getproprioprob()
{
	return prop;
}

void main()
{   
	unsigned variable;
	char nom[25];
	char *proprio;
	Vehicule V1("Twingo",100,"10/02/2005","Richard RAUTHCHILD");
	Vehicule V2;

	//afficher
	V1.afficher();
	V2.afficher();
	
	//set puissance
	V2.setpuissance(10);
	//get puissance
	variable=V2.getpuissance();
	printf("\n %d\n",variable);
	
	//set proprio
	V2.setproprio("Stephan LORRAND");
	//get proprio
	V2.getproprio(nom);
	printf("\n nouveau proprio= %s\n",nom);
	V2.afficher();

	//methode problématique
	proprio = V2.getproprioprob();
	printf("\nprop est %s\n",proprio);
	//demonstration que on peut modifier prop
	strcpy(proprio,"jerard");
	V2.afficher();

	//3 emme constructeur
	Vehicule V3("R4",16,"10/02/1999");
	V3.afficher();
	getch();
}