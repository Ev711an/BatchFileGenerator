/*
 * main.cpp
 *
 *  Created on: May 21, 2019
 *      Author: SHREC5450
 */
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

ofstream outputFile;

int jarFile();
int exeFile();

int main() {
	int intResponse;

	FILETYPE:
	cout << "What type of file are you executing?\n"
			<< "(1): .jar\n"
			<< "(2): .exe\n";
	cin >> intResponse;

	switch (intResponse) {
		case 1: return jarFile();
		break;

		case 2: return exeFile();
		break;

		default: cout << "Invalid response. Try again. Idiot.\n";
		goto FILETYPE;
	}

	return 0;
}




int jarFile() {
	int maxRam;
	int minRam;
	string filename;
	outputFile.open("CustomJar.bat");

	cout << "What is the filename (including .jar at the end)\n";
	cin >> filename;

	cout << "What is the maximum amount of RAM this program can use? (in Mb)\n";
	cin >> maxRam;

	cout << "What is the minimum amount of RAM this program can use? (in Mb)\n";
	cin >> minRam;

	outputFile << "echo off\n"
			<< "java -jar " << "-Xms" << minRam << "M -Xmx" << maxRam << "M " << filename;

	return 0;

}



int exeFile() {

	return 0;
}
