
#include "box.h"
#include <windows.h>                    //  Подключаем (заголовочный файл ) библиотеки функций WinAPI  

//////////////////////////////////////////  Глобальные переменные 
HWND                  hWnd;             //  хедер ГЛАВНОГО! окна  
HINSTANCE        hInstance; 			//  Экземпляр этой программы 


LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)   //  Функция обработки сообщений от...
{			
HDC hdc; //??????? ???????? ??????????
PAINTSTRUCT ps; //??????? ????????? ????????? ???????????? ??????//  ...OS Windows	
	switch(message)
	{
		case  WM_CREATE:   SetTimer(hWnd, 1, 200, 0); 
			               break;     
						                        //  Принимаем однократное сообщение для инициализации
	    case WM_DESTROY:   PostQuitMessage(0);             //  Принимаем однократное сообщение для ДЕ_инициализации
		 	 			   break;		 	 		
		case WM_COMMAND:   switch(LOWORD(wParam))
	                	{
		                   case 100:xCetka ();
		                   break;
						}
			               break;	
										 
		case WM_MOUSEMOVE: xMove = LOWORD(lParam);	  // Во время перемещения мыши сюда приходят сообщения от OS
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
						   					 	   
		        default:   return DefWindowProc(hWnd, message, wParam, lParam);   // обработка OS остальных сообщений
	}
	return 0;
}

//---------------------------------------------------------------------------------------------------------------------

int WINAPI WinMain(HINSTANCE hInst, HINSTANCE hPrevInstance, LPSTR lpszCmd, int nCmdShow)
{
	
	WNDCLASS WndClass;             // Создаём элемент оконной структуры	
			 WndClass.style         = 0;
			 WndClass.lpfnWndProc   = WndProc;                                 //   Имя оконной функции
			 WndClass.cbClsExtra    = 0;
			 WndClass.cbWndExtra    = 0;
			 WndClass.hInstance     = hInstance = hInst;                       //   Дескриптор приложения
			 WndClass.hIcon		    = LoadIcon(hInstance, "MYICON");           //   Загружаем иконку
			 WndClass.hCursor	    = LoadCursor(NULL, IDC_ARROW);             //   Загружаем тип курсора 
			 WndClass.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);      //   Цвет заливки окна выбрали
			 WndClass.lpszMenuName  = "xMENU";                                 //   Указываем имя меню 
			 WndClass.lpszClassName = "dllBridge";                             //   Придумали сами имя класса окна  
                                                    // Cначала регистрируем класс главного окна программы  
	if(!RegisterClass(&WndClass)) return 0;         // если класс не зарегистрирован, то выходим 
	
	hWnd = CreateWindow("dllBridge",                // ————— создаем окно класса dllBridge —————
						"Lessons",                  // заголовок окна (надпись на верхней-синей полосе)
						WS_OVERLAPPEDWINDOW,        // стиль окна
						700,              // координата X левого верхнего угла окна 
						200,              // координата Y левого верхнего угла окна 
						608,                        // размеры окна (Ширина)
					    526,                        // Высота
					      0,                        // Дескриптор родительского окна  ( нет главного окна программы :)
					      0,                        // Дескриптор  меню  (или идентификатор дочернего окна)
					    hInstance,                  // Дескриптор экземпляра приложения
					      0);                      
	if(hWnd == 0) return 0;							    //  если окно не создано, то выходим (программа не запустилась)
	ShowWindow(hWnd, nCmdShow);						//  отобразить окно на экране
	UpdateWindow(hWnd);								//  обновить окно       								  									   								   


               MSG      msg;                        //  Создаём элемент структуры сообщений от OS Windows
	while(  GetMessage(&msg, 0, 0, 0))              //  Цикл обработки сообщений	
	{ TranslateMessage(&msg);                       //  Принятие и "проталкивание" сообщений в очереди
	   DispatchMessage(&msg);
	} 

return msg.wParam;
}




























