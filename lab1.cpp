/* Author: Ariane Doris Umuhire
 Date: 08-29-2025
 Description: This code takes data from a seperate file or user input and
organizes the list using the ID of customers and employees to
match their transaction data history.
*/
#include <iostream>
#include <iomanip>
#include <string>
#include <stdio.h>
using namespace std;
struct Employee {
 int ID;
 string name;
};
struct Customer {
 int ID;
 double balance;
 string name;
};
int main()
{
 Employee emp[50];
 Customer cus[50];
 int empCount = 0;
 int cusCount = 0;
 char type;
 cout << "************* Transaction Information *************" << endl;
 cout << left << setw(12) << "Customer" << left << setw(12) << "Employee";
 cout << right << setw(12) << "Amount" << right << setw(12) << "Balance" <<
endl;
 cout << "___________________________________________________" << endl;
 while(cin >> type) { // reads the first char in each line to know what type
 if(type == 'e') {
 cin >> emp[empCount].ID >> emp[empCount].name;
 ++empCount;
 // read employee data and store it in the employee array
 }
 else if(type == 'c') {
 cin >> cus[cusCount].ID >> cus[cusCount].name >> cus[cusCount].balance;
 ++cusCount;
 // read customer data and store it in the customer array
 }
 else if(type == 't') {
 int custID, empID;
 char transType;
 double amount;
 int i, j;
 cin >> custID >> empID >> transType >> amount;
 Customer* custPtr2 = nullptr;
 for(i = 0; i < cusCount; ++i) {
 if (cus[i].ID == custID) { // match transaction to customer
 custPtr2 = &cus[i]; // point to and save address of customer ID
 break;
 }
 }
 string empName;
 for(j = 0; j < empCount; ++j) {
 if(emp[j].ID == empID) { // match transaction to employee
 empName = emp[j].name;
 break;
 }
 }
 if (custPtr2) {
 if(transType == 'w') {
 (*custPtr2).balance = (*custPtr2).balance - amount;
 cout << left << setw(12) << (*custPtr2).name << left <<
setw(12) << empName << right << setw(6) << "-$" << amount;
 }
 else if(transType == 'd') {
 (*custPtr2).balance = (*custPtr2).balance + amount;
 cout << left << setw(12) << (*custPtr2).name << left <<
setw(12) << empName << right << setw(6) << "+$" << amount;
 }
 }
 cout << "$ " << setw(9) << fixed << setprecision(2) <<
(*custPtr2).balance << endl;
 }
 else {
 cout << "Invalid Data Type. Try Again" << endl << endl;
 }
 }
 return 0;
}

