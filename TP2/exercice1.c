#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// programme de gestion d'action.
typedef struct Action {
        char string[100];
        int type;
} Action;

typedef struct Stack {
	Action action;
	struct Stack *next;
} Stack;


Stack *ajouter(Action *action, Stack *top) {
	Stack *new_node = malloc(sizeof(Stack));
	if (!new_node) {
		printf("Error allocation de memoire.\n");
		return NULL;
	}

	new_node->action = *action;
	new_node->next = top;

	return (new_node);

}

const char *type(int num) {
	if (num == 1)
		return "ajouter";
	else if (num == 2)
		return "sumprimer";
	else if (num == 3)
		return "modifier";
	else
		return "unknown";
}

void afficher(Stack *top) {
	Stack *current = top;

	if (!top) {
		printf("le file est vide!.\n");
	} else {
		printf("L'historique des operation sont:");
		while (current->next) {
			printf("le text \"%s\" a ete %s\n", top->action.string, type(top->action.type));
			current = current->next;
		}
	}
}
int main() {
	Stack *top = NULL;
	Action *actions[4];
	char *texts[] = {"first text", "second text", "third text", "fourth text"};
	int types[] = {1, 2, 3, 2};

	for (int i = 0; i < 4; i++) {
		actions[i] = malloc(sizeof(Action));
		if (actions[i] == NULL) {
			printf("Error allocation de memoire.\n");
			return 1;
		}
		strcpy(actions[i]->string, texts[i]);
		actions[i]->type = types[i];

		top = ajouter(actions[i], top);
	}

	afficher(top);

	return (0);
}
