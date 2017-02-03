//  LogBase
//  Created by Zanetta  Tyler on 1/24/17.
//  Copyright © 2017 Zanetta  Tyler. All rights reserved.


#include <iostream>
using namespace std;

int main(int argn, char *argv[]) {
    
    int number, log;
    cout << "Enter a number > ";
    cin >> number;
    
    asm {
        
        // Calculate the log2 of number and store the result in log
        mov eax,number;
        
        //Create a while loop
    again:
        shr eax,1;//shift right once
        inc log;//increment log value
        cmp eax,1;//compare the stored value to 1
        jle endloop;//if it is less than or equal to 1 end while
        
        jmp again;//otherwise continue loop
        
    endloop:
        
    }
    //Prints log value
    cout << "The logarithm is " << log << endl;
}
