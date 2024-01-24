
#include "box.h"
#include <windows.h>                    //  ���������� (������������ ���� ) ���������� ������� WinAPI  

//////////////////////////////////////////  ���������� ���������� 
HWND                  hWnd;             //  ����� ��������! ����  
HINSTANCE        hInstance; 			//  ��������� ���� ��������� 


LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)   //  ������� ��������� ��������� ��...
{			
HDC hdc; //??????? ???????? ??????????
PAINTSTRUCT ps; //??????? ????????? ????????? ???????????? ??????//  ...OS Windows	
	switch(message)
	{
		case  WM_CREATE:   SetTimer(hWnd, 1, 200, 0); 
			               break;     
						                        //  ��������� ����������� ��������� ��� �������������
	    case WM_DESTROY:   PostQuitMessage(0);             //  ��������� ����������� ��������� ��� ��_�������������
		 	 			   break;		 	 		
		case WM_COMMAND:   switch(LOWORD(wParam))
	                	{
		                   case 100:xCetka ();
		                   break;
						}
			               break;	
										 
		case WM_MOUSEMOVE: xMove = LOWORD(lParam);	  // �� ����� ����������� ���� ���� �������� ��������� �� OS
						   yMove = HIWORD(lParam); 							 
						   break; 
		case WM_RBUTTONDOWN:
        
        char *str;
        HDC hDC;

        hDC=GetDC(hWnd);
        x=LOWORD(lParam); //?????? ??????????
        y=HIWORD(lParam);

        TextOut(hDC, x, y, szText, strlen(szText));

        break;
        
        case WM_LBUTTONDOWN:
        
        char *str1;
        HDC hDC1;

        hDC1=GetDC(hWnd);
        x1=LOWORD(lParam); //?????? ??????????
        y1=HIWORD(lParam);

        TextOut(hDC1, x1, y1, szText1, strlen(szText1));

        break;
						   					 	   
		        default:   return DefWindowProc(hWnd, message, wParam, lParam);   // ��������� OS ��������� ���������
	}
	return 0;
}

//---------------------------------------------------------------------------------------------------------------------

int WINAPI WinMain(HINSTANCE hInst, HINSTANCE hPrevInstance, LPSTR lpszCmd, int nCmdShow)
{
	
	WNDCLASS WndClass;             // ������ ������� ������� ���������	
			 WndClass.style         = 0;
			 WndClass.lpfnWndProc   = WndProc;                                 //   ��� ������� �������
			 WndClass.cbClsExtra    = 0;
			 WndClass.cbWndExtra    = 0;
			 WndClass.hInstance     = hInstance = hInst;                       //   ���������� ����������
			 WndClass.hIcon		    = LoadIcon(hInstance, "MYICON");           //   ��������� ������
			 WndClass.hCursor	    = LoadCursor(NULL, IDC_ARROW);             //   ��������� ��� ������� 
			 WndClass.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);      //   ���� ������� ���� �������
			 WndClass.lpszMenuName  = "xMENU";                                 //   ��������� ��� ���� 
			 WndClass.lpszClassName = "dllBridge";                             //   ��������� ���� ��� ������ ����  
                                                    // C������ ������������ ����� �������� ���� ���������  
	if(!RegisterClass(&WndClass)) return 0;         // ���� ����� �� ���������������, �� ������� 
	
	hWnd = CreateWindow("dllBridge",                // ����� ������� ���� ������ dllBridge �����
						"Lessons",                  // ��������� ���� (������� �� �������-����� ������)
						WS_OVERLAPPEDWINDOW,        // ����� ����
						700,              // ���������� X ������ �������� ���� ���� 
						200,              // ���������� Y ������ �������� ���� ���� 
						608,                        // ������� ���� (������)
					    526,                        // ������
					      0,                        // ���������� ������������� ����  ( ��� �������� ���� ��������� :)
					      0,                        // ����������  ����  (��� ������������� ��������� ����)
					    hInstance,                  // ���������� ���������� ����������
					      0);                      
	if(hWnd == 0) return 0;							    //  ���� ���� �� �������, �� ������� (��������� �� �����������)
	ShowWindow(hWnd, nCmdShow);						//  ���������� ���� �� ������
	UpdateWindow(hWnd);								//  �������� ����       								  									   								   


               MSG      msg;                        //  ������ ������� ��������� ��������� �� OS Windows
	while(  GetMessage(&msg, 0, 0, 0))              //  ���� ��������� ���������	
	{ TranslateMessage(&msg);                       //  �������� � "�������������" ��������� � �������
	   DispatchMessage(&msg);
	} 

return msg.wParam;
}




























