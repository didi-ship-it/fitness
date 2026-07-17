#include "CentreFitness.h"
#include <iostream>
#include <fstream>
#include <stdexcept>

using namespace std;

CentreFitness::CentreFitness() {
}

CentreFitness::~CentreFitness() {
    for (int i = 0; i < listeMembres.size(); i++) {
        if (listeMembres[i] != nullptr) {
            delete listeMembres[i];
        }
    }
    listeMembres.clear();
}

void CentreFitness::ajouterMembre(Membre* m) {
    if (m == nullptr) {
        throw runtime_error("Erreur : Impossible d'ajouter un membre vide !");
    }
    listeMembres.push_back(m);
}

void CentreFitness::afficherTous() const {
    if (listeMembres.size() == 0) {
        cout << "Aucun membre n'est inscrit pour le moment." << endl;
        return;
    }

    cout << "\n=== LISTE DES MEMBRES ===" << endl;
    for (int i = 0; i < listeMembres.size(); i++) {
        if (listeMembres[i] != nullptr) {
            listeMembres[i]->afficher();
            cout << "-------------------------" << endl;
        }
    }
}

Membre* CentreFitness::rechercherMembre(int id) const {
    for (int i = 0; i < listeMembres.size(); i++) {
        if (listeMembres[i] != nullptr && listeMembres[i]->getId() == id) {
            return listeMembres[i];
        }
    }
    return nullptr;
}

bool CentreFitness::supprimerMembre(int id) {
    for (int i = 0; i < listeMembres.size(); i++) {
        if (listeMembres[i] != nullptr && listeMembres[i]->getId() == id) {
            delete listeMembres[i];
            listeMembres.erase(listeMembres.begin() + i);
            return true;
        }
    }
    return false;
}

void CentreFitness::sauvegarder(const string& nomFichier) const {
    ofstream fichier(nomFichier);
    
    if (!fichier.is_open()) {
        throw runtime_error("Erreur : Impossible de creer le fichier de sauvegarde !");
    }

    for (int i = 0; i < listeMembres.size(); i++) {
        if (listeMembres[i] != nullptr) {
            fichier << listeMembres[i]->getId() << " "
                    << listeMembres[i]->getNom() << " "
                    << listeMembres[i]->getPrenom() << " "
                    << listeMembres[i]->getTypeAbonnement() << endl;
        }
    }
    fichier.close();
}

void CentreFitness::charger(const string& nomFichier) {
    ifstream fichier(nomFichier);
    
    if (!fichier.is_open()) {
        return; 
    }

    // Pour eviter les doublons
    for (int i = 0; i < listeMembres.size(); i++) {
        if (listeMembres[i] != nullptr) {
            delete listeMembres[i];
        }
    }
    listeMembres.clear();

    int id;
    string nom, prenom, type;

    while (fichier >> id >> nom >> prenom >> type) {
        Membre* m = new Membre(id, nom, prenom, type);
        listeMembres.push_back(m);
    }
    fichier.close();
}