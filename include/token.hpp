
#include <string>

using namespace std;

enum TokenType {
    KEYWORD,
    IDENTIFIER,
    INTEGER_LITERAL,
    REAL_LITERAL,
    OPERATOR,
    ERROR,
    LPAR,
    RPAR,
    LBRAC,
    RBRAC,

};

class Token {

    
public:
	string type;
	string content;
    Token(){}
    Token(string t, const string& v)
        : type(t)
        , content(v)
    {
    }
     operator string() const {
        return type + " " + content + "\n";
    }
};

