#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define max 30

typedef struct {
    int jour;
    int mois;
    int annee;
} date;

typedef struct {
    char titre[50];      
    char description[100]; 
    date dt;
    char priorite[10];     
} tache;

// Function to create a new task
tache add() {
    tache tc;

    printf("Entrer le titre d'une tache: ");
    scanf("%s", tc.titre);
    printf("Entrer la description de la tache: ");
    scanf("%s", tc.description);
    printf("Entrer la date de la tache:\n");
    printf("Le jour : ");    
    scanf("%d", &tc.dt.jour);
    printf("Le mois: ");
    scanf("%d", &tc.dt.mois);
    printf("L'annee: ");
    scanf("%d", &tc.dt.annee);
    printf("Entrer la priorite (Haute / Basse) : ");
    scanf("%s", tc.priorite);
    
    return tc;
}

// Function to display tasks
void afficher(tache tc[], int nbr_tache) {
    printf("Liste des taches : \n");

    for (int i = 0; i < nbr_tache; i++) {
        printf("~~~~~~~ taches %d.~~~~~~~~\n",i+1);
        printf("Titre: %s\n", tc[i].titre);    
        printf("Description: %s\n", tc[i].description);
        printf("-Date de creation: \n");
        printf("%d / %d / %d\n", tc[i].dt.jour, tc[i].dt.mois, tc[i].dt.annee);
        printf("Priorite: %s\n", tc[i].priorite);
    }    
}

// Function to modify a task
void modifier(tache tc[], int index) {
    printf("Modifier les informations de: %s\n", tc[index].titre);
    printf("Entrer le nouveau titre: ");
    scanf("%s", tc[index].titre);
    printf("Entrer la nouvelle description: ");
    scanf("%s", tc[index].description);
    printf("*** Modifier la date de creation: ***\n");
    printf("Entrer le nouveau jour: ");
    scanf("%d", &tc[index].dt.jour);
    printf("Entrer le nouveau mois: ");
    scanf("%d", &tc[index].dt.mois);
    printf("Entrer la nouvelle annee: ");
    scanf("%d", &tc[index].dt.annee);
    printf("Entrer la nouvelle priorite: ");
    scanf("%s", tc[index].priorite);
}

// Function to delete a task
void supprimer(tache taches[], int *nbr_tache, int index) {
    for (int i = index; i < (*nbr_tache) - 1; i++) {
        taches[i] = taches[i + 1]; // Shift tasks left
    }
    (*nbr_tache)--; // Decrement the number of tasks
}

// Fonction pour filtrer les tâches par priorité
void filtrer(tache tc[], int nbr) {
    if (nbr == 0) {
        printf("Aucune tâche à filtrer.\n");
        return;
    }
    
    char priorite[10];
    printf("Entrez la priorité à filtrer (Haute / Basse) : ");
    scanf("%s", priorite);

    printf("Tâches avec la priorité %s :\n", priorite);
    int found = 0;
    for (int i = 0; i < nbr; i++) {
        if (strcmp(tc[i].priorite, priorite) == 0) {
            printf("~~~~~~~ taches %d.~~~~~~~~\n",i+1);
            printf("Titre: %s\n", tc[i].titre);    
            printf("Description: %s\n", tc[i].description);
            printf("- Date de création: \n");
            printf("%d / %d / %d\n", tc[i].dt.jour, tc[i].dt.mois, tc[i].dt.annee);
            printf("Priorité: %s\n", tc[i].priorite);
            found = 1;
        }
    }
    
    if (!found) {
        printf("Aucune tâche trouvée avec cette priorité.\n");
    }
}

// Nouvelle fonction pour confirmer la sortie
int confirmerSortie() {
    char reponse;
    printf("\nVoulez-vous vraiment quitter le programme ? (O/N): ");
    while (getchar() != '\n');
    scanf("%c", &reponse);
    return (tolower(reponse) == 'o');
}

int main() {
    int choix;
    tache taches[max];
    int nbr_tache = 0;
    
    do {
        printf("\n********Menu********\n");
        printf("1. Ajouter une tache\n");
        printf("2. Afficher les taches\n");
        printf("3. Modifier une tache\n");
        printf("4. Supprimer une tache\n");
        printf("5. Filtrer une tache\n");
        printf("6. Quitter\n");
        printf("*********************\n");
        printf("~Votre choix : ");
        
        if(scanf("%d", &choix) != 1) {
            printf("Erreur : Veuillez entrer un nombre.\n");
            while(getchar() != '\n');
            continue;
        }
        
        switch (choix) {
            case 1:
                if (nbr_tache < max) {
                    taches[nbr_tache] = add();
                    nbr_tache++;
                    printf("\nTâche ajoutée avec succès!\n");
                } else {
                    printf("Limite de taches atteinte.\n");
                }
                break;

            case 2:
                if (nbr_tache == 0) {
                    printf("Pas de tache à afficher.\n");
                } else {
                    afficher(taches, nbr_tache);
                }
                break;

            case 3:
                if (nbr_tache == 0) {
                    printf("Pas de tache à modifier.\n");
                } else {
                    printf("\n____Vous avez %d taches____\n", nbr_tache);
                    int index;
                    printf("Entrer l'index pour modifier : ");
                    scanf("%d", &index);
                    if (index >= 0 && index < nbr_tache) {
                        modifier(taches, index);
                    } else {
                        printf("Indice invalide.\n");
                    }
                }
                break;
    
            case 4:
                if (nbr_tache == 0) {
                    printf("Pas de tache à supprimer.\n");
                } else {
                    int index;
                    printf("Entrer l'index de tache à supprimer : ");
                    scanf("%d", &index);
                    if (index >= 0 && index < nbr_tache) {
                        supprimer(taches, &nbr_tache, index);
                        printf("Tache supprimée.\n");
                    } else {
                        printf("Indice invalide.\n");
                    }
                }
                break;

            case 5:
                filtrer(taches, nbr_tache);
                break;

            case 6:
                if (confirmerSortie()) {
                    printf("\nAu revoir! Merci d'avoir utilisé notre gestionnaire de tâches.\n");
                    return 0;
                }
                break;

            default:
                printf("Choix invalide, veuillez réessayer.\n");
        }
    } while(1); // Boucle infinie qui ne se termine que par return dans case 6

    return 0;
}
