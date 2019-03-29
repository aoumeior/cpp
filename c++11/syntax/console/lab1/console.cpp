#include <iomanip>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// constant var
constexpr int NUMBER_OF_VALUES = 3;
constexpr int DIVIDER_WIDTH = 73;
constexpr int OUT_WIDTH = 120;
const string COLLEGE = "";
const string COURSE = "";
const string PROGRAMMER_NAME = "";
const string LAB_NAME = "";

const float pi = 3.14159f;

int main()
{

	///The data type of an input file is ifstream
	///The logical file name is inFile
	ifstream inFile;

	///The data type of an output file is ofstream
	///The logical file name is outFile
	ofstream outFile;

	//-------------------Initial Setup of the program----------------------------------------------
	//Open the input and output files
	inFile.open("PlayersData.txt", ios::in);
	outFile.open("PlayerResults.txt", ios::out | std::ios::trunc);

	//Output two messages on the screen stating location of the input & output file

	//Output the divider to the screen
	cout << setfill('*') << setw(DIVIDER_WIDTH + 1) << " " << setfill(' ') << endl;

	//Output file location messages to the screen
	cout << R"ascii(The input is from the file, PlayersData.txt)ascii" << endl;
	cout << R"ascii(The output is to the file, PlayerResults.txt)ascii" << endl;

	//Output the divider to the screen
	cout << setfill('*') << setw(DIVIDER_WIDTH + 1) << " " << setfill(' ') << endl;

	system("pause");

	//Output the divider to the  output files
	outFile << setfill('*') << setw(OUT_WIDTH + 1) << " " << setfill(' ') << endl;
	outFile << setw((OUT_WIDTH + 11) / 2) << COLLEGE << endl;
	outFile << setw((OUT_WIDTH + 11) / 2) << COURSE << endl;
	outFile << setw((OUT_WIDTH + 5) / 2) << LAB_NAME << endl;
	outFile << setw((OUT_WIDTH + 5) / 2) << PROGRAMMER_NAME << endl;
	outFile << setfill('*') << setw(OUT_WIDTH + 1) << " " << setfill(' ') << endl
			<< endl;
	outFile << std::setiosflags(ios::right) << setw(OUT_WIDTH - 13) << "Total" << setw(8 + sizeof("Total") - 1) << "Total" << endl;

	outFile << std::setiosflags(ios::right) << setw(30)
			<< "#"
			<< setw(7 + sizeof("Position") - 1) << "Position"
			<< setw(7 + sizeof("Salary") - 1) << "Salary"
			<< setw(7 + sizeof("Bonus") - 1) << "Bonus"
			<< setw(7 + sizeof("# of") - 1) << "# of"
			<< setw(7 + sizeof("Players") - 1) << "Players"
			<< setw(7 + sizeof("Salary") - 1) << "Salary"
			<< setw(7 + sizeof("Bonus") - 1) << "Bonus" << endl;

	outFile << setiosflags(ios::right)
			<< setw(40 + sizeof("in Million") - 1) << "(in Million)"
			<< setw(5 + sizeof("in Million") - 1) << "(in Million)"
			<< setw(25 + sizeof("in Million") - 1) << "(in Million)"
			<< setw(5 + sizeof("in Million") - 1) << "(in Million)" << endl;
	outFile << setfill('*') << setw(OUT_WIDTH + 1) << " " << setfill(' ') << endl
			<< endl;

	//Loop
	float Salary = {0.0f};
	float Bonus = {0.0f};
	float number[3] = {0.0};
	string playerPosition;

	for (int line = 1; !inFile.eof(); line++)
	{

		//read file
		getline(inFile, playerPosition);
		inFile >> number[0] >> number[1] >> number[2];
		inFile.ignore(1, '\n');

		//Line results
		Salary += number[2] * number[0];
		Bonus += number[2] * number[1];

		//Output
		outFile << std::setiosflags(ios::right) << setw(30) << setiosflags(ios::fixed) << setprecision(2)
				<< line
				<< setw(7 + sizeof("Position") - 1) << playerPosition
				<< setw(7 + sizeof("Salary") - 1) << number[0]
				<< setw(7 + sizeof("Bonus") - 1) << number[1]
				<< setw(7 + sizeof("# of") - 1) << ""
				<< setw(7 + sizeof("Players") - 1) << setprecision(0) << number[2]
				<< setw(7 + sizeof("Salary") - 1) << setprecision(2) << number[2] * number[0]
				<< setw(7 + sizeof("Bonus") - 1) << number[2] * number[1] << endl;
	}

	outFile << setfill('*') << setw(OUT_WIDTH + 1) << " " << setfill(' ') << endl;
	outFile << "Grand Total Salary" << setw(OUT_WIDTH + 1 - (sizeof("Grand Total Salary") - 1) - (7 + sizeof("Salary") - 1)) << Salary << endl;
	outFile << "Grand Total Bonus" << setw(OUT_WIDTH + 1 - (sizeof("Grand Total Bonus") - 1)) << setiosflags(ios::right) << Bonus << endl;
	outFile << setfill('*') << setw(OUT_WIDTH + 1) << " " << setfill(' ') << endl;
	//End output

	//Close file operation
	outFile.close();
	inFile.close();
}