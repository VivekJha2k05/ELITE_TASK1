#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void writeToFile(const string& filename) {
    ofstream file(filename); // Overwrites if file exists
    if (file.is_open()) {
        file << "This is a file management tool in C++.\n";
        file << "We are writing data to the file.\n";
        file.close();
        cout << "Data written successfully.\n";
    } else {
        cout << "Unable to open file for writing.\n";
    }
}

void appendToFile(const string& filename) {
    ofstream file(filename, ios::app); // Append mode
    if (file.is_open()) {
        file << "Appending a new line to the file.\n";
        file.close();
        cout << "Data appended successfully.\n";
    } else {
        cout << "Unable to open file for appending.\n";
    }
}

void readFromFile(const string& filename) {
    ifstream file(filename);
    string line;
    if (file.is_open()) {
        cout << "Reading file contents:\n";
        while (getline(file, line)) {
            cout << line << endl;
        }
        file.close();
    } else {
        cout << "Unable to open file for reading.\n";
    }
}

int main() {
    string filename = "data.txt";

    int choice;
    do {
        cout << "\nFile Management Tool\n";
        cout << "1. Write to file\n";
        cout << "2. Append to file\n";
        cout << "3. Read from file\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                writeToFile(filename);
                break;
            case 2:
                appendToFile(filename);
                break;
            case 3:
                readFromFile(filename);
                break;
            case 4:
                cout << "Exiting program.\n";
                break;
            default:
                cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 4);

    return 0;
}
