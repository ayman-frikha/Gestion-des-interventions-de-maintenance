#include <stdio.h>
#include <stdlib.h>
#include "types.h"

noeudeq* ajouterEquipement(noeudeq *noeud, Equipement eq) {
    noeudeq *nouveau = (noeudeq*)malloc(sizeof(noeudeq));

    nouveau->data = eq;
    nouveau->suivant = NULL;

    if (noeud == NULL) {
        return nouveau;
    }

    noeudeq* aux = noeud;
    while (aux->suivant != NULL) {
        aux = aux->suivant;
    }
    aux->suivant = nouveau;
    return noeud;
}
Equipement *rechercherEquipement(noeudeq *tete, int id) {
    noeudeq *aux = tete;
    while (aux != NULL && aux->data.id != id) {
        aux = aux->suivant;
    }
    return (aux == NULL) ? NULL : &aux->data;
}


void afficherParc(const noeudeq *tete) {
    const noeudeq *aux = tete;
    if (aux == NULL) {
        printf("Parc vide.\n");
        return;
    }
    while (aux != NULL) {
        printf("*** [%d] %s ***\ntype: %s\nlocalisation: %s\netat: %d\n\n",
               aux->data.id, aux->data.nom, aux->data.type,
               aux->data.localisation, aux->data.etat);
        aux = aux->suivant;
    }
}