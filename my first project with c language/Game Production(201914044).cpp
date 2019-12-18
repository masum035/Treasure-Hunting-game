#include<graphics.h>
#include<process.h>
#include<dos.h>
#include<conio.h>
#include<stdio.h>
#include<windows.h>
#include<MMsystem.h>
#include<stdlib.h>
#include<time.h>

int treasure=0,highscore=0,health=5,x1,y1,b,t,nothing=0,total=0;
int row1,col1,table1[100][100],row2=0,col2=0;
int ch2;
static int x=185,y=191;
time_t start,endd;
char ins[500];

/*void show_score()
{
    char show[200];
    int s;
    FILE *fptr ;
    fptr= fopen("C:\\Users\\Malware\\Desktop\\file testing001.txt", "w");
        ///fprintf("Your score is : ");

        fscanf(fptr,"%d\n",&treasure);
        fclose(fptr);

    if(treasure>highscore)
        {
            highscore=treasure;
    FILE *fp;
    fp = fopen("C:\\Users\\Malware\\Desktop\\file testing001.txt", "r");
    /// fprintf("New highscore is : ");
            fprintf(fptr,"%d\n",highscore);
            fclose(fptr);
        }
    treasure=0;
    health=5;
    rock=0;
}
*/

char data1[20],data2[20],result[15];
void Welcome();
int main();
void Load();
void object(int x,int y);
void object();
void control();
void TABLE();
void Design();
void credit();
void Border();
void Music();
void Instruction();
void ExitGame();
void settime();


void Load()
{
    int t,i;
    char load[20];
    setcolor(11);
    moveto((getmaxx()/2) - 80,(getmaxy()/2 + 50));

    outtext("Loading....Please Wait!");
    setcolor(1);
    for(i=0; i<=360; ++i)
    {
        for(t=0; t<=60; t++)
        {
            circle(getmaxx()/2,getmaxy()/2 - 60,t);
            pieslice(getmaxx()/2,getmaxy()/2 - 60,0,i,60);
        }
        /// delay(3);
    }
    cleardevice();
}

void Welcome()
{
    cleardevice();
    int i;
    while (1)
    {
        for (i=0; i<15; i++)
        {
            setcolor(i);
            settextstyle(BOLD_FONT,0, 5);
            outtextxy(375, 220, "WELCOME TO TREASURE HUNT");
            delay(250);

            setcolor(15-i);
            settextstyle(BOLD_FONT, HORIZ_DIR, 2);
            outtextxy(500, 290, "press ENTER to continue");

        }
        if(getch()==13)
        {
            cleardevice();
            break;
        }
        if(i==14)
            i=0;
    }

}

void  Instruction()
{
    cleardevice();
    char ins[100];
    setcolor(YELLOW);
    settextstyle(BOLD_FONT, HORIZ_DIR, 03);
    sprintf(ins, "GAME INSTRUCTIONS");
    outtextxy(50,100,ins);
    setcolor(CYAN);
    sprintf(ins,"Use arrow keys for movement.");
    outtextxy(50,200,ins);
    sprintf(ins, "You have to find treasure in several boxes of the screen which you have to collect.");
    setcolor(MAGENTA);
    outtextxy(50, 300, ins);
    setcolor(RED);
    sprintf(ins, "Everytime you collect a treasure,your treasure will be increased by 1$ and thus the score.");
    outtextxy(50,400,ins);
    setcolor(GREEN);
    sprintf(ins,"Here you are provided with health level 05. Your health will decrease,if you find any rock.");
    outtextxy(50,500,ins);
    setcolor(WHITE);
    sprintf(ins, "PREES ANY KEY TO START THE GAME.");
    outtextxy(50,600,ins);

    getch();
    cleardevice();
    setcolor(MAGENTA);
    settextstyle(BOLD_FONT, HORIZ_DIR, 04);
    sprintf(ins,"STORY LINE:");
    outtextxy(50,70,ins);
    settextstyle(DEFAULT_FONT,0,0);
    setcolor(GREEN);
    sprintf(ins,"Once a king ordered a man to collect treasure to help him to build the nation richfully.");
    outtextxy(50,130,ins);
    sprintf(ins,"Now the task is to be completed otherwise the man will be executed.");
    outtextxy(50,180,ins);
    sprintf(ins,"Now,here King means computer and the initial task is to collect above 5 treasure box.");
    outtextxy(50,230,ins);
    sprintf(ins,"and the man is YOU who is playing.");
    outtextxy(50,280,ins);
    sprintf(ins,"If you cross the boarder you will be executed and the game will therefore end.");
    outtextxy(50,330,ins);
    sprintf(ins,"and if you find any rock, your health will be decreased by one.");
    outtextxy(50,380,ins);
    sprintf(ins,"Remember That: initial health is 5.");
    outtextxy(50,430,ins);
    sprintf(ins,"Now,the theme is to find treasure box is that:if the output number is divisible of 11,you score will get increased");
    outtextxy(50,480,ins);
    sprintf(ins,"And if the output number is divisible of 5,you got rock & your health will decreased.");
    outtextxy(50,530,ins);
    sprintf(ins,"Otherwise,you will unleashed empty box each time.");
    outtextxy(50,590,ins);
    getch();
    cleardevice();
}

void ExitGame()
{
    cleardevice();
    b=1;
    while(b<15)
    {
        setcolor(b);
        settextstyle(BOLD_FONT,0,8);
        outtextxy(455,300, "GAME OVER");

        setcolor(b-2);
        settextstyle(BOLD_FONT,0,3);

        sprintf(ins,"Do You Really Want To Quit?");
        outtextxy(480,500,ins);

        sprintf(ins,"YES");
        outtextxy(500,580,ins);

        sprintf(ins,"NO");
        outtextxy(660,580,ins);

        sprintf(ins,"Press Y ");
        outtextxy(500,630,ins);

        sprintf(ins,"Press N");
        outtextxy(660,630,ins);
        char ch1;
        ch1=getch();
        switch(ch1)
        {
        case 'y':
        case 'Y':
            cleardevice();
            endd = time(NULL);
            sprintf(ins,"Hope you enjoyed Total %.2f seconds of this game",difftime(endd,start));
            outtextxy(300,300,ins);
            settextstyle(8,0,4);
            setcolor(12);
            outtextxy(475,410,"CONGRATULATIONS!!");
            getch();
            exit(0);
        case 'n':
        case 'N':
            system("cls");
            cleardevice();
            health=5;
            treasure=0;
            main();
        }
        b++;
    }
    cleardevice();
    //show_score();
    exit(0);
}

void Border()
{
    //setcolor(01);
    //setbkcolor(0);
    {
        bar(0,30,1350,47);///UP
        bar(0,47,17,700);///left
        bar(17,700,1350, 700-452);///DOWNN
        bar(1350-20,47, 1350, 700);///right
    }
    //setcolor(0);
}
void credit()
{
    cleardevice();
    while(1)
    {
CREDIT:
        {
            for(int i=1; i<=15; i++)
            {
                setcolor(12);
                settextstyle(BOLD_FONT, HORIZ_DIR, 2);
                outtextxy(500, 290, "press ENTER to continue");

                settextstyle(3,0,1);
                setcolor(i+2);
                outtextxy(getmaxx()-180,400,"   MASUM  ");
                outtextxy(getmaxx()-220,420,"GAME PRODUCTION");
                delay(280);
                /* for credit's border  */
                line(getmaxx()-222,398,getmaxx()-60,398);   ///for top
                line(getmaxx()-222,460,getmaxx()-60,460);    ///for below
                line(getmaxx()-222,398,getmaxx()-222,460);    ///for left
                line(getmaxx()-60,398,getmaxx()-60,460);      ///for right

            }
        }
        if(getch()==13)
        {
            break;
        }
        else
            goto CREDIT;

    }
    cleardevice();
}

void object()
{
    //x=440,y=155;
    // body and leg of man
    setcolor(YELLOW);
    setlinestyle(SOLID_LINE, 1, 3);
    line(x + 40, y - 35, x + 40, y - 20);
    line(x + 40, y - 15, x + 45, y - 10);
    line(x + 45, y - 10, x + 45, y);
    line(x + 40, y - 15, x + 37, y);
    // head, hands of man
    circle(x + 40, y - 45, 5.5);
    line(x + 40, y - 35, x + 52, y - 30);
    line(x + 40, y - 35, x + 37, y - 32);
    //lineto(x+30,y-27);
    line(x + 37, y - 32, x + 30, y - 25);
    int points[]= {x + 37, y - 32,x + 40,y-27,x+44,y-30,x + 37, y - 32};
    drawpoly(4, points);
    circle(x + 40, y - 25, 3);
    circle(x + 40, y - 22, 3);
    circle(x + 40, y - 20, 3);
    delay(5);
}

void TABLE()
{
    int i,j=0,k=0,rock=0;
    setcolor(MAGENTA);
    rectangle(205,154,940+205,606);

    for (i=0; i<11; i++)
    {
        setcolor(5);
        line(205,155+j,205+470+470,155+j);
        j+=45;
    }
    j=0;
    for (i=0; i<=21; i++)
    {
        setcolor(9);
        line(204+j,155,204+j,605);
        j+=45;
    }
    srand(time(NULL));
    ///getch();
    for(int row1=0; row1<10; row1++)
    {
        for(int col1 = 0; col1<=20; col1++)
        {
            table1[row1][col1]=1+rand()%100;
            /*  sprintf(data1,"%2d",table1[row1][col1]);
               setcolor(07);
               outtextxy(217+x1,170+y1,data1);
            */
            x1+=45;

        }
        x1=0;
        y1+=45;
    }
    y1=0;

    {
setcolor(0);
    if(table1[row1][col1]%5== 0)
    {
        rock=rock+1;
        health=health-rock;
        // setbkcolor(13);
        setcolor(WHITE);
        sprintf(data1,"Health Remains: %d",health);
        outtextxy(30,30,data1);
        sprintf(data1,"Oops!you found rock: %d",table1[row1][col1]);
        outtextxy(30,10,data1);

        if(health<-1 || health<=0)
        {
            printf("%d ",health);
            cleardevice();
            endd = time(NULL);
            b=1;
            while(b<=15)
            {
                setcolor(b);
                settextstyle(BOLD_FONT,0,8);
                outtextxy(455,300, "GAME OVER");
                setcolor(b+2);
                settextstyle(8,0,3);
                sprintf(result,"You Failed to Complete the task");
                outtextxy(470,150,result);
                settextstyle(8,0,4);
                sprintf(ins,"%.2f seconds has been deducted from yor precious life. ",difftime(endd,start));
                outtextxy(150,200,ins);
                outtextxy(570,390,"LOSER!!");
                settextstyle(8,0,2);
                sprintf(result,"TILL TOTAL MOVES: %d",total);
                outtextxy(530,480,result);
                sprintf(result,"SCORE: %d",treasure);
                outtextxy(580,510,result);
                outtextxy(470,560,"PLAY TO WIN..NOT TO LOSE.");
                delay(250);
                b++;
                if(getch()==13)
                {
                    cleardevice();
                    ExitGame();
                    break;
                }
                if(b==1)
                    b=1;
            }
      // show_score();
        }
    }
    else if(table1[row1][col1]%11 == 0)
    {
        treasure++;
        // setbkcolor(BLACK);
        sprintf(data2,"You get treasure: %d",table1[row1][col1]);
        setcolor(YELLOW);
        outtextxy(1350-280,10,data2);
        sprintf(data2,"Score: %d",treasure);
        outtextxy(1350-280,35,data2);

        if(treasure>=5)
        {
            endd = time(NULL);
            cleardevice();
            while(1)
            {
                for(b=1; b<=15; b++)
                {
                    setcolor(b);
                    settextstyle(BOLD_FONT,0,8);
                    outtextxy(495,285, "WINNER");
                    settextstyle(8,0,4);
                    sprintf(ins,"WOW! You have enjoyed my game for %.2f seconds.",difftime(endd,start));
                    outtextxy(200,200,ins);
                    outtextxy(470,370,"CONGRATULATIONS!!");
                    settextstyle(8,0,2);
                    sprintf(result,"TOTAL MOVES: %d",total);
                    outtextxy(540,480,result);
                    sprintf(result,"SCORE: %d",treasure);
                    outtextxy(580,510,result);

                    delay(250);
                }
                if(getch())
                {
                    cleardevice();
                    ExitGame();
                    break;
                }
            }

        }

    }
    else
    {
        nothing++;
        setcolor(10);
        sprintf(data2,"nothing found and got : %d",table1[row1][col1]);
        outtextxy(420,12,data2);
        sprintf(data2,"Empty boxes: %d",nothing);
        outtextxy(420,37,data2);
    }
    }
    total=rock+treasure+nothing;
    if(y1==0 || x1 ==0)
    {
        for(int row1=0; row1<10; row1++)
        {
            for(int col1 = 0; col1<=20; col1++)
            {
                table1[row1][col1]=0;
            }
        }
    }
    ///getch();
    control();
}

void control()
{
    Design();
    //Border();
    settextstyle(8,1,3);
    setcolor(14);
    outtextxy(120,620,"TO WIN,You have to SCORE above 10");
    settextstyle(8,1,3);
    setcolor(7);
    outtextxy(1200,530,"wish you good luck");
    settextstyle(8,0,3);
    setcolor(11);
    outtextxy(440,635,"Use arrow keys for movement.");
    settextstyle(8,0,3);
    setcolor(9);
    outtextxy(500,670,"Stay within boxes");
    settextstyle(0,0,0);
    ///int table2[10][20]= {0};
    char ch1;
    char data[10];
    int row,col,table1[100][100],x1=0,y1=0;
    ch1=getch();
    for(  ; ( (x<=1100 && x>=185) && (y<=606 && y>=191) );  )
    {
        if(kbhit())
        {
            ///TABLE();
            ch2 = getch();
            if(ch2==72)
            {
                y=y-45;
                //object(x,y);
                moveto(x,y);
                object();

            }///Up
            /// break;
            else if(ch2 == 80)
            {
                y=y+45;
                //object(x,y);
                moveto(x,y);
                object();
                ///Down
                ///break;
            }
            else if(ch2 == 75)
            {
                x=x-45;
                // object(x,y);
                moveto(x,y);
                object();
                ///Left
                ///   break;
            }
            else if(ch2 == 77)
            {
                x=x+45;
                //object(x,y);
                moveto(x,y);
                object();
                ///Right();
                /// break;
            }
            else if(ch2 == 27)
            {
                cleardevice();
                while(1)
                {
                    for(b=0; b<15; b++)
                    {
                        setcolor(b);
                        settextstyle(BOLD_FONT,0, 7);
                        outtextxy(405, 350, "GAME  OVER");
                        delay(250);
                    }
                    if(getch())
                    {
                        cleardevice();
                        ExitGame();
                        break;
                    }
                }
            }
            else
            {
                moveto(x,y);
                object();
            }
            TABLE();
        }
        delay(10);
        if(x>1100 || y>606 || x<185 || y<191)
        {
            cleardevice();
            settextstyle(8,0,3);
            sprintf(ins,"You Crossed The Boarder!!");
            outtextxy(500,300,ins);
            delay(390);
            break;
        }
        getch();
    }
    cleardevice();
}

void Design()
{
    /*   for down part   */
    pieslice(228, 605, 180,360, 22);
    pieslice(273, 605, 180,360, 22);
    pieslice(318, 605, 180,360, 22);
    pieslice(363, 605, 180,360, 22);
    pieslice(408, 605, 180,360, 22);
    pieslice(453, 605, 180,360, 22);
    pieslice(498, 605, 180,360, 22);
    pieslice(543, 605, 180,360, 22);
    pieslice(588, 605, 180,360, 22);
    pieslice(633, 605, 180,360, 22);
    pieslice(678, 605, 180,360, 22);
    pieslice(723, 605, 180,360, 22);
    pieslice(768, 605, 180,360, 22);
    pieslice(813, 605, 180,360, 22);
    pieslice(858, 605, 180,360, 22);
    pieslice(903, 605, 180,360, 22);
    pieslice(948, 605, 180,360, 22);
    pieslice(993, 605, 180,360, 22);
    pieslice(1038, 605, 180,360, 22);
    pieslice(1083, 605, 180,360, 22);
    pieslice(1128, 605, 180,360, 22);

    /*   for right part   */

    pieslice(1145, 185,270,90,22);
    pieslice(1145, 230,270,90,22);
    pieslice(1145, 275,270,90,22);
    pieslice(1145, 320,270,90,22);
    pieslice(1145, 365,270,90,22);
    pieslice(1145, 410,270,90,22);
    pieslice(1145, 455,270,90,22);
    pieslice(1145, 500,270,90,22);
    pieslice(1145, 545,270,90,22);
    pieslice(1145, 590,270,90,22);

    /*   for left part   */

    pieslice(205,185, 90, 270, 22);
    pieslice(205,230, 90, 270, 22);
    pieslice(205, 275, 90, 270, 22);
    pieslice(205,320, 90, 270, 22);
    pieslice(205,365, 90, 270, 22);
    pieslice(205,410, 90, 270, 22);
    pieslice(205, 455, 90, 270, 22);
    pieslice(205, 500, 90, 270, 22);
    pieslice(205, 545, 90, 270, 22);
    pieslice(205, 590, 90, 270, 22);
}

void Music()
{
    int p;
    srand(time(NULL));
    p = 1+(rand()%1000);
    if(p%11==0)
        PlaySound(TEXT("C:\\Users\\Malware\\Desktop\\my first project with c language\\Synth Pop Loop.wav"),NULL, SND_FILENAME|SND_LOOP|SND_ASYNC);
    else if(p%7==0)
        PlaySound(TEXT("C:\\Users\\Malware\\Desktop\\my first project with c language\\Yo Camel!.wav"),NULL, SND_FILENAME|SND_LOOP|SND_ASYNC);
    else if(p%5==0)
        PlaySound(TEXT("C:\\Users\\Malware\\Desktop\\my first project with c language\\Slowfunky 88.wav"),NULL, SND_FILENAME|SND_LOOP|SND_ASYNC);
    else if(p%3==0)
        PlaySound(TEXT("C:\\Users\\Malware\\Desktop\\my first project with c language\\Ekon Beat loop.wav"),NULL, SND_FILENAME|SND_LOOP|SND_ASYNC);
    else
        PlaySound(TEXT("C:\\Users\\Malware\\Desktop\\my first project with c language\\Pim Poy.wav"),NULL, SND_FILENAME|SND_LOOP|SND_ASYNC);

}

int main()
{
    health=5;
    system("cls");
    start = time(NULL);

    Music();
    int gd=DETECT,gm;
    initgraph(&gd,&gm,"c:\\tc\\bgi");
    system("color 30");
    initwindow(1350,700,"MASUM GAME PRODUCTION");
    cleardevice();
   /// system("cls");
    Load();
   credit();
    Welcome();
   Instruction();
    TABLE();
    control();
    ExitGame();
    getch();
    ///system("cls");
    closegraph();
    endd = time(NULL);
    printf("\n\nYou have just played for %.2f seconds",difftime(endd,start));
    printf("\nTRY BETTER , NEXT TIME\n\n");
    system("cls");
}
/* At last it ends,but there are many things i want to add  */

