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
	int i = 0;
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
	
	(*nblivre)++;
}


int main() 
{
	Livre bibliotheque[100];
	int nblivre = 0;
	  


	puts("====== BIBLIOTHEQUE ======\n");
	puts("1. Ajouter un livre \n");
	puts("2. Afficher un livre \n");
	puts("3. Rechercher un livre \n");
	puts("4. Supprimer un livre \n");
	puts("Votre choix \n");
	
	ajoutlivre(bibliotheque, &nblivre);
	printf("%p\n", &nblivre);

	ajoutlivre(bibliotheque, &nblivre);
	printf("%d\n", &nblivre);
	
	printf("Le nombre de livre dans la bibliotheque est de: %d\n", nblivre);
	return 0;
}