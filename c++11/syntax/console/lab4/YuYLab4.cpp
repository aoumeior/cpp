//-------------------------------------GRADING BLOCK-----------------------------------------------
//Lab 4 Grading Block
//Name:  Yue Yu
//Grade:
//General Comments:
//
//
//
//
//
//
//
//
//
//	Total Possible Lab Grade ------------------------------------------------------------------> 200
//	Total Points Lost ------------------------------------------------------------------------->
//	Actual Lab Grade -------------------------------------------------------------------------->
//--------------------------------------------------------------------------------------------------
//
//--------------------------------------------------------------------------------------------------
//Lab 4 Program Flow (IPO):
//Output the divider to the screen
//Input the input file name from the keyboard
//Input the output file name from the keyboard
//Output the divider to the screen
//Open the input file using the input file name entered by the user
//Open the output file using the output file name entered by the user
//Set the precision for the output to the output file
//Output the divider to the output file
//Output the course heading to the output file
//Output the divider to the output file
//Output the input and output file names to the output file
//Output the divider to the output file
//Initialize the line counter
//Initialize the total daily sales
//Initialize the grand box sales
//Initialize the grand premium sales
//Initialize the grand general sales
//Initialize the grand total sales for 3 days
//Input the date from the input file
//
//while there is data in the input file
// Input the number sold & cost per ticket for each type of item from the input file
// Increment the line number
// Calculate the total sales of each type per day
// Calculate the total sales for each type of item in total daily sales
// Accumulate the grand total sales for 3 days
// Accumulate the grand total box sales
// Accumulate the grand premium sales
// Accumulate the grand general sales
// Output the divider to the output file
// Output the line counter & date to the output file
// Output the column heading for the data and calculated values of items to the output file
// Output the type of item, number sold, cost per ticket, total sales to the output file
// Output the divider to the output file
// Output the total daily sales of all the item to the output file
// Move the input pointer to the next line in the input file
// Input the date from the input file
//End while
//
//Output the divider to the output file
//Output the name of programmer to the output file
//Output the grand box sales, grand premium sales, grand general sales
//and grand total sales for 3 days to the output file
//Output the divider to the output file
//
//Close the input & output file
//-------------------------------------------------------------------------------------------------

#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>

using namespace std;

const int DIVIDER_WIDTH = 80;

const string PROGRAMMER_NAME = "YUE YU";
const string COURSE = "CST 133 Y01";

int main(void)
{

	ifstream fin;
	ofstream fout;

	string outputFileName;
	string inputFileName;
	string data;

	int lineCounter;
	int numberSoldOfBox;
	int numberSoldOfSideLine;
	int numberSoldOfPremium;
	int numberSoldOfGeneral;

	double costPerTicketOfBox;
	double costPerTicketOfSideLine;
	double costPerTicketOfPremium;
	double costPerTicketOfGeneral;

	double totalSalesOfBox;
	double totalSalesOfSideLine;
	double totalSalesOfPremium;
	double totalSalesOfGeneral;
	double totalSales;
	double grandTotalSalesFor3Days;
	double grandBoxSales;
	double grandPremiumSales;
	double grandGeneralSales;

	//-------------------Initial Setup of the program----------------------------------------------

	//Output the divider to the screen
	cout << setfill('~') << setw(DIVIDER_WIDTH + 1) << ' ' << setfill(' ') << endl;

	//Input the input file name from the keyboard
	cout << "Enter the name of the input File: ";
	cin >> inputFileName;

	//Input the output file name from the keyboard
	cout << "Enter the name of the output File: ";
	cin >> outputFileName;

	//Output the divider to the screen
	cout << endl
		 << setfill('~') << setw(DIVIDER_WIDTH + 1) << ' ' << setfill(' ') << endl;

	//Open the input file using the input file name entered by the user
	fin.open(inputFileName);

	//Open the output file using the output file name entered by the user
	fout.open(outputFileName);

	//Set the precision for the output to the output file
	fout << fixed << setprecision(2);

	//Output the divider to the output file
	fout << setfill('~') << setw(DIVIDER_WIDTH + 1) << ' ' << setfill(' ') << endl;

	//Output the course heading to the output file
	fout << setw((DIVIDER_WIDTH + 6) / 2) << PROGRAMMER_NAME << endl;
	fout << setw((DIVIDER_WIDTH + 11) / 2) << COURSE << endl;

	//Output the divider to the output file
	fout << setfill('~') << setw(DIVIDER_WIDTH + 1) << ' ' << setfill(' ') << endl;

	//Output the input and output file names to the output file
	fout << "the input file name is: " << inputFileName << endl;
	fout << "the input file name is: " << outputFileName << endl;

	//Output the divider to the output file
	fout << setfill('~') << setw(DIVIDER_WIDTH + 1) << ' ' << setfill(' ') << endl;
	fout << endl;

	//Initialize the line counter
	lineCounter = 0;

	//Initialize the grand box sales
	grandBoxSales = 0.00;

	//Initialize the grand premium sales
	grandPremiumSales = 0.00;

	//Initialize the grand general sales
	grandGeneralSales = 0.00;

	//Initialize the grand total sales for 3 days
	grandTotalSalesFor3Days = 0.00;

	//Input the date from the input file
	getline(fin, data);

	//--------------------------while there is input data processing-------------------------------
	//while there is data in the input file
	while (fin)
	{

		//Input the number sold & cost per ticket for each type of item from the input file
		fin >> costPerTicketOfBox >> numberSoldOfBox;
		fin >> costPerTicketOfSideLine >> numberSoldOfSideLine;
		fin >> costPerTicketOfPremium >> numberSoldOfPremium;
		fin >> costPerTicketOfGeneral >> numberSoldOfGeneral;

		//Increment the line number
		lineCounter++;

		//Calculate the total sales of each type per day
		totalSalesOfBox = numberSoldOfBox * costPerTicketOfBox;
		totalSalesOfSideLine = numberSoldOfSideLine * costPerTicketOfSideLine;
		totalSalesOfPremium = numberSoldOfPremium * costPerTicketOfPremium;
		totalSalesOfGeneral = numberSoldOfGeneral * costPerTicketOfGeneral;

		//Calculate the total sales for each type of item in total daily sales
		totalSales = totalSalesOfBox + totalSalesOfSideLine + totalSalesOfPremium + totalSalesOfGeneral;

		//Accumulate the grand total sales for 3 days
		grandTotalSalesFor3Days += totalSales;

		//Accumulate the grand total box sales
		grandBoxSales += totalSalesOfBox;

		//Accumulate the grand premium sales
		grandPremiumSales += totalSalesOfPremium;

		//Accumulate the grand general sales
		grandGeneralSales += totalSalesOfGeneral;

		//Output the divider to the output file
		fout << setfill('~') << setw(DIVIDER_WIDTH + 1) << ' ' << setfill(' ') << endl;

		//Output the line counter & date to the output file
		fout << "For data # " << lineCounter << endl;
		fout << "Ticket Sales for : " << data << endl;

		//Output the column heading for the data and calculated values of items to the output file
		fout << right << setw(20) << "Type" << setw(20) << "Number Sold" << setw(20)
			 << "Cost per Ticket" << setw(20) << "Total Sales" << endl;

		//Output the type of item, number sold, cost per ticket, total sales to the output file
		fout << right << setw(20) << "Box" << setw(20) << numberSoldOfBox << setw(20)
			 << costPerTicketOfBox << setw(20) << totalSalesOfBox << endl;
		fout << right << setw(20) << "Sideline" << setw(20) << numberSoldOfSideLine
			 << setw(20) << costPerTicketOfSideLine << setw(20) << totalSalesOfSideLine << endl;
		fout << right << setw(20) << "Premium" << setw(20) << numberSoldOfPremium << setw(20)
			 << costPerTicketOfPremium << setw(20) << totalSalesOfPremium << endl;
		fout << right << setw(20) << "General" << setw(20) << numberSoldOfGeneral << setw(20)
			 << costPerTicketOfGeneral << setw(20) << totalSalesOfGeneral << endl;

		//Output the divider to the output file
		fout << setfill('~') << setw(DIVIDER_WIDTH + 1) << ' ' << setfill(' ') << endl;

		//Output the total daily sales of all the item to the output file
		fout << "Total Sales for " << data << " are:  " << setw(49) << totalSales << endl;

		//Move the input pointer to the next line in the input file
		fin.ignore(100, '\n');

		//Input the date from the input file
		getline(fin, data);
	}

	//----------------------------------Output the Summary Data------------------------------------

	//Output the divider to the output file
	fout << setfill('~') << setw(DIVIDER_WIDTH + 1) << ' ' << setfill(' ') << endl;

	//Output the name of programmer to the output file
	fout << setw((DIVIDER_WIDTH + 6) / 2) << PROGRAMMER_NAME << endl;

	//Output the grand box sales, grand premium sales, grand general sales
	//and grand total sales for 3 days to the output file
	fout << "Grand Total Sales for 3 days  " << setw(50) << grandTotalSalesFor3Days << endl;
	fout << "Grand Box Sales is            " << setw(50) << grandBoxSales << endl;
	fout << "Grand Premium Sales is        " << setw(50) << grandPremiumSales << endl;
	fout << "Grand General Sales is        " << setw(50) << grandGeneralSales << endl;

	//Output the divider to the output file
	fout << setfill('~') << setw(DIVIDER_WIDTH + 1) << ' ' << setfill(' ') << endl;

	//------------------------------------Close the files------------------------------------------

	//Close the input & output file
	fin.close();
	fout.close();
	return 0;
}