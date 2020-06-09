#include"main.h";
#include<iostream>;
#include<fstream>;
#include<string>;
#include<Windows.h>

#define a_down		0x8000;

using namespace std;

int main() {
	ofstream myFile;
	myFile.open("./file.txt");
	myFile << "205 573";
	myFile.close();
	getText("./file.txt");

	while (true) {
		if (GetKeyState('A') & 0x8000) {
			readConfig("./file.txt");
		}
		else if (GetKeyState('B') & 0x8000) {
			getMousePos(100);
		}
	}
	return 0;
}

int getText(string fileName)
{
	string line;
	ifstream myFile(fileName);
	if (myFile.is_open()) {
		while (getline(myFile, line)) {
			cout << line << endl;

		}
	}
	else {
		myFile.open(fileName);
	}

	return 0;
}

int readConfig(std::string fileName)
{
	int a, b;
	ifstream myConfig(fileName);
	while (myConfig >> a >> b) {
		SetCursorPos(a, b);
		Sleep(30);
	}

	return 0;
}

int getMousePos(int accuracy)
{
	int Xvalues[500] = {};
	int Yvalues[500] = {};
	for (int i = 0; i < accuracy; i++)
	{
		POINT p;
		if (GetCursorPos(&p)) {
			HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleTextAttribute(hConsole, 5);
			cout << "X: " << p.x << " Y: " << p.y << endl;
			Xvalues[i] = p.x;
			Yvalues[i] = p.y;
			Sleep(30);
		}
	}

	ofstream myFile("./file.txt");

	if (myFile.is_open()) {
		for (int i = 0; i < accuracy; i++)
		{
			myFile << Xvalues[i] << " " << Yvalues[i] << endl;
		}
		myFile.close();
	}
	else {
		myFile.open("./file.txt");
	}

	return 0;
}
