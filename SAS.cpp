#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define max 30 // Structure principale pour une t�che
// Structure pour g�rer les dates
typedef struct { 
    int jour;
    int mois;
    int annee;
} date;
// Structure principale pour une t�che
typedef struct {
    char titre[50];       // Titre de la t�che (limit� � 50 caract�res)
    char description[100]; // Description d�taill�e (limit�e � 100 caract�res)
    date dt;              // Date de la t�che (utilise la structure date)
    char priorite[10];    // Niveau de priorit� (Haute ou Basse)
} tache;
// Fonction qui demande � l'utilisateur les d�tails d'une nouvelle t�che
// Retourne une structure tache compl�tement remplie
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

// Fonction qui affiche la liste de toutes les t�ches existantes
void afficher(tache tc[], int nbr_tache) { 
// tc[]: tableau contenant toutes les t�ches
// nbr_tache: nombre total de t�ches � afficher
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

// Fonction qui permet de modifier une t�che existante

void modifier(tache tc[], int index) {
// tc[]: tableau de t�ches
// index: position de la t�che � modifier dans le tableau
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

// Fonction qui supprime une t�che du tableau
// taches[]: tableau de toutes les t�ches
// *nbr_tache: pointeur vers le nombre total de t�ches (modifi� apr�s suppression)
// index: position de la t�che � supprimer
void supprimer(tache taches[], int *nbr_tache, int index) {
    for (int i = index; i < (*nbr_tache) - 1; i++) {
        taches[i] = taches[i + 1]; 
    }
    (*nbr_tache)--; 
}
// Fonction qui filtre et affiche les t�ches selon leur priorit�
// tc[]: tableau de t�ches � filtrer
// nbr: nombre total de t�ches dans le tableau
void filtrer(tache tc[], int nbr) {
    if (nbr == 0) {
        printf("Aucune t�che � filtrer.\n");
        return;
    }
    
    char priorite[10];
    printf("Entrez la priorit� � filtrer (Haute / Basse) : ");
    scanf("%s", priorite);

    printf("T�ches avec la priorit� %s :\n", priorite);
    int found = 0;
    for (int i = 0; i < nbr; i++) {
        if (strcmp(tc[i].priorite, priorite) == 0) {
            printf("~~~~~~~ taches %d.~~~~~~~~\n",i+1);
            printf("Titre: %s\n", tc[i].titre);    
            printf("Description: %s\n", tc[i].description);
            printf("- Date de cr�ation: \n");
            printf("%d / %d / %d\n", tc[i].dt.jour, tc[i].dt.mois, tc[i].dt.annee);
            
            printf("Priorit�: %s\n", tc[i].priorite);
            found = 1;
        }
    }
    
    if (!found) {
        printf("Aucune t�che trouv�e avec cette priorit�.\n");
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
// G�re le menu principal et coordonne toutes les op�rations
int main() {
   
    int choix;            // Stocke le choix de l'utilisateur dans le menu
    tache taches[max];    // Tableau pour stocker toutes les t�ches (maximum d�fini par max)
    int nbr_tache = 0;    // Compteur du nombre actuel de t�ches
    
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
                // V�rifie si l'entr�e est un nombre valide
        if(scanf("%d", &choix) != 1) {
            printf("Erreur : Veuillez entrer un nombre.\n");
            while(getchar() != '\n');
            continue;
        }
         // Traitement des diff�rentes options du menu

        switch (choix) {
            case 1:// Option pour ajouter une nouvelle t�che
                if (nbr_tache < max) {
                    taches[nbr_tache] = add();
                    nbr_tache++;
                    printf("\nT�che ajout�e avec succ�s!\n");
                } else {
                    printf("Limite de taches atteinte.\n");
                }
                break;

            case 2: // Option pour afficher toutes les t�ches

                if (nbr_tache == 0) {
                    printf("Pas de tache � afficher.\n");
                } else {
                    afficher(taches, nbr_tache);
                }
                break;

            case 3: // Option pour modifier une t�che existante
                if (nbr_tache == 0) {
                    printf("Pas de tache � modifier.\n");
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
    
            case 4: // Option pour supprimer une t�che
                if (nbr_tache == 0) {
                    printf("Pas de tache � supprimer.\n");
                } else {
                    int index;
                    printf("Entrer l'index de tache � supprimer : ");
                    scanf("%d", &index);
                    if (index >= 0 && index < nbr_tache) {
                        supprimer(taches, &nbr_tache, index);
                        printf("Tache supprim�e.\n");
                    } else {
                        printf("Indice invalide.\n");
                    }
                }
                break;

            case 5: // Option pour filtrer les t�ches par priorit�
                filtrer(taches, nbr_tache);
                break;

            case 6: // Option pour quitter le programme
                if (confirmerSortie()) {
                    printf("\nAu revoir! Merci d'avoir utilis� notre gestionnaire de t�ches.\n");
                    return 0;
                }
                break;

            default:// Gestion des choix invalides
                printf("Choix invalide, veuillez r�essayer.\n");
        }
    } while(1); // Continue jusqu'� ce que l'utilisateur choisisse de quitter

    return 0;
}
