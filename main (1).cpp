#include <iostream>
#include <cmath>

using namespace std;
int firstnumber;
int secondnumber;
int powernumber;
int modulonumber;


void
inputtwonumbers ()
{
  cout << "Enter a number: ";
  cin >> firstnumber;
  cout << "Enter another number: ";
  cin >> secondnumber;
}


int
main ()
{
  inputtwonumbers ();

  int option;
  do
    {
      cout << "[1] Sum" << endl;
      cout << "[2] Difference" << endl;
      cout << "[3] Product" << endl;
      cout << "[4] Quotient" << endl;
      cout << "[5] Modulo" << endl;
      cout << "[6] Power" << endl;
      cout << "Choose a calculation: " << endl;
      cin >> option;

      switch (option)
	{
	case 1:
	  cout << "The answer is: " << firstnumber + secondnumber << endl;
	  break;
	case 2:
	  cout << "The answer is: " << firstnumber - secondnumber << endl;
	  break;
	case 3:
	  cout << "The answer is: " << firstnumber * secondnumber << endl;
	  break;
	case 4:
	  cout << "The answer is: " << firstnumber / secondnumber << endl;
	  break;
	case 5:
	  cout << "The answer is: " << firstnumber % secondnumber << endl;
	  break;
	case 6:
	  powernumber = pow(firstnumber, secondnumber);
	  cout << "The answer is: " << powernumber << endl;
	  break;
	default:
	  cout << "Invalid input" << endl;
	}

    }
  while (option != 0);

}
