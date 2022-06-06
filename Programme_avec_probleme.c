/*
 * test.c
 * 
 * Copyright 2022 CYTech Student <cytech@student-laptop>
 * 
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301, USA.
 * 
 * 
 */


#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define SIZE 3

typedef struct{
	int status;
//indique si la case est miné ou pas, -1 miné, 0 aucune mine autour, 1 une mine autour... max 8.
	int discover;
//permet de connaître le statut de la case -1 caché, 0 un marqueur, 1 visible
}Case;


//void endgame(Case* 

//}
void minedropper(Case* table, int size, int minenumber){
	int num = 0 ;
	int i = 0 ;
	//int verify1 = 0;
	Case* verify = NULL;
	//Case* tempory = NULL;
	int abscisse =0;
	int ordonnee =0;
	verify = table;
	
	
	for( i = 0 ; i <size * size ; i++){
		(*(table+i)).status = 0;
	}
	
	srand(time(NULL));	
	//tempory = table ;
	while(num < minenumber){ // on va vérifier plusieurs fois dans la boucle si on ne dépasse pas le nombre de mine et aussi si on ne remet pas de mine sur une autre
		
		abscisse = rand() % size ;
		ordonnee = rand() % size ;
		
		if((*(table + abscisse + (ordonnee * size))).status != -1){
			
			(*(table + abscisse + (ordonnee * size))).status = -1 ;
			
			num++;
		}
		
		
		
		
		
		
		
		
		
		
		/*tempory = table;
		for(i = 0 ; i < (size * size) ; i++){
			tempory ++;
			
			if((*tempory).status != -1){
				
				while(num <= minenumber){
					
					verify1 = (rand() % size);
				//	printf("%d ", verify1);			//pour une raison inconnu le printf déforme totalement le tableau	
					if(verify1 == 1){

						(*tempory).status = -1 ;
						num++ ;
					}
				}
			}*/
		}
	table = verify ;
	
	table = verify ;
	//verify1 = 0;
}

//confirme si les coordonne à proximité de la case sont valide et ajoute si il trouve une mine
int confirmmarkCase(Case* table, int size, int abscisse, int ordonnee, int ab, int ord){
	
	if (abscisse < size && abscisse >= 0 && ordonnee < size && ordonnee >= 0){
		
		if((*(table + ab + (ord * size))).status == -1){
			return(1);
		}
	}
	return(0);	
}

//procédure qui attribut le numbre de mine à proximité d'une case	
void markCase(Case* table, int size){
	//	int verify = 0;
	//	int y = 0 ;
		//int i = 0 ;
		int abscisse = 0 ;
		int ordonnee = 0 ;
		//Case* initial = NULL;
	//	initial = table ;
		
		if((*table).status != -1){ 
			(*table).status = (*table).status + confirmmarkCase( table,  size,  abscisse,  ordonnee, -1, -1);
			(*table).status = (*table).status + confirmmarkCase( table,  size,  abscisse,  ordonnee, 0, -1);
			(*table).status = (*table).status + confirmmarkCase( table,  size,  abscisse,  ordonnee, 1, -1);
			(*table).status = (*table).status + confirmmarkCase( table,  size,  abscisse,  ordonnee, -1, 0);
			(*table).status = (*table).status + confirmmarkCase( table,  size,  abscisse,  ordonnee, 1, 0);
			(*table).status = (*table).status + confirmmarkCase( table,  size,  abscisse,  ordonnee, -1, 1);
			(*table).status = (*table).status + confirmmarkCase( table,  size,  abscisse,  ordonnee, 0, 1);
			(*table).status = (*table).status + confirmmarkCase( table,  size,  abscisse,  ordonnee, 1, 1);
		}
		
		
		/*do{
			verify = 0 ;
			for(i=0 ; i < size; i++){
				abscisse = 0;
			//printf("a");
				for(y = 0 ; y < size ; y++){
			//printf("b");
					if((*table).status != -1){ // on va vérifier chaque case à coté de celle-ci en vérifiant une par une si il y à une mine 
			//printf("c");
					(*table).status = (*table).status + confirmmarkCase( table,  size,  abscisse,  ordonnee, -1, -1);
					(*table).status = (*table).status + confirmmarkCase( table,  size,  abscisse,  ordonnee, 0, -1);
					(*table).status = (*table).status + confirmmarkCase( table,  size,  abscisse,  ordonnee, 1, -1);
					(*table).status = (*table).status + confirmmarkCase( table,  size,  abscisse,  ordonnee, -1, 0);
					(*table).status = (*table).status + confirmmarkCase( table,  size,  abscisse,  ordonnee, 1, 0);
					(*table).status = (*table).status + confirmmarkCase( table,  size,  abscisse,  ordonnee, -1, 1);
					(*table).status = (*table).status + confirmmarkCase( table,  size,  abscisse,  ordonnee, 0, 1);
					(*table).status = (*table).status + confirmmarkCase( table,  size,  abscisse,  ordonnee, 1, 1);
					}
					table++ ; // on va sur la prochaine case
					abscisse++ ; // abscisse et ordonnee son des valeurs qui vont servir à verifier si on est toujours sur le terrain
			//printf("d");
				}
				ordonnee++ ;	
				
			//printf("e");
			}
			
		table = initial;
			for(i = 0 ; i < (size * size) ; i++){
				if((*table).status ==-2){
					verify++ ;
				}*/
			//}
		//}while(verify != 0);
		
	//table = initial;
}
	
	
//procédure qui attribut le nombre de mine du terranin complet
void indicationdropper(Case* table, int size){
	Case* initial = NULL;
	int i =0 ;
	initial = table;
	
	for(i = 0; i < (size * size) ; i++){
		
		markCase(table+i, size);
	}
	table = initial;
}
	
// cette fonxtion retourne un pointeur Case sur un espace remplie de mine et d'indication prêt à être utiliser	
Case *initable(Case* table, int size, int minenumber){
	Case * initial = NULL ;
	int  i;
	table = NULL;
	
	table = malloc ( size * size * sizeof(Case));
		initial = table;
	
	for( i = 0 ; i < size * size ; i++){
		(*table).status = 0;
		(*table).discover = -1;
		table ++;
	}
	table = initial ;
	
	
	printf("\n addresse du terrain %p \n" , table);
	
	
	
	minedropper(table, size, minenumber);
	
	printf("\n addresse du terrain %p \n" , table);
	
	
	indicationdropper(table, size);
	
	
	printf("\n addresse du terrain %p \n" , table);
	 return (table);
}






char* translate_int(int num){ //transforme un unt en une chaîne char, il faut faire un free
	
	char* word=NULL;
	char letter =0;
	//char number = 1;
	//int power;
	
	letter=0;
		
	/*if(number<0){
		word= malloc(2* sizeof(char));
		*word= '-' ;
		word++;
		letter=48 + num;
		*word=letter;
		word= word-1;
		return(word);
	}
	*/
	//else{
	word = malloc(sizeof(char));
	letter=48 + num;
	*word=letter;
	return(word);
	//}
}

/*
void affectation_char1(char* point, int size, char* content){
	point = malloc(size * sizeof(char));
	*point = *content;
		
}

//return ce que doit montrer sur la case entre caché marqué 
// ou le nombre de mine à proximité.
char* whatIshow(Case square){ 
	char* contet = NULL;
	
	if(square.discover == -1){
		affectation_char1(contet, SIZE, "X");
	}
	else if(square.discover == 0){
		affectation_char1(contet, SIZE, "P");
	}
	else if(square.discover == 1){
		contet = translate_int(square.status);
	}
	else{
		affectation_char1(contet, SIZE, "R");
	}
	return(contet);
}*/


	
		

//return ce que doit montrer sur la case entre caché marqué 
// ou le nombre de mine à proximité.
void whatIshow(Case square){ 
	//char* content = NULL;
	
	if(square.discover == -1){
		//content = malloc(SIZE * sizeof(char));
		//*content = *"X";
		printf(" ");
		
	}
	else if(square.discover == 0){
	//	content = malloc(SIZE * sizeof(char));
	//	*content = *"P";
	printf("P");
	
	}
	else if(square.discover == 1){
		//content = translate_int(square.status);
		printf("%d", square.status);
		
		
	}
	else{
	//	content = malloc(SIZE * sizeof(char));
	//	*content = *"R";
	printf("R");
	
	}
	
}

/*
void showgame( Case* plate, int size){
	
	char letter = 'A';
	int y;
	int i;
	char number = 1;
	printf("   ");
	for(i=0 ; i< size ; i++){
		printf("%c ", letter);
		letter++;
	}
	printf("\n");
	
	for(i=0; i< size ; i++){
		if(i<9){
		printf("%c ", number);
		number++;
		}
		else if (i < 19){
						
		}
		for (y = 0; y<size ; y++){
			printf("|%s", whatIshow(*plate));
			free(whatIshow(*plate));
			printf("| \n");
		}
	}
}
*/

void showgame( Case* plate, int size){
	
	//char letter [10];
	int y;
	int z;
	int i;
	Case * initial = NULL;
	printf("\n");
	
	
	//du printf à la fin de la boucle c'est la première ligne.
	printf("    ");
	for(i=0 ; i< size ; i++){
		//itoa(i , letter, 10);
		
		if(i<10){
			printf("%d  ", i);
		}
		
		else if(i<100){
			printf("%d ", i);
		}
	}
	
	printf("\n");
	
	for(z=0; z < size ; z++){
			//itoa(i, letter, 10);
			if(i<10){
			printf("%d  ", i);
		}
		
		else if(i<100){
			printf("%d ", i);
		}
						
		
		for (y = 0; y<size ; y++){
		//	printf("a");
			printf("|");
			whatIshow(*plate);
			printf(" ");
		//	printf("c");
			//free(whatIshow(*plate));
			plate++;
		}
		//printf("b");
		printf("| \n");
	}
	plate = initial;
}

void recurseCase(int abscisse, int ordonnee, Case* plate, int size);

//procédure qui permet de verifier si les coordonné sont valides pour la récursivité
void lineconfirm(Case* plate , int abscisse, int ordonnee, int size){ 
	if(abscisse < size && abscisse >= 0 && ordonnee < size && ordonnee >= 0){
		recurseCase( abscisse, ordonnee, plate, size);
	}
	return;
}


// a finir fonction qui met les cases vide en visible attention à ordonnee et abscisse doivent avoir -1 pour correspondrent sur le tableaux.
void recurseCase(int abscisse, int ordonnee, Case* plate, int size){
	Case* initial = NULL;
	
	initial = plate ;
	if(abscisse < size && abscisse >= 0 && ordonnee < size && ordonnee >= 0){
		plate = plate + abscisse + ordonnee * size;
	
	
		if((*plate).discover == 1){
			plate = initial;
			return;
		}
	
		(*plate).discover = 1;
	
		if((*plate).status != 0){
			plate = initial;
			return;
		}
		
		plate = initial;
		//	plate = plate - abscisse - ordonnee * size; //on effectue la récursivité sur chaque case à proximité
		lineconfirm(plate , abscisse-1, ordonnee-1, size);
		lineconfirm(plate , abscisse, ordonnee-1, size);
		lineconfirm(plate , abscisse+1, ordonnee-1, size);
		lineconfirm(plate , abscisse-1, ordonnee, size);
		lineconfirm(plate , abscisse+1, ordonnee, size);
		lineconfirm(plate , abscisse-1, ordonnee+1, size);
		lineconfirm(plate , abscisse, ordonnee+1, size);
		lineconfirm(plate , abscisse+1, ordonnee+1, size);
	
		plate = initial;
	}
}


int main(int argc, char **argv)
{
	char* pipo = NULL;
	int size = 10;  //le maximum est 83 inclus pourquoi ? Je sais pas sinon segmentation fault :[
	int verif = 0;
	Case* terrain =NULL ;
	int nbrmine = 5;
	int i = 0 ;
	long begin =0;
	long end =0;
	//char* pif [20];
	
	time_t timestamp = time( NULL );
	begin = timestamp;
	printf("a");
	
	
	
	//itoa(15 , pif, 10);
	//terrain = malloc ( size * size * sizeof(Case));
	
	
	//minedropper(terrain, size, nbrmine);
	printf("b");
	printf("\n addresse du terrain %p \n" , terrain);
	terrain = initable(terrain,  size, nbrmine);
	printf("\n addresse du terrain %p \n" , terrain);
	printf("c");
	
	printf("\n addresse du terrain %p \n" , terrain);
	verif = confirmmarkCase( terrain,  size,  size,  size, 1, 1);
	printf ("%d \n", verif);
	
	printf("\n %d", (*(terrain+2)).status);
	printf("\n %d", (*(terrain+2)).discover);
	printf("\n %d", (*(terrain+5)).discover);
	whatIshow(*terrain);
	
	//for(i = 0; i < (size * size) ; i++)
	printf("\n addresse du terrain %p \n" , terrain);
	showgame(terrain, size);
	printf("\n addresse du terrain %p \n" , terrain);
	recurseCase(5, 4, terrain, size);
	printf("\n addresse du terrain %p \n" , terrain);
	showgame(terrain, size);
	//markCase(terrain, size);
	
	
	for(i = 0 ; i<( size *size) ; i++){
			(*(terrain+i)).discover = 0;
		
	}
	showgame(terrain, size);
	
	
	for(i = 0 ; i<(size * size ) ; i++){
			(*(terrain+i)).discover = 1;
		
	}
	showgame(terrain, size);
	
	for(i = 0 ; i<(size * size ) ; i++){
			(*(terrain+i)).discover = -1;
		
	}
	showgame(terrain, size);
	
	
		printf("\n %d", (rand() % 100));
	
	(*terrain).discover = 1;
	printf("\n %d", (*(terrain+2)).status);
	printf("\n %d", (*(terrain+2)).discover);
	printf("\n %d", (*(terrain+5)).discover);
	whatIshow(*terrain);
	showgame(terrain, size);
	printf("\n %s", pipo);
	
	end = timestamp;
	printf("\n %ld", end);
	end = end - begin;
	printf("\n %ld", end);
	printf("\t %ld", begin);
	return (0);
}

