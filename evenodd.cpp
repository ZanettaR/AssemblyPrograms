//  EvenOdd
//  Created by Zanetta  Tyler on 1/25/17.
//  Copyright © 2017 Zanetta  Tyler. All rights reserved.



#include <iostream>
using namespace std;

int main(int argc, const char * argv[]) {
    int number, mod = 2;
    char evenodd, odd = 'O', even = 'E';
    
    cout << "Enter a number > "<<endl;
    cin>>number;
    asm {
        mov eax,number;//store number in eax register
        mov edx,0;//clear edx register
        idiv mod;//get the remainder of number/2
        cmp edx,0;//compare remainder to 0
        jne noteq;//remainder != 0 jump to noteq
        mov al,even;//remainder == 0 then store 'E' in al register
        jmp after;//remainder == 0 jump to after
    noteq:
        mov al,odd;//Store 'O' in al register
        mov evenodd,al;//move 'O' to evenodd
    after:
        mov evenodd,al;//move 'E' to evenodd
    
    }
    
    if (number == 0){cout<<"Neither Even Nor Odd"<<endl;}
    else{cout<<"The number "<<number<<" is " << evenodd<<endl;}
}
