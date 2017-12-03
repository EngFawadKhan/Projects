#include <iostream>
#include <stdio.h>
#include <windows.h>
#include <string>
#include <vector>
using namespace std;

int pts =0;

void gotoxy( short x, short y )
{
    HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD position = { x, y };

    SetConsoleCursorPosition( hStdout, position );
}

struct coord{
short X = 2, Y = 2;
short x = 15, y = 16;
}OC,NC;

//coord target(coord OC);
 char map[26][33] = {
	"+#############################+",
	"|              |               ",
	"|  |                          |",
	"|  |      ###############     |",
	"|                             |",
	"|   ##############  |   ##### |",
	"|                             |",
	"|  #####  ######   #######  ##|",
	"|                             |",
	"|     |#####    #####   | |   |",
	"|                             |",
	"|## ####  ##### ##   ###  ####|",
	"|                             |",
	"| | |    |  |           |     |",
	"| |           |  |  |   |  |  |",
	"| | #  ##|  | |  |   ## |     |",
	"|             |     |      |  |",
	"| |##### ###         ##       |",
	"|          ######  ####### ###|",
	"|                             |",
	"|# ### ####      ###   #######|",
	"|             |               |",
	"|             |               |",
	"| ##########  |    #########  |",
	"|                             |",
	"+#############################+"};

coord target (coord OC)
{
   if(OC.Y < OC.y && map[OC.Y+1][OC.X] == ' ')OC.Y++;

    else if(OC.X > OC.x && map[OC.Y][OC.X-1] == ' ')OC.X--;

    else if(OC.X < OC.x && map[OC.Y][OC.X+1] == ' ')OC.X++;

    else if(OC.Y > OC.y && map[OC.Y-1][OC.X] == ' ')OC.Y--;

    else if(OC.X == OC.x && map[OC.Y+1][OC.X] != ' ')
        {while(map[OC.Y+1][OC.X] != ' '){OC.X++;}OC.Y++;}

    else if(OC.X < OC.x && map[OC.Y][OC.X+1] != ' ')
        {while(map[OC.Y][OC.X+1] != ' '){OC.Y++;}OC.X++;}

    else if(OC.X == OC.x && map[OC.Y-1][OC.X] != ' ')
        {while(map[OC.Y-1][OC.X] != ' '){OC.X--;}OC.Y--;}

    else if(OC.X < OC.x && map[OC.Y][OC.X-1] != ' ')
         {while(map[OC.Y][OC.X-1] != ' '){OC.Y++;}OC.X--;}
    //Sleep(100);
    //else if(OC.X == OC.x && map[OC.Y-1][OC.X] != ' '){while(map[OC.Y+1][OC.X] != ' '){OC.X--;}}

    return OC;
};



int main()
{


bool running = false;

for(int i = 0; i <= 26; i++)
    {
        cout << map[i] << endl;
    }

gotoxy(OC.x,OC.y); cout << "P";

gotoxy(OC.X,OC.Y); cout << "O";


gotoxy(1,26);cout << "Press Any Enter To Start The Game : ";
cin.get();

while(!running)
{

    for(short i = 0; i <= 26; i++)
    {
        cout << map[i] << endl;
    }


    if(OC.X != OC.x && OC.Y != OC.y){NC = target(OC);}

        gotoxy( 32, 5 ); cout <<  "Points Earned = "<< pts; ;
    //gotoxy( 32, 6 ); cout <<  OC.X << "\t" << OC.Y;
    //gotoxy( 32, 7 ); cout <<  OC.x << "\t" << OC.y;
    //gotoxy( 32 , 1 ); cout << "->Exit Here ";
    gotoxy(OC.x,OC.y); cout << "P";

    gotoxy(OC.X,OC.Y); cout << "O";



    if ( GetAsyncKeyState( VK_UP ) ){
			if( map[OC.y-1][OC.x] == ' ' ){ OC.y--; pts++; } //else
			//if( map[OC.y-1][OC.x] == ' ' ) OC.y--;
		}
		if ( GetAsyncKeyState( VK_DOWN ) ){
			if( map[OC.y+1][OC.x] == ' ' ){ OC.y++; pts++; } //else
			//if( map[OC.y+1][OC.x] == ' ' ) OC.y++;
		}
		if ( GetAsyncKeyState( VK_LEFT ) ){
			if( map[OC.y][OC.x-1] == ' ' ){ OC.x--; pts++; } //else
			//if( map[OC.y][OC.x-1] == ' ' ) OC.x--;
		}
		if ( GetAsyncKeyState( VK_RIGHT ) ){
			if( map[OC.y][OC.x+1] == ' ' ){ OC.x++; pts++; } //else
			//if( map[OC.y][OC.x+1] == ' ' ) OC.x++;
		}

        if(OC.x > 29 || OC.X == OC.x && OC.Y == OC.y)
        break;

        OC = target(OC);

		Sleep( 100 );
        system("cls");

}

char gameover[11][31] =
{
    " #######  AAAAA M|   |M EEEEEE",
    " ##       A   A M |_/ M E     ",
    " ##  ###  A   A M     M EEE   ",
    " ##    #  AAAAA M     M E     ",
    " #######  A   A M     M EEEEEE",
    "                              ",
    " OOOOOO V     V EEEEEE RRRRRR ",
    " O    O |     | E      R    R ",
    " O    O  V   V  EEE    RRRRRR ",
    " O    O   | |   E      RRRRR  ",
    " OOOOOO    V    EEEEEE R   \\ ",
};
system("cls");
for(short i = 0; i <= 11; i++)
{
    cout << gameover[i]<< endl;;
    Sleep(100);
}
if(OC.x && OC.Y == OC.y)
{
        gotoxy( 2 , 13 ); cout << " YOU LOSE, Total Points Earned = " << pts;
}
else if (OC.x > 29) {gotoxy( 2, 13); cout << " YOU WIN, Total Points Earned =  " << pts; }
system("PAUSE>null");
    cin.get();
	cin.get();
	cin.get();

 return 0;
}

