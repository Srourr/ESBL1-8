/* The Code Has 5 Functions the Flow starts with with ( Mark_Choose ) Function which
determines the Marks which the players choosing to play with
then the ( Print_Grid ) Function which prints 
the grid view of game with a number in each cell in the matrix so the player can choose easily the position
at the end of the ( Print_Grid ) function the ( Play ) Function is called to start get 
the player input and checks if the cell is empty and that the 
position number is valid ( From 1 -9 ) at the end of the function the ( Print_Grid ) is called again
to update the Matrix and to check the number of rounds 
cause the maximum number of rounds is 9 then it's checking if any one have won the game, if not it's 
calling the ( Play ) Function Again till any one wins 
or in case of draw the ( Again ) Function is called to ask the player if he wants to 
play again or quit in case of playing again all variables are cleared and the loop starts again.*/

#include<stdio.h>
#include<stdlib.h>
void Print_Grid();
void Check();
int Play();
int Mark_Choose();
int Again();

int CN[9]={1,2,3,4,5,6,7,8,9},UC[9],R=0,POS,WP[2],P=1;
char ag,CM[9] = {' ',' ',' ',' ',' ',' ',' ',' ',' '};
char Mark1,Mark2;

int main(){
if (ag == 'q') exit; 
Mark_Choose();
Print_Grid();
 
}


int Mark_Choose(){
printf("Player (1) Please Choose One Of The Two Options 'X' or 'O' :\n");
scanf("%s",&Mark1);
if (Mark1 == 'x' || Mark1 == 'X' || Mark1 == 'o' || Mark1 == 'O'){
system("cls");
if (Mark1 == 'x' || Mark1 == 'X') Mark2 = 'O';
else if (Mark1 == 'o' || Mark1 == 'O') Mark2 = 'X';
}
else {printf("\nWrong Option, Please Enter Again !\n");
return Mark_Choose();}
}

void Print_Grid(){
/* This Funtion is responsible of printing the grid view of the game matrix */

printf("\nPlayer 1 : %c\t\t\t Player 2 : %c  \n\t\tROUND NUMBER: %d\n\n",Mark1,Mark2,R);
int r = 0;
/* Print_Grid Function is responsible for printing the Tic-Tac-Toe Grid view through two 
for loops to make a matrix shape and printing the cell number represented in the "CN" variable 
at the end of each cell so user can choose easily between them to place his mark*/

for (int BOUND = 0 ; BOUND < 3; BOUND ++){ 
if (BOUND == 0 )printf("          %d|          %d|          %d\n",CN[0],CN[1],CN[2]);
else if (BOUND == 1 )printf("          %d|          %d|          %d\n",CN[3],CN[4],CN[5]);
else if (BOUND == 2 )printf("          %d|          %d|          %d\n",CN[6],CN[7],CN[8]);
for (int ROWS= 0; ROWS<4; ROWS ++){
if (ROWS == 1) printf("    %c      |    %c      |    %c      \n",CM[r],CM[r+1],CM[r+2]);
else printf("           |           |           \n");
}
if (BOUND != 2) printf("----------- ----------- -----------\n");
r = r+3;
}
Check();
Play();
}

int Play(){
/* This Function is responsible of Checking the number of rounds and getting the input postition */

if (R == 9){
Check();
system("cls");
printf("\n\n --------------------------\n|^^^^^^^^^^^^^^^^^^^^^^^^^^|\n|   << NO ONE WINS!!! >>   |\n|vvvvvvvvvvvvvvvvvvvvvvvvvv|\n --------------------------\n");
Again();
}
printf("\nPlayer(%d) Please Enter The Position you want to place mark in :",P);
scanf("%d",&POS);
if (POS > 9 || POS < 1){
printf("\nThe Position isn't correct !");
return Play();
} 
if (UC[POS-1] == 1 || UC[POS-1] == 2){
printf("\nThe Position is busy !");
return Play();
}

if (P == 1) {
CM[POS-1] = Mark1;
UC[POS-1] = 1;
}
if (P == 2){
CM[POS-1] = Mark2;
UC[POS-1] = 2;
}

system("cls");

if (P == 1) P = 2;
else if (P == 2) P = 1;
R++;
Print_Grid();
}

void Check(){

for (int i = 1;i<3;i++){
if ( UC[0] == i && UC[1] == i && UC[2] == i) WP[i-1] = 1;
else if ( UC[3] == i && UC[4] == i && UC[5] == i) WP[i-1] = 1;
else if ( UC[6] == i && UC[7] == i && UC[8] == i) WP[i-1] = 1;
else if ( UC[0] == i && UC[3] == i && UC[6] == i) WP[i-1] = 1;
else if ( UC[1] == i && UC[4] == i && UC[7] == i) WP[i-1] = 1;
else if ( UC[2] == i && UC[5] == i && UC[8] == i) WP[i-1] = 1;
else if ( UC[0] == i && UC[4] == i && UC[8] == i) WP[i-1] = 1;
else if ( UC[2] == i && UC[4] == i && UC[6] == i) WP[i-1] = 1;
}
if (WP[0] == 1){
system("cls");
printf("\n\n --------------------------\n|^^^^^^^^^^^^^^^^^^^^^^^^^^|\n| << PLAYER (1) WINS!!! >> |\n|vvvvvvvvvvvvvvvvvvvvvvvvvv|\n --------------------------\n"); 
Again();
}

else if (WP[1] == 1){
system("cls");
printf("\n\n --------------------------\n|^^^^^^^^^^^^^^^^^^^^^^^^^^|\n| << PLAYER (2) WINS!!! >> |\n|vvvvvvvvvvvvvvvvvvvvvvvvvv|\n --------------------------\n"); 
Again();
}
}

int Again(){
/* This Function is checking if the player wants to play again or not and clearing all the used variables */

printf("\n\n\n\nIf You Want To Play Again Enter 'y' If You Want To Quit Enter 'q' : ");
scanf("%s",&ag);
if (ag == 'y') {
system("cls");
for(int i = 0;i<9;i++){CN[i] = (i+1);}
for(int i = 0;i<9;i++){UC[i] = 0;}
WP[0] = 0;
WP[1] = 0;
for(int i = 0;i<9;i++){CM[i] = ' ';}
POS = 0;
P = 1;
Mark1 = ' ';
Mark2 = ' ';
R = 0;
ag = ' ';
return main();
}
else if (ag == 'q')  exit(0);
else {
printf("Unknown Option !");
return Again();
}
}
