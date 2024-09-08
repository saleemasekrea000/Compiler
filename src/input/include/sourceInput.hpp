#ifndef SOURCEINPUT_HPP
#define SOURCEINPUT_HPP


#include <iostream>
#include <string>
using namespace std;
class sourceInput
{
private:
public:
    virtual string takeInput(string file_name) =0; 
};

#endif 
