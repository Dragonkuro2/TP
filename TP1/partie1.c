#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int ID;
	char title[256];
	char author[120];
	bool disponible;
	struct livre *next;
} livre;


struct livre *ajoute_livre(struct livre *tail) {
	struct *livre new_node;
	// cette variable est pour verifie la disponiblite de livre
	char dispo[2];
	if (!new_node) {
		printf("Error allocation de memoire!\n");
		return (NULL);
	}

	printf("Entrer l'id de livre: ");
	scanf("%d", &new_node->ID);
	printf("Entrer le titre de livre: ");
	fgets(new_node.title, sizeof(new_node.title), stdin);
	printf("Entrer l'auteur du livre: ");
	fgets(new_node.author, sizeof(new_node.author), stdin);
	printf("Est-ce que le livre est disponible (s'il disponible entrer 'y' sinon entrer une autre littre): ");
	scanf("%c", &dispo);
	new_node->disponible = (dispo == 'y') ? true : false;

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
	struct livre *tail;
	if (!tail) {
		printf("Error allocation de memoire!\n");
		return (NULL);
	}

	ajouter_livre(tail);
}
