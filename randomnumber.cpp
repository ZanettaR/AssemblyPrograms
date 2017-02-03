//  RandomNumber
//  Created by Zanetta  Tyler on 1/25/17.
//  Copyright © 2017 Zanetta  Tyler. All rights reserved.


#include <iostream>
using namespace std;

int main(int argc, const char * argv[]) {
    int seed, i,mul = 16807,div=2147483647;
    cout << "Enter the random number seed > ";
    cin >> seed;
    for (i = 0; i < 10000; i++ ) {
        asm {
            // write the following in assembler
            mov eax,seed;//stores seed in eax register
            mov edx,0;//clears the edx register
            imul mul;//edx:eax = seed * 16807
            idiv div;//edx:(seed*16807)%2147483647
            mov seed,edx;//stores the value of edx register in seed
            
        }
    }
    cout << "The 10,000th random number is " << seed << endl;
    if (seed != 1043618065) cout << "incorrect";
    else cout << "Correct!" <<endl;
}
