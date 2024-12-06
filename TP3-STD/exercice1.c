#include <stdio.h>
#include <stdlib.h>

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

	return (new_node);
}

Node *insert(Node *tree, contact *contact) {
	if (!tree) {
		return (create_node(contact));
	} else if (tree->contact.name > contact->name) {
		tree->left = insert(tree->left, contact);
	} else {
		tree->right = insert(tree->right, contact);
	}
	
	printf("new contact added.\n\tnom: %s\n\tnemuro: %u\n\n", contact->name, contact->num);
	return (tree);
}

int main() {
	Node *tree = NULL;

	contact *Contact = getContact();
	tree = insert(tree, Contact);

	return (0);
}
