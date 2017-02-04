//  GCD
//
//  Created by Zanetta  Tyler on 2/3/17.
//  Copyright © 2017 Zanetta  Tyler. All rights reserved.
//

#include <iostream>
using namespace std;

int main(int argc, const char * argv[]) {
    int u, v, gcd = 1, k = 0, t = 0;
    cout << "Enter u and v values > ";
    cin >> u >> v;
    int beginu = u;
    int beginv = v;
    asm{
    again:
        mov eax, u; // eax = u
        mov ebx, v; // ebx = v
        cmp eax, 1; // is eax == 1?
        je uisodd;  // if eax == 1 then jump to u is odd
        cmp ebx, 1; // is ebx == 1?
        je visodd;  // if ebx == 1 then jump to v is odd
        shr eax, 0; // store last bit and check to see if the last bit is a zero
        and eax, 1;
        cmp eax, 0;
        jne uisodd; // if not 0 the u is odd
        shr ebx,0;  // store last bit and check to see if the last bit is a zero
        and ebx,1;
        cmp ebx, 0;
        jne visodd; // if not 0 the v is odd
        jmp last;   // else jump to last
    last:
        
        mov eax, u; // store u into eax
        mov ebx, v; // store v into ebx
        sar eax,1;  // eax = eax/2
        sar ebx, 1; // ebx = ebx/2
        mov u, eax; // u = eax
        mov v, ebx; // v = ebx
        inc k;      // k = k+1
        jmp again;  // jump to again
    uisodd:
        mov ebx, v;
        neg ebx;    // negate the value of ebx (-v)
        mov t, ebx; // t = -v
        jmp tiseven;// jump to t is even
    visodd:
        mov eax, u;
        mov t, eax; // t = u
        jmp halft;// jump to half t
    halft:
        mov eax, t; // eax = t
        sar eax,1;  // eax = eax/2
        mov t, eax; // t = eax
        jmp tiseven;// jump to t is even
    tiseven:
        mov eax, t; // eax = t
        shr eax,0;  // check the last bit to see if t is even or odd
        and eax,1;
        cmp eax, 0;
        je halft;   // jump to half t if even
        jmp reset;  // otherwise jump to reset
    reset:
        cmp t, 0;   // check to see if t equals 0
        jg maxedu;  // if greater than zero jump to maxedu
        jmp maxedv; // otherwise jump to maxedv
    maxedu:
        mov eax, t; // eax = t
        mov u, eax; // u = t
        jmp subtraction; // jump to subtraction
    maxedv:
        mov eax, t; //eax = t
        neg eax;    // eax = -eax
        mov v,eax;  // v = eax
        jmp subtraction; // jump to subtraction
    subtraction:
        mov eax, u; // eax = u
        mov ebx, v; // ebx = v
        sub eax,ebx;// eax = u - t
        mov t, eax; // t = u - t
        cmp t, 0; // check to see if t is 0
        je endloop; // jump to the end
        jmp halft; // jump to half t
   
    endloop:
        
    }
    
    //Calculates the GCD
    if(k == 0){
        gcd = 1;
    }else{
        for(int i = 0; i < k; i++ ){
            gcd *= 2;
        }
        
    }
    gcd = u * gcd;
    cout<< "The Greatest Common Divisor of " << beginu << " and "<< beginv << " is " << gcd<<endl;
    return 0;
}
