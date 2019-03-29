#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

//task 1
const int SEMESTERS_FOR_DISCOUNTS = 3;

const double SEMESTER_AMOUNT = 50.00;
const double GPA_AMOUNT = 100.00;
const double GPA_REQUIRED = 3.45;

//task 2
const int WARMTEMPERATURE = 70;

//task 3
const int POINTS = 3000;
//output
const int FORMAT_WIDTH = 100;
using namespace std;
int main()
{

	fstream inFile;
	fstream outFile;

	//task 0
	int beSelectFile;
	//task 1
	int semestersCompleted;
	double gpa;
	double semesterDiscount;
	double gpaDiscount;
	double totalDiscount;
	string studentName;
	//task 2
	string city;
	int temperature;
	string weathercondition;

	//task 3
	string name;
	int money;
	int rewardPoints;
	string states;

	//task 4
	string weeks;
	string time;
	string A;
	double AviewersNumber;
	string B;
	double BviewersNumber;
	string res;

	cout << "select the input file " << endl;
	cout << "1.	Lab5In-1.txt" << endl;
	cout << "2.	Lab5In-2.txt" << endl;
	cout << "Enter the number of the input File :";
	cin >> beSelectFile;
	if (beSelectFile <= 0 || beSelectFile > 2)
	{
		return -1;
	}
	if (beSelectFile == 1)
	{

		inFile.open("Lab5In-1.txt");
		outFile.open("Lab5Out-1.txt");
		cout << endl;
		cout << "The input File Lab5In-1.txt is successfully opened." << endl;
		cout << "The output File Lab5Out-1.txt is successfully opened." << endl;
	}
	else
	{

		inFile.open("Lab5In-2.txt");
		outFile.open("Lab5Out-2.txt");
		cout << endl;
		cout << "The input File Lab5In-2.txt is successfully opened." << endl;
		cout << "The output File Lab5Out-2.txt is successfully opened." << endl;
	}
	//task 1
	inFile >> studentName;
	inFile.ignore(100, '\n');
	inFile >> semestersCompleted;
	inFile >> gpa;

	if (gpa < SEMESTERS_FOR_DISCOUNTS)
	{

		semesterDiscount = 0.0;
	}
	else if (gpa >= GPA_REQUIRED)
	{
		semesterDiscount = SEMESTER_AMOUNT;
		gpaDiscount = GPA_AMOUNT;
	}

	if (gpa >= GPA_REQUIRED)
	{

		gpaDiscount = GPA_AMOUNT;
	}

	totalDiscount = semesterDiscount + gpaDiscount;

	outFile << setw(FORMAT_WIDTH) << setfill('*') << '*' << setfill(' ') << endl;
	outFile << "Task 1 - Tuition Discount" << endl;
	outFile << left << "Name:" << setw(FORMAT_WIDTH - 5) << right << studentName << endl;
	outFile << left << "Semesters Completed:" << setw(FORMAT_WIDTH - 20) << right << semestersCompleted << endl;
	outFile << left << "GPA:" << setw(FORMAT_WIDTH - 4) << right << gpa << endl;
	outFile << setw(FORMAT_WIDTH) << setfill('*') << '*' << setfill(' ') << endl;
	outFile << left << "Semester Discount:" << setw(FORMAT_WIDTH - 18) << right << semesterDiscount << endl;
	outFile << left << "GPA Discount:" << setw(FORMAT_WIDTH - 13) << right << gpaDiscount << endl;
	outFile << left << "Total Discount:" << setw(FORMAT_WIDTH - 15) << right << totalDiscount << endl;
	outFile << setw(FORMAT_WIDTH) << setfill('*') << '*' << setfill(' ') << endl;

	//task 2
	inFile >> city;
	inFile.ignore(100, '\n');
	inFile >> temperature;
	if (temperature > WARMTEMPERATURE)
	{

		weathercondition = " is warm";
	}
	else
	{
		weathercondition = "is not warm enough yet";
	}

	outFile << setw(FORMAT_WIDTH) << setfill('*') << '*' << setfill(' ') << endl;
	outFile << "Task 2 - Temperature Message " << endl;
	outFile << "The temperature :" << temperature << endl;
	outFile << "The city," << city << weathercondition << endl;
	outFile << setw(FORMAT_WIDTH) << setfill('*') << '*' << setfill(' ') << endl;

	//task 3
	inFile.ignore(100, '\n');
	getline(inFile, name);
	inFile >> money;
	inFile.ignore(100, '\n');
	if (money > POINTS)
	{
		states = "you have earned a FREE GALACTIC Coffee";
		rewardPoints = money - POINTS;
	}
	else
	{
		states = " you not yet earned a free Galactic Coffee";
		rewardPoints = money;
	}
	outFile << setw(FORMAT_WIDTH) << setfill('*') << '*' << setfill(' ') << endl;
	outFile << "Task 3 - Reward Points Bonus" << endl;
	outFile << setw((FORMAT_WIDTH + 24) / 2) << "GalaxyBucks Coffee Shop" << endl;
	outFile << "Customer's Name:" << setw(FORMAT_WIDTH - 16) << right << name << endl;
	outFile << "Current Reward Points:" << setw(FORMAT_WIDTH - 22) << right << money << endl;
	outFile << states << endl;
	outFile << "Ending Reward Points:" << setw(FORMAT_WIDTH - 21) << right << rewardPoints << endl;
	outFile << setw(FORMAT_WIDTH) << setfill('*') << '*' << setfill(' ') << endl;

	outFile << endl;
	//task 4
	inFile >> weeks;
	inFile.ignore(100, '\n');

	outFile << setw(FORMAT_WIDTH) << setfill('*') << '*' << setfill(' ') << endl;
	outFile << setw((FORMAT_WIDTH + 26) / 2) << "Task 4 - Tv Rating Winners" << endl;
	for (; inFile;)
	{

		inFile >> time;
		inFile.ignore(100, '\n');
		getline(inFile, A);
		inFile >> AviewersNumber;
		inFile.ignore(100, '\n');
		getline(inFile, B);
		inFile >> BviewersNumber;
		if (AviewersNumber > BviewersNumber)
		{

			res = A;
		}
		else
		{

			res = B;
		}
		outFile << setw(FORMAT_WIDTH) << setfill('*') << '*' << setfill(' ') << endl;
		outFile << "Time" << setw(30) << right << "Show" << setw(FORMAT_WIDTH - 34) << right << "Viewer per Million" << endl;
		outFile << time << " PM " << setw(30 - 5) << right << A << setw(FORMAT_WIDTH - 34) << right << fixed << setprecision(2) << AviewersNumber << endl;
		outFile << time << " PM " << setw(30 - 5) << right << B << setw(FORMAT_WIDTH - 34) << right << fixed << setprecision(2) << BviewersNumber << endl;
		outFile << setw(FORMAT_WIDTH) << setfill('*') << '*' << setfill(' ') << endl;
		outFile << "Highest Viewership Tv Show for " << weeks << endl;
		outFile << "in the " << time << "PM time slot is :" << setw(FORMAT_WIDTH - 29) << right << res << endl;
		outFile << setw(FORMAT_WIDTH) << setfill('*') << '*' << setfill(' ') << endl;
	}

	inFile.close();
	outFile.close();
}