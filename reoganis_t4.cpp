#include <iostream>
#include <cstring>
using namespace std;
struct weeklyTemp
{
string cityName;
double tempMonday, tempTuesday, tempWednesday, tempThursday, tempFriday, tempSaturday, tempSunday;
double temperature, average;
};

weeklyTemp t1;

int main(){
cout << "Enter City: ";
getline(cin,t1.cityName);
cout << "Enter From Monday to Sunday" << endl;
cin >> t1.tempMonday;
cin >> t1.tempTuesday;
cin >> t1.tempWednesday;
cin >> t1.tempThursday;
cin >> t1.tempFriday;
cin >> t1.tempSaturday;
cin >> t1.tempSunday;

t1.temperature = t1.tempMonday + t1.tempTuesday + t1.tempWednesday + t1.tempThursday + t1.tempFriday + t1.tempSaturday + t1.tempSunday;
t1.average = t1.temperature/7;
cout << "Average Temperature in " << t1.cityName << " is: " << t1.average;



return 0; }
