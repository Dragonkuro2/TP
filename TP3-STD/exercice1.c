#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// structur of the conatct
typedef struct contact {
	char name [100];
	unsigned int num;
} contact;

// node of the contact
typedef struct Node {
	contact contact;
	struct Node *left;
	struct Node *right;
} Node;

// function that gets the information of the contact from the user
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

// function that create a new node of the contact tree
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


// function that insert the new node to the list
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

// recursive function that prints all the elements of the list
void afficher(Node *tree) {
	if (!tree)
		return;

	afficher(tree->left);
	printf("\nNom: %s\nNemuro: %u\n", tree->contact.name, tree->contact.num);
	afficher(tree->right);
}


// this function shows an additional message that shows if the list is empty
void afficherAvecMessage(Node *tree) {
	if (!tree) {
		printf("La liste est vide!\n");
		return;
	}

	afficher(tree);
}

Node *searchName(Node *tree, char *name) {
	if (tree == NULL) {
		printf("\nContact non trouvé.\n");
		return NULL;
	}

	if (strcmp(tree->contact.name, name) > 0)
		return searchName(tree->left, name);
	else if (strcmp(tree->contact.name, name) < 0)
		return searchName(tree->right, name);
	else {
		printf("\nContact trouvé:\n");
		printf("Nom: %s\n", tree->contact.name);
		printf("Phone: %u\n", tree->contact.num);
	}
}

void search(Node *tree) {
	char name[30];
	printf("Entrer le nom a chercher: ");
	scanf("%s", name);
	searchName(tree, name);
}

// main function
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
				search(tree);
				break;
			case 3:
				afficherAvecMessage(tree);
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
