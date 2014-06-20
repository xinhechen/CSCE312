//
//  p2.cpp
//  part12
//
//  Created by Xinhe Chen on 6/8/14.
//  Copyright (c) 2014 Xinhe Chen. All rights reserved.
//
#include "basic_functions.h"
#include "p2.h"
#include "p1.h"
bool* mux(bool* output, bool operation, bool input1[8], bool input2[8])
{
    output[0]=Mux(operation,input1[0],input2[0]);
    output[1]=Mux(operation,input1[1],input2[1]);
    output[2]=Mux(operation,input1[2],input2[2]);
    output[3]=Mux(operation,input1[3],input2[3]);
    output[4]=Mux(operation,input1[4],input2[4]);
    output[5]=Mux(operation,input1[5],input2[5]);
    output[6]=Mux(operation,input1[6],input2[6]);
    output[7]=Mux(operation,input1[7],input2[7]);
    return output;
}
bool* addu(bool* output, bool input1[8], bool input2[8])
{
    output[0]=0;
    output[1]=0;
    output[2]=0;
    output[3]=0;
    output[4]=0;
    output[5]=0;
    output[6]=0;
    output[7]=0;
    output[0]=Sum(input1[0],input2[0]);
    bool carryout=CarryOut(input1[0],input2[0],false);
   
    output[1]=Sum(input1[1],input2[1],carryout);
    carryout=CarryOut(input1[1],input2[1],carryout);
    
    output[2]=Sum(input1[2],input2[2],carryout);
    carryout=CarryOut(input1[2],input2[2],carryout);
   
    output[3]=Sum(input1[3],input2[3],carryout);
    carryout=CarryOut(input1[3],input2[3],carryout);
   
    output[4]=Sum(input1[4],input2[4],carryout);
    carryout=CarryOut(input1[4],input2[4],carryout);
    
    output[5]=Sum(input1[5],input2[5],carryout);
    carryout=CarryOut(input1[5],input2[5],carryout);
    
    output[6]=Sum(input1[6],input2[6],carryout);
    carryout=CarryOut(input1[6],input2[6],carryout);
   
    output[7]=Sum(input1[7],input2[7],carryout);
    return output;
}
bool* negateb(bool* output, bool input[8])
{
    bool temp[8];
    temp[0]=Not(input[0]);
    temp[1]=Not(input[1]);
    temp[2]=Not(input[2]);
    temp[3]=Not(input[3]);
    temp[4]=Not(input[4]);
    temp[5]=Not(input[5]);
    temp[6]=Not(input[6]);
    temp[7]=Not(input[7]);
    bool one[8];
    one[0]=true;
    one[1]=false;
    one[2]=false;
    one[3]=false;
    one[4]=false;
    one[5]=false;
    one[6]=false;
    one[7]=false;
    addu(output,temp,one);
    return output;
}
bool* subu(bool* output, bool input1[8], bool input2[8])
{
    bool* negb=new bool[8];
    negateb(negb,input2);
    addu(output,input1,negb);
    return output;
}
bool equal(bool input1[8], bool input2[8]) //return 0 if two values are different)
{
    bool temp[8];
    temp[0]=Equal(input1[0],input2[0]);
    temp[1]=Equal(input1[1],input2[1]);
    temp[2]=Equal(input1[2],input2[2]);
    temp[3]=Equal(input1[3],input2[3]);
    temp[4]=Equal(input1[4],input2[4]);
    temp[5]=Equal(input1[5],input2[5]);
    temp[6]=Equal(input1[6],input2[6]);
    temp[7]=Equal(input1[7],input2[7]);
    return And(temp[0],And(temp[1],And(temp[2],And(temp[3],And(temp[4],And(temp[5],And(temp[6],temp[7])))))));
}
bool lessthan(bool input1[8], bool input2[8]) //(return 0 if false)
{
    bool* sub=new bool[8];
    subu(sub,input1,input2);
    bool sign=sub[7];
    return And(sign,Not(equal(input1,input2)));
}
bool greaterthan(bool input1[8], bool input2[8]) //(return 0 if false)
{
    bool* sub=new bool[8];
    subu(sub,input1,input2);
    bool opposite=Not(sub[7]);
    return And(opposite,Not(equal(input1,input2)));
}
bool* equal(bool* output, bool input1[8], bool input2[8])// (return 00000001 if two values are the same)
{
    bool e=equal(input1,input2);
    output[0]=e;
    output[1]=0;
    output[2]=0;
    output[3]=0;
    output[4]=0;
    output[5]=0;
    output[6]=0;
    output[7]=0;
    return output;
}
bool* lessthan(bool* output, bool input1[8], bool input2[8]) //(return 00000000 if false)
{
    bool o=lessthan(input1,input2);
    output[0]=o;
    output[1]=0;
    output[2]=0;
    output[3]=0;
    output[4]=0;
    output[5]=0;
    output[6]=0;
    output[7]=0;
    return output;
}
bool* greaterthan(bool* output, bool input1[8], bool input2[8])//(return 00000000 if false)
{
    bool o=greaterthan(input1,input2);
    output[0]=o;
    output[1]=0;
    output[2]=0;
    output[3]=0;
    output[4]=0;
    output[5]=0;
    output[6]=0;
    output[7]=0;
    return output;
    
}
bool* and8(bool* output, bool input1[8], bool input2[8])//(bitwise and)
{
    output[0]=And(input1[0],input2[0]);
    output[1]=And(input1[1],input2[1]);
    output[2]=And(input1[2],input2[2]);
    output[3]=And(input1[3],input2[3]);
    output[4]=And(input1[4],input2[4]);
    output[5]=And(input1[5],input2[5]);
    output[6]=And(input1[6],input2[6]);
    output[7]=And(input1[7],input2[7]);
    return output;
}
bool* or8(bool* output, bool input1[8], bool input2[8])//(bitwise or)
{
    output[0]=Or(input1[0],input2[0]);
    output[1]=Or(input1[1],input2[1]);
    output[2]=Or(input1[2],input2[2]);
    output[3]=Or(input1[3],input2[3]);
    output[4]=Or(input1[4],input2[4]);
    output[5]=Or(input1[5],input2[5]);
    output[6]=Or(input1[6],input2[6]);
    output[7]=Or(input1[7],input2[7]);
    return output;
}
bool* shiftLeft(bool* output, bool input[8])
{
    output[0]=false;
    output[1]=input[0];
    output[2]=input[1];
    output[3]=input[2];
    output[4]=input[3];
    output[5]=input[4];
    output[6]=input[5];
    output[7]=input[6];
    return output;
}
bool* shiftRight(bool* output, bool input[8])
{
    output[0]=input[1];
    output[1]=input[2];
    output[2]=input[3];
    output[3]=input[4];
    output[4]=input[5];
    output[5]=input[6];
    output[6]=input[7];
    output[7]=false;
    return output;
}
