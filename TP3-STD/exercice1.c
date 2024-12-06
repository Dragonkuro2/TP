#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure pour le contact
typedef struct contact {
	char name[100];
	unsigned int num;
} contact;

// Noeud de l'arbre de contacts
typedef struct Node {
	contact contact;
	struct Node *left;
	struct Node *right;
} Node;

// Fonction pour obtenir les informations du contact de l'utilisateur
contact *getContact() {
	contact *new_contact = malloc(sizeof(contact));
	if (!new_contact) {
		printf("Erreur d'allocation mémoire.\n");
		exit(EXIT_FAILURE);
	}

	printf("Entrez le nom du contact : ");
	scanf("%s", new_contact->name);
	printf("Entrez le numéro du contact : ");
	scanf("%u", &new_contact->num);

	return new_contact;
}

// Fonction pour créer un nouveau noeud
Node *create_node(contact *contact) {
	Node *new_node = malloc(sizeof(Node));
	if (!new_node) {
		printf("Erreur d'allocation mémoire.\n");
		exit(EXIT_FAILURE);
	}

	new_node->contact = *contact;
	new_node->left = NULL;
	new_node->right = NULL;

	printf("Nouveau contact ajouté :\n\tNom : %s\n\tNuméro : %u\n\n", contact->name, contact->num);
	return new_node;
}

// Fonction pour insérer un nouveau noeud dans l'arbre
Node *insert(Node *tree, contact *contact) {
	if (!tree) {
		return create_node(contact);
	} else if (strcmp(tree->contact.name, contact->name) > 0) {
		tree->left = insert(tree->left, contact);
	} else {
		tree->right = insert(tree->right, contact);
	}

	return tree;
}

// Fonction pour afficher tous les contacts
void afficher(Node *tree) {
	if (!tree)
		return;

	afficher(tree->left);
	printf("\nNom : %s\nNuméro : %u\n", tree->contact.name, tree->contact.num);
	afficher(tree->right);
}

// Fonction d'affichage avec un message si l'arbre est vide
void afficherAvecMessage(Node *tree) {
	if (!tree) {
		printf("La liste des contacts est vide !\n");
		return;
	}

	afficher(tree);
}

// Fonction pour rechercher un contact par nom
Node *searchName(Node *tree, char *name) {
	if (!tree) {
		printf("\nContact non trouvé.\n");
		return NULL;
	}

	if (strcmp(tree->contact.name, name) > 0)
		return searchName(tree->left, name);
	else if (strcmp(tree->contact.name, name) < 0)
		return searchName(tree->right, name);
	else {
		printf("\nContact trouvé :\n");
		printf("Nom : %s\n", tree->contact.name);
		printf("Numéro : %u\n", tree->contact.num);
		return tree;
	}
}

// Fonction pour demander à l'utilisateur de rechercher un contact
void search(Node *tree) {
	char name[30];
	printf("Entrez le nom à rechercher : ");
	scanf("%s", name);
	searchName(tree, name);
}

// Fonction pour trouver le plus grand noeud dans le sous-arbre gauche
Node *findLargestNode(Node *tree) {
	if (!tree || !tree->right) {
		return tree;
	}

	return findLargestNode(tree->right);
}

// Fonction pour supprimer un contact de l'arbre
Node *delete(Node *tree, char *name) {
	if (!tree) {
		printf("%s non trouvé dans l'arbre.\n", name);
		return NULL;
	}

	if (strcmp(name, tree->contact.name) < 0) {
		tree->left = delete(tree->left, name);
	} else if (strcmp(name, tree->contact.name) > 0) {
		tree->right = delete(tree->right, name);
	} else {
		if (tree->left && tree->right) {
			Node *temp = findLargestNode(tree->left);
			strcpy(tree->contact.name, temp->contact.name);
			tree->contact.num = temp->contact.num;
			tree->left = delete(tree->left, temp->contact.name);
		} else {
			Node *temp = tree;
			if (tree->left) {
				tree = tree->left;
			} else {
				tree = tree->right;
			}
			free(temp);
		}
	}

	return tree;
}

// Fonction principale
int main() {
	Node *tree = NULL;
	int choix;
	char nameDelete[40];

	do {
		printf("\t************ Menu : ************\n");
		printf("1- Insérer un nouveau contact\n");
		printf("2- Rechercher un contact\n");
		printf("3- Afficher tous les contacts\n");
		printf("4- Supprimer un contact\n");
		printf("5- Quitter\n");
		printf("\n\tEntrez votre choix : ");
		scanf("%d", &choix);

		switch (choix) {
			case 1: {
					contact *newContact = getContact();
					tree = insert(tree, newContact);
					free(newContact);
					break;
				}
			case 2:
				search(tree);
				break;
			case 3:
				afficherAvecMessage(tree);
				break;
			case 4:
				printf("Entrez le nom à supprimer : ");
				scanf("%s", nameDelete);
				tree = delete(tree, nameDelete);
				break;
			case 5:
				printf("À bientôt !\n");
				break;
			default:
				printf("Entrez une option valide !\n\n");
				break;
		}
	} while (choix != 5);

	return 0;
}

