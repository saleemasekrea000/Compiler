#include <string>
#include <stdexcept>
#include "inputFactory.cpp"
using namespace std;

string parse_input(int argc, char const *argv[]){
    if (argc < 2) {
        throw invalid_argument("Not enough arguments you should provide terminal or file then file_name");
    } 
    if  (argc > 3) {
        throw invalid_argument("Too much arguments you should provide terminal or file then file_name");
    }
    sourceInput* input = inputFactory::createInput(argc);
    if (input == nullptr) {
        throw invalid_argument("Invalid input type");
    }
    cout << "input type is " << argv[1] << endl;
    string file_name = "terminal";
    if (argc == 3) {
        file_name = argv[2];
    }
    
    return input->takeInput(file_name);
}