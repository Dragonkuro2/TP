#include <stdio.h>
#include <stdlib.h>


typedef struct patient {
	char name[60];
	int niveau;
	struct patient *next;
} patient;

void ajouter_patient(patient **front, patient **rear) {
	patient *new_node = malloc(sizeof(patient));

	if (!new_node) {
		printf("Error allocation de memoire.\n");
		return;
	}

	printf("Entrer le nome de neveau patient: ");
	scanf("%s", new_node->name);
	printf("Entrer son preority (de 0 a 2 cad 0 est plus preoritere que 1): ");
	scanf("%d", &new_node->niveau);

	if (*front == NULL && *rear == NULL) {
		*rear = *front = new_node;
	} else {
		(*rear)->next = new_node;
		*rear = new_node;
	}

	printf("le patient %s de poirety %d a ete ajouter.\n", (*rear)->name, (*rear)->niveau);
}

patient *servir_patient(patient **front, patient **rear) {
	if (*rear == NULL && *front == NULL) {
		printf("il n'y a rien à servir!\n");
		return NULL;
	} else {
		int priorite = 0;
		patient *current = *front;

		if (*rear == *front) {
			printf("le patient %s doit être servi maintenant.\n", (*front)->name);
			free(*front);
			*front = *rear = NULL;
			return NULL;
		}

		while (priorite < 3) {
			if ((*front)->niveau == priorite) {
				patient *to_free = *front;

				printf("le patient %s doit être servi maintenant.\n", to_free->name);
				*front = (*front)->next;
				free(to_free);
				if (*front == NULL) {
					*rear = NULL;
				}
				return to_free;
			}

			current = *front;
			while (current && current->next) {
				if (current->next->niveau == priorite) {
					patient *to_free = current->next;
					printf("le patient %s doit être servi maintenant.\n", to_free->name);
					current->next = current->next->next;
					free(to_free);


					if (current->next == NULL) {
						*rear = current;
					}

					return to_free;
				}
				current = current->next;
			}

			priorite++;
		}
	}
	return NULL;
}

void voir_prochain_patient(patient *front) {
	if (front == NULL) {
		printf("Il n'y a aucun patient en attente.\n");
		return;
	}

	int priorite = 0;
	patient *current = front;
	patient *next_patient = NULL;

	while (priorite < 3) {
		current = front;  // Reset current to the front for each priority level
		while (current) {
			if (current->niveau == priorite) {
				next_patient = current;
				break;
			}
			current = current->next;
		}
		if (next_patient != NULL) {
			break;
		}
		priorite++;
	}
	if (next_patient) {
		printf("Le prochain patient à servir est %s avec une priorité de %d.\n", next_patient->name, next_patient->niveau);
	} else {
		printf("Aucun patient trouvé dans la liste.\n");
	}
}


int main() {
	patient *front = NULL;
	patient *rear = NULL;

	ajouter_patient(&front, &rear);

	return (0);
}
