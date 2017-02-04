//
//  main.cpp
//  EorO
//
//  Created by Zanetta  Tyler on 2/3/17.
//  Copyright © 2017 Zanetta  Tyler. All rights reserved.
//

#include <iostream>
using namespace std;

int main(int argc, const char * argv[]) {
    int number;
    char eoro = 'e';
    cout << "Enter A Number > ";
    cin >> number;
    
    asm{
        
        mov eax, number;
        shr eax, 0;
        and eax, 1;
        cmp eax, 0;
        je even;
        jmp odd;
    even:
        mov eoro, 'e';
        jmp endloop;
    odd:
        mov eoro , 'o';
        jmp endloop;
    endloop:
        
    }
    
    cout << "The number "<<number<< " is "<< eoro<<endl;
    
    return 0;
}
