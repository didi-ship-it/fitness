// STUB TEMPORAIRE — à remplacer par le fichier réel du Membre 1
// Sert uniquement à permettre la compilation de main.cpp
// en attendant l'intégration finale du groupe.
#ifndef MEMBRE_H
#define MEMBRE_H
#include <string>
#include <iostream>
#include "Abonnement.h"
class Membre {
private:
int id;
std::string nom;
std::string prenom;
Abonnement abonnement;
public:
Membre(int id = 0, std::string nom = "", std::string prenom = "",
Abonnement abonnement = Abonnement())
: id(id), nom(nom), prenom(prenom), abonnement(abonnement) {}
// Getters
int getId() const { return id; }
std::string getNom() const { return nom; }
std::string getPrenom() const { return prenom; }
Abonnement getAbonnement() const { return abonnement; }
// Setters
void setNom(std::string n) { nom = n; }
void setPrenom(std::string p) { prenom = p; }
void setAbonnement(Abonnement a) { abonnement = a; }
virtual void afficher() const {
std::cout << "ID: " << id << " | " << prenom << " " << nom << " | ";
abonnement.afficher();
}
virtual ~Membre() {}
};

#endif