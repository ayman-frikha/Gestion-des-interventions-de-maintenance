int main(void) {
    noeudeq *parc = NULL;

    Date d1 = {12, 3, 2024};
    Date d2 = {5, 11, 2025};
    Date aucune = {0, 0, 0};

    // 1. Test de creerEquipement + ajouterEquipement
    Equipement eq1 = creerEquipement(1, "Pompe Principale", "Hydraulique", "Atelier A", 3, EN_SERVICE, d1, d2, 1);
    Equipement eq2 = creerEquipement(2, "Serveur Base", "Informatique", "Salle Serveur", 3, EN_PANNE, d1, aucune, 2);
    Equipement eq3 = creerEquipement(3, "Compresseur Air", "Mecanique", "Zone Nord", 1, EN_MAINTENANCE, d2, aucune, 0);

    parc = ajouterEquipement(parc, eq1);
    parc = ajouterEquipement(parc, eq2);
    parc = ajouterEquipement(parc, eq3);

    // 2. Test de afficherParc
    printf("=== 1. AFFICHAGE DU PARC INITIAL ===\n");
    afficherParc(parc);

    // 3. Test de rechercherEquipement (ID existant)
    printf("=== 2. RECHERCHE DE L'EQUIPEMENT ID 2 ===\n");
    Equipement *trouve = rechercherEquipement(parc, 2);
    if (trouve != NULL) {
        afficherDetailEquipement(trouve);


        // Test de modification directe via le pointeur retourne
        trouve->etat = EN_SERVICE;
        printf("Apres reparation -> Nouvel etat : %s\n\n", etateq(trouve->etat));
    } else {
        printf("Equipement ID 2 introuvable.\n\n");
    }

    // 4. Test de rechercherEquipement (ID inexistant)
    printf("=== 3. RECHERCHE D'UN ID INEXISTANT (99) ===\n");
    if (rechercherEquipement(parc, 99) == NULL) {
        printf("ID 99 introuvable (comportement attendu).\n\n");
    }

    // 5. Test de supprimerEquipement (milieu, tete, puis inexistant)
    printf("=== 4. SUPPRESSION ID 2 (MILIEU) ===\n");
    parc = supprimerEquipement(parc, 2);
    afficherParc(parc);

    printf("=== 5. SUPPRESSION ID 1 (TETE) ===\n");
    parc = supprimerEquipement(parc, 1);
    afficherParc(parc);

    printf("=== 6. SUPPRESSION ID 99 (INEXISTANT) ===\n");
    parc = supprimerEquipement(parc, 99);
    afficherParc(parc);

    // 7. Liberation de la memoire restante
    while (parc != NULL) {
        noeudeq *suiv = parc->suivant;
        free(parc);
        parc = suiv;
    }

    return 0;
}
