
#include <stdio.h>
#include <stdlib.h>
#include "demande.h"
Priorite calculerPriorite(int criticite, int gravite) {
    int score = criticite * gravite;   

    if (score >= 15) return CRITIQUE;
    if (score >= 8)  return HAUTE;
    if (score >= 4)  return MOYENNE;
    return BASSE;
};
Demande *rechercherDemande(Demande *D,int id){
    Demande *aux=D;
    while(aux!=NULL && id!=aux->id){
        aux=aux->suivant;
    }
    return aux;
};
Demande *chercherDoublon( Demande *D,int idEquipement, CodePanne code){
    Demande *aux=D;
    while(aux!=NULL){
        if (idEquipement==aux->idEquipement && code==aux->code && (aux->statut == EN_ATTENTE || aux->statut == EN_COURS)){
            return aux;
        };
        aux=aux->suivant;
    }
    return NULL;
}