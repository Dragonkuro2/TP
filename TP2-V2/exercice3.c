#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct patient {
	char name[60];
	int niveau;
	struct patient *next;
} patient;

void ajouter_patient(patient **front, patient **rear) {
	patient *new_node = malloc(sizeof(patient));

	if (!new_node) {
		printf("Erreur d'allocation de mémoire.\n");
		return;
	}

	printf("Entrer le nom du nouveau patient: ");
	scanf("%s", new_node->name);
	printf("Entrer sa priorité (de 0 à 2, où 0 est plus prioritaire que 1): ");
	scanf("%d", &new_node->niveau);
	new_node->next = NULL;

	if (*front == NULL && *rear == NULL) {
		*rear = *front = new_node;
	} else {
		(*rear)->next = new_node;
		*rear = new_node;
	}

	printf("Le patient %s avec priorité %d a été ajouté.\n", (*rear)->name, (*rear)->niveau);
}

patient *servir_patient(patient **front, patient **rear) {
	if (*rear == NULL && *front == NULL) {
		printf("Il n'y a rien à servir!\n");
		return NULL;
	} else {
		int priorite = 0;
		patient *current = *front;

		if (*rear == *front) {
			printf("Le patient %s doit être servi maintenant.\n", (*front)->name);
			free(*front);
			*front = *rear = NULL;
			return NULL;
		}

		while (priorite < 3) {
			if ((*front)->niveau == priorite) {
				patient *to_free = *front;

				printf("Le patient %s doit être servi maintenant.\n", to_free->name);
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
					printf("Le patient %s doit être servi maintenant.\n", to_free->name);
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
		current = front;
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

void afficher_patients(patient *front) {
	if (front == NULL) {
		printf("La liste des patients est vide.\n");
		return;
	}

	printf("Liste des patients:\n");
	while (front) {
		printf("Nom: %s, Priorité: %d\n", front->name, front->niveau);
		front = front->next;
	}
}

int main() {
	patient *front = NULL;
	patient *rear = NULL;
	int choix;
	bool running = true;

	while (running) {
		printf("\nMenu:\n");
		printf("1. Ajouter un patient\n");
		printf("2. Servir un patient\n");
		printf("3. Voir le prochain patient\n");
		printf("4. Afficher tous les patients\n");
		printf("5. Quitter\n");
		printf("Entrez votre choix: ");
		scanf("%d", &choix);

		switch (choix) {
			case 1:
				ajouter_patient(&front, &rear);
				break;
			case 2:
				servir_patient(&front, &rear);
				break;
			case 3:
				voir_prochain_patient(front);
				break;
			case 4:
				afficher_patients(front);
				break;
			case 5:
				running = false;
				printf("Au revoir!\n");
				break;
			default:
				printf("Choix invalide. Veuillez réessayer.\n");
		}
	}

	return 0;
}

