/*
* Class: CMSC140 CRN 30434
* Instructor: Ahmed Tarek
* Project 4
* Description: Employee Tax Withholding Calculator. Demonstrating loops, nested loops, and mathematical operations
* Due Date: April 03, 2018
* I pledge that I have completed the programming assignment independently.
  I have not copied the code from a student or any source.
  I have not given my code to any student.
  Print your name here: Michael Meyers
*/
/*Proccess - Pseudocode/Algorithm
* Input: (from the keyboard)
* 1. Enter the employee ID number (positive integer only)
*     1a. Users may enter 0 to quit
* 2. Enter employee's gross pay
*     2a. No negative numbers accepted
* 3. Enter employee's federal withholdings
*     3a. No negative numbers accepted
* 4. Enter employee's state tax withholdings
*     4a. No negative numbers accepted
* 5. Enter employee's FICA withholdings
*     5a. No negative numbers accepted
* 6. Check to confirm that withholding amounts do not exceed gross pay
*     6a. If withholding total is more than gross, repeat loop
* 7. If input is valid, add variables to running total
* 8. Repeat for additional employees as needed
* 9. When user inputs 0 to quit, display final running total amounts
*/


#include<iostream>
#include<string>
#include<iomanip>
using namespace std;

int main() {
	
	int employeeNumber = 1; //Holds Employee ID
	double grossPay, grossTotal = 0; //Holds gross pay and gross pay total
	float stateTax, stateTaxTotal = 0; //To hold state tax and state tax total
	float fedTax, fedTaxTotal = 0; //To hold federal tax and federal tax total
	float fica, ficaTotal = 0; //To hold FICA withholding and FICA total
	double totalNetPay = 0; //Total net pay
	const int QUIT_VALUE = 0; //Enter this value at time of Employee ID entry to quit

	cout << "Enter the following information:" << endl << endl;
	cout << "Employee Number (0 to quit): ";
	cin >> employeeNumber;

	while (employeeNumber != QUIT_VALUE) {
	
	if (employeeNumber < 0) { //Validate input, redo if negative number
		cout << "Invalid: Employee Number must be positive. To quit, enter 0.";
		cout << "\nEmployee Number (0 to quit): ";
		cin >> employeeNumber;
		continue;
		}

	cout << "Gross pay: ";
	cin >> grossPay;
	if (grossPay < 0) { //Validate input, redo if negative number
		cout << "\nInvalid: gross pay must not be negative.";
		cout << "\nGross pay: ";
		cin >> grossPay;
	}

	cout << "Federal Withholding: ";
	cin >> fedTax;
	if (fedTax < 0) { //Validate input, redo if negative number
		cout << "\nInvalid: federal withholding must not be negative.";
		cout << "\nFederal Withholding: ";
		cin >> fedTax;
	}

	cout << "State Withholding: ";
	cin >> stateTax;
	if (stateTax < 0) { //Validate input, redo if negative number
		cout << "\nInvalid: state withholding must not be negative.";
		cout << "\nState withholding: ";
		cin >> stateTax;
	}

	cout << "FICA Withholding: ";
	cin >> fica;
	if (fica < 0) { //Validate input, redo if negative number
		cout << "\nInvalid: FICA withholding must not be negative.";
		cout << "\nFICA Withholding: ";
		cin >> fica;


		}
	
	//Check withholdings against gross pay. Withholdings may not be larger than the gross pay
	if ((stateTax + fedTax + fica) > grossPay) {
		cout << "ERROR: withholdings may not exceed gross pay." << endl << endl;
		cout << "Please re-enter the data for this employee." << endl << endl;
		cout << "\nProcessing the next employee:" << endl;
		cout << "Employee Number (0 to quit): ";
		cin >> employeeNumber;
		continue;
	}

	//If the check is good, add data to running totals
	grossTotal += grossPay;
	fedTaxTotal += fedTax;
	stateTaxTotal += stateTax;
	ficaTotal += fica;

	totalNetPay = (grossTotal - fedTaxTotal - stateTaxTotal - ficaTotal);

	//Leads into next loop. User may hit 0 to quit
	cout << "\n\nProcessing the next employee:" << endl;
	cout << "Employee Number (0 to quit): ";
	cin >> employeeNumber;
	}
	
	//Print totals and final net
	cout << endl << endl;
	cout << "Total Gross Pay:    $" << fixed << setprecision(2) << setw(8) << grossTotal << endl;
	cout << "Total Federal Tax:  $" << fixed << setprecision(2) << setw(8) << fedTaxTotal << endl;
	cout << "Total State Tax:    $" << fixed << setprecision(2) << setw(8) << stateTaxTotal << endl;
	cout << "Total FICA:         $" << fixed << setprecision(2) << setw(8) << ficaTotal << endl;
	cout << "Total Net Pay:      $" << fixed << setprecision(2) << setw(8) << totalNetPay << endl;
	cout << endl;
	system("PAUSE");

	return 0;
}