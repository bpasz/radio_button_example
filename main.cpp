// Win32 Tutorial (Radio Buttons)

// Alan Baylis 2004



#include <windows.h>
#define IDI_ICON   101
#define IDB_RADIO1 102
#define IDB_RADIO2 103
#define IDB_RADIO3 104
#define IDB_RADIO4 105

const char ClassName[] = "MainWindowClass";

HWND hWndButton1;

HWND hWndButton2;
HWND hWndButton3;
HWND hWndButton4;

LRESULT CALLBACK WndProc( HWND    hWnd,

                          UINT    Msg,

                          WPARAM  wParam,

                          LPARAM  lParam )

{

    switch (Msg)

    {

        case WM_CREATE:

        {

            HINSTANCE hInstance = (HINSTANCE)GetWindowLong(hWnd, GWL_HINSTANCE);


            hWndButton1 = CreateWindowEx(

            0,

            "BUTTON",

            "Bt1 gr 1",

            WS_VISIBLE | WS_CHILD | BS_AUTORADIOBUTTON | WS_GROUP,  //<------------Pocz¹tek nowej grupy

            10,

            10,

            80,

            20,

            hWnd,

            (HMENU)IDB_RADIO1,

            hInstance,

            NULL);



            hWndButton2 = CreateWindowEx(

            0,

            "BUTTON",

            "Bt 2 gr 1",

            WS_VISIBLE | WS_CHILD | BS_AUTORADIOBUTTON,

            10,

            40,

            80,

            20,

            hWnd,

            (HMENU)IDB_RADIO2,

            hInstance,

            NULL);

             hWndButton3 = CreateWindowEx(

            0,

            "BUTTON",

            "Bt 3 gr 2",

            WS_VISIBLE | WS_CHILD | BS_AUTORADIOBUTTON | WS_GROUP,

            90,

            10,

            80,

            20,

            hWnd,

            (HMENU)IDB_RADIO3,

            hInstance,

            NULL);

             hWndButton4 = CreateWindowEx(

            0,

            "BUTTON",

            "Bt 4 gr 2",

            WS_VISIBLE | WS_CHILD | BS_AUTORADIOBUTTON,

            90,

            40,

            80,

            20,

            hWnd,

            (HMENU)IDB_RADIO4,
            hInstance,

            NULL);


        }

        break;



        case WM_COMMAND:

        {

            switch (LOWORD(wParam))

            {



            }

            return 0;

        }

        break;



        case WM_CLOSE:

            DestroyWindow(hWnd);

        break;



        case WM_DESTROY:

            PostQuitMessage(0);

        break;



        default:

            return (DefWindowProc(hWnd, Msg, wParam, lParam));

    }



    return 0;

}



INT WINAPI WinMain( HINSTANCE  hInstance,

                    HINSTANCE  hPrevInstance,

                    LPSTR      lpCmdLine,

                    INT        nCmdShow )

{

    WNDCLASSEX    wc;



    wc.cbSize           = sizeof(WNDCLASSEX);

    wc.style            = 0;

    wc.lpfnWndProc      = (WNDPROC)WndProc;

    wc.cbClsExtra       = 0;

    wc.cbWndExtra       = 0;

    wc.hInstance        = hInstance;

    wc.hIcon            = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_ICON));

    wc.hIconSm          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_ICON));

    wc.hCursor          = LoadCursor(NULL, IDC_ARROW);

    wc.hbrBackground    = (HBRUSH)(COLOR_WINDOW + 1);

    wc.lpszMenuName     = NULL;

    wc.lpszClassName    = ClassName;



    if (!RegisterClassEx(&wc))

    {

        MessageBox(NULL, "Failed To Register The Window Class.", "Error", MB_OK | MB_ICONERROR);

        return 0;

    }



    HWND    hWnd;



    hWnd = CreateWindowEx(

    WS_EX_CLIENTEDGE,

    ClassName,

    "Radio Buttons",

    WS_OVERLAPPEDWINDOW,

    CW_USEDEFAULT,

    CW_USEDEFAULT,

    240,

    120,

    NULL,

    NULL,

    hInstance,

    NULL);



    if (!hWnd)

    {

        MessageBox(NULL, "Window Creation Failed.", "Error", MB_OK | MB_ICONERROR);

        return 0;

    }



    ShowWindow(hWnd, SW_SHOW);

    UpdateWindow(hWnd);



    MSG    Msg;



    while (GetMessage(&Msg, NULL, 0, 0))

    {

        TranslateMessage(&Msg);

        DispatchMessage(&Msg);

    }



    return Msg.wParam;

}
