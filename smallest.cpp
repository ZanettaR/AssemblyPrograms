//  Smallest
//
//  Created by Zanetta  Tyler on 2/1/17.
//  Copyright © 2017 Zanetta  Tyler. All rights reserved.
//

#include <iostream>
using namespace std;

int main(int argn, char *argv[]) {
    int smallest, i, arrayA[8];
    cout << "Enter 8 numbers" << endl;
    for (i = 0; i < 8; i++) {
        cin >> arrayA[i];
    }
    smallest = arrayA[0];// initializes smallest to the first value in the array
    asm{
        
        lea rsi, arrayA;// rsi = arrayA address
        mov ebx, 8;// start loop counter at 8 to work backwards
        mov eax, [rsi];// store first value in the array in eax
        add rsi, 4;// increment rsi to the next element
        
    forloop:
        mov eax, [rsi];// move second value in the array into eax
        add rsi, 4;// increment rsi to the next element
        sub ebx, 1;// subtract one from loop counter
        cmp eax, smallest;// compare eax value to smallest
        jl after;// jump to after if less than
        jge after2;// jump to after2 if greater than or equal to
        
    after:
        mov smallest,eax; // store eax value into smallest
        cmp ebx, 1;// compare counter loop to 1
        jg forloop;// if greater than 1 jump to forloop
        jle endloop;// if less than or equal to 1 end the loop
    after2:
        cmp ebx, 1;// compare counter loop to 1
        jg forloop;// if greater than 1 jump to forloop
        jle endloop;// if less than or equal to 1 end the loop
    endloop:
        
        
        
    }
    cout << "The smallest value is " << smallest << endl;
    return 0;
}
