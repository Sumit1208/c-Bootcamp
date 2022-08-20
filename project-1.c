
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#include<windows.h>

void swap(char*,char*);
int print_matrix(char[],int);
char arrows(int*,int,char[]);
int difficulty(int);
void print_rules(char[]);
void gameplay(char[],char[],char[]);
void font_color(int Forgc);

int main()
{
    char mat[10][16]={{2,3,5,6,4,8,32,9,7,1,10,15,13,12,11,14},{5,15,14,2,3,4,7,11,9,10,32,13,12,1,6,8},{4,5,6,7,10,11,12,13,1,2,3,32,8,9,15,14},{3,15,1,14,2,13,4,12,5,11,6,10,7,8,9,32},{6,7,8,9,10,11,32,1,2,3,4,5,12,13,14,15},{32,15,1,3,5,9,11,2,4,6,8,10,12,14,7,13},{1,2,3,4,5,6,7,8,32,9,10,11,12,13,14,15},{8,3,1,9,7,5,4,6,2,10,11,32,12,13,14,15},{9,8,2,7,5,3,6,1,15,10,32,11,12,13,14,4},{10,11,12,13,14,15,32,1,9,8,2,3,7,6,5,4}};
    char solved[16]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,32};
    char name[21];
    int random;

    printf("Enter your name: ");

    fgets(name,21,stdin);
    name[strlen(name)-1]=0;
    strupr(name);
    random=strlen(name)%10;
    gameplay(mat[random],solved,name);
}
void swap(char *blank,char *swap)
{
    char ch;
    ch=*swap;
    *swap=*blank;
    *blank=ch;
}

int print_matrix(char mat[],int k )
{
    int i,blank;
    if(k>0)
    {
        system("cls");
        font_color(1);
        printf("\n\n  Move Remaining : %d\n\n",k);
    }
    for(i=0;i<16;i++)
    {
        font_color(12);
        if(i%4==0)
            printf("\n  ---------------------\n  ");
        font_color(2);
        if(mat[i]==32)
        {
            font_color(2);
            if(k>0)
                blank=i;
            if(i%4==3)
                printf("| %c  |",mat[i]);
            else
                printf("| %c  ",mat[i]);
        }
        else if(mat[i]<10)
                if(i%4==3)
                    printf("| %d  |",mat[i]);
                else
                    printf("| %d  ",mat[i]);
            else if(i%4==3)
                    printf("| %d |",mat[i]);
                else
                    printf("| %d ",mat[i]);
    }
    font_color(12);
    printf("\n  ---------------------");

    if(k>0)
        printf("\n");
    return (blank);
}

char arrows(int *ch2,int blank,char mat[])
{
    char temp;
    switch(*ch2)
    {
        case 72:  // UP
            if(blank<12)
            {
                temp=mat[blank+4];
                swap(&mat[blank],&mat[blank+4]);
                *ch2=0;
                break;
            }
            else
                break;

        case 80:  // DOWN
            if(blank>3)
            {
                temp=mat[blank-4];
                swap(&mat[blank],&mat[blank-4]);
                *ch2=0;
                break;
            }
            else
                break;

        case 75: // LEFT
            if(blank%4!=3)
            {
                temp=mat[blank+1];
                swap(&mat[blank],&mat[blank+1]);
                *ch2=0;
                break;
            }
            else
                break;

        case 77: // RIGHT
            if(blank%4)
            {
                temp=mat[blank-1];
                swap(&mat[blank],&mat[blank-1]);
                *ch2=0;
                break;
            }
            else
                break;
    }
    return(temp);
}
void print_rules(char solved[])
{
    printf("\n\n\n");
    font_color(4);
    printf("\t\t\tRULE OF THIS GAME\n");
    font_color(15);
    printf("1.You can move only 1 step at a time by arrow key\n");
    font_color(14);
    printf("Move up   : by Up arrow key\n");
    printf("Move Down : by Down arrow key\n");
    printf("Move Left : by Left arrow key\n");
    printf("Move Right: by Right arrow key\n\n");
    font_color(15);
    printf("2.You can move number at empty position only\n\n");
    printf("3.For each valid move : your total number of move will decreased by 1\n\n");
    printf("4.Winning situation : number in 4*4 matrix should be in order from 1 to 15\n\n");
    font_color(12);
    print_matrix(solved,0);
    font_color(7);
    printf("\n5.you can exit the game at any time by pressing 'E' or 'e'\n\n");
    printf("\nSo try to win in minimum no of move\n\n");
    font_color(1);
    printf("\t\tHappy gaming , Good Luck\n");

    font_color(7);
    printf("\t\t\t\t\tPress any key to continue : ");

    getch();
}
void gameplay(char mat[],char solved[],char name[])
{
    char gmply_mat[10][16]={{2,3,5,6,4,8,32,9,7,1,10,15,13,12,11,14},{5,15,14,2,3,4,7,11,9,10,32,13,12,1,6,8},{4,5,6,7,10,11,12,13,1,2,3,32,8,9,15,14},{3,15,1,14,2,13,4,12,5,11,6,10,7,8,9,32},{6,7,8,9,10,11,32,1,2,3,4,5,12,13,14,15},{32,15,1,3,5,9,11,2,4,6,8,10,12,14,7,13},{1,2,3,4,5,6,7,8,9,10,11,12,13,14,32,15},{8,3,1,9,7,5,4,6,2,10,11,32,12,13,14,15},{9,8,2,7,5,3,6,1,15,10,32,11,12,13,14,4},{10,11,12,13,14,15,32,1,9,8,2,3,7,6,5,4}};
    char temp;
    int turns=0,ch1,ch2=0;
    int i,j,k,m,blank,win=0,play,choice;
    int add,random=&add;

    print_rules(solved);
    while(turns==0)
    {
        fflush(stdin);
        system("cls");
        turns=400;
    }
    printf("\n  Press any key to start the game.\n\n  ");
    getch();

    for(k=0;k<=turns;k++)
    {
        for(m=0;m<16;m++)
            if(mat[m]-solved[m]!=0)
            {
                win=0;
                if(k==turns)
                {
                    font_color(12);
                    printf("\n\n Sorry ");

                    font_color(11);
                    printf("%s,",strlwr(name));

                    font_color(12);
                    printf(" You Lose...\n\n\n\n\n\n\n");

                    font_color(7);
                    printf("Would you like to play again ?\n\n  Press 'Y' if Yes,\n  Press 'N' if No : \n\n  ");
                    while(play!='y' || play!='y' || play!='N' || play!='n')
                    {
                        play=getch();
                        if(play=='N' || play=='n' || play=='E' || play=='e')
                            exit(0);
                        else if(play=='Y' || play=='y')
                            gameplay(gmply_mat[blank%10],solved,name);
                    }
                }
                else
                    break;
            }
            else
                win=1;
        if(win)
        {
            print_matrix(mat,-1);

            font_color(6);
            printf("\n\n\n\n *****  CONGRATULATIONS");

            font_color(11);
            printf("%s",strupr(name));

            font_color(6);
            printf("!!!! YOU HAVE WON !!!!  ****\n  You took");

            font_color(10);
            printf(" %d turns ",k);

            font_color(6);
            printf("to sort the matrix.\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");

            font_color(7);
            printf("\n\n  Would you like to play again ?\n\n  Press 'Y' if Yes,\n  Press 'N' if NO : \n\n  ");

            while(play!='y' || play!='y' || play!='N' || play!='n')
            {
                play=getch();
                if(play=='N' || play=='n' || play=='E' || play=='e')
                    exit(0);
                else if(play=='Y' || play=='y')
                    gameplay(gmply_mat[blank%10],solved,name);
            }
        }
        blank=print_matrix(mat,turns-k);

        while(1)
        {
            ch1=getch();
            if(ch1=='E' || ch1=='e')
            {
                printf("\n\n  The user has quit the game....\n\n\n\n\n\n\n\n ");
                system("pause");
                exit(0);
            }
            if(ch1==0xE0)
                ch2=getch();

            temp=arrows(&ch2,blank,mat);
            if(temp==mat[blank])
                break;
        }
    }
    printf("\n\n  Press any key to exit program.\n\n  ");
    getch();
}
void font_color(int Forgc)
{
    WORD wColor;
    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO csbi;

    if(GetConsoleScreenBufferInfo(hStdOut, &csbi))
    {
        wColor = (csbi.wAttributes & 0xF0) + (Forgc & 0x0F);
        SetConsoleTextAttribute(hStdOut, wColor);
    }
    return;
}
