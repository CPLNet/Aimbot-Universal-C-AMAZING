#include <iostream>
#include <windows.h>
#include <math.h>
#include <STDLIB.H>
#include <conio.h>
using namespace std;

int main()
{


    
    int tolerance = 64;
    float speed = 0;
    float offsety = 0;
    float fovx = 0;
    float fovy = 0;
    cout << "Enter color variation " << endl;
    cin >> tolerance;
    cout << "Color Variation is " << tolerance << endl;

    cout << "Enter aim speed " << endl;
    cin >> speed;
    cout << "Aim speed is " << speed << endl;
    
    cout << "Enter offset Y (High Value = down side; under 0 or -number = up side offset aim) " << endl;
    cin >> offsety;
    cout << "Offset Y is " << offsety << endl;

    cout << "Enter FovX " << endl;
    cin >> fovx;
    cout << "FovX is " << fovx << endl;

    cout << "Enter FovY " << endl;
    cin >> fovy;
    cout << "FovY is " << fovy << endl;
 
    ::ShowWindow(::GetConsoleWindow(), SW_SHOW);
while (1) {
    
   
    HDC hdc = GetDC(NULL);

  

    POINT p;
    GetCursorPos(&p);
    p.y = p.y + offsety;
    int  x = p.x;
    int  y = p.y;
    COLORREF color;
    RECT rect;
    rect.left = p.x - fovx;
    rect.top = p.y - fovy;
    rect.right = p.x + fovx;
    rect.bottom = p.y + fovy;
    
    color = GetPixel(hdc, x-rect.left, y-rect.top);
    color = GetPixel(hdc, x + rect.right, y - rect.bottom);
    int r = GetRValue(color);
    int g = GetGValue(color);
    int b = GetBValue(color);
    
    int alpha = color;
    
   
    if ((GetKeyState(VK_LBUTTON) & 0x100) != 0)
    {
       
            if ((r < tolerance) && (g < tolerance) && (b < tolerance))
            {
                for (int i = 0; i < 135; i++)
                {
                    mouse_event(MOUSEEVENTF_MOVE, color * speed, color * speed, NULL, NULL);
                }
                for (int i = 0; i < 135; i++)
                {
                    mouse_event(MOUSEEVENTF_MOVE, -alpha * speed, -alpha * speed, NULL, NULL);
                }
            }
           
        
    }
    if (GetKeyState(VK_INSERT))
    {   
          
                break;
    }
        
    Sleep(1);
    ReleaseDC(NULL, hdc);


 }
}