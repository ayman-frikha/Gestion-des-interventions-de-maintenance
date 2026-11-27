#include <stdio.h>
#include "types.h"
#include <stdlib.h>
noeudtech *ajouterTechnicien(noeudtech *noeud, Technicien tech) {
    noeudtech *nouveau = (noeudtech *)malloc(sizeof(noeudtech));
    if (nouveau == NULL) {
        printf("Erreur d'allocation mémoire pour le technicien.\n");
        exit(1);
    }
    nouveau->info = tech;
    nouveau->suivant = noeud;
    return nouveau;
}
void afficherTechnicien(Technicien *tech) {
    if (tech == NULL) {
        printf("Technicien non trouvé.\n");
        return;
    }
    printf("ID: %d\nNom: %s\nSpécialité: %s\nCharge: %d\n",
           tech->id, tech->nom, tech->specialite, tech->charge);
}
noeudtech *supprimerTechnicien(noeudtech *noeud, int id) {
    noeudtech *aux = noeud;
    noeudtech *precedent = NULL;
    while (aux != NULL && aux->info.id != id) {
        precedent = aux;
        aux = aux->suivant;
    }
    if (aux == NULL) {
        return noeud;
    }
    if (precedent == NULL) {
        noeud = aux->suivant;
    } else {
        precedent->suivant = aux->suivant;
    }
    free(aux);
    return noeud;
}
noeudtech *rechercherTechnicien(noeudtech *noeud, int id) {
    noeudtech *aux = noeud;
    while (aux != NULL && aux->info.id != id) {
        aux = aux->suivant;
    }
    return aux;
}
noeudtech *recommanderTechnicien(noeudtech *noeud, const char *specialite) {
    noeudtech *aux = noeud;
    noeudtech *meilleur = NULL;
    int chargeMin = __INT_MAX__;
    while (aux != NULL) {
        if (strcmp(aux->info.specialite, specialite) == 0 && aux->info.charge < chargeMin) {
            chargeMin = aux->info.charge;
            meilleur = aux;
        }
        aux = aux->suivant;
    }
    return meilleur;
}
void incrementerCharge(noeudtech *noeud, int id) {
    noeudtech *tech = rechercherTechnicien(noeud, id);
    if (tech != NULL) {
        tech->info.charge++;
    }
}
void decrementerCharge(noeudtech *noeud, int id) {
    noeudtech *tech = rechercherTechnicien(noeud, id);
    if (tech != NULL && tech->info.charge > 0) {
        tech->info.charge--;
    }
}