#include <iostream>
#include <string>
#include "input/input.cpp"
using namespace std;

int main(int argc, char const *argv[])
{
    cout<<"Hello "<<endl;
    string input = parse_input(argc, argv);
    cout << input << endl;
    return 0;

}