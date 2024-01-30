#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_TASKS 100

//ToDO:
//Function : Display menu 
//Function : Add task
//Function : Display Tasks
//Function : Edit Task
//Function : Remove Task
//Function : Sorting Tasks 
//Function : Filter Tasks
//Function : Exit


//Declaration de structure :

typedef struct {
	int day;
	int month;
	int year;
}  DateTache;


typedef struct {
	char titre [30];
	char description[200];
	int priorite;
 	DateTache DateCreation;
} Tache;


// Fonction pour ajouter une tâche
void AjouterTache(Tache tache[], int *tacheCount) {
    if (*tacheCount < MAX_TASKS) {
    	
    	printf("Entrer le titre du tache: ");
        scanf(" %[^\n]s", tache[*tacheCount].titre);
    	
        printf("Entrer la description du tache: ");
        scanf(" %[^\n]s", tache[*tacheCount].description);

        printf("Entrer la date du tache:\n");
        scanf("%d %d %d",&tache[*tacheCount].DateCreation.day, &tache[*tacheCount].DateCreation.month, &tache[*tacheCount].DateCreation.year);

        printf("Entrer la priorite (1-5): ");
        scanf("%d", &tache[*tacheCount].priorite);

        (*tacheCount)++;
        printf("Tache a ete ajoutee avec succes.\n");
    } else {
        printf("Vous avez depasse la limite des taches a entrer!\n");
    }
} 

//La fonction Afficher :
void AfficherTache(Tache tache[], int tacheCount) {
	if (tacheCount == 0) {
		printf("la liste des taches est vide, veuillez ajouter une tache!\n");
	}
	else {
    printf("La liste des taches :\n");
    for (int i = 0; i < tacheCount; i++) {
        printf("%d. Titre: %s\n   Description: %s\n   Date: %02d/%02d/%d\n   Priorite: %d\n", 
               i + 1, tache[i].titre, tache[i].description, 
               tache[i].DateCreation.day, tache[i].DateCreation.month, tache[i].DateCreation.year, 
               tache[i].priorite);
    }
    }
}

//Fonction Supprimer :

void SupprimerTache(Tache tache[], int *tacheCount, int index) {
    // Check if the index is valid
    if (index >= 1 && index <= *tacheCount) {
        // Shift elements to fill the gap
        for (int i = index-1; i < *tacheCount - 1; i++) {
            tache[i] = tache[i + 1];
        }

        // Decrease the task count
        (*tacheCount)--;

        printf("La tache a ete supprimee avec succes.\n");
    } else {
        printf("Indice invalide. La tache n'a pas ete supprimee.\n");
    }
}
// Fonction pour modifier une tâche
void ModifierTache(Tache tache[], int tacheCount, int index) {
    if (index >= 1 && index <= tacheCount) {
        printf("Entrer le nouveau titre du tache: ");
        scanf(" %[^\n]s", tache[index-1].titre);
        
        printf("Entrer la nouvelle description du tache: ");
        scanf(" %[^\n]s", tache[index-1].description);

        printf("Entrer la nouvelle date du tache:\n");
        scanf("%d %d %d", &tache[index-1].DateCreation.day, &tache[index-1].DateCreation.month, &tache[index-1].DateCreation.year);

        printf("Entrer la nouvelle priorite (1-5): ");
        scanf("%d", &tache[index-1].priorite);

        printf("La tache a ete modifiee avec succes.\n");
    } else {
        printf("Indice invalide. La tache n'a pas ete modifiee.\n");
    }
}
//Tri 
void sortTasks(Tache taches[], int tacheCount, int ascending) {
    int i, j;
    Tache temp;
    for (i = 0; i < tacheCount - 1; i++) {
        for (j = 0; j < tacheCount - 1 - i; j++) {
            int comparison = strcmp(taches[j].description, taches[j + 1].description);
            if ((ascending && comparison > 0) || (!ascending && comparison < 0)) {
                temp = taches[j];
                taches[j] = taches[j + 1];
                taches[j + 1] = temp;
            }
        }
    }}
  //  printf("Tasks sorted %s.\n", ascending ? "in ascending order" : "in descending order");}

//lLa fonction principale Main ()

int main() {

	Tache tache[MAX_TASKS];
    int tacheCount = 0;
    int choice;
  
   	do {
	 
	printf("Bienvenue dans votre To Do List  ^_^ \n");
	printf("\n");
	printf("    ***Menu:*** \n")	;
	printf("\n");
	printf("1.Afficher les taches \n");
	printf("2.Ajouter une tache \n");
	printf("3.Supprimer une tache \n");
	printf("4.Modifier une tache\n");
	printf("5.Ordonner les taches\n");
	printf("6.Filtrer les taches\n");
	printf("7.Sortir du programme\n");
	printf("Entrer votre choix:");
    scanf("%d", &choice);
    
    switch (choice) {
    	
    	case 1:  AfficherTache(tache, tacheCount);
                break;
                
    	case 2:  AjouterTache(tache, &tacheCount);
                break;
                
        case 3: {
				int tacheIndex;
				printf("Donner l'index du tache a supprimer :");
		      	scanf("%d", &tacheIndex);
      			SupprimerTache(tache, &tacheCount, tacheIndex);
		      	break; 
		      	}
		      	
		case 4: {
   				 int tacheIndex;
   				 printf("Donner l'index de la tache a modifier :");
   				 scanf("%d", &tacheIndex);
   				 ModifierTache(tache, tacheCount, tacheIndex);
    			break;
}   	
		case 5:{
				int choix;
		printf("Ordre croissant ou decroissant? \n Entrer O pour un ordre decroissant \n Entrer 1 pour un ordre croissant  ");
				if(choix==0)
				 sortTasks(tache, tacheCount, 0); 
				 else   
				 sortTasks(tache, tacheCount, 1);    	
    			break;
				}
    			
    	case 7:
                printf("Exiting program.\n");
                break;
    	
    	default:
                printf("Votre choix est invalide, Veuillez entrer un choix valide.\n");
	}

		} while (choice!=7);
	return 0;
	
	
}
