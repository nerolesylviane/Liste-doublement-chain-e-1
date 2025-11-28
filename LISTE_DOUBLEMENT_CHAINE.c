#include <stdio.h>
#include <stdlib.h>

// 1. Définition de la structure du Nœud
typedef struct Node {
    int data;           
    struct Node *prev;  
    struct Node *next;  
} Node;

// Pointeur global vers la Tête de la liste
Node *head = NULL; 

// Crée un nouveau nœud
Node* createNode(int data) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Erreur d'allocation memoire.\n");
        exit(1);
    }
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// 2. Insertion en tête
void insertAtHead(int data) {
    Node *newNode = createNode(data);

    if (head == NULL) {
        head = newNode;
    } 
    else {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
    printf("Noeud %d inséré en tete.\n", data);
}

// 3. Suppression d'un nœud par valeur
void deleteNode(int value) {
    Node *current = head;

    while (current != NULL && current->data != value) {
        current = current->next;
    }

    if (current == NULL) {
        printf("Le noeud avec la valeur %d n'a pas ete trouve.\n", value);
        return;
    }

    if (current == head) {
        head = current->next;
        if (head != NULL) {
            head->prev = NULL;
        }
    } 
    else {
        current->prev->next = current->next;
        if (current->next != NULL) {
            current->next->prev = current->prev;
        }
    }

    printf("Noeud %d supprime.\n", current->data);
    free(current);
}

// Affichage
void displayList() {
    Node *current = head;
    printf("\nListe (Tete -> Queue): ");
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

// --- Menu Principal ---
int main() {
    int choix, valeur;

    do {
        printf("\n===== MENU =====\n");
        printf("1. Inserer un noeud en tete\n");
        printf("2. Supprimer un noeud\n");
        printf("3. Afficher la liste\n");
        printf("4. Quitter\n");
        printf("Votre choix : ");
        scanf("%d", &choix);

        switch (choix) {
            case 1:
                printf("Entrez la valeur a inserer : ");
                scanf("%d", &valeur);
                insertAtHead(valeur);
                break;

            case 2:
                printf("Entrez la valeur à supprimer : ");
                scanf("%d", &valeur);
                deleteNode(valeur);
                break;

            case 3:
                displayList();
                break;

            case 4:
                printf("Fin du programme.\n");
                break;

            default:
                printf("Choix invalide.\n");
        }

    } while (choix != 4);

    return 0;
}
