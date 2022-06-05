// Projet Informatique "Jeu demineur" redigée par Maellys Amaini
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAILLED  9                   // TAILLE TABLEAU NIVEAU DEBUTANT
#define TAILLEI  16                  // TAILLE TABLEAU NIVEAU INTERMEDIAIRE


void placeMinesI(int nbMines);
void placeMinesD(int nbMines);          
void initialisationI();
void initialisationI();
void reglesDuJeu();
void affichageD();
void affichageI();
int jouerD(int resulat, int ligne, int colonne);
int jouerI(int resulat, int ligne, int colonne);
int coordonneeD(int *colonne, int* ligne);
int coordonneeI(int *colonne, int* ligne);
char grilleD   [11][11];  // Grille du jeu debutant sans mines
char grilleI   [18][18];  // Grille du jeu intermediaire sans mines
char grilleminesD [11][11];  // Grille du jeu debutant avec les mines
char grilleminesI [18][18];  // Grille du jeu Intermidiares avec les mines
char alentourD[11][11];  // Grille du jeu debutant nombre de mines au alentour 
char alentourI[18][18];  // Grille du jeu intermediaire nombre de mines au alentour 
char tempD [11][11];  // Grille temporaire pour le calcul de la case jouée niveau debutant
char tempI [18][18];  // Grille temporaire pour le calcul de la case jouée niveau intermediare

void reglesDuJeu(){
	printf("Les règles du jeu sont ...");  // Ecrire bien les regles du jeu 
}

void initialisationD(){

  int a, b;
  for (a=0; a<11; a++)
    for (b=0; b<11; b++)
    {
      grilleD  [a][b]  = '*';  // ' 'implique case cachée
      grilleminesD[a][b]  = 0;
      alentourD[a][b] = 0;
    }
}

void initialisationI(){

  int a, b;
  for (a=0; a<18; a++)
    for (b=0; b<18; b++)
    {
		grilleminesI[a][b]  = 0;
		alentourI[a][b] = 0;
		grilleI  [a][b]  = '*';  // ' 'implique case cachée
    }
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
  }
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
  }
}



void placeMinesD(int nbMines){
	int i,j,a,b;
	int restemines;
	restemines= nbMines;
	for (i=0;i<nbMines;i++){
			a=rand()%10;
			b=rand()%10;
			if (!grilleminesI[a][b]){
				grilleminesD[a][b] = 1;
				restemines--;
				printf("\nmine: colonne=%d, ligne=%d", a, b);
		    }
	} 
	for(j=1;j<TAILLED;b++)
			alentourD[a][b] =  grilleminesD [a-1][a-1] + grilleminesD[a-1][b] + grilleminesD[a-1][a+1] +
                      grilleminesD[a  ][b-1]                        + grilleminesD[a  ][b+1] +
                      grilleminesD[a+1][b-1] + grilleminesD[a+1][b] + grilleminesD[a+1][b+1];
	
}



void placeMinesI(int nbMines)
{
  int a, b;
  while(nbMines)
  {  
    int a = rand()%TAILLEI + 1;  // On choisit la ligne de manière aléatoire
    int b = rand()%TAILLEI+ 1;  // On choisit la colonne de manière aléatoire
    if (!grilleminesI[a][b])    // On vérifie ie que la case est libre
    {
      grilleminesI[a][b]= 1;  // On place un 1 pour indiquer qu'il y a une mine
      nbMines--;        // Une mine de moins à placer
      printf("\nmine: colonne=%d, ligne=%d", a, b);
    }
  }
  for (a=1; a<=TAILLEI; a++)  // Met le tableau 'autour' à jour
    for (b=1; b<=TAILLEI; b++)
      alentourI[a][b] =  grilleminesI [a-1][a-1] + grilleminesI[a-1][b] + grilleminesI[a-1][a+1] +
                      grilleminesI[a  ][b-1]                        + grilleminesI[a  ][b+1] +
                      grilleminesI[a+1][b-1] + grilleminesI[a+1][b] + grilleminesI[a+1][b+1];
}


int jouerD(int resulat, int ligne, int colonne)
{
  int a, b, m, n;
  switch (resulat)
  {
    case 1 :
        for (a=0; a<TAILLED+2; a++)
          for (b=0; b<TAILLEI+2; b++)
            tempD[a][b] = 0;
      if (grilleminesD[colonne][ligne])
        return 1;    // Perdu, on est tombé sur une mine
    case 0 :
      tempD[colonne][ligne] = alentourD[colonne][ligne] + '0';
      for (a=1; a<=TAILLED; a++)
        for (b=1; b<=TAILLED; b++)
          if (tempD[a][b] == '0')
          {
            tempD[a][b] = ' ';
            for (m=a-1; m<=a+1; m++)
              for (n=b-1; n<=b+1; n++)
                if ( !((m == a) ||(n == b))||(m)||(m <= TAILLED) ||(n) ||(n <= TAILLED) || (!tempD[m][n]) )    // Pour éviter de retester la même case et les bords
                  jouerD(0, m, n);
          }
      for (a=1; a<=TAILLED; a++)    // Recopie de temp dans jeu
        for (b=1; b<=TAILLED; b++)
          if (tempD[a][b])
            if (grilleD [a][b] == '*')
              grilleD[a][b] = tempD[a][b];
      break;
    case 2 :
      grilleD[colonne][ligne] = '#';
      break;
  }
  return 0;
}
int jouerI(int resulat, int ligne, int colonne)
{
  int a, b, m, n;
  switch (resulat)
  {
    case 1 :
        for (a=0; a<TAILLEI+2; a++)
          for (b=0; b<TAILLEI+2; b++)
            tempI[a][b] = 0;
      if (grilleminesI[colonne][ligne])
        return 1;    // Perdu, on est tombé sur une mine
    case 0 :
      tempI[colonne][ligne] = alentourI[colonne][ligne] + '0';
      for (a=1; a<=TAILLEI; a++)
        for (b=1; b<=TAILLEI; b++)
          if (tempI[a][b] == '0')
          {
            tempI[a][b] = ' ';
            for (m=a-1; m<=a+1; m++)
              for (n=b-1; n<=b+1; n++)
                if ( !((m == a) ||(n == b))||(m)||(m <= TAILLEI) ||(n) ||(n <= TAILLEI) || (!tempI[m][n]) )    // Pour éviter de retester la même case et les bords
                  jouerI(0, m, n);
          }
      for (a=1; a<=TAILLEI; a++)    // Recopie de temp dans jeu
        for (b=1; b<=TAILLEI; b++)
          if (tempI[a][b])
            if (grilleI [a][b] == '*')
              grilleI[a][b] = tempI[a][b];
      break;
    case 2 :
      grilleI[colonne][ligne] = '#';
      break;
  }
  return 0;
}


int coordonneeD(int *colonne, int* ligne){
  int resultat;
  do{
	printf("\n Selectionner une case"); 
	printf("\n Entrez son numero de colonne"); 
	scanf("%d", colonne);
	printf("\n Entrez son numero de ligne"); 
	scanf("%d",ligne);
  } while((*colonne>TAILLED) || (*colonne<1) ||(*ligne>TAILLED) || (*ligne<1));
  do{
	printf("\nFaites votre choix: \n 1: Decouvrir une case \n 2: Placer un marqueur");
	printf("\n Tapez 1 ou 2\n");
	scanf("%d", &resultat);
  }while (resultat<0 || resultat>2);
  return resultat;
}


int coordonneeI(int *colonne, int* ligne){
  int resultat;
  do{
	printf("\n Selectionner une case"); 
	printf("\n Entrez son numero de colonne"); 
	scanf("%d", colonne);
	printf("\n Entrez son numero de ligne"); 
	scanf("%d",ligne);
  } while((*colonne>TAILLEI) || (*colonne<1) ||(*ligne>TAILLEI) || (*ligne<1));
  do{
	printf("\nFaites votre choix: \n 1: Decouvrir une case \n 2: Placer un marqueur");
	printf("\n Tapez 1 ou 2\n");
	scanf("%d", &resultat);
  }while (resultat<0 || resultat>2);
  return resultat;
}


int main(){
	int colonne, ligne;  // Mémorise la case jouée
	int resultat;    // Mémorise le choix 
	int nbMines = 0;    // Nombre de mines choisi par le joueur
	int nbCaseJouee, nbDrapeau, nbDrapeauOK;  // Pour le test de fin de jeu
	int niveau;
	int a, b;
	char nom[100];
	
	clock_t temps;
	srand(time(NULL));

	//Afficher le début du jeu

	printf("\n\n\n*********************Lancement du jeu DEMINEUR*********************\n\n\n");

	reglesDuJeu();
	
	printf("\n Entrez votre nom de joueur\t");
	scanf("%s",nom);
	
	do
	  {
		printf("\nChoisisez votre niveau de jeu %s\n 1: Niveau débutant \n 2: Niveau Intermédiare \n",nom);
		printf("Tapez 1 ou 2 selon le niveau souhaité\n");
		scanf("%d", &niveau);
	  }while(niveau<1 || niveau>2 );  
	  
	 

  
  
	if (niveau==1){
						initialisationD();
						nbMines=10;
						affichageD();
						while (1){
							resultat = coordonneeD(&colonne, &ligne);
							if (jouerD(resultat, colonne, ligne)){
								temps=clock();
								printf("BOOM Perdu !\n Vous avez mit %f secondes.\n", (double) temps/CLOCKS_PER_SEC);
								return 0;
						    }
							affichageD();
						
							nbCaseJouee = nbDrapeau = nbDrapeauOK = 0;
							for (a=1; a<=TAILLED; a++)
							  for (b=1; b<=TAILLED; b++)
							  {
								if (grilleD[a][b] != '*')
								  nbCaseJouee++;
								
								if (grilleD[a][b] == '#')
								{
								  nbDrapeau++;
								  if (grilleminesD[a][b])
									nbDrapeauOK++;
							    }
						      }
						if ( (nbDrapeau == nbMines) && (nbDrapeauOK == nbMines) )
						  break;  // Les drapeaux correspondent bien à toutes les mines et à elles seules
						if (nbCaseJouee >= (TAILLED*TAILLED))
						{
						  temps=clock();
						  printf("Perdu!\nTu as mis %f secondes.\n", (double) temps/CLOCKS_PER_SEC);
						  return 0;
						}
					  }
					  temps=clock();
					  printf("Gagner!\n Vous avez mit %f secondes.\n", (double) temps/CLOCKS_PER_SEC);
					  
					  return 0;
					}


  
	if(niveau==2){
					initialisationI();
					nbMines=40;
					affichageI();
					
					while (1)
					{
						resultat= coordonneeI(&colonne, &ligne);
						if (jouerI(resultat, colonne, ligne))
						{
							temps=clock();
							printf("BOOM Perdu !\n Vous avez mit %f secondes.\n", (double) temps/CLOCKS_PER_SEC);
							return 0;
						}
					
						affichageI();
						// Test de la fin du jeu
						nbCaseJouee = nbDrapeau = nbDrapeauOK = 0;
						for (a=1; a<=TAILLEI; a++)
						  for (b=1; b<=TAILLEI; b++)
						  {
							if (grilleI[a][b] != '*')
							  nbCaseJouee++;
							if (grilleI[a][b] == '#')
							{
								nbDrapeau++;
								if (grilleminesI[a][b])
								nbDrapeauOK++;
							}
						}  
					if ((nbDrapeau == nbMines) && (nbDrapeauOK == nbMines))
					  break;
					  
					if (nbCaseJouee >= (TAILLEI*TAILLEI))
					{
					  temps=clock();
					  printf("Perdu!\nTu as mis %f secondes.\n", (double) temps/CLOCKS_PER_SEC);
					  return 0;
					}
				  }
				  temps=clock();
				  printf("Gagner!\nTu as mis %f secondes.\n", (double) temps/CLOCKS_PER_SEC);
				  
				  return 0;
	}
				  
}				  
				 
  



