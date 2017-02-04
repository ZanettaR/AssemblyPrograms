//  CPUModel
//
//  Created by Zanetta  Tyler on 2/3/17.
//  Copyright © 2017 Zanetta  Tyler. All rights reserved.
//

#include <iostream>
using namespace std;

int main(int argc, const char * argv[]) {
    int cores;//number of cores in cpu
    string model;//model of CPU
    char arrayC[49];
    
    asm{
        mov eax, 11;        // eax = 11
        mov ebx, 0;         // ebx = 0
        mov ecx, 1;         // ecx = 1
        mov edx, 0;         // edx = 0
        cpuid;              // execute cpuid instruction
        shr ecx, 8;         // shift ecx right 8 bits
        and ecx, 255;       // moves every other bit
        cmp ecx, 0;         // compare ecx bits 8-15 to 0
        je after;           // jump to after if equal to zero
        jmp after2;         // otherwise jump to after2
    after:
        mov eax, 1;         // eax = 1
        mov ebx,0;          // ebx = 0
        mov ecx,0;          // ecx = 0
        mov edx,0;          // edx = 0
        cpuid;              // execute cpuid instruction
        shr ebx, 16;        // shift ebx right 16 bits
        and ebx,16711680;   // moves every other bit
        mov ebx,ecx;        // saves the number of cores in ebx bits 16-23
        mov cores,ebx;      // stores ebx register in variable cores
    after2:
        mov edx, ecx;       // saves the number of cores in edx register
        mov cores,edx;      // stores edx register in variable cores
    }
    
    cout<<"There are "<< cores <<" cores."<<endl;
    
    asm{
        lea rsi,arrayC;         // rsi = arrayC address
        mov eax, 0x80000002;    // eax = 0x80000002
        cpuid                   // execute cpuid instruction
        
        
                                /* 16 byte character string is stored in
                                   eax, ebx, ecx, and edx registers. Stores
                                   the character values into the char array
                                   bits 1 - 16.
                                */
        mov 0[rsi], eax;
        mov 4[rsi], ebx;
        mov 8[rsi], ecx;
        mov 12[rsi], edx;
        
        
        mov eax, 0x80000003;    // eax = 0x80000003
        cpuid                   // execute cpuid instruction
        
                                /* 16 byte character string is stored in
                                   eax, ebx, ecx, and edx registers. Stores
                                   the character values into the char array
                                   bits 17 - 32.
                                */
        mov 16[rsi], eax;
        mov 20[rsi], ebx;
        mov 24[rsi], ecx;
        mov 28[rsi], edx;
        
        mov eax, 0x80000004;    // eax = 0x80000004
        cpuid                   // execute cpuid instruction
       
                                /* 16 byte character string is stored in
                                   eax, ebx, ecx, and edx registers. Stores
                                   the character values into the char array
                                   bits 33 - 48.
                                */
        mov 32[rsi], eax;
        mov 36[rsi], ebx;
        mov 40[rsi], ecx;
        mov 44[rsi], edx;
        
        
        mov eax,0x00000000;     // eax = 0
        mov 48[rsi], eax;       // stores a 0 in the 49th byte to terminate the string

    }
    
    for(int i = 0; i < 49; i++){
        model += arrayC[i];
    }
    cout<< "The model is a(n) "<< model <<endl;
    return 0;
}
