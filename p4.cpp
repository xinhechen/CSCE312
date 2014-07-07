//
//  p4.cpp
//
#include <iostream>
#include <stdexcept>
#include "basic_functions.h"
#include "p2.h"
#include "p1.h"
#include "p3.h"
#include "p4.h"
using namespace std;
bool* add(bool* output, bool input1[8], bool input2[8])
{
    bool carryout=CarryOut(input1[0],input2[0],false);
    output[0]=Sum(input1[0],input2[0]);
    
    bool next_carryout=CarryOut(input1[1],input2[1],carryout);
    output[1]=Sum(input1[1],input2[1],carryout);
    carryout = next_carryout;
    
    next_carryout=CarryOut(input1[2],input2[2],carryout);
    output[2]=Sum(input1[2],input2[2],carryout);
    carryout = next_carryout;
    
    next_carryout=CarryOut(input1[3],input2[3],carryout);
    output[3]=Sum(input1[3],input2[3],carryout);
    carryout = next_carryout;
    
    next_carryout=CarryOut(input1[4],input2[4],carryout);
    output[4]=Sum(input1[4],input2[4],carryout);
    carryout = next_carryout;
    
    next_carryout=CarryOut(input1[5],input2[5],carryout);
    output[5]=Sum(input1[5],input2[5],carryout);
    carryout = next_carryout;
    
    next_carryout=CarryOut(input1[6],input2[6],carryout);
    output[6]=Sum(input1[6],input2[6],carryout);
    carryout = next_carryout;
    
    next_carryout=CarryOut(input1[7],input2[7],carryout);
    output[7]=Sum(input1[7],input2[7],carryout);
    carryout = next_carryout;
    
    bool overflow = Or(And(And(input1[7], input2[7]), Not(output[7])),
                       And(And(Not(input1[7]), Not(input2[7])), output[7]));
    if(overflow)
        throw "overflow";
    return output;
    
    
}
bool* sub(bool* output, bool input1[8], bool input2[8])
{
    bool* negb=new bool[8];
    negateb(negb,input2);
    add(output,input1,negb);
    return output;
    
}
