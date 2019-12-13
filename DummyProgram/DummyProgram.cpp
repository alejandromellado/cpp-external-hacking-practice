#include <iostream>
#include <Windows.h>

#define ARRAY_SIZE 128

using namespace std;

int main()
{
	int varInt(123456);
	string varString("DefaultString");
	char arrChar[ARRAY_SIZE] = "Long char array right there ->";
	
	int* ptr2int(&varInt);
	int** ptr2ptr(&ptr2int);
	int*** ptr2ptr2(&ptr2ptr);

	while (true)
	{
		cout << "Process ID: " << dec << GetCurrentProcessId() << endl;

		cout << endl;

		cout << "varInt		(0x" << hex << uppercase << (uintptr_t) &varInt << ") = " << dec << varInt << endl;
		cout << "varString	(0x" << hex << uppercase << (uintptr_t) &varString << ") = " << varString << endl;
		cout << "arrChar[" << dec << ARRAY_SIZE << "]	(0x" << hex << uppercase << (uintptr_t) &arrChar << ") = " << arrChar << endl;

		cout << endl;

		cout << "ptr2int		(0x" << hex << uppercase << (uintptr_t) &ptr2int << ") = 0x" << hex << uppercase << ptr2int << endl;
		cout << "ptr2ptr		(0x" << hex << uppercase << (uintptr_t) &ptr2ptr << ") = 0x" << hex << uppercase << ptr2ptr << endl;
		cout << "ptr2ptr2	(0x" << hex << uppercase << (uintptr_t) &ptr2ptr2 << ") = 0x" << hex << uppercase << ptr2ptr2 << endl;

		cout << "\nPress ENTER to print again." << endl;
		cin.ignore();
		cout << "--------------------------------------------------" << endl;

		cout << endl;
	}
}
