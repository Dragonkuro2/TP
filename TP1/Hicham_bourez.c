#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct livre {
    int ID;
    char title[256];
    char author[120];
    bool disponible;
    struct livre *next;
} livre;

struct livre *ajouter_livre(struct livre *tail) {
    struct livre *new_node = malloc(sizeof(livre));
    char dispo;

    if (!new_node) {
        printf("Error allocation de memoire!\n");
        return NULL;
    }

    printf("Entrer l'id de livre: ");
    scanf("%d", &new_node->ID);
    getchar(); // Consume newline after ID input
    printf("Entrer le titre de livre: ");
    fgets(new_node->title, sizeof(new_node->title), stdin);
    new_node->title[strcspn(new_node->title, "\n")] = '\0';

    printf("Entrer l'auteur du livre: ");
    fgets(new_node->author, sizeof(new_node->author), stdin);
    new_node->author[strcspn(new_node->author, "\n")] = '\0';

    printf("Est-ce que le livre est disponible (s'il disponible entrer 'y' sinon entrer une autre littre): ");
    scanf(" %c", &dispo); // Added space before %c to consume any leftover whitespace
    new_node->disponible = (dispo == 'y');

    if (!tail) {
        new_node->next = new_node; // Circular link for the first node
        return new_node;
    } else {
        new_node->next = tail->next; // Insert after tail
        tail->next = new_node;
        return new_node; // Return new tail
    }
}

void afficher_livre(struct livre *tail) {
    if (!tail) {
        printf("La liste est vide!\n");
        return;
    }

    struct livre *current = tail->next; // Start from the head
    do {
        printf("L'id de livre est: %d\n", current->ID);
        printf("Le titre de livre est: %s\n", current->title);
        printf("L'auteur de livre est: %s\n", current->author);
        printf("Le livre est: %s\n", current->disponible ? "disponible" : "non-disponible");

        current = current->next;
    } while (current != tail->next);
}

struct livre *supprimer_livre(struct livre *tail, int id) {
    if (!tail) {
        printf("La liste est vide!\n");
        return tail;
    }

    struct livre *current = tail;
    struct livre *to_delete = NULL;

    if (tail->ID == id) {
        while (current->next != tail) {
            current = current->next;
        }
        current->next = tail->next;
        to_delete = tail;
        if (current->next == current) {
            free(to_delete);
            return NULL; // List becomes empty
        }
        free(to_delete);
        return current->next; // New tail
    }

    while (current->next != tail && current->next->ID != id) {
        current = current->next;
    }

    if (current->next->ID == id) {
        to_delete = current->next;
        current->next = current->next->next;
        free(to_delete);
        printf("L'element a ete supprimer avec success\n");
    } else {
        printf("L'element n'existe pas!\n");
    }

    return tail;
}

struct livre *recherche_livre(struct livre *tail, int id) {
    if (!tail) {
        printf("La liste est vide!\n");
        return NULL;
    }

    struct livre *current = tail->next; // Start from the head
    do {
        if (current->ID == id) {
            return current;
        }
        current = current->next;
    } while (current != tail->next);

    printf("L'élément n'existe pas!\n");
    return NULL;
}

struct livre *modifie_livres(struct livre *tail) {
    int choose;
    int id;
    struct livre *current;

    printf("Tu dois modifier quoi?\n");
    printf("1: titre\n");
    printf("2: auteur\n");
    printf("3: disponible\n");
    printf("Entrer votre choix: ");
    scanf("%d", &choose);
    printf("Entrer l'id de livre: ");
    scanf("%d", &id);
    current = recherche_livre(tail, id);
    getchar(); // Consume newline after ID input

    if (current) {
        switch (choose) {
            case 1:
                printf("Entrer le nouveau titre: ");
                fgets(current->title, sizeof(current->title), stdin);
                current->title[strcspn(current->title, "\n")] = '\0';
                break;
            case 2:
                printf("Entrer le nouveau auteur: ");
                fgets(current->author, sizeof(current->author), stdin);
                current->author[strcspn(current->author, "\n")] = '\0';
                break;
            case 3:
                char dispo;
                printf("Est-ce que le livre est disponible? (Entrer 'y' s'il est disponible sinon entrer une autre lettre): ");
                scanf(" %c", &dispo);
                current->disponible = (dispo == 'y');
                break;
            default:
                printf("Le choix n'est pas valable\n");
                break;
        }
    }
    return tail;
}

int main() {
    struct livre *tail = NULL; // Initialize tail as NULL
    int choose;

    do {
        printf("-------------------- Menu --------------------\n");
        printf("1: ajout de livres.\n");
        printf("2: suppression de livres.\n");
        printf("3: modification des informations d'un livre.\n");
        printf("4: recherche de livre.\n");
        printf("5: afficher les livres.\n");
        printf("0: terminer.\n");
        printf("Entrer une valeur: ");
        scanf("%d", &choose);

        switch (choose) {
            case 1:
                tail = ajouter_livre(tail);
                break;
            case 2: {
                int id;
                do {
                    printf("Entrer l'id de livre (id est toujours > 0): ");
                    scanf("%d", &id);
                } while (id <= 0);
                tail = supprimer_livre(tail, id);
                break;
            }
            case 3:
                tail = modifie_livres(tail);
                break;
            case 4: {
                int id;
                struct livre *current;
                printf("Entrer l'id de votre livre: ");
                scanf("%d", &id);
                current = recherche_livre(tail, id);
                if (current) {
                    printf("L'element a ete trouve\n");
                    printf("Le titre de livre est: %s\n", current->title);
                    printf("L'auteur de livre est: %s\n", current->author);
                    printf("Le livre est: %s\n", current->disponible ? "disponible" : "non-disponible");
                } else {
                    printf("Le livre n'existe pas!\n");
                }
                break;
            }
            case 5:
                afficher_livre(tail);
                break;
            case 0:
                printf("See you next time :)\n");
                break;
            default:
                printf("Invalid option\n");
                break;
        }
    } while (choose != 0);

    // Free the memory for the books before exiting
    if (tail) {
        struct livre *current = tail->next;
        struct livre *next;
        do {
            next = current->next;
            free(current);
            current = next;
        } while (current != tail->next);
    }

    return 0;
}

