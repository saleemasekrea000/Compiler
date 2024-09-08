#include <string>
#include "terminalInput.cpp"
#include "fileInput.cpp"
using namespace std;

class inputFactory
{
private:
public:
        static sourceInput* createInput(int argNumber){
            if (argNumber == 2) {
                return new terminalInput();
            }
            else if (argNumber == 3) {
                return new fileInput();
            }
            else {
                return nullptr;
            }
        }
};

