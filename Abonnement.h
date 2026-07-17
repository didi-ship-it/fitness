// Abonnement.h
// STUB TEMPORAIRE — à remplacer par le fichier réel du Membre 1
// Sert uniquement à permettre la compilation de main.cpp
// en attendant l'intégration finale du groupe.
// ============================================================
#ifndef ABONNEMENT_H
#define ABONNEMENT_H
#include <string>
class Abonnement {
private:
std::string typeFormule; // "Mensuel" ou "Annuel"
double tarif;
public:
Abonnement(std::string typeFormule = "Mensuel", double tarif = 0.0)
: typeFormule(typeFormule), tarif(tarif) {}
std::string getTypeFormule() const { return typeFormule; }
double getTarif() const { return tarif; }
void setTypeFormule(std::string t) { typeFormule = t; }
void setTarif(double t) { tarif = t; }
virtual void afficher() const {
std::cout << "Formule: " << typeFormule << " | Tarif: " << tarif << " FCFA" << std::endl;
}
virtual ~Abonnement() {}
};
#endif