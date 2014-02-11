#include <iostream>

using namespace std;

int main (int argc, char* argv[])
{
    cout << "There are " << argc - 1<< " arguments" << endl;
    
    for (int i = 1; i <= argc; i++)
        cout << argv[i] << endl;
    
    return 0;
}
