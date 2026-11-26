#include <stdio.h>
#include "types.h"
#include <stdlib.h>

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
