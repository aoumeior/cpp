#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

void printDivider(ofstream &, char, int);

//task 0
const int WIDTH = 80;

//task1

//?? 这里不应该和其他任务一样有一个 string 定义么

//task 2
const string UNIVERSITY_NAME = "William and Chris University";

//task 3
const string GROUP_NAME = "C++ Programming Group";

//task 4
const string SPORTING_STADIUM = "BCC Sports Stadium";

int main()
{
	//task 0
	int fileNumber;
	string inFileName;
	string outFileName;
	ifstream fin;
	ofstream fout;

	//task 1
	double weeklyTotal;
	double totalGroceriesSpend;
	int countOfWeek;
	double totalPointsAward;
	double gasDiscountAward;

	//task 2
	string professorName;
	int professionalPoint;
	string Ranking;

	//task 3
	int numberOfEmployee;
	int countOfEmployee;
	string nameOfEmployee;
	int taxBracket;
	double grossPay;
	int taxRate;
	double taxesPaid; // (grossPay * taxRate)
	double netPay;	//(grossPay - taxPaid)

	//task 4
	string ticket;
	string tickSub;
	int gate;
	int fanCount;
	int countOfGate1;
	int countOfGate2;
	int countOfGate3;
	int countOfGate4;

	//-------------------Initial Setup of the program----------------------------------------------
	//Task 0 - Opening the input file

	//Output file options on the screen
	cout << "Select the input file:" << endl;
	cout << "1.	lab6-1.txt" << endl;
	cout << "2.	lab6-2.txt" << endl;
	cout << "3.	lab6-3.txt" << endl;
	cout << "Enter the input file choice:";

	//Input the file number from the keyboard
	cin >> fileNumber;

	printDivider(static_cast<ofstream &>(cout), '-', WIDTH);

	//Determine the input file
	if (fileNumber == 1)
	{

		inFileName = "lab6In-1.txt";
		outFileName = "lab6Out-1.txt";
	}
	else if (fileNumber == 2)
	{

		inFileName = "lab6In-2.txt";
		outFileName = "lab6Out-2.txt";
	}
	else
	{

		inFileName = "lab6In-3.txt";
		outFileName = "lab6Out-3.txt";
	}

	//Open the selected file
	fin.open(inFileName);
	fout.open(outFileName);

	//Output to the screen the successful input file open message
	cout << "The input file: " << inFileName << " is successfully opened" << endl;
	cout << "The input file: " << outFileName << " is successfully opened" << endl;

	//Output the divider to the screen
	printDivider(static_cast<ofstream &>(cout), '-', WIDTH);

	//task 1

	//Output the divider to the output file
	printDivider(fout, '-', WIDTH);

	//Output the task heading to the output file
	fout << setw((WIDTH + 17) / 2) << "Task 1 - Grocery points & Discount" << endl;

	//Output the divider to the output file
	printDivider(fout, '-', WIDTH);

	//Set the formatting for the output file
	fout << fixed << setprecision(2);

	//Initialize monthly purchase total
	totalGroceriesSpend = 0.0;
	//Output the column heading for the grocery totals to the output file
	//Output the divider to the output file
	printDivider(fout, '-', WIDTH);
	fout << "Week #" << setw(WIDTH - 7) << right << "Weekly Total" << endl;
	//Output the divider to the output file
	printDivider(fout, '-', WIDTH);

	//For each week, process the weekly purchases
	for (countOfWeek = 1; countOfWeek <= 4; countOfWeek++)
	{
		//Input the weekly purchase from the input file
		fin >> weeklyTotal;
		//Output the weekly purchase to the output file
		fout << "	 " << countOfWeek << setw(WIDTH - 7) << right << weeklyTotal << endl;
		//Accumulate the monthly total
		totalGroceriesSpend += weeklyTotal;
	} //End For

	//Determine the points awarded based on the total monthly purchase
	if (totalGroceriesSpend > 0 && totalGroceriesSpend < 300)
	{
		totalPointsAward = 100;
		gasDiscountAward = 100 * 0.02;
	}
	else if (totalGroceriesSpend > 300 && totalGroceriesSpend < 480)
	{
		totalPointsAward = 150;
		gasDiscountAward = 100 * 0.04;
	}
	else if (totalGroceriesSpend > 480 && totalGroceriesSpend < 675)
	{
		totalPointsAward = 180;
		gasDiscountAward = 100 * 0.10;
	}
	else if (totalGroceriesSpend > 675 && totalGroceriesSpend < 900)
	{
		totalPointsAward = 200;
		gasDiscountAward = 100 * 0.15;
	}
	else if (totalGroceriesSpend > 900 && totalGroceriesSpend < 1500)
	{
		totalPointsAward = 430;
		gasDiscountAward = 100 * 0.25;
	}
	else if (totalGroceriesSpend > 1500)
	{
		totalPointsAward = 500;
		gasDiscountAward = 100 * 0.30;
	}

	//Output the divider to the output file
	printDivider(fout, '-', WIDTH);

	//Output the total monthly purchase to the output file
	fout << "The Total points awards are " << totalPointsAward << endl;

	//Set the formatting for the output file
	fout << fixed << setprecision(2);

	//Output the gas discount amount to the output file
	fout << "Gas Discount per gallon awards is " << gasDiscountAward << static_cast<char>(unsigned(4U)) << endl;

	//Output the divider to the output file
	printDivider(fout, '-', WIDTH);

	//Output two blank lines to the output file
	fout << endl;

	//task 2

	//Output the divider to the output file
	printDivider(fout, '-', WIDTH);
	//Output the task heading to the output file
	fout << setw((WIDTH + 15) / 2) << "Task 2 - Professional Ranking" << endl;
	//Output the divider to the output file
	printDivider(fout, '-', WIDTH);
	//Output the college name to the output file
	fout << setw((WIDTH + 14) / 2) << UNIVERSITY_NAME << endl;
	//Output the divider to the output file
	printDivider(fout, '-', WIDTH);
	//Output the column heading to the output file
	fout << " professor’s name " << setw(20) << right << "Points" << setw(WIDTH - 40) << right << "Weekly Total" << endl;
	//Output the divider to the output file
	printDivider(fout, '-', WIDTH);

	//将文件指针移动到下一行
	fin.ignore(100, '\n');

	//从文件中获取一行赋值给professorName
	getline(fin, professorName);

	//while begin ,当professorName！="DONE"时候停止
	while (professorName != "DONE")
	{

		fin >> professionalPoint;

		//这估计你应该看不懂 打电话说吧。
		switch (professionalPoint / 200)
		{
		case 0:
		case 1:
			Ranking = "Lecturer";
			break;
		case 2:
			Ranking = "Assistant";
		case 3:
			Ranking = "Associate";
		default:
			Ranking = "Professor";
		}
		//Output professor's name, points, ranking aligned to fout file
		fout << setw(19) << left << professorName << setw(20) << right << professionalPoint << setw(WIDTH - 40) << right << Ranking << endl;
		//将文件指针移动到下一行
		fin.ignore(100, '\n');
		//从文件中获取一行赋值给professorName
		getline(fin, professorName);
	}

	//Output the divider to the output file
	printDivider(fout, '-', WIDTH);

	//Output two blank lines to the output file
	fout << endl;

	//task 3

	//Set the formatting for the output file
	fout << fixed << setprecision(2);

	//Output the divider to the output file
	printDivider(fout, '-', WIDTH);

	//Output the task heading to the output file
	fout << setw((WIDTH + 11) / 2) << "Task 3 - Exployee Pay" << endl;

	//Output the divider to the output file
	printDivider(fout, '-', WIDTH);

	//Output the company name to the output file
	fout << setw((WIDTH + 11) / 2) << GROUP_NAME << endl;

	//Output the divider to the output file
	printDivider(fout, '-', WIDTH);

	//  Output the column heading to the output file
	fout << setw(15) << left << "name" << setw(20) << right << "Tax Bracket" << setw(15) << right << "Gross Pay" << setw(15) << "Taxes" << setw(WIDTH - 66) << right << "Net Pay" << endl;

	//Output the divider to the output file
	printDivider(fout, '-', WIDTH);

	//从文件中输入到numberOfEmployee
	fin >> numberOfEmployee;
	for (countOfEmployee = 1; countOfEmployee <= numberOfEmployee; countOfEmployee++)
	{

		//忽略一行
		fin.ignore(100, '\n');

		//从文件中输入到nameOfEmployee
		getline(fin, nameOfEmployee);
		fin >> grossPay;

		//  Nested if used to set tax bracket and tax rate (no compound conditionals)  //要改 英文不好 直接看评分标准吧
		if (grossPay <= 30000)
		{

			taxBracket = 1;
			taxRate = 15;
		}
		else if (30000 < grossPay && grossPay > 59999)
		{
			taxBracket = 2;
			taxRate = 22;
		}
		else if (60000 < grossPay && grossPay > 99999)
		{
			taxBracket = 3;
			taxRate = 33;
		}
		else if (grossPay > 100000)
		{
			taxBracket = 4;
			taxRate = 44;
		}
		//Calculate the tax amount and the net pay  //这个要改
		taxesPaid = grossPay * taxRate;

		netPay = grossPay - grossPay * taxRate / 100;

		//Output Divider and blank lines used to separate tasks //要改
		fout << setw(15) << left << nameOfEmployee << setw(20) << right << grossPay << setw(15) << right << taxRate << '%' << setw(15) << taxesPaid / 100 << setw(WIDTH - 67) << right << netPay << endl;
	}

	//Output the divider to the output file
	printDivider(fout, '-', WIDTH);

	//Output two blank lines to the output file
	fout << endl;

	//task 4

	//Output the divider to the output file
	printDivider(fout, '-', WIDTH);

	//Output the task heading to the output file
	fout << setw((WIDTH + 16) / 2) << "Task 4 - sports  stadium Seating" << endl;

	//Output the divider to the output file
	printDivider(fout, '-', WIDTH);

	//Output the stadium name to the output file
	fout << setw((WIDTH + 9) / 2) << SPORTING_STADIUM << endl;

	//Output the divider to the output file
	printDivider(fout, '-', WIDTH);

	//Output the column heading to the output file
	fout << setw(15) << left << "Fan Count" << setw(20) << right << "Ticket" << setw(15) << right << "Gate" << setw(WIDTH - 50) << "Seat Number" << endl;
	//Output the divider to the output file
	printDivider(fout, '-', WIDTH);

	fin.ignore(100, '\n');

	fanCount = 1;
	countOfGate1 = 0;
	countOfGate2 = 0;
	countOfGate3 = 0;
	countOfGate4 = 0;
	while (fin)
	{

		getline(fin, ticket);
		switch (ticket.at(0))
		{
		case 'A':
		case 'E':
		case 'I':
		case 'M':
		case 'Q':
		case 'U':
		case 'Y':
			gate = 1;
			countOfGate1++;
			break;
		case 'B':
		case 'F':
		case 'J':
		case 'N':
		case 'R':
		case 'V':
		case 'Z':
			gate = 2;
			countOfGate2++;
			break;
		case 'C':
		case 'G':
		case 'K':
		case 'O':
		case 'S':
		case 'W':
			gate = 3;
			countOfGate3++;
			break;
		default:
			gate = 4;
			countOfGate4++;
		}
		tickSub = ticket.substr(1, 2);
		fout << setw(15) << left << fanCount << setw(20) << right << ticket << setw(15) << right << gate << setw(WIDTH - 53) << tickSub << endl;
		fanCount++;
	}

	//Output the divider to the output file
	printDivider(fout, '-', WIDTH);

	fout << setw(15) << ' ' << setw(20) << "Gate Number" << setw(20) << "Fan Count" << endl;

	//Output the divider to the output file
	printDivider(fout, '-', WIDTH);

	fout << setw(15) << ' ' << setw(20) << 1 << setw(20) << countOfGate1 << endl;
	fout << setw(15) << ' ' << setw(20) << 2 << setw(20) << countOfGate2 << endl;
	fout << setw(15) << ' ' << setw(20) << 3 << setw(20) << countOfGate3 << endl;
	fout << setw(15) << ' ' << setw(20) << 4 << setw(20) << countOfGate4 << endl;

	//Output the divider to the output file
	printDivider(fout, '-', WIDTH);

	//Output two blank lines to the output file
	fout << endl;

	//Close the input file
	fin.close();
	//Close the output file
	fout.close();

	return 0;
}

void printDivider(ofstream &fout, char symbol, int numberOfSymbol)
{
	fout << setfill(symbol) << setw(numberOfSymbol) << ' ' << setfill(' ') << endl;
}
