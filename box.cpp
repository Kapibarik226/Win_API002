#include "box.h"

void xCetka ()
	{
		
		HDC       hdc;
		int y1 = 100,
		    x1 = 100;
		hdc = GetDC(hWnd);
		hPen[9] = CreatePen(0, 1, color[1] ); 				                     
		SelectObject(hdc, hPen[9]);
		
		for(int i = 0; i<11; i++)
		{
			
		MoveToEx(hdc, 100, y1,0);
        LineTo  (hdc, 300, y1);
        y1 += 20;
	    }
		
		for(int i = 0; i<11; i++)
		{
			
		MoveToEx(hdc, x1, 100,0);
        LineTo  (hdc, x1, 300);
        x1+=20;
        
	    }
	    
		ReleaseDC(hWnd,hdc);
	}
	
void xKv ()
	{
		
		
		
		
		
	}
