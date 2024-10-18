#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>


typedef struct livre {
	int ID;
	char title[256];
	char author[120];
	bool disponible;
	struct livre *next;
} livre;


struct livre *ajouter_livre(struct livre *tail) {
	struct livre *new_node = malloc(sizeof(livre));
	// cette variable est pour verifie la disponiblite de livre
	char dispo;

	if (!new_node) {
		printf("Error allocation de memoire!\n");
		return (NULL);
	}

	printf("Entrer l'id de livre: ");
	scanf("%d", &new_node->ID);
	getchar();
	printf("Entrer le titre de livre: ");
	fgets(new_node->title, sizeof(new_node->title), stdin);
	// ce ligne est pour eveter le problem de '\n' de stdin
	new_node->title[strcspn(new_node->title, "\n")] = '\0';

	printf("Entrer l'auteur du livre: ");
	fgets(new_node->author, sizeof(new_node->author), stdin);
	new_node->author[strcspn(new_node->author, "\n")] = '\0';

	printf("Est-ce que le livre est disponible (s'il disponible entrer 'y' sinon entrer une autre littre): ");
	scanf("%c", &dispo);
	new_node->disponible = (dispo == 'y');

	if (!tail) {
		new_node->next = new_node;
		printf("le livre a ete ajoute avec success\n");
		return (new_node);
	} else {
		new_node->next = tail->next;
		tail->next = new_node;
		printf("le livre a ete ajoute avec success\n");
		return (new_node);
	}
}

int main() {
	struct livre *tail = malloc(sizeof(livre));
	if (!tail) {
		printf("Error allocation de memoire!\n");
		return (1);
	}

	ajouter_livre(tail);
}
