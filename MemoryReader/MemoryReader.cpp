#include <iostream>
#include <Windows.h>
#include <vector>

using namespace std;


int main()
{
	DWORD pID = 0;

	cout << "Enter a PID: ";
	cin >> dec >> pID;

	HANDLE handle = OpenProcess(PROCESS_VM_READ, false, pID);

	if (handle == NULL)
	{
		cout << "OpenProcess failed to get a valid handle." << endl;
		system("pause");
		return EXIT_FAILURE;
	}
	else 
	{
		uintptr_t memoryAddress = 0x0;
		cout << "Integer Memory Address: ";
		cin >> hex >> memoryAddress;
		cout << endl;

		int intRead(0);
		bool addressWasRead = ReadProcessMemory(handle, (LPCVOID)memoryAddress, &intRead, sizeof(int), NULL);

		if (addressWasRead)
		{
			cout << "intRead = " << dec << intRead << endl;
			cout << "\nPress ENTER exit." << endl;
			cin.ignore();
			CloseHandle(handle);
			return EXIT_SUCCESS;
		}
		else
		{
			cout << "ReadProcessMemory function failed." << endl;
			system("pause");
			CloseHandle(handle);
			return EXIT_FAILURE;
		}

	}

}