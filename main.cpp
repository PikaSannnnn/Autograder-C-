// Change to 0 to TURN OFF fail outputs, 1 to TURN ON fail outputs
#define FAIL_OUT 1
// Change to 1 to read from custom_inputs.txt
#define CUSTOM_IN 0

// DO NOT EDIT BELOW THIS
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <ctime>
#include "solution.h"    // This file may contain duplicate libraries

struct tester {
    std::ifstream sample_input;
    tester() {
        std::stringstream file;
        sample_input.open("unit_tests/unit_tests.txt");
        
        std::streambuf *cinbuf = std::cin.rdbuf();
        std::cin.rdbuf(sample_input.rdbuf());
    }
};

int main(int argc, char** argv) { // edit ONLY if smain() contains new parameters
    if (CUSTOM_IN) {
        smain();
        // smain(argc, argv);
        return CUSTOM_IN;
    }
    
    std::stringstream solution_output;
    static tester utest = tester();
    int num_cases = 0;
    std::cin >> num_cases;
    
    std::cout << "==== Running Test Cases ====" << std::endl;

    int num_correct = 0;
    for (size_t i = 0; i < num_cases; i++) {
        std::stringstream test_file;
        test_file << "unit_tests/" << i << ".txt";
        std::ifstream test_outputs(test_file.str());
        bool correct = true;
        solution_output.str("");    // clears last print
        
        // capture output
        std::cout << ">>>>> Case " << i << std::endl;
        std::streambuf* stdout = std::cout.rdbuf(solution_output.rdbuf()); 

        // run solutions
        smain();
        // smain(argc, argv);
        
        std::cout.rdbuf(stdout);
    
        // Compare With Test Cases (Reading through output)        
        char x, y;
        std::string u_out = "";
        // std::string t_out = "";
        while (solution_output.get(x) && test_outputs.get(y)) {
            u_out.push_back(x);
            // t_out.push_back(y);
            if (x != y) {
                correct = false;
                break;
            }
        }
        
        int line = 0, ch = -1;
        if (solution_output.get(x) || !test_outputs.eof()) {    // false finish
            if (FAIL_OUT) {
                for (int i = u_out.size() - 1; i >= 0; i--) {
                    if (u_out[i] == '\n') { line++; }    // get line position
                    else if (line == 0) { ch++; }    // get char position
                }
            }
            correct = false;
        }

        // Result Output
        if (correct) {
            std::cout << "\tRESULT: PASSED" << std::endl;
            num_correct++;
        }
        else {
            std::cout << "\tRESULT: FAILED" << std::endl;
            if (FAIL_OUT) {
                std::cout << "\t\tYour Output:" << std::endl;
                std::cout << "~~~~~~~~~~~~~~~~~~~~~~~\n";
                std::cout << solution_output.str() << std::endl;
                std::cout << "~~~~~~~~~~~~~~~~~~~~~~~\n";

                std::cout << "\tMismatch: First appeared on line " << line 
                        << ", char " << ((ch > 0) ? ch : 0) 
                        << std::endl << std::endl;
            }
        }

        solution_output.str("");
        solution_output.clear();
        test_outputs.clear();
        test_outputs.close();
    }

    std::cout << "=======================" << std::endl;
    std::cout << "Total Cases: " << num_cases << std::endl;
    std::cout << "Cases Passed: " << num_correct << std::endl;
    std::cout << "=======================" << std::endl;

    return CUSTOM_IN;
} 
