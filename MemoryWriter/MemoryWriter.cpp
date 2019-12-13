#include <iostream>
#include <Windows.h>
#include <vector>

using namespace std;


int main()
{
	DWORD pID = 0;

	// Prompting user for the process ID of target process
	cout << "Enter a PID: ";
	cin >> dec >> pID;

	HANDLE handle = OpenProcess(PROCESS_ALL_ACCESS, false, pID);

	if (handle == NULL)
	{
		cout << "OpenProcess failed to get a valid handle." << endl;
		system("pause");
		return EXIT_FAILURE;
	}
	else
	{
		// Prompting user for for memory address to overwrite
		uintptr_t memoryAddress = 0x0;
		cout << "Integer Memory Address: ";
		cin >> hex >> memoryAddress;

		// Prompting user for integer value to overwrite
		int intToWrite(0);
		cout << "Value to Write: ";
		cin >> dec >> intToWrite;

		// Overwriting the integer in the other process
		bool valueOverwritten = WriteProcessMemory(handle, (LPVOID)memoryAddress, &intToWrite, sizeof(int), NULL);

		if (valueOverwritten)
		{
			cout << "Value overwritten successfuly" << endl;
			cout << "\nPress ENTER exit." << endl;
			cin.ignore();
			CloseHandle(handle);
			return EXIT_SUCCESS;
		}
		else
		{
			cout << "WriteProcessMemory function failed. GetLastError = " << dec << GetLastError() << endl;
			system("pause");
			CloseHandle(handle);
			return EXIT_FAILURE;
		}

	}

}