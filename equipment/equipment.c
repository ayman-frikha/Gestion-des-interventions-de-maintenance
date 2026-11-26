#include <stdio.h>
#include "types.h"
#include <stdlib.h>
#include <string.h>

Equipement creerEquipement(
    int id,
    const char *nom,
    const char *type,
    const char *localisation,
    int criticite,
    EtatEquipement etat,
    Date miseEnService,
    Date derniereIntervention,
    int nbPannes
) {
    Equipement eq;

    eq.id = id;
    snprintf(eq.nom, sizeof(eq.nom), "%s", nom);
    snprintf(eq.type, sizeof(eq.type), "%s", type);
    snprintf(eq.localisation, sizeof(eq.localisation), "%s", localisation);
    eq.criticite = criticite;
    eq.etat = etat;
    eq.miseEnService = miseEnService;
    eq.derniereIntervention = derniereIntervention;
    eq.nbPannes = nbPannes;

    return eq;
}

char *etateq(EtatEquipement etat) {
    switch (etat) {
        case EN_SERVICE: return "En service";
        case EN_PANNE: return "En panne";
        case EN_MAINTENANCE: return "En maintenance";
        case HORS_SERVICE: return "Hors service";
        default: return "Inconnu";
    }
}

noeudeq *supprimerEquipement(noeudeq *tete, Equipement eq) {
    noeudeq *courant = tete;
    noeudeq *precedent = NULL;
    while (courant != NULL && courant->data.id != eq.id) {
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
