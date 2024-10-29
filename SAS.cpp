#include<stdio.h>
typedef struct{
		int jour;
		int mois;
		int annee;
	}date;
typedef struct{
	char  titre;
	char description;
	date dt;
	char priorite;
	}tache;
	
	

		//la fonction qui permet de creat nouvelle tache 
tache add()
{
	tache tc;
	
	printf("entrer la titre une tache:");
	scanf("%s",&tc.titre);
	printf("entrer la description de tache:");
	scanf("%s",&tc.description);
	printf("entrer la date de tache:");
	printf("le jour:");	
	scanf("%d",&tc.dt.jour);
	printf("le mois");
	scanf("%d",&tc.dt.mois);
		printf("l annee");
	scanf("%d",&tc.dt.annee);
	printf ("entrer la priorite");
	scanf("%s",&tc.priorite);
return tc;
}
       //fonction quin permet de afficher les taches
void afficher(tache tc){
	
	printf("titre:%s",tc.titre);
	printf("\n la description:%s\n",tc.description);
	printf("\n*******la date de creation:*******\n");
	printf("\n %d / %d / %d ",tc.dt.jour,tc.dt.mois,tc.dt.annee);
    printf("\n priorite : %s\n",tc.priorite);	
	
	}
   //fonction qui permet de modifier une tache
void modifier(tache tc[], int index){
	printf("modifier les information de :%s\n",&tc[index].titre);
        printf("entrer le nouveu titre :");
        scanf("%s",&tc[index].titre);
        printf("entrer le nouveu description  :");
        scanf("%s",&tc[index].description);
        printf("***modifier la date de creation:***");
		printf("entrer le nouveu jour :");
        scanf("%d",&tc[index].dt.jour);
        printf("entrer le nouveu mois :");
        scanf("%d",&tc[index].dt.mois);
        printf("entrer le nouveu annee :");
        scanf("%d",&tc[index].dt.annee);
        printf("entrer la noveu priorite :");
        scanf("%s",&tc[index].priorite);
		}
        //fonction qui permet de supprimer une tache
       
void supprimer(tache taches[], int nbr_tache, int index){
	for(int i=index; i<(nbr_tache)-1; i++){
		taches[i]=taches[i+1]; //tache 4 suppreimer la tache 5 ghatwlli f case 4 
	}
		nbr_tache--; 
}
	int main(){
		tache taches[100];
		int nbr=0;
		while(1){
	
		printf("**************menu**************\n");
		printf(" 1-Ajouter une Tache :\n");	
		printf(" 2-Afficher la Liste des Taches :\n");
    	printf(" 3-Modifier une Tache :\n");
    	printf(" 4-Supprimer une Tache :\n");
    	printf(" 5-Filtrer les Taches :\n");
    	printf(" 6-Quitter \n");
    	printf("*********************************\n");
    int choix;
    printf("choisi votre choix : ");
    scanf("%d",&choix);
    switch(choix) 
	{
    	case 1:
    		taches[nbr]=add();
    		nbr++;
			break;
    
    	    	
	}
	
		 
		}	
return 0;
}

