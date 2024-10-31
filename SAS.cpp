#include <stdio.h>
#include <string.h>
#define max 30

typedef struct {
    int jour;
    int mois;
    int annee;
} date;

typedef struct {
    char titre[50];       // Changed to an array
    char description[100]; // Changed to an array
    date dt;
    char priorite[10];     // Changed to an array
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
    printf("Entrer la priorite (High / Low): ");
    scanf("%s", tc.priorite);
    
    return tc;
}

// Function to display tasks
void afficher(tache tc[], int nbr_tache) {
    for (int i = 0; i < nbr_tache; i++) {
        printf("Titre: %s\n", tc[i].titre);    
        printf("Description: %s\n", tc[i].description);
        printf("~~~~~~~~ Date de creation: ~~~~~~~~\n");
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
            printf("Titre: %s\n", tc[i].titre);    
            printf("Description: %s\n", tc[i].description);
            printf("~~~~~~~~ Date de création: ~~~~~~~~\n");
            printf("%d / %d / %d\n", tc[i].dt.jour, tc[i].dt.mois, tc[i].dt.annee);
            printf("Priorité: %s\n", tc[i].priorite);
            found = 1;
        }
    }
    
    if (!found) {
        printf("Aucune tâche trouvée avec cette priorité.\n");
    }
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
        scanf("%d", &choix);
        
        switch (choix) {
            case 1:
                if (nbr_tache < max) {
                    taches[nbr_tache] = add(); // Add a new task
                    nbr_tache++; // Increment number of tasks
                } else {
                    printf("Limite de taches atteinte.\n");
                }
                break;

            case 2:
                if (nbr_tache == 0) { // Check if tasks exist
                    printf("Pas de tache à afficher.\n");
                } else {
                    afficher(taches, nbr_tache); // Display tasks
                }
                break;

            case 3:
                if (nbr_tache == 0) { // Check if tasks exist
                    printf("Pas de tache à modifier.\n");
                } else {
                    printf("\n____Vous avez %d taches____\n", nbr_tache); 
                    int index;
                    printf("Entrer l'index pour modifier : ");
                    scanf("%d", &index);
                    if (index >= 0 && index < nbr_tache) { // Check index validity
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
                filtrer(taches, nbr_tache); // Filtrer les tâches
                break;

            case 6:
                printf("Au revoir!\n");
                break;

            default:
                printf("Choix invalide, veuillez réessayer.\n");
}

}while(choix!=7);

 return 0;
}
