//  LogBase2
//
//  Created by Zanetta  Tyler on 2/3/17.
//  Copyright © 2017 Zanetta  Tyler. All rights reserved.
//

#include <iostream>
using namespace std;

int main(int argc, const char * argv[]) {
    
    int number, log = 0;
    cout << "Enter a number > ";
    cin >> number;
    
    asm{
        
        bsr eax, number;// finds the leftmost 1 bit in eax register
        mov log, eax;// stores the result in log
    
    
    }
    cout<< "The logarithm of "<< number<<" is "<< log <<endl;
    return 0;
}
