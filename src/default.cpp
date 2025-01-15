#include <iostream>
#include <string>
#include <sstream>
#include <stdexcept>
#include <cmath>
#include "muParser.h"

// Rsil resistor equation
//("9.0e-6/w + 7.0*((b + 1)*l + (1.081*(w+1.0e-8) + 0.18e-6)*b)/(w+1.0e-8))/m"



using namespace std;

void processEquation(int option, const string& equation) {
    // Example of handling different options based on the integer input (0:100)
    switch(option) {
        case 0:
            cout << "Option 0 selected: Resistor value  based on w, l, b, m" << endl;
            cout << "Equation: " << equation << endl;
            try
            {
                double var_w = 1.0e-6;
                double var_l = 1.0e-6;
                double    var_b = 0;
                double    var_m = 1;
                mu::Parser p;
                p.DefineVar("w", &var_w); 
                p.DefineVar("l", &var_l); 
                p.DefineVar("b", &var_b); 
                p.DefineVar("m", &var_m); 
                p.SetExpr(equation);
                double var_res;
                var_res = p.Eval();
                std::cout << var_res << std::endl;
                
            }
            catch (mu::Parser::exception_type &e)
            {
                std::cout << e.GetMsg() << std::endl;
            }
            break;
        case 1:
            cout << "Option 1 selected: Evaluating simple math equation." << endl;
            // Very basic evaluation for demonstration purposes (only addition and subtraction)
            // This is a naive example, use a more robust expression evaluator for complex cases
            try {
                double result;
                stringstream eqStream(equation);
                eqStream >> result;
                cout << "Result of equation: " << result << endl;
            } catch(const exception& e) {
                cout << "Error evaluating equation: " << e.what() << endl;
            }
            break;
        case 2:
            cout << "Option 2 selected: Equation length check." << endl;
            cout << "Equation length: " << equation.length() << endl;
            break;
        case 3:
            cout << "Option 3 selected: Equation in uppercase." << endl;
            break;
        default:
            cout << "Option " << option << " is not recognized." << endl;
    }
}

int main(int argc, char* argv[]) {
    if (argc != 3) {
        cerr << "Usage: " << argv[0] << " <option (0:100)> <equation>" << endl;
        return 1;
    }

    int option = stoi(argv[1]);  // Convert first argument to an integer
    string equation = argv[2];   // The second argument is the equation (string)

    if (option < 0 || option > 100) {
        cerr << "Error: Option must be between 0 and 100." << endl;
        return 1;
    }

    // Process the equation based on the option
    processEquation(option, equation);

    return 0;
}
