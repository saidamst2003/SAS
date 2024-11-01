#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define max 30 // Structure principale pour une tâche
// Structure pour gérer les dates
typedef struct { 
    int jour;
    int mois;
    int annee;
} date;
// Structure principale pour une tâche
typedef struct {
    char titre[50];       // Titre de la tâche (limité à 50 caractères)
    char description[100]; // Description détaillée (limitée à 100 caractères)
    date dt;              // Date de la tâche (utilise la structure date)
    char priorite[10];    // Niveau de priorité (Haute ou Basse)
} tache;
// Fonction qui demande à l'utilisateur les détails d'une nouvelle tâche
// Retourne une structure tache complètement remplie
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

// Fonction qui affiche la liste de toutes les tâches existantes
void afficher(tache tc[], int nbr_tache) { 
// tc[]: tableau contenant toutes les tâches
// nbr_tache: nombre total de tâches à afficher
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

// Fonction qui permet de modifier une tâche existante

void modifier(tache tc[], int index) {
// tc[]: tableau de tâches
// index: position de la tâche à modifier dans le tableau
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

// Fonction qui supprime une tâche du tableau
// taches[]: tableau de toutes les tâches
// *nbr_tache: pointeur vers le nombre total de tâches (modifié après suppression)
// index: position de la tâche à supprimer
void supprimer(tache taches[], int *nbr_tache, int index) {
    for (int i = index; i < (*nbr_tache) - 1; i++) {
        taches[i] = taches[i + 1]; 
    }
    (*nbr_tache)--; 
}
// Fonction qui filtre et affiche les tâches selon leur priorité
// tc[]: tableau de tâches à filtrer
// nbr: nombre total de tâches dans le tableau
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

// Fonction qui demande confirmation avant de quitter le programme
int confirmerSortie() {
    char reponse;
    printf("\nVoulez-vous vraiment quitter le programme ? (O/N): ");
    while (getchar() != '\n');
    scanf("%c", &reponse);
    return (tolower(reponse) == 'o');// Retourne 1 si l'utilisateur confirme, 0 sinon
}
// Fonction principale du programme
// Gère le menu principal et coordonne toutes les opérations
int main() {
   
    int choix;            // Stocke le choix de l'utilisateur dans le menu
    tache taches[max];    // Tableau pour stocker toutes les tâches (maximum défini par max)
    int nbr_tache = 0;    // Compteur du nombre actuel de tâches
    
    // Boucle principale du programme
    do {
    	  // Affichage du menu avec toutes les options disponibles

        printf("\n********Menu********\n");
        printf("1. Ajouter une tache\n");
        printf("2. Afficher les taches\n");
        printf("3. Modifier une tache\n");
        printf("4. Supprimer une tache\n");
        printf("5. Filtrer une tache\n");
        printf("6. Quitter\n");
        printf("*********************\n");
        printf("~Votre choix : ");
                // Vérifie si l'entrée est un nombre valide
        if(scanf("%d", &choix) != 1) {
            printf("Erreur : Veuillez entrer un nombre.\n");
            while(getchar() != '\n');
            continue;
        }
         // Traitement des différentes options du menu

        switch (choix) {
            case 1:// Option pour ajouter une nouvelle tâche
                if (nbr_tache < max) {
                    taches[nbr_tache] = add();
                    nbr_tache++;
                    printf("\nTâche ajoutée avec succès!\n");
                } else {
                    printf("Limite de taches atteinte.\n");
                }
                break;

            case 2: // Option pour afficher toutes les tâches

                if (nbr_tache == 0) {
                    printf("Pas de tache à afficher.\n");
                } else {
                    afficher(taches, nbr_tache);
                }
                break;

            case 3: // Option pour modifier une tâche existante
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
    
            case 4: // Option pour supprimer une tâche
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

            case 5: // Option pour filtrer les tâches par priorité
                filtrer(taches, nbr_tache);
                break;

            case 6: // Option pour quitter le programme
                if (confirmerSortie()) {
                    printf("\nAu revoir! Merci d'avoir utilisé notre gestionnaire de tâches.\n");
                    return 0;
                }
                break;

            default:// Gestion des choix invalides
                printf("Choix invalide, veuillez réessayer.\n");
        }
    } while(1); // Continue jusqu'à ce que l'utilisateur choisisse de quitter

    return 0;
}
