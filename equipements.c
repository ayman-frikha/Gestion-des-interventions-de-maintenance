#include"equipements.h"
Equipement *rechercherEquipement(Equipement *equipment,int id){
    Equipement* aux= equipment;
    while( aux !=NULL && aux->id!=id ){
        aux=aux->suivant;
    }
    return aux;
}
void afficherParc(Equipement *equipement){
    Equipement *aux= equipement;
    while (aux !=NULL){
        printf("***%s***\ntype: %s\nlocalisation: %s\n",aux->nom,aux->type,aux->localisation,aux->etat);
        aux=aux->suivant;
    }
}