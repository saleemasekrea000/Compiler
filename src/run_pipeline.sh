echo "Running lexer tests..."
cd lexer  
./run_lexer_tests.sh 
cd .. 

echo "Running syntax analysis..."
cd parser  
./run_syntax_analysis.sh  
cd .. 