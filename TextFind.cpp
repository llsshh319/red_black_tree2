#include "textfind.h"

WIN32_FIND_DATA ffd;
TCHAR szDir[MAX_PATH];
size_t length_of_arg;
HANDLE hFind = INVALID_HANDLE_VALUE;
DWORD dwError = 0;

TCHAR* findFile()
{

	StringCchCopy(szDir, MAX_PATH, TEXT("."));

	//_tprintf(TEXT("\nTarget directory is %s\n\n"), szDir);
	// Prepare string for use with FindFile functions.  First, copy the
	// string to a buffer, then append '\*' to the directory name.


	StringCchCat(szDir, MAX_PATH, TEXT("\\*.txt"));

	// Find the first file in the directory.

	hFind = FindFirstFile(szDir, &ffd);

	if (INVALID_HANDLE_VALUE == hFind)
	{
		printf("Error: FindFirstFile\n");
		return _T("");
	}
	return ffd.cFileName;

}
TCHAR* nextFile()
{
	// List all the files in the directory with some info about them.
	if (FindNextFile(hFind, &ffd) != 0)
	{
		if (ffd.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)
		{
			//_tprintf(TEXT("  %s, %d \n"), ffd.cFileName, _tcslen(ffd.cFileName));
		}
		else
		{
			//TCHAR dir[100], ext[100], filename[100], drive[100];
			//_tsplitpath_s(ffd.cFileName, drive, 100, dir, 100, filename, 100, ext, 100);
			//_tprintf(TEXT("  %s   <DIR>, %d \n"), ffd.cFileName, _tcslen(ffd.cFileName));
			return ffd.cFileName;
		}
	}
	return _T("");
}
void printFile()
{
	_tprintf(TEXT("%s"), ffd.cFileName);
}
void closeFile()
{
	dwError = GetLastError();
	if (dwError != ERROR_NO_MORE_FILES)
	{
		printf("Error: FindFirstFile\n");
	}

	FindClose(hFind);
	getchar();
}