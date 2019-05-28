/*
 * main.cpp
 *
 *  Created on: May 21, 2019
 *      Author: Evan Garrison
 */

/*
 * Version 0.1.0 | May 24, 2019
 *
 * Contributers:
 * Evan Garrison
 *
 * First Viable batch file generator, has basic functionality, can make
 * 3 different types of batch file: For an .exe, a .jar and a minecraft server.
 */
#include <iostream> //For test IO
#include <fstream> //For file IO
using namespace std; //Because I don't feel like putting that in front of cout, cin, etc.

//This will be our output filestream.
ofstream outputFile;

//Function Declarations
int jarFile(); //creates a batch file to execute a .jar
int exeFile(); //for a .exe
int minecraftServer(); //for a minecraft server
string checkForEndStringAndAdd(string inString, string reqString);

int main() {
	//response to query about filetype
	int intResponse;

	//query for filetype, with TYPE: in case the user decides not to follow the rules.
	TYPE:
	cout << "What kind of program are you executing?\n"
			<< "(1): .jar\n"
			<< "(2): .exe\n"
			<< "(3): Minecraft Server\n"
			;
	cin >> intResponse;

	//decides which function to execute based on user's response.
	switch (intResponse) {
		case 1: return jarFile();
		break;

		case 2: return exeFile();
		break;

		case 3: return minecraftServer();
		break;

		default: cout << "Invalid response. Try again. Idiot.\n";
		goto TYPE; //in case user is dumb
	}

	return 1; //If the program somehow makes it here, something went wrong.
	//It should end when it returns 0 in the switch.
}




/**
 * This function will execute a .jar file with a max RAM value and a min RAM value.
 * You can also add extra parameters if needed.
 */
int jarFile() {
	//RAM variable
	int ram;

	//variables for extra parameters, if applicable
	string tempString;
	string parameters = "";
	int numParameters;

	//output file variables
	string filename;
	outputFile.open("CustomJar.bat");

	//gets filename
	cout << "What is the filename (including .jar at the end)\n";
	cin >> filename;

	//gets RAM
	cout << "How much RAM do you want this program to use?(in Mb)\n";
	cin >> ram;

	//gets number of additional parameters
	cout << "How many more parameters do you have(if none, enter 0)?\n";
		cin >> numParameters;

		//entering additional parameters if needed
		for (int i = 0; i < numParameters; i++) {
			cout << "Enter Parameter " << i + 1 << ":\n";
			cin >> tempString;
			parameters = parameters + tempString + ' ';
		}

	//outputs all needed code to batch file.
	outputFile << "echo off\n"
			<< "java -jar " << "-Xms" << ram << "M -Xmx" << ram << "M " << filename << ' ' << parameters;

	//returns 0, successful execution of the program.
	return 0;

}




/**
 *
 */
int exeFile() {
	//filename, includes the .exe, will eventually add logic to automatically add .exe
	string filename;

	//variables for extra parameters, if applicable
	string tempString;
	string parameters = "";
	int numParameters;

	//opens the output file for the batch file
	outputFile.open("CustomExe.bat");

	//gets filename
	cout << "What is the filename (including .exe at the end)\n";
	cin >> filename;

	//gets number of additional parameters
	cout << "How many more parameters do you have(if none, enter 0)?\n";
	cin >> numParameters;

	//entering additional parameters if needed
	for (int i = 0; i < numParameters; i++) {
		cout << "Enter Parameter " << i + 1 << ":\n";
		cin >> tempString;
		parameters = parameters + tempString + ' ';
	}

	//outputs all needed code to batch file.
	outputFile << "echo off\n"
			<< filename << ' ' << parameters;

	//returns 0, successful execution of the program.
	return 0;
}




/**
 *
 */
int minecraftServer() {
	//RAM variable
	int ram;

	//variables for determining if user wants GUI interface
	char isgui;
	string gui;

	//output file variables
	string filename;
	outputFile.open("CustomJar.bat");

	//gets filename
	cout << "What is the filename?\n";
	cin >> filename;

	//gets RAM
	cout << "How much RAM do you want the server use?(in Mb)\n";
	cin >> ram;

	//Asks whether user wants to use GUI
	cout << "Do you want to use the GUI interface? If not, the server will run through the command line(Y/n).\n";
	cin >> isgui;

	if (isgui == 'Y' || isgui == 'y') gui = "";
	else gui = "nogui";

	//outputs all needed code to batch file.
	outputFile << "echo off\n"
			<< "java -jar " << "-Xms" << ram << "M -Xmx" << ram << "M " << checkForEndStringAndAdd(filename, ".jar") << ' ' << gui;

	//returns 0, successful execution of the program.
	return 0;
}




string checkForEndStringAndAdd(string inString, string reqString) {
	int reqCharPresent = 0;

	for (int i = 0; i < reqString.length(); i++) {
		char inStringChar = inString.at((inString.length() - reqString.length()) + 1 + i);
		char reqStringChar = reqString.at(i);

		if (inStringChar == reqStringChar) {
			reqCharPresent++;
		}
	}

	if (reqCharPresent == reqString.length()) {
		return inString;
	}
	else {
		string outString = inString + reqString;
		return outString;
	}

}
