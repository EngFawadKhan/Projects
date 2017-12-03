#define _WIN32_WINNT 0x0500
#include<windows.h>
#include<iostream>
#include <cmath>

using namespace std;

//#define PI 3.14

int main()
{
    int x=0, y=0, inputx, inputy, prevx=0, prevy=0;
    //Get a console handle
    HWND myconsole = GetConsoleWindow();
    //Get a handle to device context
    HDC mydc = GetDC(myconsole);

    int pixel =0;

    //Choose any color
    COLORREF COLOR= RGB(255,100,0);
     COLORREF COLOR1= RGB(0,0,0);

    //Draw pixels

           // COLOR= RGB(255,255,255);


while (inputx!=-1)
{

  cout << "Input x = ";
  cin >> inputx;
  cout << "Input y = ";
  cin >> inputy;
   x= x + inputx;
   y= y + inputy;

   for(int i = 0; i < 50; i++)
    {

        SetPixel(mydc,i+prevx,prevy,COLOR1);
         Sleep (1);
     //   pixel+=1;
    }


   for(int i = 0; i < 50; i++)
    {

        SetPixel(mydc,i+x,y,COLOR);
        Sleep (1);

     //   pixel+=1;
    }

   prevx = x;
   prevy = y;

}

ReleaseDC(myconsole, mydc);
    cin.ignore();
    return 0;
}
