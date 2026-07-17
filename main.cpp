#include <iostream>
#include <limits>
#include "CentreFitness.h"
#include "Membre.h"
#include "Abonnement.h"
using namespace std;
void viderBuffer() {
cin.clear();
cin.ignore(numeric_limits<streamsize>::max(), '\n');
}
int lireEntier(const string& message) {
int valeur;
cout << message;
while (!(cin >> valeur)) {
cout << "Entree invalide. Veuillez saisir un no mbre entier : ";
viderBuffer();
}
viderBuffer();
return valeur;
}
string lireTexte(const string& message) {
string valeur;
cout << message;
getline(cin, valeur);
while (valeur.empty()) {

cout << "Ce champ ne peut pas etre vide. Reessayez : ";
getline(cin, valeur);
}
return valeur;
}
void afficherMenu() {
cout << "\n==============================================\n";
cout << " GESTION D UN CENTRE DE FITNESS\n";
cout << "==============================================\n";
cout << "1. Inscrire un nouveau membre\n";
cout << "2. Rechercher un membre (par ID)\n";
cout << "3. Afficher tous les membres\n";
cout << "4. Supprimer un membre\n";
cout << "5. Quitter\n";
cout << "==============================================\n";
}
void inscrireMembre(CentreFitness& centre) {
cout << "\n--- Inscription d un nouveau membre ---\n";
int id = lireEntier("ID du membre : ");
if (centre.rechercherMembre(id) != nullptr) {
cout << "Erreur : un membre avec cet ID existe deja.\n";
return;
}
string nom = lireTexte("Nom : ");
string prenom = lireTexte("Prenom : ");
cout << "Type de formule (1 = Mensuel, 2 = Annuel) : ";
int choixFormule = lireEntier("");
string typeFormule = (choixFormule == 2) ? "Annuel" : "Mensuel";
double tarif = (choixFormule == 2) ? 120000.0 : 15000.0;
Abonnement abonnement(typeFormule, tarif);
Membre nouveauMembre(id, nom, prenom, abonnement);
if (centre.ajouterMembre(nouveauMembre)) {
cout << "Membre inscrit avec succes !\n";
} else {

cout << "Erreur : capacite maximale du centre atteinte.\n";
}
}
void rechercherMembreMenu(CentreFitness & centre) {
int id = lireEntier("\nEntrez l ID du membre a rechercher : ");
Membre* m = centre.rechercherMembre(id);
if (m != nullptr) {
cout << "\nMembre trouve :\n";
m->afficher();
} else {
cout << "Aucun membre trouve avec cet ID.\n";
}
}
void afficherTousMenu(CentreFitness& centre) {
cout << "\n--- Liste des membres (" << centre.getNbMembres() << ") ---\n";
centre.afficherTousLesMembres();
}

void supprimerMembreMenu(CentreFitness& centre) {
int id = lireEntier("\nEntrez l ID du membre a supprimer : ");
if (centre.supprimerMembre(id)) {
cout << "Membre supprime avec succes.\n";
} else {
cout << "Aucun membre trouve avec cet ID.\n";
}
}
int main() {
CentreFitness centre;
int choix;
cout << "Bienvenue dans l application de gestion du Centre de Fitness !\n";
do {
afficherMenu();
choix = lireEntier("Votre choix : ");
switch (choix) {
case 1:
inscrireMembre(centre);
break;
case 2:
rechercherMembreMenu(centre);
break;
case 3:
afficherTousMenu(centre);
break;
case 4:
supprimerMembreMenu(centre);
break;
case 5:
cout << "\nMerci d avoir utilise l application. A bientot !\n";
break;
default:
cout << "\nChoix invalide. Veuillez reessayer.\n";
}
} while (choix != 5);
return 0;
}