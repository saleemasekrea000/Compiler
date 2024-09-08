#include <iostream>
#include <string>
#include "../input/include/sourceInput.hpp"
#include <fstream> 
using namespace std;
class fileInput : public sourceInput
{
private:
public:
    string takeInput(string file_name)override{
        ifstream file(file_name);
    if (!file.is_open()) {
        return "Error: Unable to open file.";
    }

    string content((istreambuf_iterator<char>(file)), istreambuf_iterator<char>());
    file.close();
    return content;

    }

};
