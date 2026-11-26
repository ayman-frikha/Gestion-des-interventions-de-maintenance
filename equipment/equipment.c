#include <stdio.h>
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

noeudeq *supprimer(noeudeq *tete, Equipement x) {
    noeudeq *courant = tete;
    noeudeq *precedent = NULL;
    while (courant != NULL && courant->data.id != x.id) {
        precedent = courant;
        courant = courant->suivant;
    }
    if (courant == NULL) {
        return tete;
    }
    if (precedent == NULL) {
        tete = courant->suivant;
    } else {
        precedent->suivant = courant->suivant;
    }
    free(courant);
    return tete;
}
