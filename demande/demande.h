#ifndef DEMANDE_H
#define DEMANDE_H
#include "../equipment/types.h"

Priorite calculerPriorite(int criticite, int gravite);
Demande *rechercherDemande(Demande *D,int id);
Demande *chercherDoublon( Demande *D,int idEquipement, CodePanne code);
#endif