#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    // Open the input file
    ifstream inputFile;
    inputFile.open("people.txt");

    // Check if the file opened successfully
    if (!inputFile) {
        cout << "Error opening file 'people.txt'. Make sure it is in the correct folder." << endl;
        return 1;
    }

    // Display the chart header
    cout << "PRAIRIEVILLE POPULATION GROWTH" << endl;
    cout << "(each * represents 1000 people)" << endl << endl;

    int population;

    // Loop through each of the 20-year intervals from 1910 to 2010
    for (int year = 1910; year <= 2010; year += 20) {
        // Read the population figure from the file
        if (inputFile >> population) {
            // Display the year
            cout << year << " ";

            // Calculate the number of asterisks needed (1 asterisk per 1,000 people)
            int asterisks = population / 1000;

            // Loop to print the asterisks for the current year
            for (int i = 0; i < asterisks; i++) {
                cout << "*";
            }

            // Move to the next line for the next year
            cout << endl;
        } else {
            cout << "Error: Missing data in file for year " << year << endl;
            break;
        }
    }

    // Close the file
    inputFile.close();

    return 0;
}
