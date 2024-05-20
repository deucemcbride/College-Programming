#include <iostream>
#include <cstring>


using namespace std;

int main()
{
    string word;
    
    cout << "Enter a word: ";
    cin >> word;
    cout << "Original String: " << word << endl;
    cout << "New String: ";
    for (char character : word){
        if (character == 'z' && 'Z'){
        cout << 'a';
        }else{
        character++;
        cout << character;}
    }
    return 0;
}

        