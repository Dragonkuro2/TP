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

	printf("Entrer un nombre a ajouter au debut de liste: ");
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

	printf("l'element %d a ete ajouter avec success au debut de liste.\n", data);
	return (head);
}


struct node *ajouter_element_fin(struct node *head) {
	struct node *current = head;
	struct node *new_node = malloc(sizeof(struct node));
	int data;

	if (!new_node) {
		printf("Error allocation de memoire.\n");
		return (head);
	}

	printf("Entrer une elemenet a ajouter au fin de liste: ");
	if(scanf("%d", &data) != 1) {
		printf("invalid input!.\n");
		free(new_node);
		return (head);
	}

	new_node->next = NULL;
	new_node->data = data;

	if (!head) {
		new_node->prev = NULL;
		head = new_node;
	} else {
		while (current->next) {
			current = current->next;
		}

		new_node->prev = current;
		current->next = new_node;
	}

	printf("l'elemenet %d a ete ajouter avec success a la fin de la liste.\n", data);
	return (head);
}

int main() {
	struct node *head = NULL;

	head = ajouter_element_debut(head);
	head = ajouter_element_fin(head);

	return (0);
}
