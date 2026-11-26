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
    strcpy(eq.nom,nom);
    strcpy(eq.type,type);
    strcpy(eq.localisation,localisation);
    eq.criticite = criticite;
    eq.etat = etat;
    eq.miseEnService = miseEnService;
    eq.derniereIntervention = derniereIntervention;
    eq.nbPannes = nbPannes;

    return eq;
}

char *etateq(int etat) {
    switch (etat) {
        case 0: return "En service";
        case 1: return "En panne";
        case 2: return "En maintenance";
        case 3: return "Hors service";
        default: return "Inconnu";
    }
}

noeudeq *supprimerEquipement(noeudeq *noeud, int id) {
    noeudeq *aux = noeud;
    noeudeq *precedent = NULL;
    while (aux != NULL && aux->data.id != id) {
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

Equipement *rechercherEquipement(noeudeq *noeud, int id) {
    noeudeq *aux = noeud;
    while (aux != NULL && aux->data.id != id) {
        aux = aux->suivant;
    }
    if (aux == NULL) {
        return NULL;
    } else {
        return &aux->data;
    }
}


void afficherParc( noeudeq *tete) {
    noeudeq *aux = tete;
    if (aux == NULL) {
        printf("Parc vide.\n");
        return;
    }
    while (aux != NULL) {
        printf("*** [%d] %s ***\ntype: %s\nlocalisation: %s\netat: %s\n\n",
               aux->data.id, aux->data.nom, aux->data.type,
               aux->data.localisation, etateq(aux->data.etat));
        aux = aux->suivant;
    }
}

void afficherDetailEquipement(Equipement *eq) {
    if (eq == NULL) {
        printf("Equipement introuvable.\n");
        return;
    }
    printf("=== FICHE EQUIPEMENT [%d] ===\n", eq->id);
    printf("  Nom                  : %s\n", eq->nom);
    printf("  Type                 : %s\n", eq->type);
    printf("  Localisation         : %s\n", eq->localisation);
    printf("  Criticite            : %d / 3\n", eq->criticite);
    printf("  Etat                 : %s\n", etateq(eq->etat));
    printf("  Nombre de pannes     : %d\n", eq->nbPannes);
    printf("  Mise en service      : %d/%d/%d\n",
           eq->miseEnService.jour, eq->miseEnService.mois, eq->miseEnService.annee);
    if (eq->derniereIntervention.jour == 0) {
        printf("  Derniere intervention: Aucune\n");
    } else {
        printf("  Derniere intervention: %d/%d/%d\n",
               eq->derniereIntervention.jour, eq->derniereIntervention.mois, eq->derniereIntervention.annee);
    }
}
