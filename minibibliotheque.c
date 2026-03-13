#include <stdio.h>
#include <stdlib.h>
#include <string.h>



typedef struct {
	char nom[30];
	char auteur[50];
	int annee;
	
} Livre;

void ajoutlivre(Livre bibliotheque[], int *nblivre) 
{
	printf("Saisir le titre du livre:  \n");
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


int main() 
{
	Livre bibliotheque[100];
	int nblivre = 0;
	int choix;
	int i = 0;


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
		for (int j = 0; j < nb; j++);
		{
			ajoutlivre(bibliotheque, &nblivre);
		}
		printf("%d\n", nblivre);
		break;
	}

	case 2:
	{
		printf("Voici la liste des livres dans la bibliotheque: \n");
		for (int i = 0; i < nblivre; i++);
		{
			printf("Titre: %s\n", bibliotheque[i].nom);
			printf("Auteur: %s\n", bibliotheque[i].auteur);
			printf("Annee d'edition: %d\n", bibliotheque[i].annee);
			printf("\n");

		}
		break;
	}
	default:
		printf("Choix invalide !!\n");
	}
	 
	printf("Le nombre de livre dans la bibliotheque est de: %d\n", nblivre);
	printf("\nVoici la liste des livres dans la bibliotheque: \n");

	for (int i = 0; i < nblivre; i++)
	{
		printf("Titre: %s\n", bibliotheque[i].nom);
		printf("Auteur: %s\n", bibliotheque[i].auteur);
		printf("Annee d'edition: %d\n", bibliotheque[i].annee);
		printf("\n");

	}
	printf("\n");
	
	return 0;
}