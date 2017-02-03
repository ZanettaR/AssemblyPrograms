//  BitCopy
//  Created by Zanetta  Tyler on 1/25/17.
//  Copyright © 2017 Zanetta  Tyler. All rights reserved.

#include <iostream>
using namespace std;

int main(int argc, const char * argv[]) {
    int stuff, good;
    cout << "Enter a number greater than 2048 > ";
    cin >> stuff;
    
    asm {
        mov eax,stuff;//moves stuff to eax register
        shr eax,11;//shifts eax right 11
        and eax, 15;//moves every other bit
        mov good,eax;//stores eax value in good
    
    }
    // put bits 11 through 14 of stuff into good using assembler
    cout << "bits 11 – 14 are " << good << endl;
}
