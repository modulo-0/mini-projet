#include <stdio.h>
#include <stdlib.h>
#include <string.h>



int main {
    char titre[50] = "le titre des livres pour les prets";

    FILE * fiche = fopen("bibliotheque.txt", "w");
    if (fiche != NULL) {
        printf("Registre des livres\n");
    }

    else  {
        printf("bibliotheque non disponible");
        return;
    }
    fprintf(fiche, %s, titre);

    fclose(fiche);

    return 0;
}