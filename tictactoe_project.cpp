#include<iostream>
#include<string.h>
#include<stdlib.h>
#include<time.h>
using namespace std;

char square[10]={' ',' ',' ',' ',' ',' ',' ',' ',' ',' '};
int x=0;
int mark;

int check();
void func1();
void func2();
void pattern();
int checkAI();
int guidelines();

int main()
{
    menu:
    system("cls");
    cout<<"WELCOME"<<endl<<"Proceed as per the instructions"<<endl<<"1. Play against AI"<<endl<<"2. Play against friend"<<endl<<"3. guidelines"<<endl<<"4. exit"<<endl;
    int input;
    cin>>input;
    if(input==1)
    {
        func1();
    }
    else if(input==2)
    {
        func2();
    }
    else if(input==3)
    {
        retry:
        system("cls");
        int y=guidelines();
        if(y<10 && y>-1)
        goto menu;
        else
        goto retry;
    }
    else if(input==4)
    {
        exit(0);
    }
    else
    {
        goto menu;
    }
    return 0;
}

void func1()
{
    cout<<"taking it easy on you, you make the first move"<<endl<<"Player(x) vs. AI(o)"<<endl;
    for(int i=1;i<=9;i++)
    {
        if(i%2!=0)
        {
            entry3:
            cout<<"player(x) turn"<<endl;
            cin>>mark;
            if(square[mark]=='x' || square[mark]=='o')
            {cout<<"already marked, try another spot"<<endl;
            goto entry3;}
            if(mark<1 || mark>9)
            {
                cout<<"invalid entry, try again"<<endl;
                goto entry3;
            }
            else
            {
                square[mark]='x';
                system("cls");
                pattern();
                x=check();
            }
            if(x==1)
            {
                cout<<"!! PLAYER WON !!"<<endl<<"YOU BEAT THE AI, from today you must be known as...."<<endl<<"JOHN CONNOR"<<endl;
                break;
            }
        }
        else
        {
            entry4:
            mark=checkAI();
            if(square[mark]=='x' || square[mark]=='o')
            goto entry4;
            else
            {
                cout<<"AI(o) turn : "<<mark<<endl;
                square[mark]='o';
                pattern();
                x=check();
            }
            if(x==1)
            {
                cout<<"the computer beats you :("<<endl<<"*the computer mumbling* these human are idiots, it'll be easier for us to take control in the future...... judgement day is arriving"<<endl;
                break;
            }
        }
    }
    if(x==0)
    {cout<<"no winner"<<endl<<"you gave the machine a tough competition"<<endl;}
}

void func2()
{
    cout<<"Player 1(x) vs. Player 2(o)"<<endl;
    for(int i=1;i<=9;i++)
    {
        if(i%2!=0)
        {
            entry1:
            cout<<"player 1(x) turn"<<endl;
            cin>>mark;
            if(square[mark]=='x' || square[mark]=='o')
            {cout<<"already marked, try another spot"<<endl;
            goto entry1;}
            if(mark<1 || mark>9)
            {
                cout<<"invalid entry, try again"<<endl;
                goto entry1;
            }
            else
            {
                square[mark]='x';
                system("cls");
                pattern();
                x=check();
            }
            if(x==1)
            {
                cout<<"!! PLAYER 1 WON !!"<<endl;
                break;
            }
        }
        else
        {
            entry2:
            cout<<"player 2(o) turn"<<endl;
            cin>>mark;
            if(square[mark]=='x' || square[mark]=='o')
            {cout<<"already marked, try another spot"<<endl;
            goto entry2;}
            if(mark<1 || mark>9)
            {
                cout<<"invalid entry, try again"<<endl;
                goto entry2;
            }
            else
            {
                square[mark]='o';
                system("cls");
                pattern();
                x=check();
            }
            if(x==1)
            {
                cout<<"!! PLAYER 2 WON !!"<<endl;
                break;
            }
        }
    }
    if(x==0)
    {cout<<"haha, looks like no one won..... suckas"<<endl;}  
}

void pattern()
{
    cout<<square[1]<<"  | "<<square[2]<<" |  "<<square[3]<<endl;
    cout<<"___|___|___"<<endl;
    cout<<square[4]<<"  | "<<square[5]<<" |  "<<square[6]<<endl;
    cout<<"___|___|___"<<endl;
    cout<<square[7]<<"  | "<<square[8]<<" |  "<<square[9]<<endl;
    cout<<"   |   |   "<<endl;
}

int check()
{
    if(square[1]=='x'&&square[2]=='x'&&square[3]=='x' || square[1]=='o'&&square[2]=='o'&&square[3]=='o')
    return 1;
    else if(square[1]=='x'&&square[4]=='x'&&square[7]=='x' || square[1]=='o'&&square[4]=='o'&&square[7]=='o')
    return 1;
    else if(square[3]=='x'&&square[6]=='x'&&square[9]=='x' || square[3]=='o'&&square[6]=='o'&&square[9]=='o')
    return 1;
    else if(square[7]=='x'&&square[8]=='x'&&square[9]=='x' || square[7]=='o'&&square[8]=='o'&&square[9]=='o')
    return 1;
    else if(square[2]=='x'&&square[5]=='x'&&square[8]=='x' || square[2]=='o'&&square[5]=='o'&&square[8]=='o')
    return 1;
    else if(square[4]=='x'&&square[5]=='x'&&square[6]=='x' || square[4]=='o'&&square[5]=='o'&&square[6]=='o')
    return 1;
    else if(square[1]=='x'&&square[5]=='x'&&square[9]=='x' || square[1]=='o'&&square[5]=='o'&&square[9]=='o')
    return 1;
    else if(square[3]=='x'&&square[5]=='x'&&square[7]=='x' || square[3]=='o'&&square[5]=='o'&&square[7]=='o')
    return 1;
    else
    return 0;
}

int checkAI()
{
    if(square[1]=='x'&&square[2]=='x'&&square[3]==' ' || square[1]=='o'&&square[2]=='o'&&square[3]==' ')
    return 3;
    else if(square[2]=='x'&&square[3]=='x'&&square[1]==' ' || square[2]=='o'&&square[3]=='o'&&square[1]==' ')
    return 1;
    else if(square[1]=='x'&&square[3]=='x'&&square[2]==' ' || square[1]=='o'&&square[3]=='o'&&square[2]==' ')
    return 2;
    else if(square[1]=='x'&&square[7]=='x'&&square[4]==' ' || square[1]=='o'&&square[7]=='o'&&square[4]==' ')
    return 4;
    else if(square[1]=='x'&&square[4]=='x'&&square[7]==' ' || square[1]=='o'&&square[4]=='o'&&square[7]==' ')
    return 7;
    else if(square[4]=='x'&&square[7]=='x'&&square[1]==' ' || square[4]=='o'&&square[7]=='o'&&square[1]==' ')
    return 1;
    else if(square[3]=='x'&&square[6]=='x'&&square[9]==' ' || square[3]=='o'&&square[6]=='o'&&square[9]==' ')
    return 9;
    else if(square[3]=='x'&&square[9]=='x'&&square[6]==' ' || square[3]=='o'&&square[9]=='o'&&square[6]==' ')
    return 6;
    else if(square[6]=='x'&&square[9]=='x'&&square[3]==' ' || square[6]=='o'&&square[9]=='o'&&square[3]==' ')
    return 3;
    else if(square[7]=='x'&&square[8]=='x'&&square[9]==' ' || square[7]=='o'&&square[8]=='o'&&square[9]==' ')
    return 9;
    else if(square[7]=='x'&&square[9]=='x'&&square[8]==' ' || square[7]=='o'&&square[9]=='o'&&square[8]==' ')
    return 8;
    else if(square[8]=='x'&&square[9]=='x'&&square[7]==' ' || square[8]=='o'&&square[9]=='o'&&square[7]==' ')
    return 7;
    else if(square[2]=='x'&&square[5]=='x'&&square[8]==' ' || square[2]=='o'&&square[5]=='o'&&square[8]==' ')
    return 8;
    else if(square[2]=='x'&&square[8]=='x'&&square[5]==' ' || square[2]=='o'&&square[8]=='o'&&square[5]==' ')
    return 5;
    else if(square[5]=='x'&&square[8]=='x'&&square[2]==' ' || square[5]=='o'&&square[8]=='o'&&square[2]==' ')
    return 2;
    else if(square[4]=='x'&&square[5]=='x'&&square[6]==' ' || square[4]=='o'&&square[5]=='o'&&square[6]==' ')
    return 6;
    else if(square[5]=='x'&&square[6]=='x'&&square[4]==' ' || square[5]=='o'&&square[6]=='o'&&square[4]==' ')
    return 4;
    else if(square[4]=='x'&&square[6]=='x'&&square[5]==' ' || square[4]=='o'&&square[6]=='o'&&square[5]==' ')
    return 5;
    else if(square[1]=='x'&&square[5]=='x'&&square[9]==' ' || square[1]=='o'&&square[5]=='o'&&square[9]==' ')
    return 9;
    else if(square[5]=='x'&&square[9]=='x'&&square[1]==' ' || square[5]=='o'&&square[9]=='o'&&square[1]==' ')
    return 1;
    else if(square[1]=='x'&&square[9]=='x'&&square[5]==' ' || square[1]=='o'&&square[9]=='o'&&square[5]==' ')
    return 5;
    else if(square[3]=='x'&&square[5]=='x'&&square[7]==' ' || square[3]=='o'&&square[5]=='o'&&square[7]==' ')
    return 7;
    else if(square[5]=='x'&&square[7]=='x'&&square[3]==' ' || square[5]=='o'&&square[7]=='o'&&square[3]==' ')
    return 3;
    else if(square[3]=='x'&&square[7]=='x'&&square[5]==' ' || square[3]=='o'&&square[7]=='o'&&square[5]==' ')
    return 5;
    else
    {srand(time(0));
    int num = 1 + rand() % 9;
    return num;}
}

int guidelines()
{
    int y;
    cout<<"I assume u already know how to play tictactoe"<<endl<<"here is the theoretical display of the tictactoe board(#)"<<endl;
    cout<<"1 | 2 | 3"<<endl<<"__|___|__"<<endl<<"4 | 5 | 6"<<endl<<"__|___|__"<<endl<<"7 | 8 | 9"<<endl<<"  |   |  "<<endl;
    cout<<"when the input is the number defining the index on the board, it get replaced with x/o (according to whoever's turn it is), like"<<endl;
    cout<<"if the input is 6 and it's  x's turn, the following gets displayed"<<endl;
    cout<<"__|___|__"<<endl<<"__|___|x_"<<endl<<"  |   |  "<<endl<<"and so on"<<endl<<endl<<"press any number b/w 0-9 to go back to menu";
    cin>>y;
    return y;
}