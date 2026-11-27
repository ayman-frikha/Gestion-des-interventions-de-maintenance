#ifndef FILE_H
#define FILE_H
#include <stdbool.h>
#include "../equipment/types.h"

void initialiserFilePriorite(FilePriorite *fp);
void libererFilePriorite(FilePriorite *fp);


void enfilerDemande(FilePriorite *fp, Demande *d);
Demande *defilerProchaine(FilePriorite *fp);
Demande *consulterProchaine(FilePriorite *fp);


bool retirerDemandeDeLaFile(FilePriorite *fp, int idDemande);
bool estFilePrioriteVide(FilePriorite *fp);
void afficherFilePriorite(FilePriorite *fp);

#endif
