#include <iostream>
using namespace std;

//user defined functions
void inputGrades();
void summaryofGrades();
void summaryofpassingGrades();
void summaryoffailingGrades();
void searchValues();

    int gradeNumber = 10;
    int passingScore = 70;
    int grades[10];
    int passingGrades[10];
    int failingGrades[10];

//function to input 10 grade values
void inputGrades()
{
    cout<<"Enter 10 Grade Values"<< endl;
    
    for (int i = 0; i < 10; i++)
    {
        do {
            cin >> grades[i];
            
            if (grades[i] < 0 || grades [i] > 100)
            {
                cout <<"Error Message: Invalid Grade. Grade must be 0-100 only."<< endl;
            }
        } while (grades[i] < 0 || grades [i] > 100);
    }
}

//function to display summary of grades
void summaryofGrades()
{
    cout<<"Summary of Grades"<<endl;
    for (int i = 0; i < gradeNumber; ++i){
        cout<< grades[i]<<" ";
    }
}

//function to display summary of passing grades
void summaryofpassingGrades()
{
    cout<<"Summary of Passing Grades"<<endl;
    for (int i = 0; i < gradeNumber; ++i){
        if (grades[i] > passingScore){
            cout<<"Grade "<<i+1<< ": "<<grades[i]<<endl;
        }
    }
}

//function to display summary of failing grades
void summaryoffailingGrades()
{
    cout<<"Summary of Failing Grades"<<endl;
    for (int i = 0; i < gradeNumber; ++i){
        if (grades[i] < passingScore){
            cout<<"Grade "<<i+1<< ": "<<grades[i]<<endl;
        }
    }
}

//function to search grades
void searchValues(){
    int searchGrade;
    cout<<"Search Value: ";
    cin>>searchGrade;
    
    bool found = false;
    for (int i = 0; i < gradeNumber; ++i){
    
        if (grades[i] == searchGrade){
            found = true;
            break;
        }
    }
    cout << "Result: " << (found ? "Found" : "Not Found")<<endl;
}

//main menu
int main() {
    inputGrades();
    
    int option;
    
    do{
        cout<<endl<<"MENU"<<endl;
        cout<<"[1] Summary of Grades"<<endl;
        cout<<"[2] Summary of Passing Grades"<<endl;
        cout<<"[3] Summary of Failing Grades"<<endl;
        cout<<"[4] Search Grade"<<endl;
        cout<<"[5] Re-Enter Grades"<<endl;
        cout<<"Option: ";
        cin>>option;
       
        switch(option) {
     
            case 1:
                summaryofGrades();
                break;
            case 2:
                summaryofpassingGrades();
                break;
            case 3 :
                summaryoffailingGrades();
                break;
            case 4 :
                searchValues();
                break;
            case 5 :
                inputGrades();
                break;
            default: 
            cout<<"Invalid Option. Please Try Again"<<endl;
        }
    } while (option != 0);
    
    return 0;
}
