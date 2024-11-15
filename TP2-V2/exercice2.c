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

	// exemples des functions
	Function func1 = {"add(int num1, int num2)"};
	Function func2 = {"delete(Node *top)"};

	// call push functions
	appeler_fonction(&Stack, func1);
	appeler_fonction(&Stack, func2);

	// call pop functions
	terminer_fonction(&Stack);

	// call peek functions
	fonction_active_actuelle(Stack);
	return (0);
}
