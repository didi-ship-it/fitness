#ifndef CENTREFITNESS_H
#define CENTREFITNESS_H

#include <vector>
#include <string>
#include "Membre.h" 

using namespace std; 

class CentreFitness {
 //Creation du tableau
 private:
    vector<Membre*> listeMembres;

 public:
    // Constructeur et destructeur
    CentreFitness();
    ~CentreFitness();

    // ajouter un membre
    void ajouterMembre(Membre* m);
    void afficherTous() const;

    //Rechercher un membre
    Membre* rechercherMembre(int id) const;

    //Supprimer
    bool supprimerMembre(int id);

    // Sauvegarder fichier
    void sauvegarder(const string& nomFichier) const;

    //Charger fichier
    void charger(const string& nomFichier);
};

#endif