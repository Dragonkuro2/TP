#include <stdio.h>
#include <stdlib.h>


struct node {
	struct node *prev;
	int data;
	struct node *next;
};

struct node *ajouter_element_debut(struct node *head) {
	int data;
	struct node *new_node = malloc(sizeof(struct node));

	if (!new_node) {
		printf("Error allocation de memoire.\n");
		return (head);
	}

	printf("Entrer un nombre a ajouter a la liste: ");
	if (scanf("%d", &data) != 1) {
		printf("Invalid input.\n");
		free(new_node);
		return (head);
	}

	new_node->prev = NULL;
	new_node->data = data;

	if (!head) {
		new_node->next = NULL;
		head = new_node;
	} else {
		head->prev = new_node;
		new_node->next = head;
		head = new_node;
	}

	printf("l'element %d a ete ajouter avec success a la listes.\n", data);
	return (head);
}

int main() {
	struct node *head = NULL;

	head = ajouter_element_debut(head);

	return (0);
}
