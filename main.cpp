#include <iostream>
#include<windows.h>
#include<conio.h>
#include <cstdlib>
#include<string>
#include <fstream>

using namespace std;

void sleep(int m)
{
    for(int j=0; j<m*21000; j++)
    {

    }
}

void gotoRowCol(int rpos, int cpos)
{
    int xpos=cpos, ypos = rpos;
    COORD scrn;

    HANDLE hOuput = GetStdHandle(STD_OUTPUT_HANDLE);

    scrn.X = xpos;
    scrn.Y = ypos;

    SetConsoleCursorPosition(hOuput,scrn);
}

void savemygame(char CB[8][8],int turn)
{
    ofstream savemygame1;
    savemygame1.open("save.txt");
    for(int i=0; i<=7; i++)
    {
        for(int j=0; j<=7; j++)
        {
            if(CB[i][j]==' ')
            {
                CB[i][j]='-';
            }
            savemygame1<<CB[i][j];
        }
        savemygame1<<"\n";
    }
    savemygame1<<turn<<endl;
    savemygame1.close();

    for(int i=0; i<=7; i++)
    {
        for(int j=0; j<=7; j++)
        {
            if(CB[i][j]=='-')
            {
                CB[i][j]=' ';
            }
        }
    }
}
void loadgame(char CB[8][8],int &turn)
{

    fstream savemygame1("save.txt");
    for(int x=0; x<8; x++)
    {
        for(int y=0; y<8; y++)
        {
            savemygame1>>CB[x][y];
            if(CB[x][y]=='-')
            {
                CB[x][y]=' ';
            }
        }
    }
    savemygame1>>turn;
}

void savegam(char CB[8][8],int turn)
{
    ofstream savegame;
    savegame.open("sav.txt");
    for(int i=0; i<=7; i++)
    {
        for(int j=0; j<=7; j++)
        {
            if(CB[i][j]==' ')
            {
                CB[i][j]='-';
            }
            savegame<<CB[i][j];
        }
        savegame<<"\n";
    }
    savegame.close();
    for(int i=0; i<=7; i++)
    {
        for(int j=0; j<=7; j++)
        {
            if(CB[i][j]=='-')
            {
                CB[i][j]=' ';
            }
        }
    }
}

void redo(char CB[8][8])
{
    ofstream redo1;
    redo1.open("undu.txt");
    for(int i=0; i<=7; i++)
    {
        for(int j=0; j<=7; j++)
        {
            if(CB[i][j]==' ')
            {
                CB[i][j]='-';
            }
            redo1<<CB[i][j];
        }
        redo1<<"\n";
    }
    redo1.close();

    for(int i=0; i<=7; i++)
    {
        for(int j=0; j<=7; j++)
        {
            if(CB[i][j]=='-')
            {
                CB[i][j]=' ';
            }
        }
    }
}

void rdundo(char CB[8][8])
{

    fstream redo1("undu.txt");
    for(int x=0; x<8; x++)
    {
        for(int y=0; y<8; y++)
        {
            redo1>>CB[x][y];
            if(CB[x][y]=='-')
            {
                CB[x][y]=' ';
            }
        }
    }
}




void printbox(int sr,int sc,int rdim,int cdim)
{
    for(int r=1; r<=rdim; r++)
    {
        for(int c=1; c<=cdim; c++)
        {
            if(r==1 || r==rdim || c==1 || c==cdim)
            {
                gotoRowCol(sr+r-1+10,sc+c-1+15);
                cout<<char(15);
                sleep(10);
            }
        }
    }
}




void printbox1(int sr,int sc,int rdim,int cdim)
{
    for(int r=1; r<=rdim; r++)
    {
        for(int c=1; c<=cdim; c++)
        {
            if(r==1 || r==rdim || c==1 || c==cdim)
            {
                gotoRowCol(sr+r-1+10,sc+c-1+15);
                cout<<char(15);
                sleep(10);
            }
        }
    }
}













bool ismypeice(char s,int turn)
{
    if(turn==1)
    {
        return(s>='A' && s<='Z');
    }
    else
    {
        return(s>='a' && s<='z');
    }
}

bool isopponentpiece(char s,int turn)
{
    if(turn==2)
    {
        return(s>='A' && s<='Z');
    }
    else
    {
        return(s>='a' && s<='z');
    }
}
char Init(char CB[8][8])
{
    CB[0][0]=CB[0][7]='R';
    CB[0][1]=CB[0][6]='N';
    CB[0][2]=CB[0][5]='B';
    CB[0][3]='Q';
    CB[0][4]='K';
    int r=1;
    for(int i=0; i<=7; i++)
    {
        CB[r][i]='P';
    }
    for(int j=2; j<=5; j++)
    {
        for(int k=0; k<=7; k++)
        {
            CB[j][k]=' ';
        }
    }
    for(int i=0; i<=7; i++)
    {
        CB[6][i]='p';
    }


    CB[7][0]=CB[7][7]='r';
    CB[7][1]=CB[7][6]='n';
    CB[7][2]=CB[7][5]='b';
    CB[7][3]='q';
    CB[7][4]='k';

}

bool ishorizontal(int sr,int er)
{
    return (sr==er);
}

bool isdigonal(int sr,int sc,int er,int ec)
{
    return (abs(er-sr)==abs(ec-sc));
}

bool isvertical(int sc,int ec)
{
    return (sc==ec);
}
bool ishorizontalclear(char CB[8][8],int sr,int ec,int sc)
{
    int s,e;
    if(ec>sc)
    {
        s=sc+1;
        e=ec-1;
    }
    else
    {
        s=ec+1;
        e=sc-1;
    }
    for(int i=s; i<=e; i++)
    {
        if(CB[sr][i]!=' ')
        {
            return false;
        }
    }
    return true;
}

bool isverticalalclear(char CB[8][8],int sr,int er,int sc)
{
    int s,e;
    if(er>sr)
    {
        s=sr+1;
        e=er-1;
    }
    else
    {
        s=er+1;
        e=sr-1;
    }
    for(int i=s; i<=e; i++)
    {
        if(CB[i][sc]!=' ')
        {
            return false;
        }
    }
    return true;
}
bool IsDigonalClear(char CB[8][8] , int sr , int sc , int er , int ec)
{
    int r,c,t=abs(sr-er);
    if(sr-er == -(sc-ec))
    {
        if(sr<er)
        {
            r=sr+1;
            c=sc-1;
        }
        else
        {
            r=er+1;
            c=ec-1;
        }
        for(int i=1 ; i<t ; i++)
        {
            if(CB[r][c]!=' ')
                return false;
            r++;
            c--;
        }
    }
    else
    {
        if(sr<er)
        {
            r=sr+1;
            c=sc+1;
        }
        else
        {
            r=er+1;
            c=ec+1;
        }
        for(int i=1 ; i<t ; i++)
        {
            if(CB[r][c]!=' ')
                return false;
            r++;
            c++;
        }
    }
    return true;
}
void turnchange(int & turn)
{
    switch(turn)
    {
    case 1:
        turn=2;
        break;

    case 2:
        turn=1;
        break;
    }
}

void printturn(int turn,char p1[100],char p2[100])
{
    if(turn==1)
    {
        gotoRowCol(30 , 70);
        cout<<p1<<" turn";
    }
    else
    {
        gotoRowCol(30,70);
        cout<<p2<<" turn";
    }
}



void Instructions(void)
{
    cout<<"On vertical axis Alphabets (A-G) are printed"<<endl<<endl<<endl;
    cout<<"On horizontal axis disits are printed"<<endl<<endl<<endl;
    cout<<"Now if you wanna move a piece then you have to choose Alphabet first and then digit"<<endl<<endl<<endl;
    cout<<"And also you have to give ending Alphabets and digits"<<endl<<endl<<endl;
}



void printinbox(int r,int c,int rdim,int cdim,char CB[8][8])
{

    gotoRowCol((r)*rdim+rdim/2+10,(c)*cdim+cdim/2+15);
    cout<<CB[r][c];
}
void printboard(int rdim,int cdim , char CB[8][8])
{


    for(int r=0; r<8; r++)
    {
        for(int c=0; c<8; c++)
        {
            printbox((r)*rdim,(c)*cdim,rdim,cdim);
            printinbox(r , c ,rdim , cdim , CB);

        }
    }
    int m=17;
    for(int i=1; i<=8; i++)
    {
        gotoRowCol(8,m);
        cout<<i;
        m+=5;
    }
    char C='A';
    for(int i=2; i<=9; i++)
    {
        gotoRowCol(i*5.4,8);
        cout<<C;
        C++;
    }
}

void takeinput(char CB[8][8],int&sr,int&sc,int&er,int&ec,int rdim,int cdim,int turn,int &k,int &z)
{
    int r=1,c=1;
    int key;
    char s;
    sr=0;
    sc=0;
    er=0;
    ec=0;
    bool FOS = true;
    while(1)
    {
        if(kbhit())
        {
            key=getch();
            if(key==67)
            {
                z++;
                break;
            }
            if(key==65)
            {
                k++;
                loadgame(CB,turn);
                break;
            }
            if(key==66)
            {
                k++;
                rdundo(CB);
                break;

            }
            if(key==224)
            {
                key=getch();
                switch(key)
                {
                case 72:
                    r--;
                    if(r==0)
                        r=8;
                    break;
                case 75:
                    c--;
                    if(c==0)
                        c=8;
                    break;
                case 77:
                    c++;
                    if(c==9)
                        c=1;
                    break;
                case 80:
                    r++;
                    if(r==9)
                        r=1;
                    break;

                }
            }


            if(key==13)
            {
                if(FOS)
                {
                    FOS=false;
                    sr=r-1;
                    sc=c-1;
                    s=CB[sr][sc];
                    if(ismypeice(s,turn)==false)
                    {
                        FOS=true;
                    }

                }
                else
                {
                    er=r-1;
                    ec=c-1;
                    s=CB[er][ec];
                    if(ismypeice(s,turn)==false)
                        break;
                    if((ismypeice(CB[er][ec],turn)==true))
                    {
                        FOS =false;
                        sr=r-1;
                        sc=c-1;
                    }

                }

            }

        }
        gotoRowCol((r-1)*rdim+rdim/2+10,(c-1)*cdim+cdim/2+15);
    }
}
void move(char CB[8][8], int sr, int  sc, int  er, int  ec)
{

    CB[er][ec]=CB[sr][sc];
    CB[sr][sc]=' ';
}

bool pawncheck(char CB[8][8] , int sr , int sc , int er , int ec , int turn)
{
    if((turn==1) &&  (sr==1))
        return((isvertical(sc,ec) && isverticalalclear(CB,sr,er,ec) &&((sr-er==-1)|| (sr-er==-2))&&
                (CB[er][ec]==' '))|| ((sr-er==-1)&&(abs(sc-ec)==1) && (isopponentpiece(CB[er][ec],turn ))));

    else if(turn==1)
        return((isvertical( sc,ec) && isverticalalclear(CB,sr,er,ec) && (sr-er==-1) && (CB[er][ec]==' '))
               ||  ((sr-er==-1)&&(abs(sc-ec)==1) && (isopponentpiece(CB[er][ec],turn ))));

    else if((turn==2) && (sr==6))
        return((isvertical( sc,ec) && isverticalalclear(CB,sr,er,ec) && (CB[er][ec]==' ')&&
                ((sr-er==1)|| (sr-er==2) )) ||  ((sr-er==1)&&(abs(sc-ec)==1) && (isopponentpiece(CB[er][ec],turn ))));

    else if(turn==2)
        return((isvertical( sc,ec) && isverticalalclear(CB,sr,er,ec) && (sr-er==1) && (CB[er][ec]==' ')))
              ||((sr-er==1)&&(abs(sc-ec)==1) && (isopponentpiece(CB[er][ec],turn ))) ;
}
bool IsRooklegal(char CB[8][8],int sr,int er,int ec,int sc)
{
    return((ishorizontal(sr,er) && ishorizontalclear(CB,sr,sc,ec))||
           (isvertical(sc,ec)&& isverticalalclear(CB,sr,er,sc)));
}
bool isKnightlegal(char CB[8][8],int sr,int er,int ec,int sc)
{
    return (((abs(sc-ec)==2 && abs(sr-er)==1)) || ((abs(sc-ec)==1 && abs(sr-er)==2)));
}
bool IsQueenlegal(char CB[8][8],int sr,int er,int ec,int sc)
{
    return ((ishorizontal(sr,er) && ishorizontalclear(CB,sr,ec,sc)) ||
            (isvertical(sc,ec)&& isverticalalclear(CB,sr,er,sc)) ||
            (isdigonal(sr,sc,er,ec)&& IsDigonalClear(CB,sr,sc,er,ec)));
}
bool IsKinglegal(char CB[8][8],int sr,int sc,int er,int ec)
{
    int a=sr-er , b=sc-ec;
    return ((a==-1 && b==-1) || (a==-1 && b==0)|| (a==-1 && b==1) ||(a==0 && b==-1) || (a==0 && b==1)
            || (a==1 && b==-1) || (a==1 && b==0) || (a==1 && b==1) );

}
bool IsBishapLegal(char CB[8][8],int sr,int er,int sc,int ec)
{
    return ( isdigonal(sr,sc,er,ec) && (IsDigonalClear(CB,sr,sc,er,ec)));
}

void pawnpromotion(char CB[8][8] ,  int sr, int sc, int er, int ec,int turn)
{
    char c;
    if(turn==2  && er==0 && CB[er][ec]== 'p')
    {
        gotoRowCol(52, 87);
        cout<<"Please put n=knight,b=bishop,q=queen,r=rook .."<<endl;
        cin>>c;
        if (c=='b'  || c=='n'|| c=='q'|| c=='r')
        {
            CB[er][ec]=c;
        }
    }
    else if(turn==1  && er==7 && CB[er][ec]== 'P')
    {
        gotoRowCol(52, 87);
        cout<<" please put N=Knight,B=bishop,Q=queen,R=rook .."<<endl;
        cin>>c;
        if (c=='B'  || c=='N'|| c=='Q'|| c=='R')
        {
            CB[er][ec]=c;
        }
    }
}
bool IsAllLegal(int turn,char CB[8][8],int sr,int er,int sc,int ec)
{
    switch(CB[sr][sc])
    {
    case 'R':
        return (IsRooklegal(CB,sr,er,ec,sc));
        break;
    case 'r':
        return (IsRooklegal(CB,sr,er,ec,sc));
        break;
    case 'K':
        return (IsKinglegal(CB,sr,sc,er,ec));
        break;
    case 'k':
        return (IsKinglegal(CB,sr,sc,er,ec));
        break;
    case 'B':
        return (IsBishapLegal(CB,sr,er,sc,ec));
        break;
    case 'b':
        return (IsBishapLegal(CB,sr,er,sc,ec));
        break;
    case 'N':
        return (isKnightlegal(CB,sr,er,ec,sc));
        break;
    case 'n':
        return (isKnightlegal(CB,sr,er,ec,sc));
        break;
    case 'Q':
        return (IsQueenlegal(CB,sr,er,ec,sc));
        break;
    case 'q':
        return (IsQueenlegal(CB,sr,er,ec,sc));
        break;
    case 'P':
        return (pawncheck(CB,sr,sc,er,ec,turn));
        break;
    case 'p':
        return (pawncheck(CB,sr,sc,er,ec,turn));
        break;
    }

}

bool kinglocationfinder(char CB[8][8],int turn,int &d,int &m)
{
    if(turn==1)
    {
        for(int i=0; i<8; i++)
        {
            for(int j=0; j<8; j++)
            {
                if(CB[i][j]=='k')
                {
                    d=i;
                    m=j;
                    return true;

                }
            }
        }
    }

    else if(turn==2)
    {
        for(int i=0; i<8; i++)
        {
            for(int j=0; j<8; j++)
            {
                if(CB[i][j]=='K')
                {
                    d=i;
                    m=j;
                    return true;
                }
            }
        }
    }
}

bool check(char CB[8][8],int turn)
{
    char c;
    int d, m;
    kinglocationfinder(CB , turn , d , m);
    for(int i=0; i<8; i++)
    {
        for(int j=0; j<8; j++)
        {
            c=CB[i][j];
            if((turn==2 ) && (CB[i][j]=='q'|| CB[i][j]=='n'||CB[i][j]=='p' || CB[i][j]=='k' || CB[i][j]=='r' ||
                              CB[i][j]=='b'))
            {
                if(IsAllLegal(turn,CB,i,d,j,m)==true)
                {

                    return true;
                }
            }

            else if((turn==1) &&(CB[i][j]=='Q'||CB[i][j]=='P' || CB[i][j]=='N' || CB[i][j]=='K' || CB[i][j]=='R'
                                 || CB[i][j]=='B'))
            {
                if(IsAllLegal(turn,CB,i,d,j,m)==true)
                {

                    return true;
                }
            }

        }
    }
    return false;
}

bool selfcheck(char CB[8][8],int turn,int sr,int sc,int er,int ec)
{
    char s;
    int b;
    s=CB[er][ec];
    if(turn==1)
    {
        b=2;
    }
    else
    {
        b=1;
    }
    move(CB,sr,sc,er,ec);
    if(check(CB,b)==true)
    {
        move(CB,er,ec,sr,sc);
        CB[er][ec]=s;
        return true;
    }
    else
    {
        move(CB,er,ec,sr,sc);
        CB[er][ec]=s;
        return false;
    }
}

bool checkmate(char CB[8][8],int turn)
{
    char c;
    if(check(CB,turn)==true)
    {
    if(turn==1)
    {
        for(int i=0; i<=7; i++)
        {
            for(int j=0; j<=7; j++)
            {
                if(CB[i][j]=='b' || CB[i][j]=='n' || CB[i][j]=='q' || CB[i][j]=='r' || CB[i][j]=='p')
                {
                    for(int a=0; a<=7; a++)
                    {
                        for(int b=0; b<=7; b++)
                        {
                            if( ismypeice(CB[a][b],2)==false)
                            {
                                if(IsAllLegal(2,CB,i,j,a,b)==true && selfcheck(CB,2,i,j,a,b)==false)
                                {
                                 return false;
                                }

                            }
                        }
                    }
                }
            }
        }
        return true;
    }
    }
    else
    if(check(CB,turn)==true)
    {
        if(turn==2)
        {
        for(int i=0; i<=7; i++)
        {
            for(int j=0; j<=7; j++)
            {
                if(CB[i][j]=='B' || CB[i][j]=='N' || CB[i][j]=='Q' || CB[i][j]=='R' || CB[i][j]=='P')
                {
                    for(int a=0; a<=7; a++)
                    {
                        for(int b=0; b<=7; b++)
                        {
                            if( ismypeice(CB[a][b],1)==false)
                            {
                                if(IsAllLegal(1,CB,i,j,a,b)==true && selfcheck(CB,1,i,j,a,b)==false)
                                {
                                    return false;
                                }

                            }
                        }
                    }
                }
            }
        }
        return true;
    }
    }

}

bool satalemate(char CB[8][8],int turn)
{
    char c;
    if(turn==1)
    {
    for(int i=0; i<=7; i++)
    {
        for(int j=0; j<=7; j++)
        {
            c=CB[i][j];
            if(ismypeice(c,turn)==true)
            {
                for(int a=0; a<=7; a++)
                {
                    for(int b=0; b<=7; b++)
                    {
                        c=CB[a][b];
                        if(ismypeice(c,turn)==false)
                        {
                            if(IsAllLegal(turn,CB,i,a,j,b)==true )
                            {
                                char t = CB[a][b];
                                move(CB, i, j, a, b);
                                if(selfcheck(CB,2,i,j,a,b)==false)
                                {
                                    CB[i][j] = CB[a][b];
                                    //move(CB, a, b, i, j);
                                 CB[a][b] = t;
                                    return false;
                                }
                                else if(selfcheck(CB,2,i,j,a,b)==true)

                                   // move(CB, a, b, i, j);
                                   CB[i][j] = CB[a][b];
                                    CB[a][b] = t;
                            }
                        }
                    }
                }
            }
        }
    }
    }

    if(turn==2)
    {
    for(int i=0; i<=7; i++)
    {
        for(int j=0; j<=7; j++)
        {
            c=CB[i][j];
            if(ismypeice(c,turn)==true)
            {
                for(int a=0; a<=7; a++)
                {
                    for(int b=0; b<=7; b++)
                    {
                        c=CB[a][b];
                        if(ismypeice(c,turn)==false)
                        {
                            if(IsAllLegal(turn,CB,i,a,j,b)==true )
                            {
                                char t = CB[a][b];
                                move(CB, i, j, a, b);
                                if(check(CB,1)==false)
                                {
                                    CB[i][j] = CB[a][b];
                                    CB[a][b] = t;
                                 //move(CB, a, b, i, j);
                                    return false;
                                }
                                else
                                    //move(CB, i,j, a, b);
                                    CB[i][j] = CB[a][b];
                                    CB[a][b] = t;
                            }
                        }
                    }
                }
            }
        }
    }
        }
    return true;
}

void castling(char CB[8][8],int &turn,int &m1,int &m2,int &n1,int &n2,int sr,int sc,int er,int ec)
{

    if(turn==1)
    {
        if(CB[0][1]==' ' && CB[0][4]==' ')
        {
            m1++;
        }
        if(check(CB,turn)==false)
        {
            if(sr==0&&sc==4 && er==0 && ec==2 && CB[0][1]==' ' && CB[0][2]==' ' && CB[0][3]==' ' && m1==0)
            {

                CB[0][2]='K';
                CB[0][3]='R';
                CB[0][0]=' ';
                CB[0][4]=' ';
                turnchange(turn);
            }

        }
        }

    if(turn==1)
    {
        if(CB[0][7]==' ' && CB[0][4]==' ')
        {
            m2++;
        }
        if(check(CB,turn)==false)
        {
            if(CB[0][6]==' ' && CB[0][5]==' ' && m2==0 && sr==0 && sc==4 && er==0 && ec==6)
            {
                CB[0][6]='K';
                CB[0][5]='R';
                CB[0][7]=' ';
                CB[0][4]=' ';
                turnchange(turn);
            }
        }
    }

    if(turn==2)
    {
        if(CB[7][0]==' ' && CB[7][4]==' ')
        {
            n1++;
        }
        if(check(CB,turn)==false)
        {
            if(CB[7][1]==' ' && CB[7][2]==' ' && CB[7][3]==' '
               && sr==7 && sc==4 && er==7 && ec==2 && n1==0)
            {
                CB[7][2]='k';
                CB[7][3]='r';
                CB[7][0]=' ';
                CB[7][4]=' ';
                turnchange(turn);
            }
        }
    }

    if(turn==2)
    {
        if(CB[7][7]==' ' && CB[7][4]==' ')
        {
            n2++;
        }
        if(check(CB,turn)==false)
        {
            if(CB[7][6]==' ' && CB[7][5]==' ' && n2==0 && sr==7 && sc==4 && er==7 && ec==6)
            {
                CB[7][6]='k';
                CB[7][5]='r';
                CB[7][7]=' ';
                CB[7][4]=' ';
                turnchange(turn);
            }
        }
    }

}

void printintro()
{
    cout<<"                 Chess Game                  "<<endl<<endl<<endl<<endl<<endl;
    cout<<"  Game made by=Hasi Niazi"<<endl<<endl<<endl<<endl<<endl;
    cout<<"  University=Namal University Mianwali"<<endl<<endl<<endl<<endl<<endl;
    cout<<"  Rate the game at=hasnain2014@namal.edu.pk"<<endl<<endl<<endl<<endl<<endl;
    cout<<"  Press any key to continue"<<endl<<endl<<endl<<endl<<endl;
}
void intro()
{
    for(int i=1; i<=51; i++)
    {
        cout<<char(219);
    }
    cout<<endl;
    for(int j=1; j<=51; j++)
    {
        for(int c=1; c<=1; c++)
        {
            cout<<char(219);
        }
        for(int s=1; s<=49; s++)
        {
            cout<<" ";
        }

        cout<<char(219)<<endl;
    }
    for(int e=1; e<=51; e++)
    {
        cout<<char(219);
    }
    gotoRowCol(3,2);
    printintro();
}

int main()
{
    int sr,sc,er,ec,turn=1;
    char CB[8][8];
    char g;
    intro();
    while(1)
    {
        if(kbhit())
        {
            system("CLS");
            cout<<"Enter a number  (N==New Game)  and (L==Load Game) and (I==Instructions)"<<endl;
            do
            {
                cin>>g;
                if(g=='L' || g=='N' || g=='I')
                    break;
            }
            while(1);
            system("CLS");
            Init(CB);
            if(g=='L')
            {
                loadgame(CB,turn);
            }
            else if(g=='I')
            {
                Instructions();
            }
            int turn=1;
            char p1[100];
            char p2[100];
            cout<<"First player Name ";
            cin>>p1;
            cout<<"Second player Name ";
            cin>>p2;
            system("CLS");
            gotoRowCol(10,57);
            cout<<"Player Name="<<p1;
            gotoRowCol(50,57);
            cout<<"Player Name="<<p2;
            gotoRowCol(65,5);
            cout<<"Press (shift+a) for undo and press (shift+b) for redo and press (shift+c) for save Game Thanks :)";
            int rows=10,cols=10;
            int k=0,z=0;
            int rdim=rows/2,cdim=cols/2;
            int sr, sc, er, ec;
            int m1=0,m2=0,n1=0,n2=0;
            char s;
            do
            {
                bool a=false;
                k=0;
                printboard(rdim,cdim,CB);
                printturn(turn,p1,p2);
                takeinput(CB,sr,sc,er,ec,rdim,cdim,turn,k,z);
                savemygame(CB,turn);
                if(k!=0)
            turnchange(turn);
                if(k==0)
                {
                if(IsAllLegal(turn,CB,sr,er,sc,ec)==false)
                    {
                        gotoRowCol(0,0);
                        cout<<" Invalid move pagal";
                    }
                    else
                    {
                        gotoRowCol(0,0);
                        cout<<"                   ";
                        if(selfcheck(CB,turn,sr,sc,er,ec)==false)
                        {
                            move(CB,sr,sc,er,ec);
                            a=true;
                        }
                        pawnpromotion(CB,sr,sc,er,ec,turn);
                        if(satalemate(CB,turn)==true)
                        {
                            cout<<"Stalement";
                            return 0;
                        }
                        if(checkmate(CB,turn)==true)
                        {
                            gotoRowCol(0,40);
                            cout<<"CheckMate";
                            return 0;
                        }
                        if(check(CB,turn)==true)
                        {
                             gotoRowCol(70,90);
                             cout<<"You are in Check yar";
                        }



                        if(a==true)
                        {
                            turnchange(turn);
                        }

                    }
                    redo(CB);
                    castling(CB,turn,m1,m2,n1,n2,sr,sc,er,ec);
                    if(z!=0)
                    {
                        savegam(CB,turn);
                        break;
                    }

                }
            }
            while(1);

        }
    }
}
