#include <iostream>

using namespace std;
int main()
{

    int inputnumber[10];
    int findnumber = 0;
    int num;
    
    cout<<"Enter 10 input numbers: "<<endl;

    for (int i = 0; i < 10; i++)
    {
        cin >> inputnumber[i];
    }
    
    cout<<"Find number: ";
    cin>> findnumber;
    
    for (int i = 0; i < 10; i++)
    {
        if (inputnumber[i] == findnumber)
        {
            num++;
        }
    }
    
    cout << findnumber << " Appeared " << num << " times";
    return 0;
}