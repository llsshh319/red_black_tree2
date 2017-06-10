#pragma once

#include <windows.h>
#include <tchar.h>
#include <stdio.h>
#include <strsafe.h>

TCHAR* findFile();
TCHAR* nextFile();
void printFile();
void closeFile();