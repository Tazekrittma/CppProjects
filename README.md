# Beverage Dispenser
This program is a simple implementation of a beverage dispenser, written in C++.

## Installation
To run this program, you need to have a C++ compiler installed on your system. You can use any compiler of your choice.

## Usage
The program defines two classes, Boisson (beverage) and Distributeur (dispenser).

The Boisson class has three private properties:

* nom: the name of the beverage
* date: the expiration date of the beverage
* volume: the volume of the beverage
The Distributeur class has four private properties:

* modele: the model of the dispenser
* nb: the number of beverages in the dispenser
* stock[N]: an array of beverages that are stored in the dispenser
* quantite[N]: an array that stores the quantity of each beverage in the dispenser
The program provides the following public methods for the Boisson class:

* Boisson(String name, String dat, int vol): a constructor that initializes the properties of the Boisson object
* Boisson(): a constructor that creates an empty Boisson object
* void afficher(bool lf=false): a method that prints the properties of the Boisson object
* void getnom(String name): a method that sets the name of the beverage
The program provides the following public methods for the Distributeur class:

* Distributeur(String mod): a constructor that initializes the model of the dispenser
* ~Distributeur(): a destructor that deletes the dispenser object
* bool ajouter(Boisson b, unsigned n): a method that adds a specified quantity of a beverage to the dispenser
* bool commander(String name): a method that removes a specified beverage from the dispenser
* unsigned lister(): a method that prints the contents of the dispenser and returns the number of beverages in the dispenser
To test the program, create Boisson objects and add them to the Distributeur object using the ajouter method. Use the lister method to print the contents of the dispenser.
### Credits
This was developed by Massinissa TAZEKRITT.
