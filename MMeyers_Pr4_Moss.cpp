#include<iostream>
#include<string>
using namespace std;

int main() {
	
	unsigned int employeeNumber = 1;
	float grossPay, grossTotal = 0;
	float stateTax, stateTaxTotal = 0;
	float fedTax, fedTaxTotal = 0;
	float fica, ficaTotal = 0;

	while (employeeNumber != 0){
	cout << "Enter the following information:" << endl << endl;
	cout << "Employee Number (0 to quit): ";

	cin >> employeeNumber;
	if (employeeNumber < 0) { //Validate input, redo if negative number
		cout << "\nInvalid: Employee Number must be positive. To quit, enter 0.";
		cout << "\nEmployee Number (0 to quit): ";
		cin >> employeeNumber;
	}

	cout << "\nGross pay: ";
	cin >> grossPay;
	if (grossPay < 0) { //Validate input, redo if negative number
		cout << "\nInvalid: gross pay must not be negative.";
		cout << "\nGross pay: ";
		cin >> grossPay;
	}

	cout << "\nFederal Withholding: ";
	cin >> fedTax;
	if (fedTax < 0) { //Validate input, redo if negative number
		cout << "\nInvalid: federal withholding must not be negative.";
		cout << "\nFederal Withholding: ";
		cin >> fedTax;
	}

	cout << "\nState Withholding: ";
	cin >> stateTax;
	if (stateTax < 0) { //Validate input, redo if negative number
		cout << "\nInvalid: state withholding must not be negative.";
		cout << "\nState withholding: ";
		cin >> stateTax;
	}

	cout << "\nFICA Withholding: ";
	cin >> fica;
	if (fica < 0) { //Validate input, redo if negative number
		cout << "\nInvalid: FICA withholding must not be negative.";
		cout << "\nFICA Withholding: ";
		cin >> fica;


		}
	
	//Check withholdings against gross pay
	if ((stateTax + fedTax + fica) > grossPay) {
		cout << "ERROR: withholdings may not exceed gross pay. Please enter information again.";
		continue;
	}

	//If the check is good, add data to running totals
	grossTotal += grossPay;
	fedTaxTotal += fedTax;
	stateTaxTotal += stateTax;
	ficaTotal += fica;

	cout << "\n\nProcessing the next employee:" << endl;
	}
	
	return 0;
}