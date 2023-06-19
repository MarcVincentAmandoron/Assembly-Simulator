Author: Marc Amandoron

Project: CS219 Project 1

My code utilizes a queue to save the file contents. Each operand is saved in a queue of type uint32_t, unsigned 32 bit int, while the string preceding the operands are saved in a queue of type string. Right now the code 
only implements ADD function. To solve the problem, I just perform
the corresponding operation with the two unsigned integers saved in the queue before moving on to the next set of operations and operands.
This continues until the queue containing the operations is empty. 

In order to use the program run the executable. If it states that you are not authorized to run the executable use 'chmod u+x (executableName)' so you can run it.
Makefile is included in the folder as well. 



Problem 1 (0x1+0x1): output is correct with no overflow occurring.

Problem 2 (0xaaa5555+0xfffffff): output is correct with no overflow occurring.

Problem 3 (0xFFFFFFFF+0x1): output is correct with overflow occurring. There is a carry of 1 that is lost due to 32 bit size limit.

Problem 4 (0x1234+0x8765): output is correct with no overflow occurring.

Problem 5 (0x72DF9901+0x2E0B484A): output is correct with no overflow occurring.