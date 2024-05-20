#include <iostream>
#include <string>
using namespace std;

struct gradesRecord {
    int grade;
    gradesRecord* next;
};

void createRecord();
void addGrades();
void updateGrades();
void searchGrades();
void deleteGrades();
void displayGrades();

gradesRecord* head = nullptr;

int main() {
    int option;
    while (true) {
        cout<<"GRADING SYSTEM" << endl;
        cout<<"[1] CREATE RECORD" << endl;
        cout<<"[2] ADD"<< endl;
        cout<<"[3] UPDATE"<< endl;
        cout<<"[4] SEARCH"<< endl;
        cout<<"[5] DELETE"<< endl;
        cout<<"[6] DISPLAY"<< endl;
        cout<<"Option: ";
        cin>>option;

        switch (option) {
            case 1:
                createRecord();
                break;
            case 2:
                addGrades();
                break;
            case 3:
                updateGrades();
                break;
            case 4:
                searchGrades();
                break;
            case 5:
                deleteGrades();
                break;
            case 6:
                displayGrades();
                break;
            default:
                cout << "Invalid option. Please choose again.\n";
        }
    }
    return 0;
}

void createRecord() {
    int numRecords;
    cout << "Number of Records: ";
    cin >> numRecords;
    for (int i = 0; i < numRecords; ++i) {
        gradesRecord* newRecords = new gradesRecord;
        cout << "Enter Grade: ";
        string input;
        cin >> input;
        newRecords->grade = stoi(input);
        newRecords->next = head;
        head = newRecords;
    }
    cout << "**Display Message**\nRecord has been created successfully.\n";
}

void addGrades() {
    gradesRecord* current = head;
    while (current->next != nullptr) {
        current = current->next;
    }
    gradesRecord* newRecords = new gradesRecord;
    cout << "Add New Grade: ";
    string input;
    cin >> input;
    newRecords->grade = stoi(input);
    newRecords->next = nullptr;
    current->next = newRecords;
    cout << "**Display Message**\nNew record has been added successfully.\n";
}

void updateGrades() {
    int searchGrade;
    cout << "Enter Grade to Update: ";
    cin >> searchGrade;
    gradesRecord* current = head;
    while (current != nullptr) {
        if (current->grade == searchGrade) {
            cout << "New Grade: ";
            string input;
            cin >> input;
            current->grade = stoi(input);
            cout << "**Display Message**\nRecord has been updated successfully.\n";
            return;
        }
        current = current->next;
    }
    cout << "**Display Message**\nRecord not found.\n";
}

void searchGrades() {
    int searchGrade;
    cout << "Search Grade: ";
    cin >> searchGrade;
    gradesRecord* current = head;
    while (current != nullptr) {
        if (current->grade == searchGrade) {
            cout << "**Display Message**\nRecord found.\n";
            return;
        }
        current = current->next;
    }
    cout << "**Display Message**\nRecord not found.\n";
}

void deleteGrades() {
    int deleteGrade;
    cout << "Enter Grade to Delete: ";
    cin >> deleteGrade;
    gradesRecord* current = head;
    gradesRecord* prev = nullptr;
    while (current != nullptr) {
        if (current->grade == deleteGrade) {
            if (prev != nullptr) {
                prev->next = current->next;
            } else {
                head = current->next;
            }
            delete current;
            cout << "**Display Message**\nThe grade has been deleted successfully.\n";
            return;
        }
        prev = current;
        current = current->next;
    }
    cout << "**Display Message**\nRecord not found.\n";
}

void displayGrades() {
    cout << "Summary of Grades: ";
    gradesRecord* current = head;
    while (current != nullptr) {
        cout << current->grade << " ";
        current = current->next;
    }
    cout << endl;
}