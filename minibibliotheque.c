#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>



typedef struct {
	char nom[30];
	char auteur[50];
	int annee;
	
} Livre;

void ajoutlivre(Livre bibliotheque[], int *nblivre) 
{
	printf("Saisir le titre du livre:  ");
	gets(bibliotheque[*nblivre].nom);

	for (int i = 0; i < *nblivre; i++)
	{
		if (strcmp(bibliotheque[*nblivre].nom, bibliotheque[i].nom) == 0)
		{
			printf("Ce livre existe deja !!\n");
			return;
		}

	}
	printf("Saisir le nom l'auteur: ");
	gets(bibliotheque[*nblivre].auteur);

	printf("Saisir l'annee d'edition: ");
	scanf("%d", &bibliotheque[*nblivre].annee);
	getchar(); // pour consommer le caractère de nouvelle ligne après la saisie de l'année
	
	(*nblivre)++;
}

void afficherlivre(Livre bibliotheque[], int nblivre) 
{
	if (nblivre == 0) {
		printf("Aucun livre dans la bibliotheque.\n");
		return;
	}

	for (int i = 0; i < nblivre; i++) {
		printf("Livre %d:\n", i + 1);
		printf("Titre: %s\n", bibliotheque[i].nom);
		printf("Auteur: %s\n", bibliotheque[i].auteur);
		printf("Annee d'edition: %d\n", bibliotheque[i].annee);
		printf("\n");
	}
}

void rechercherlivre(char *recherche, Livre *bibliotheque, int *nblivre)
{
	int i;
	for (i=0; i < *nblivre; i++) {
		if (strcmp(recherche, bibliotheque[i].nom) == 0)
		{
			printf("livre trouvé !\n");
			printf("Voici le livre: \n");
			printf("Livre %d:\n", i + 1);
			printf("Titre: %s\n", bibliotheque[i].nom);
			printf("Auteur: %s\n", bibliotheque[i].auteur);
			printf("Annee d'edition: %d\n", bibliotheque[i].annee);
			printf("\n");
			return;
		}
	}
	printf("livre non trouvé!");
}

/* bool quitter(char *response) 
{
	if (strcmp(response, "non") == 0) {
		exit(0);
	}
	return false;
} */




int main() 
{
	Livre bibliotheque[100];
	int nblivre = 0;
	int choix;
	int i = 0;
	bool exit = false;
	char reponse[4];
	char recherche[50];
	

	while(!exit) {
		puts("====== BIBLIOTHEQUE ======\n");
		puts("1. Ajouter un livre \n");
		puts("2. Afficher un livre \n");
		puts("3. Rechercher un livre \n");
		puts("4. Supprimer un livre \n");
		puts("Votre choix \n");

		scanf("%d", &choix);

		switch (choix)
		{
		case 1:
		{
			int nb = 0;
			puts("Entrez le nombre de livre à ajouter: \n");
			scanf("%d", &nb);
			getchar();
			for (int j = 0; j < nb; j++)
			{
				ajoutlivre(bibliotheque, &nblivre);
			}
			printf("%d\n", nblivre);
			printf("Entrez oui pour continuer ou non pour quitter: \n");
			scanf("%s", reponse);
			if (strcmp(reponse, "non") == 0) {
				exit = true;
			}
		
		} break;

		case 2:
		{
			puts("Voici la liste des livres dans la bibliotheque: \n");
			afficherlivre(bibliotheque, nblivre);
		} break;

		case 3:
		{
			puts("Entrez le livre à chercher: ");
			gets(recherche);
			rechercherlivre(recherche, bibliotheque, nblivre);
			
		}break;

		
		
		default:
			printf("Choix invalide !!\n");
		}
		
		printf("Le nombre de livre dans la bibliotheque est de: %d\n", nblivre);
		// printf("\nVoici la liste des livres dans la bibliotheque: \n");

		
		printf("\n");
	}
	return 0;
}