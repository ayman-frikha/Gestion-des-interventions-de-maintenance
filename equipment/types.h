#ifndef TYPES_H
#define TYPES_H
typedef struct { int jour, mois, annee; } Date;
typedef enum { EN_SERVICE, EN_PANNE, EN_MAINTENANCE, HORS_SERVICE } EtatEquipement;
typedef enum { CRITIQUE = 0, HAUTE = 1, MOYENNE = 2, BASSE = 3 } Priorite;
typedef enum { EN_ATTENTE, EN_COURS, TERMINEE, ANNULEE } StatutDemande;
typedef enum { ELECTRIQUE, MECANIQUE, HYDRAULIQUE, LOGICIEL, AUTRE } CodePanne;
typedef struct Equipement {
    int id;
    char nom[50], type[30], localisation[50];
    int criticite;                       
    EtatEquipement etat;
    Date miseEnService, derniereIntervention;
    int nbPannes;
} Equipement;
typedef struct noeudequipement{
    Equipement data;
    struct noeudequipement *suivant;
}noeudeq;
typedef struct Technicien {
    int id;
    char nom[50], specialite[30];
    int charge;                            
    struct Technicien *suivant;
} Technicien;
typedef struct Demande {
    int id, idEquipement;
    char description[200];
    int gravite;                          
    CodePanne code;
    Priorite priorite;                     
    Date dateDemande, echeance;            
    int nbSignalements;                    
    StatutDemande statut;
    struct Demande *suivant;
} Demande;
typedef struct { Demande *tete, *queue; int taille; } File; 
typedef struct { File niveaux[4]; } FilePriorite;
typedef struct Operation {
    int id, idDemande, idEquipement, idTechnicien;
    Date debut, fin;
    float duree, cout;
    CodePanne code;
    char rapport[200];
    struct Operation *suivant;
} Operation;
typedef struct { Operation *sommet; int taille; } Pile;
typedef struct PlanPreventif {                                    
    int idEquipement, frequenceJours;
    Date derniere, prochaine;
    struct PlanPreventif *suivant;
} PlanPreventif;
noeudeq* ajouterEquipement(noeudeq *noued, Equipement eq);

#endif