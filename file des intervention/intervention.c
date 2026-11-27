#include <stdio.h>
#include <stdlib.h>
#include "intervention.h"

void initialiserFilePriorite(FilePriorite* fp) {
    for (int i = 0; i < 4; i++) {
        fp->niveaux[i].tete = NULL;
        fp->niveaux[i].queue = NULL;
        fp->niveaux[i].taille = 0;
    }
}

void libererFilePriorite(FilePriorite* fp) {
    if (fp == NULL) 
        return;
    for (int i = 0; i < 4; i++) {
        noeuddemande* aux = fp->niveaux[i].tete;
        while (aux != NULL) {
            noeuddemande *temp = aux;
            aux = aux->suivant;
            free(temp); 
        }
        fp->niveaux[i].tete = NULL;
        fp->niveaux[i].queue = NULL;
        fp->niveaux[i].taille = 0;
    }
}


void enfilerDemande(FilePriorite* fp, Demande* d) {
    if (fp == NULL || d == NULL) 
        return;
    
        if (d->statut != EN_ATTENTE) 
        return;

    if (d->priorite < 0 || d->priorite > 3) 
        return;

    File *f = &fp->niveaux[d->priorite];


    noeuddemande *verif = f->tete;
    while (verif != NULL) {
        if (verif->demande->id == d->id) 
            return;
        verif = verif->suivant;
    }

    noeuddemande *nouv = (noeuddemande *)malloc(sizeof(noeuddemande));
    nouv->demande = d;
    nouv->suivant = NULL;

    if (f->tete == NULL) {
        f->tete = nouv;
        f->queue = nouv;
    } else {
        f->queue->suivant = nouv;
        f->queue = nouv;
    }

    f->taille++;
}