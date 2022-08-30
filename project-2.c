#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<conio.h>                                 // declaration all function
void Startgame(char a[],char [],char []);
int checkwin(char a[]);
void changemove(char b,char a[],int ply);
void randonmove(char a[]);
void computer(char a[],char ply);
void computerEvil(char a[],char ply);
void playerturn(char str1[],char a[],int ply);
void begingame(char str1[]);
void draw();
void winlose(char str1[],char str2[],int ply);
void red();
void reset();
void yellow();
void blue();

int main(){
    int i=0,j,n,ply=1;
    char a[10]={'0','1','2','3','4','5','6','7','8','9'};
    char str1[20],str2[20],count;
    printf("    Enter your choice\n\n");
    printf("          1. Want to plany with smart computer\n");
    printf("          2. Want to play with Evil computer\n");
    printf("          3. Want to play with player\n");
    printf("          4. Exit\n");
    scanf("%d",&n);


  switch(n){

case 1:                     // Want to plany with smart computer
    begingame(str1);
    strcpy(str2,"Computer");
    system("cls");
    Startgame(a,str1,str2);
    while(checkwin(a)){
           if((checkwin(a))==1){
                winlose(str1,str1,ply);
                getch();
                exit(0);
            }
    if(ply==1){
            blue();
           playerturn(str1,a,ply);
    }

    else
        computer(a,ply);  // computer turn
        system("cls");
      Startgame(a,str1,str2);
      ply==1?ply++:ply--;

    }
    draw();
    getch();
    break;

case 2:                    // Want to play with Evil computer
    begingame(str1);
    strcpy(str2,"Evil Computer");
    system("cls");
    Startgame(a,str1,str2);
    while(checkwin(a)){
           if((checkwin(a))==1){
                winlose(str1,str1,ply);
                getch();
                exit(0);
            }
    if(ply==1){
        blue();
        playerturn(str1,a,ply);           // player turn
        }
    else
        computerEvil(a,ply);   // computer evil turn

    system("cls");
    Startgame(a,str1,str2);
    ply==1?ply++:ply--;
    }
    draw();
    getch();
    break;


case 3:                               //   Want to play with player
    begingame(str1);
    printf("\n  enter player2 name ");
    fgets(str2,20,stdin);
     str2[strlen(str2)-1]='\0';
    system("cls");
    Startgame(a,str1,str2);

    while(checkwin(a)){
            if(checkwin(a)==1){
                winlose(str1,str2,ply);
                getch();
                exit(0);
            }
    if(ply==1){
       blue();
       playerturn(str1,a,ply);    //player1 turn
    }
   else{
        red();
        playerturn(str2,a,ply);   // player2 turn
   }
    system("cls");
    Startgame(a,str1,str2);
    ply==1?ply++:ply--;
    }
    draw();
    getch();
    break;


case 4:
    exit(0);

default:
    printf("Invalid choice");
    }


}
                 // all function define
void begingame(char str1[]){       // first function
fflush(stdin);
    system("cls");
    printf("\n  Enter player1 name ");
    fgets(str1,20,stdin);
    str1[strlen(str1)-1]='\0';

}
void Startgame(char a[],char str1[],char str2[]){  // starting the game
 blue();
 printf("\n############################## ");red();printf("Tic -Tac- Toe "); yellow();;printf("###################################\n\n");
 blue();
 printf("  %s , ",str1);
 reset();
 printf("symbol is X\n");
 red();
 printf("  %s , ",str2);
 reset();
 printf("symbol is O\n");
 printf("\n\n");
blue();
    printf("\n     |     |     \n");
reset();
    printf("  %c  |  %c  |  %c \n", a[1], a[2], a[3]);
yellow();
    printf("_____|_____|_____\n");
red();
    printf("     |     |     \n");
reset();
    printf("  %c  |  %c  |  %c \n", a[4], a[5], a[6]);
yellow();
    printf("_____|_____|_____\n");
red();
    printf("     |     |     \n");
reset();
    printf("  %c  |  %c  |  %c \n", a[7], a[8], a[9]);
yellow();
    printf("_____|_____|_____\n\n");
red();
     printf("###############################################################################\n\n");
reset();
    }

void changemove(char b,char a[],int ply){   // change the move given position
 int i;
 for(i=1;i<10;i++){
    if(a[i]==b && a[i]!='X' && a[i]!='O')
        if(ply==1)
        a[i]='X';
         else
            a[i]='O';

 }
}
int checkwin(char a[]){              // check wining condition
    if(a[1]==a[2] && a[2]==a[3])
        return 1;
    else
        if(a[4]==a[5] && a[5]==a[6])
        return 1;
     else
        if(a[7]==a[8] && a[8]==a[9])
        return 1;
     else
     if(a[1]==a[4] && a[4]==a[7])
        return 1;
     else
     if(a[2]==a[5] && a[5]==a[8])
        return 1;
    else
     if(a[3]==a[6] && a[6]==a[9])
        return 1;
    else
     if(a[3]==a[5] && a[5]==a[7])
        return 1;
    else
     if(a[1]==a[5] && a[5]==a[9])
        return 1;
    else
     if(a[1]!='1'&& a[2]!='2'&& a[3]!='3' && a[4]!='4' && a[5]!='5' && a[6]!='6' && a[7]!='7'&& a[8]!='8'&& a[9]!='9' )
        return 0;

    else
    return 2;

}
void winlose(char str1[],char str2[],int ply){           // last case which one win the game
     yellow();
     ply==1?printf("\n\n You lose! %s ",str2):printf("\n\n You Win! %s ",str1);
     blue();
     printf("\n\n\n###############################################################################");

}
void draw(){            // draw the game
    red();
    printf("\n\n\n  Game Draw!\n");
    blue();
    printf("\n\n\n###############################################################################");

}
void playerturn(char str1[],char a[],int ply){  // telling the player turn
    int count;
           printf("\n\n\n %s ,",str1);
           reset();
           printf("your Turn ");
           fflush(stdin);
           scanf("%c",&count);
           changemove(count,a,ply);
          system("cls");


}

void computer(char a[],char ply){     // automatic computer turn
if(a[1]==a[2] && a[3]!='X' && a[3]!='O')
    changemove('3',a,ply);
else
    if(a[2]==a[3] && a[1]!='X' && a[1]!='O')
    changemove('1',a,ply);
else
   if(a[1]==a[3] && a[2]!='X' && a[2]!='O')
    changemove('2',a,ply);
else
   if(a[4]==a[5] && a[6]!='X' && a[6]!='O')
    changemove('6',a,ply);
else
   if(a[5]==a[6]&& a[4]!='X' && a[4]!='O')
    changemove('4',a,ply);
else
   if(a[4]==a[6]&& a[5]!='X' && a[5]!='O')
    changemove('5',a,ply);
else
   if(a[7]==a[8]&& a[9]!='X' && a[9]!='O')
    changemove('9',a,ply);
else
   if(a[8]==a[9]&& a[7]!='X' && a[7]!='O')
    changemove('7',a,ply);
else
   if(a[7]==a[9]&& a[8]!='X' && a[8]!='O')
    changemove('8',a,ply);
else
   if(a[3]==a[5]&& a[7]!='X' && a[7]!='O')
    changemove('7',a,ply);
else
   if(a[5]==a[7]&& a[3]!='X' && a[3]!='O')
    changemove('3',a,ply);
else
   if(a[3]==a[7]&& a[5]!='X' && a[5]!='O')
    changemove('5',a,ply);
else
   if(a[1]==a[5]&& a[9]!='X' && a[9]!='O')
    changemove('9',a,ply);
else
   if(a[5]==a[9]&& a[1]!='X' && a[1]!='O')
    changemove('1',a,ply);
else
   if(a[1]==a[9]&& a[5]!='X' && a[5]!='O')
    changemove('5',a,ply);
else
  if(a[1]==a[4]&& a[7]!='X' && a[7]!='O')
    changemove('7',a,ply);
else
  if(a[4]==a[7]&& a[1]!='X' && a[1]!='O')
    changemove('1',a,ply);
else
  if(a[1]==a[7]&& a[4]!='X' && a[4]!='O')
    changemove('4',a,ply);
else
  if(a[2]==a[5]&& a[8]!='X' && a[8]!='O')
    changemove('8',a,ply);
else
  if(a[5]==a[8]&& a[2]!='X' && a[2]!='O')
    changemove('2',a,ply);
else
  if(a[2]==a[8]&& a[5]!='X' && a[5]!='O')
    changemove('5',a,ply);
 else
  if(a[3]==a[6]&& a[9]!='X' && a[9]!='O')
    changemove('9',a,ply);
else
  if(a[6]==a[9]&& a[3]!='X' && a[3]!='O')
    changemove('3',a,ply);
else
  if(a[3]==a[9]&& a[6]!='X' && a[6]!='O')
    changemove('6',a,ply);
else
    randonmove(a);

}
void randonmove(char a[]){      // select the computer random nove
char i;
for(char i=1;i<10;i++){
    if(a[i]!='X' && a[i]!='O'){
        a[i]='O';
        break;
       }

   }
}
void computerEvil(char a[],char ply){  // automatic evil computer turn
    int p=0;
if(a[1]==a[2] && a[3]!='X' && a[3]!='O'){
    changemove('3',a,ply);
    p=1;
    }
    if(a[2]==a[3] && a[1]!='X' && a[1]!='O'){
    changemove('1',a,ply);
    p=1;
    }
   if(a[1]==a[3] && a[2]!='X' && a[2]!='O'){
    changemove('2',a,ply);
    p=1;
   }
   if(a[4]==a[5] && a[6]!='X' && a[6]!='O'){
    changemove('6',a,ply);
               p=1;
   }
   if(a[5]==a[6]&& a[4]!='X' && a[4]!='O'){
    changemove('4',a,ply);
    p=1;
   }
   if(a[4]==a[6]&& a[5]!='X' && a[5]!='O'){
    changemove('5',a,ply);
    p=1;
   }
   if(a[7]==a[8]&& a[9]!='X' && a[9]!='O'){
    changemove('9',a,ply);
    p=1;
   }
   if(a[8]==a[9]&& a[7]!='X' && a[7]!='O'){
    changemove('7',a,ply);
    p=1;
   }
   if(a[7]==a[9]&& a[8]!='X' && a[8]!='O'){
    changemove('8',a,ply);
    p=1;
   }
   if(a[1]==a[4]&& a[7]!='X' && a[7]!='O'){
    changemove('7',a,ply);
    p=1;
  }
  if(a[4]==a[7]&& a[1]!='X' && a[1]!='O'){
    changemove('1',a,ply);
    p=1;
  }
  if(a[1]==a[7]&& a[4]!='X' && a[4]!='O'){
    changemove('4',a,ply);
    p=1;
  }
  if(a[2]==a[5]&& a[8]!='X' && a[8]!='O'){
    changemove('8',a,ply);
    p=1;
  }
  if(a[5]==a[8]&& a[2]!='X' && a[2]!='O'){
    changemove('2',a,ply);
    p=1;
  }
  if(a[2]==a[8]&& a[5]!='X' && a[5]!='O'){
    changemove('5',a,ply);
    p=1;

  }
  if(a[3]==a[6]&& a[9]!='X' && a[9]!='O'){
    changemove('9',a,ply);
     p=1;
  }
  if(a[6]==a[9]&& a[3]!='X' && a[3]!='O'){
    changemove('3',a,ply);
     p=1;
  }
  if(a[3]==a[9]&& a[6]!='X' && a[6]!='O'){
    changemove('6',a,ply);
     p=1;
  }
   if(a[3]==a[5]&& a[7]!='X' && a[7]!='O'){
    changemove('7',a,ply);
    p=1;
   }
   if(a[5]==a[7]&& a[3]!='X' && a[3]!='O'){
    changemove('3',a,ply);
    p=1;
   }
   if(a[3]==a[7]&& a[5]!='X' && a[5]!='O'){
    changemove('5',a,ply);
    p=1;
   }
   if(a[1]==a[5]&& a[9]!='X' && a[9]!='O'){
    changemove('9',a,ply);
    p=1;
   }
   if(a[5]==a[9]&& a[1]!='X' && a[1]!='O'){
    changemove('1',a,ply);
   p=1;
   }
  if(a[1]==a[9]&& a[5]!='X' && a[5]!='O'){
    changemove('5',a,ply);
    p=1;
  }

  if(p==0)
    randonmove(a);

}


        // function for changing colour
void red () {
  printf("\033[1;31m");
}

void yellow() {
  printf("\033[1;33m");
}

void reset () {
  printf("\033[0m");
}

void blue(){
printf("\033[034m");
}
