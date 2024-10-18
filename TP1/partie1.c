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


void afficher_livre(struct livre *tail) {
	if (!tail) {
		printf("la liste est vide!\n");
	} else {
		struct livre *current = tail;
		do {
			printf("l'id de livre est: %d\n", current->ID);
			printf("le titre de livre est: %s\n", current->title);
			printf("l'auteur de livre est: %s\n", current->author);
			printf("le livre est: %s\n", current->disponible ? "disponible" : "non-disponible");

			current = current->next;
		} while(current != tail->next);
	}
}


struct livre *supprimer_livre(struct livre *tail, int id) {
	if (!tail) {
		printf("la liste est vide!\n");
		return (tail);
	} else {
		struct livre *current = tail;

		if (tail->ID == id) {
			while (current->next != tail)
				current = current->next;
			current->next = tail->next;
			free(tail);
			if (current->next == current) {
				printf("la liste est vide mantenet!\n");
				return (NULL);
			}
			return (current->next);
		}

		while (current->next != tail && current->next->ID != id) {
			current = current->next;
		}

		if (current->next->ID == id) {
			struct livre *to_delete = current->next;
			current->next = current->next->next;
			free(to_delete);
			printf("l'element a ete supprimer avec success\n");
		} else {
			printf("l'element n'nexist pas!\n");
		}

		return (tail);
	}
}

int main() {
	struct livre *tail = malloc(sizeof(livre));
	if (!tail) {
		printf("Error allocation de memoire!\n");
		return (1);
	}
	int choose;
	do {
		printf("-------------------- Menu --------------------\n");
		printf("1: ajout de livres.\n");
		printf("2: suppression de livres.\n");
		printf("3: modification des informations d'un livre.\n");
		printf("4: recherche de livre.\n");
		printf("5: afficher les livres.\n");
		printf("0: terminer.\n");
		printf("Entrer une valeur: ");
		scanf("%d", &choose);
		switch (choose) {
			case 1:
				tail = ajouter_livre(tail);
				break;
			case 2:
				int id;
				do {
					printf("Entrer l'id de livre (id est toujor > 0): ");
					scanf("%d", &id);
				} while (id <= 0);
				tail = supprimer_livre(tail, id);
				break;
			case 3:
				printf("the function isn't working yet :(\n");
				break;
			case 4:
				printf("the function isn't working yet :(\n");
				break;
			case 5:
				afficher_livre(tail);
				break;
			case 0:
				printf("See u next time :)\n");
				break;
			default:
				printf("invalid option\n");
				break;
		}
	} while(choose != 0);
}
