#include <stdio.h>
#include <stdlib.h>


typedef struct Function {
	char name[80];
}Function;

typedef struct Node {
	Function funcname;
	struct Node *next;
} Node;

void appeler_fonction(Node **top ,Function function) {
	Node *new_node = malloc(sizeof(Node));
	if (!new_node) {
		printf("Error allocation de memoire.\n");
		return;
	}

	new_node->funcname = function;
	new_node->next = *top;
	*top = new_node;
	printf("la fonction '%s' a ete ajouter au stack.\n", new_node->funcname.name);
}

Function terminer_fonction(Node **top) {
	if (!*top) {
		printf("Stack is empty already!\n");
		exit(1);
	}

	Function current = (*top)->funcname;
	*top = (*top)->next;
	printf("la function '%s' est terminer.\n", current.name);
	return (current);
}

void fonction_active_actuelle(Node *top) {
	if (!top) {
		printf("aucun function est active actuellement.\n");
	} else {
		printf("la fonction active actuellement est: '%s'\n", top->funcname.name);
	}
}

int main() {
	Node *Stack = NULL;
	int choix;

	do {
		printf("\t********** Menu **********\n\n");
		printf("1. ajouter une fonction\n");
		printf("2. terminer la derniere fonction\n");
		printf("3. afficher la fonction actuelle\n");
		printf("4. Quitter\n\n");
		printf("Entrer votre choix: ");
		scanf("%d", &choix);

		switch (choix) {
			case 1:
				Function func;
				printf("Entrer la fonction: ");
				scanf("%s", func.name);
				appeler_fonction(&Stack, func);
				break;
			case 2:
				terminer_fonction(&Stack);
				break;
			case 3:
				fonction_active_actuelle(Stack);
				break;
			case 4:
				break;
			default:
				printf("Entrer une valide choix.\n");
		}
	} while (choix != 4);

	return (0);
}
