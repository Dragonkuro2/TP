#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct contact {
	char name [100];
	unsigned int num;
} contact;

typedef struct Node {
	contact contact;
	struct Node *left;
	struct Node *right;
} Node;

contact *getContact() {
	contact *new_contact = malloc(sizeof(contact));
	if (!new_contact) {
		printf("Error allocation de memoire.\n");
		exit(EXIT_FAILURE);
	}

	printf("Entrer le nom de votre contact: ");
	scanf("%s", new_contact->name);
	printf("Entrer le nemuro de votre contact: ");
	scanf("%u", &new_contact->num);

	return (new_contact);
}

Node *create_node(contact *contact) {
	Node *new_node = malloc(sizeof(Node));
	
	if (!new_node) {
		printf("Error allocation de memoire.\n");
		exit(1);
	}	

	new_node->contact = *contact;
	new_node->left = NULL;
	new_node->right = NULL;
	printf("new contact added.\n\tnom: %s\n\tnemuro: %u\n\n", contact->name, contact->num);

	return (new_node);
}

Node *insert(Node *tree, contact *contact) {
	if (!tree) {
		return (create_node(contact));
	} else if ( strcmp(tree->contact.name , contact->name) > 0) {
		tree->left = insert(tree->left, contact);
	} else {
		tree->right = insert(tree->right, contact);
	}
	
	return (tree);
}

int afficher(Node *tree) {
	if (!tree){
		printf("la liste des contact est vide!\n");
		return 0;
	}
	
	afficher(tree->left);
	printf("\n\tNom: %s\nNemuro: %u\n", tree->contact.name, tree->contact.num);
	afficher(tree->right);
}

int main() {
	Node *tree = NULL;
	int choix;

	do {
		printf("\t************ Menu: ************\n");
		printf("1- Inserer une nouvelle contact\n");
		printf("2- rechercher une contact\n");
		printf("3- afficher tout les contacts\n");
		printf("4- supprimer un contact\n");
		printf("5- Quitter\n");
		printf("\n\tEntrer votre choix: ");
		scanf("%d", &choix);

		switch (choix) {
			case 1:
				contact *Contact = getContact();
				tree = insert(tree, Contact);
				break;
			case 2:
				break;
			case 3:
				afficher(tree);
				break;
			case 4:
				break;
			case 5:
				break;
			default:
				printf("Entrer une valide option!\n\n");
				break;
		}
	} while (choix != 5);
	return (0);
}
