
#include "box.h"
#include <windows.h>                    //  ���������� (������������ ���� ) ���������� ������� WinAPI  

//////////////////////////////////////////  ���������� ���������� 
HWND                  hWnd;             //  ����� ��������! ����  
HINSTANCE        hInstance; 			//  ��������� ���� ��������� 


LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)   //  ������� ��������� ��������� ��...
{																				  //  ...OS Windows	
	switch(message)
	{
		case  WM_CREATE:   SetTimer(hWnd, 1, 200, 0); 
			               break;     
						                        //  ��������� ����������� ��������� ��� �������������
	    case WM_DESTROY:   PostQuitMessage(0);             //  ��������� ����������� ��������� ��� ��_�������������
		 	 			   break;		 	 		
		case WM_COMMAND: 
			               break;	
										 
		case WM_MOUSEMOVE: xMove = LOWORD(lParam);	  // �� ����� ����������� ���� ���� �������� ��������� �� OS
						   yMove = HIWORD(lParam); 							 
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




























