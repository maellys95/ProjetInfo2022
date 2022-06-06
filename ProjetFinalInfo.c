// Projet Informatique "Jeu demineur" redigée par Maellys Amaini et Alexies Loyau
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAILLED  9                   // TAILLE TABLEAU NIVEAU DEBUTANT
#define TAILLEI  16                  // TAILLE TABLEAU NIVEAU INTERMEDIAIRE
void compare(char* nom, time_t score);
void affiche_record(time_t score);
void placementMinesI(int nbMines);
void placementMinesD(int nbMines);          
void initialisationI();
void initialisationI();
void reglesDuJeu();
void affichageD();
void affichageI();
int playD(int resultat, int ligne, int colonne);
int playI(int resultat, int ligne, int colonne);
int coordonneeD(int *colonne, int* ligne);
int coordonneeI(int *colonne, int* ligne);
char grilleD   [11][11];  // Grille du jeu debutant sans mines
char grilleI   [18][18];  // Grille du jeu intermediaire sans mines
char grilleminesD [11][11];  // Grille du jeu debutant avec les mines
char grilleminesI [18][18];  // Grille du jeu Intermidiares avec les mines
char alentourD[11][11];  // Grille du jeu debutant nombre de mines au alentour 
char alentourI[18][18];  // Grille du jeu intermediaire nombre de mines au alentour 
char stockD[11] [11];  // Grille temporaire pour le calcul de la case jouée niveau debutant
char stockI[18] [18];// Grille temporaire pour le calcul de la case jouée niveau intermediare

void reglesDuJeu(){
	printf("Le but du jeu est de découvrir toutes les cases libres sans faire exploser les mines, c'est-à-dire sans cliquer sur les cases qui les dissimulent. Lorsque le joueur clique sur une case libre comportant au moins une mine dans l'une de ses cases avoisinantes, un chiffre apparaît, indiquant ce nombre de mines.\n");  // Ecrire bien les regles du jeu 
}

void initialisationD(){ //InitialiseD qui signifie initialisation pour le niveau Débutant : initialise les tableaux grillesD( grille de jeu Debutant), grillesminesD(grilles de mines Debutant) et alentourD(alentouur jeu debutant);

  int a, b;
  for (a=0; a<11; a++)
    for (b=0; b<11; b++)
    {
      grilleD  [a][b]  = '*';  //Ce tableau est une grille de jeu pour l'utlisateur grace a celle ci il ne pourra pas voir les mines et les autres informations du jeu, il verra seulement un tableau remplis de *
      grilleminesD[a][b]  = 0; // Ce tableau est une grille ou sont placé les mines l'utlisateur n'aura pas acces a ce tableau car il va devoir le deviner
      alentourD[a][b] = 0;// Ce tableau est une grille ou sont placé les informations concernant les mines les chiffres qui indique si une mines est proche et a combien de case, l'utilisateur aura acces a cette grille a fur et a mesure du jeu en decouvrant des cases du jeu.
    }//Concerne seulement le niveau Debutant
}

void initialisationI(){ //InitialiseD qui signifie initialisation pour le niveau intermediare : initialise les tableaux grillesI( grille de jeu Intermediare), grillesminesI(grilles de mines Intermedire) et alentourI(alentouur jeu Intermediaire);

  int a, b;
  for (a=0; a<18; a++)
    for (b=0; b<18; b++)
    {
		grilleminesI[a][b]  = 0;//Ce tableau est une grille de jeu pour l'utlisateur grace a celle ci il ne pourra pas voir les mines et les autres informations du jeu, il verra seulement un tableau remplis de *
		alentourI[a][b] = 0; // Ce tableau est une grille ou sont placé les mines l'utlisateur n'aura pas acces a ce tableau car il va devoir le deviner
		grilleI  [a][b]  = '*'; // Ce tableau est une grille ou sont placé les mines l'utlisateur n'aura pas acces a ce tableau car il va devoir le deviner
    }//Concerne seulement le niveau Debutant
}



void affichageI()
{
  int a, b;
  printf("\n\n");
  printf("     | 1    2    3    4    5    6    7    8    9    10   11   12   13   14   15   16\n");
  printf("_____|______________________________________________________________________________\n");
  for (a=1 ;a<=TAILLEI; a++)
  {
    if (a < 10)
      printf(" %d   | ", a);
    else
      printf("%d   | ", a);
    for (b=1; b<=TAILLEI; b++)
      printf("%c    ", grilleI[a][b]);
    printf("\n");
  }// Concerne seulement le niveau Intermediare
}


void affichageD()
{
  int a, b;
  printf("\n\n");
  printf("   | 1  2  3  4  5  6  7  8  9\n");
  printf("___|__________________________\n");
  for (a=1 ;a<=TAILLED; a++)
  {
    if (a < 10)
      printf(" %d | ", a);
    else
      printf("%d | ", a);
    for (b=1; b<=TAILLED; b++)
      printf("%c  ", grilleD[a][b]);
    printf("\n");
  }// Concerne seulement le niveau debutant
}



void placementMinesD(int nbMines){
	int i,a,b;
	int restemines;
	restemines= nbMines;
	for (i=0;i<nbMines;i++){
			a=rand()%10; // On choisit la ligne de manière aléatoire
			b=rand()%10;// On choisit la colonne de manière aléatoire
			if (!grilleminesD[a][b]){ // On vérifie ie que la case est libre
				grilleminesD[a][b] = 1; // On place un 1 pour indiquer qu'il y a une mine
				restemines--;// on enleve une mine au compteur
				
		    }
	} 
	
// PLACER LE POSITIONNEMENT DES NOMBRES A COTE DES MINES SUR LE TABLEAU ALENTOUUR, (PAS REUSSI A LE FAIRE)
}



void placementMinesI(int nbMines){
	int i,a,b;
	int restemines;
	restemines= nbMines;
	for (i=0;i<nbMines;i++){
			a=rand()%10; // On choisit la ligne de manière aléatoire
			b=rand()%10;// On choisit la colonne de manière aléatoire
			if (!grilleminesI[a][b]){ // On vérifie ie que la case est libre
				grilleminesI[a][b] = 1; // On place un 1 pour indiquer qu'il y a une mine
				restemines--;// on enleve une mine au compteur
				
		    }
	} 
	
// PLACER LE POSITIONNEMENT DES NOMBRES A COTE DES MINES SUR LE TABLEAU ALENTOUUR, (PAS REUSSI A LE FAIRE)
}


int playD(int resultat, int ligne, int colonne)
{
  int a, b;
  switch (resultat)
  {
    case 1 :
        for (a=0; a<TAILLED+2; a++) // parcous 
          for (b=0; b<TAILLEI+2; b++)// 2D
            stockD[a][b] =0; 
      if (grilleminesD[colonne][ligne])// On tombe sur une mine 
        return 1;    
    case 0 :
      stockD[colonne][ligne] = alentourD[colonne][ligne] + '0';
      for (a=1; a<=TAILLED; a++)
        for (b=1; b<=TAILLED; b++)
          if (stockD [a][b] == '0')
          {
            stockD[a][b] = ' ';
              
          }
   
      return 0;
    case 2 :
      grilleD[colonne][ligne] = '#'; //Marqueur
      return 0;
  }
  return 0;
}// PAS FINI NE MARCHE PAS 








int playI(int resultat, int ligne, int colonne)
{
  int a, b;
  switch (resultat)
  {
    case 1 :
        for (a=0; a<TAILLEI+2; a++)
          for (b=0; b<TAILLEI+2; b++)
            stockI [a][b]=0;
      if (grilleminesI[colonne][ligne])
        return 0;    
    case 0 :
      stockI[colonne][ligne] = alentourI[colonne][ligne] + '0';
      for (a=1; a<=TAILLEI; a++)
        for (b=1; b<=TAILLEI; b++)
          if (stockI[a][b] == '0')
          {
            stockI[a][b] = ' ';
            
          }
     
      return 1;
    case 2 :
      grilleI[colonne][ligne] = '#';//Marqueur
      return 1;
  }
  return 0;
}
// PAS FINI NE MARCHE PAS 

int coordonneeD(int *colonne, int* ligne){// Cette fonction permet de stocker les coordonnées entrée par l'utlisateur et de lui demande ce qu'il souhaite faire pour la suite du jeu si il veut placer un marqueur ou bien decouvrir une case 
  int resultat;
  do{
	printf("\n Selectionner une case"); 
	printf("\n Entrez son numero de colonne"); 
	scanf("%d", colonne);                    // Prend la valeur colonne de l'utilisateur 
	printf("\n Entrez son numero de ligne"); 
	scanf("%d",ligne); // Prend la valeur ligne de l'utilisateur 
  } while((*colonne>TAILLED) || (*colonne<1) ||(*ligne>TAILLED) || (*ligne<1)); //Si l'utilisateur entre une valeur non correcte alors il sera oblige de repeter l'operation jusqu'a il rentre une bonne valeur
  do{
	printf("\nFaites votre choix: \n 1: Decouvrir une case \n 2: Placer un marqueur");
	printf("\n Tapez 1 ou 2\n");
	scanf("%d", &resultat);
  }while (resultat<0 || resultat>2);// De meme ici si l'utlisateur entre une mauvaise valeur il sera contraint de recommencer 
  return resultat;
}//Concerne seulement le niveau debutant 


int coordonneeI(int *colonne, int* ligne){// Cette fonction permet de stocker les coordonnées entrée par l'utlisateur et de lui demande ce qu'il souhaite faire pour la suite du jeu si il veut placer un marqueur ou bien decouvrir une case 

  int resultat;
  do{
	printf("\n Selectionner une case"); 
	printf("\n Entrez son numero de colonne"); 
	scanf("%d", colonne);// Prend la valeur colonne de l'utilisateur 
	printf("\n Entrez son numero de ligne"); 
	scanf("%d",ligne);// Prend la valeur ligne de l'utilisateur 
  } while((*colonne>TAILLEI) || (*colonne<1) ||(*ligne>TAILLEI) || (*ligne<1));//Si l'utilisateur entre une valeur non correcte alors il sera oblige de repeter l'operation jusqu'a il rentre une bonne valeur
  do{
	printf("\nFaites votre choix: \n 1: Decouvrir une case \n 2: Placer un marqueur");
	printf("\n Tapez 1 ou 2\n");
	scanf("%d", &resultat);
  }while (resultat<0 || resultat>2); // De meme ici si l'utlisateur entre une mauvaise valeur il sera contraint de recommencer 
  return resultat;
}//Concerne seulement le niveau Intermediare 

void affiche_record(time_t score){
	FILE* reader =NULL;
	char tab1[50];
	char tab2[50];
	char tab3[50];
	time_t time1 = 0;
	time_t time2 = 0;
	time_t time3 = 0;
	
		
	reader = fopen("record.txt", "r");
	
	fscanf(reader, "%s", tab1);
//	printf("%s ", tab1);
	fscanf(reader, "%ld", &time1);
//	printf("%ld \n", time1);
	fscanf(reader, "%s", tab2);
//	printf("%s ", tab2);
	fscanf(reader, "%ld", &time2);
//	printf("%ld \n", time2);
	fscanf(reader, "%s", tab3);
//	printf("%s ", tab3);
	fscanf(reader, "%ld", &time3);
//	printf("%ld \n", time3);
	
	if ( score >= time3){
		printf("\n \t\t Félicitation vous dans les 3 meilleurs temps \n");
		
	}
		printf("\t\t Les trois meilleures temps sont :");
		printf("\n\n\t premier temps %ld de %s", time1, tab1);
		printf("\n\n\t deuxième temps %ld de %s", time2, tab2);
		printf("\n\n\t troisième temps %ld de %s", time3, tab3);
	

}
	
	
void compare(char* nom, time_t score){
	int i;
	char tab1[50];
	char tab2[50];
	char tab3[50];
	time_t time1 = 0;
	time_t time2 = 0;
	time_t time3 = 0;

	FILE* reader=NULL;
	reader = fopen("record.txt", "r+");
	rewind(reader);

	rewind(reader);
	fscanf(reader, "%s", tab1);
	printf("%s ", tab1);
	fscanf(reader, "%ld", &time1);
	printf("%ld \n", time1);
	fscanf(reader, "%s", tab2);
	printf("%s ", tab2);
	fscanf(reader, "%ld", &time2);
	printf("%ld \n", time2);
	fscanf(reader, "%s", tab3);
	printf("%s ", tab3);
	fscanf(reader, "%ld", &time3);
	printf("%ld \n", time3);

rewind(reader);
	if(score <= time1){
		time3 = time2;
		time2 = time1;
		time1 = score;
		for(i=0;i<50;i++){
		tab3[i]= tab2[i];
		tab2[i]= tab1[i];
		tab1[i]= *(nom+i);
		}
		fprintf(reader,"%s %ld ", tab1, time1);
		fprintf(reader,"%s %ld ", tab2, time2);
		fprintf(reader,"%s %ld ", tab3, time3);
	}	
	
	else if(score <=time2){
		time3 = time2;
		time2 = score;
		for(i=0;i<50;i++){
		tab3[i]= tab2[i];
		tab2[i]= *(nom+i);
		
		}
		fprintf(reader,"%s %ld ", tab1, time1);
		fprintf(reader,"%s %ld ", tab2, time2);
		fprintf(reader,"%s %ld ", tab3, time3);
		
	}
	
	else if(score <= time3){
		time3 = score;
		for(i=0;i<50;i++){
		tab3[i]= *(nom+i);
		
		}
		fprintf(reader,"%s %ld ", tab1, time1);
		fprintf(reader,"%s %ld ", tab2, time2);
		fprintf(reader,"%s %ld ", tab3, time3);
	}
	fclose(reader);
}




int main(){
	int colonne, ligne;// ligne et colonne entrer par l'utlisateur   
	int resultat;    
	int nbMines = 0;    //les mines sont initilisée a 0 et prendrons plutard la valeur de mines selon le niveau choisis par l'utlisateur 
	int nbCaseJouee, nbMarqueur, nbBonMarqueur; 
	nbCaseJouee =0;
	nbMarqueur=0;
	nbBonMarqueur=0;
	int niveau; // Niveau choisis par l'utlisateur 
	int a, b;
	char nom[100]; //stocke le nom de l'utlisateur 
	
	clock_t temps; // Sert pour le chronometre
	srand(time(NULL)); 
	
	//Afficher le début du jeu

	printf("\n\n\n*********************Lancement du jeu DEMINEUR*********************\n\n\n");

	reglesDuJeu(); // indique en debut de partie les regles du jeu afin de faciliter l'utlisateur 
	
	printf("\n Entrez votre nom de joueur\t");
	scanf("%s",nom);// Prend le nom de l'utlisateur pour stocker son score a la fin de la partie 
	
	do
	  {
		printf("\nChoisisez votre niveau de jeu %s\n 1: Niveau débutant \n 2: Niveau Intermédiare \n",nom);
		printf("Tapez 1 ou 2 selon le niveau souhaité\n");
		scanf("%d", &niveau);
	  }while(niveau<1 || niveau>2 );  
	  
	 

  
  
	if (niveau==1){      // CHOIX NIVEAU 1
						initialisationD(); // on intilialise les tableaux
						nbMines=10;       // Prend la valeur de 10 car c'est le niveau debutant 
						affichageD();     // Affichage de la grille de jeu
						
						while (1){
							temps=clock();// Le chronometre est lancé
							resultat = coordonneeD(&colonne, &ligne); // le resultat est l'union des coordonnées de l'utilisateur 
							if (playD(resultat, colonne, ligne)){    // cas ou les coordonnées choisis sont celle de la mine 
								         
								printf("BOOM Perdu !\n Vous avez mit %f secondes.\n", (double) temps/CLOCKS_PER_SEC);//chronometre arreté car l'utlisateur a perdu, nombre de seconde renvoye a l'utilisateur 
								return 0;
						    }
						
							
							for (a=1; a<=TAILLED; a++)
							  for (b=1; b<=TAILLED; b++)
							  {
								if (grilleD[a][b] != '*')
								  nbCaseJouee++;
								
								if (grilleD[a][b] == '#')
								{
								  nbMarqueur++;
								  if (grilleminesD[a][b])
									nbBonMarqueur++;
									
							    }
						      }
						      
						  
						     
						if ( (nbMarqueur == nbMines) || (nbBonMarqueur == nbMines) )// si le nombre de 
							temps=clock();
					        printf("Gagner!\n Vous avez mit %f secondes.\n", (double) temps/CLOCKS_PER_SEC);
					        return 0;
						                // Les drapeaux correspondent bien à toutes les mines et à elles seules
						if (nbCaseJouee >= (TAILLEI*TAILLEI)-nbMines) 
						{
						  temps=clock();
						  printf("Perdu!\nTu as mis %f secondes.\n", (double) temps/CLOCKS_PER_SEC);
						  return 0;
						}
					  }
					  
					}
								


  
	if(niveau==2){
					initialisationI();
					nbMines=40;
					affichageI();
					
					while (1)
					{
						resultat= coordonneeI(&colonne, &ligne);
						if (playI(resultat, colonne, ligne))
						{
							temps=clock();
							printf("BOOM Perdu !\n Vous avez mit %f secondes.\n", (double) temps/CLOCKS_PER_SEC);
							return 0;
						}
					
						
						for (a=1; a<=TAILLEI; a++) //on parcours le tableau
						  for (b=1; b<=TAILLEI; b++)// avec les deux dimensions
						  {
							if (grilleI[a][b] != '*')// si une case n'a plus le caractere de debut alors elle a ete joué
							  nbCaseJouee++;// donc on rajoute +1 au nombre de case jouée
							if (grilleI[a][b] == '#')// si la case parcourus comporte le symbole # qui est un marqueur 
							{
								nbMarqueur++;//alors on rajoute +1 au nombre de marqueur
								if (grilleminesI[a][b]) // si un marqueur correspont a une case dans grilles des mines 
								nbBonMarqueur++;// alors le marqueur est un bon marqueur de bombe, il est donc correct on rajoute +1 au compteur de bon marqueur
							}
						}  // Les sorties du jeu sont 
					if ((nbMarqueur == nbMines) || (nbBonMarqueur == nbMines)) // si le nombre de marqueur equivaut au nombre de mines et que c'est  marqueur sont bien placé 
						temps=clock();
				        printf("Gagner!\nTu as mis %f secondes.\n", (double) temps/CLOCKS_PER_SEC); // Alors l'utlisateur a gagner
				        
						return 0;
					  
					if (nbCaseJouee >= (TAILLEI*TAILLEI)-nbMines) // si l'utilisateur a joué toutes les cases sauf les mines alors il a perdu car il ne reste que les mines 
					{
					  temps=clock();
					  printf("Perdu!\nTu as mis %f secondes.\n", (double) temps/CLOCKS_PER_SEC);
					  return 0;
					}
				  }
				 
	}
				  
}				  
				 
  
