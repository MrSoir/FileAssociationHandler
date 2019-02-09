#pragma comment(lib, "advapi32")

#include <windows.h>
#include <iostream>
#include <stdio.h>

#include "Shobjidl.h"

void getFileAssociatedApps(LPCTSTR file_extension)
{
    IEnumAssocHandlers *pEnumHandlers = NULL;
    if (SUCCEEDED(SHAssocEnumHandlers(file_extension, ASSOC_FILTER_RECOMMENDED, &pEnumHandlers)))
    {
        IAssocHandler *pAssocHandler = NULL;
        while (S_OK == pEnumHandlers->Next(1, &pAssocHandler, NULL))
        {
            if (pAssocHandler != NULL)
            {
                LPWSTR pszName;
                LPWSTR pszUIName;
                LPWSTR ppszPath;
                int pIndex;

                pAssocHandler->GetUIName(&pszName);
                pAssocHandler->GetName(&pszUIName);
                pAssocHandler->GetIconLocation(&ppszPath, &pIndex);
                pAssocHandler->Release();
                pAssocHandler = NULL;

                printf("%S \n", pszUIName);
                printf("%S \n", pszName);
                printf("%S - index: %i\n", ppszPath, pIndex);
                std::cout << std::endl;
            }
        }
        pEnumHandlers->Release();
    }
}

void registry_read(HKEY root_key, LPCTSTR sub_key, LPCTSTR key_name)
{
    HKEY hkey;
    if (RegOpenKeyEx(root_key, sub_key, 0, KEY_READ, &hkey) == ERROR_SUCCESS)
    {
        TCHAR rgValue[1024];
        DWORD size1 = 1024;
        DWORD type = REG_SZ;

        DWORD dwRet;

        dwRet = RegQueryValueEx(hkey, key_name, NULL, &type, (LPBYTE)&rgValue, &size1); // Here I tried with and without reference at rgValue

        switch (dwRet)
        {
        case ERROR_SUCCESS:
            std::cout << "OK" << std::endl;
            std::wcout << rgValue << std::endl;
            break;
        case ERROR_MORE_DATA:
            std::cout << "MORE DATA Error" << std::endl;
            break;
        case ERROR_FILE_NOT_FOUND:
            std::cout << "File Not Found" << std::endl;
            break;
        default:
            std::cout << "OTHER system error code" << std::endl;
            break;
        }
    }
    else
        std::cout << "could not open key!" << std::endl;

    RegCloseKey(hkey);
}


