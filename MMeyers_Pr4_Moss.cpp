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
	if (employeeNumber < 0) {
		cout << "Invalid: Employee Number must be positive. To quit, enter 0.";
		break;
	}

	cout << "\nGross pay: ";
	cin >> grossPay;
	if (grossPay < 0) {
		cout << "Invalid: gross pay must not be negative.";
		break;
	}

	cout << "\nFederal Withholding: ";
	cin >> fedTax;
	if (fedTax < 0) {
		cout << "Invalid: federal withholding must not be negative.";
		break;
	}

	cout << "\nState Withholding: ";
	cin >> stateTax;
	if (stateTax < 0) {
		cout << "Invalid: state withholding must not be negative.";
		break;
	}

	cout << "\nFICA Withholding: ";
	cin >> fica;
	if (fica < 0) {
		cout << "Invalid: FICA withholding must not be negative.";
		break;
	}

	grossTotal += grossPay;
	fedTaxTotal += fedTax;
	stateTaxTotal += stateTax;
	ficaTotal += fica;

	cout << "Processing the next employee:" << endl;
	}
	
	return 0;
}