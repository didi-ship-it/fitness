// ============================================================
// CentreFitness.h
// STUB TEMPORAIRE — à remplacer par le fichier réel du Membre 2
// Sert uniquement à permettre la compilation de main.cpp
// en attendant l'intégration finale du groupe.
//
// IMPORTANT: quand le Membre 2 aura fini son fichier,
// vérifie que les noms de méthodes correspondent, sinon
// adapte les appels dans main.cpp en conséquence.
// ============================================================
#ifndef CENTREFITNESS_H
#define CENTREFITNESS_H
#include "Membre.h"
#include <iostream>
const int MAX_MEMBRES = 50;
class CentreFitness {
private:
Membre* listeMembres[MAX_MEMBRES];
int nbMembres;
public:
CentreFitness() : nbMembres(0) {
for (int i = 0; i < MAX_MEMBRES; i++) listeMembres[i] = nullptr;
}
bool ajouterMembre(const Membre& m) {
if (nbMembres >= MAX_MEMBRES) return false;
listeMembres[nbMembres] = new Membre(m);
nbMembres++;
return true;
}
Membre* rechercherMembre(int id) const {
for (int i = 0; i < nbMembres; i++) {
if (listeMembres[i]->getId() == id) return listeMembres[i];
}
return nullptr;
}
bool supprimerMembre(int id) {
for (int i = 0; i < nbMembres; i++) {

if (listeMembres[i]->getId() == id) {
delete listeMembres[i];
for (int j = i; j < nbMembres - 1; j++) {
listeMembres[j] = listeMembres[j + 1];
}
listeMembres[nbMembres - 1] = nullptr;
nbMembres--;
return true;
}
}
return false;
}
void afficherTousLesMembres() const {
if (nbMembres == 0) {
std::cout << "Aucun membre enregistre." << std::endl;
return;
}
for (int i = 0; i < nbMembres; i++) {
listeMembres[i]->afficher();
}
}
int getNbMembres() const { return nbMembres; }
~CentreFitness() {
for (int i = 0; i < nbMembres; i++) {
delete listeMembres[i];
}
}
};
#endif