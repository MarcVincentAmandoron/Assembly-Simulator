#include <iostream>
#include <queue>
#include <fstream>
#include <iomanip>
#include <ostream>
#include <sstream>

#define file "Programming-Project-1.txt"

using namespace std;

void doProblems(queue<string>, queue<uint32_t>);
void solveProblem(queue<string>, queue<uint32_t>);

template<typename T>
string hexConversion(T);


int main() {
    queue<string> operations;
    queue<uint32_t> operands;

    doProblems(operations, operands);

    return 0;
}

//Getting the operation required and the operands for each operation and saving them via queue
//Calls to solveProblem to iterate through the queues and perform the operations saved in the operations queue
void doProblems(queue<string> operations, queue<uint32_t> operands){
    string operation;
    uint32_t operand1, operand2;
    ifstream problemData(file);
    if(problemData.is_open()){
        while(problemData.good()){
            problemData >> operation >> hex >> operand1 >> hex >> operand2;
            operations.push(operation);
            operands.push(operand1);
            operands.push(operand2);
        }
        solveProblem(operations, operands);
    }
    else{
        cout << "Could not open file" << endl;
    }
}

//Solving the problem by popping the operands and operation save in the queue
//Outputting the correct syntax required for the project using string stream and io manipulators
void solveProblem(queue<string> operations, queue<uint32_t> operands){
    string operation;
    uint32_t operand1, operand2;
    string op1, op2, sol;
    while(!operations.empty()){
        operation = operations.front();
        operations.pop();
        operand1 = operands.front();
        operands.pop();
        operand2 = operands.front();
        operands.pop();
        if(operation == "ADD"){
            cout << operation << setw(12) << hexConversion(operand1) << setw(12) <<  hexConversion(operand2) << ": " << hexConversion(operand1+operand2) << endl;

        }
    }
}

//Using a string stream we can convert an integer into a string and append it to the 0x hex identifier. This makes it easier to use io manipulators
template<typename T>
string hexConversion(T i){
    stringstream stream;
    stream << "0x" << setfill('0') << setw(sizeof(T)*2) << hex << i;
    return stream.str();

}