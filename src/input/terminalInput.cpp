#include <iostream>
#include <string>
#include "../input/include/sourceInput.hpp"
using namespace std;
class terminalInput : public sourceInput
{
private:
public:
     string takeInput(string file_name) override{
         string input;
        cout << "Please enter input from terminal" << endl;
        getline(cin, input);
        return input;
    }
 
};

