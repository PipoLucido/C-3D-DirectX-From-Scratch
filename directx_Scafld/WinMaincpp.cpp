
#include <Windows.h>

LRESULT CALLBACK WndProc(HWND hwnd,UINT msg, WPARAM wParam,LPARAM lParam ) {


    switch (msg) {
    case WM_CLOSE:
            PostQuitMessage(69);
            break;
    }


    return DefWindowProc(hwnd, msg, wParam, lParam);

}

int CALLBACK WinMain(
    HINSTANCE hInstance,
    HINSTANCE hPrevInstance,
    LPSTR     lpCmdLine,
    int       nShowCmd
) {

    const auto pClassName = "hw3dbutts";
    const auto windowTitle = L"Titulo window test";
    


    //register windows class
    WNDCLASSEXW wc = { 0 };
    wc.cbSize = sizeof(wc);
    wc.style = CS_OWNDC;
    wc.lpfnWndProc = WndProc;
    wc.cbClsExtra = 0;
    wc.cbWndExtra = 0;
    wc.hInstance = hInstance;
    wc.hIcon = nullptr;
    wc.hCursor = nullptr;
    wc.hbrBackground = nullptr;
    wc.lpszMenuName = nullptr;
    wc.lpszClassName = (LPCWSTR)pClassName;
    wc.hIconSm = nullptr;

    RegisterClassEx(&wc);


    //create windows instance
    HWND hwnd = CreateWindowEx(
        0,
        (LPCWSTR)pClassName,
        (LPCWSTR)windowTitle,
        WS_CAPTION | WS_MINIMIZEBOX | WS_SYSMENU,
        200, 200,
        640, 480,
        nullptr,
        nullptr,
        hInstance,
        nullptr
    );
    //show window
     ShowWindow(hwnd, SW_SHOW);
     //message pump
     MSG msg;
     BOOL gResult;
     while ( (gResult = GetMessage(&msg,nullptr,0,0)) > 0)
     {
         TranslateMessage(&msg);
         DispatchMessage(&msg);
     };

     if (gResult == -1)
     {
         return -1;
     }
     else {
         return msg.wParam;
     }
}
