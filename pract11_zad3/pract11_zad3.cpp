
#include <Windows.h>
#include <tchar.h>
#include <stdio.h>
#include <iostream>
#include<windows.h>
#include "atlstr.h"
#define _CRT_SECURE_NO_WARNINGS
using namespace std;
int _tmain(int argc, char* argv[])
    {
        if (argc == 1)
        {
            STARTUPINFO si = { sizeof(STARTUPINFO) };
            PROCESS_INFORMATION pi;
            ZeroMemory(&si, sizeof(STARTUPINFO));
            TCHAR szCmdLine[] = TEXT("myprog.exe");
            TCHAR str[64];
            BOOL bRet;
            HANDLE THandle;
            HANDLE hEvent = CreateEvent(NULL, true, true, NULL);  //создаю событие
            DuplicateHandle(GetCurrentProcess(), hEvent, GetCurrentProcess(), &THandle, 0, FALSE, DUPLICATE_SAME_ACCESS); //дублирую его дескриптор

            HANDLE* hD = new HANDLE[3]; //массив процессов
            for (int i = 0; i < 3; i++)
            {
                bRet = CreateProcess(NULL, szCmdLine, NULL, NULL, FALSE, CREATE_NEW_CONSOLE, NULL, NULL, &si, &pi); //пораждаю экземпляр
                hD[i] = pi.hProcess;
                CloseHandle(pi.hThread);
            }
            CloseHandle(hEvent);
            OpenEvent(EVENT_MODIFY_STATE, true, NULL);

            WaitForSingleObject(THandle, INFINITY);
            for (int i = 0; i < 3; i++)
                CloseHandle(hD[i]);
        }
        else if (argc == 3)
        {
            cout << argv[1] << endl;
            int c = 0;
            DWORD dwResult;
            HANDLE hEvent = argv[2];
            while (c < 3)
            {
                dwResult = WaitForSingleObject(hEvent, INFINITE);
                if (WAIT_FAILED != dwResult)
                {
                    for (int j = 0; j < 10; j++) {
                        cout << j << endl;
                        Sleep(200);
                    }
                    c++;
                    SetEvent(hEvent);
                }
            }
        }
        return 0;
}