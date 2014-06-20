//
//  p5.cpp
//
#include "basic_functions.h"
#include "p2.h"
#include "p1.h"
#include "p3.h"
#include "p4.h"
#include "p5.h"
#include "test_utils.h"
#include <iostream>
using namespace std;
bool greaterthan16(bool input1[16], bool input2[16])//(return 0 if false)
{
    bool* sub=new bool[16];
    bool* temp=new bool[16];
    negate16(temp, input2);
    add16(sub,temp,input1);
    bool opposite=Not(sub[15]);
    return opposite;
}
bool* shiftLeft16(bool* output, bool input[16])
{
    
    output[15]=input[14];
    output[14]=input[13];
    output[13]=input[12];
    output[12]=input[11];
    output[11]=input[10];
    output[10]=input[9];
    output[9]=input[8];
    output[8]=input[7];
    output[7]=input[6];
    output[6]=input[5];
    output[5]=input[4];
    output[4]=input[3];
    output[3]=input[2];
    output[2]=input[1];
    output[1]=input[0];
    output[0]=false;
    return output;
}
bool* shiftRight16(bool* output, bool input[16])
{
    
    output[0]=input[1];
    output[1]=input[2];
    output[2]=input[3];
    output[3]=input[4];
    output[4]=input[5];
    output[5]=input[6];
    output[6]=input[7];
    output[7]=input[8];
    output[8]=input[9];
    output[9]=input[10];
    output[10]=input[11];
    output[11]=input[12];
    output[12]=input[13];
    output[13]=input[14];
    output[14]=input[15];
    output[15]=false;
    return output;
}
bool* add16(bool* output, bool input1[16], bool input2[16])
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
    
    next_carryout=CarryOut(input1[8],input2[8],carryout);
    output[8]=Sum(input1[8],input2[8],carryout);
    carryout = next_carryout;
    
    next_carryout=CarryOut(input1[9],input2[9],carryout);
    output[9]=Sum(input1[9],input2[9],carryout);
    carryout = next_carryout;
    
    next_carryout=CarryOut(input1[10],input2[10],carryout);
    output[10]=Sum(input1[10],input2[10],carryout);
    carryout = next_carryout;
   
    next_carryout=CarryOut(input1[11],input2[11],carryout);
    output[11]=Sum(input1[11],input2[11],carryout);
    carryout = next_carryout;
   
    next_carryout=CarryOut(input1[12],input2[12],carryout);
    output[12]=Sum(input1[12],input2[12],carryout);
    carryout = next_carryout;
    
    next_carryout=CarryOut(input1[13],input2[13],carryout);
    output[13]=Sum(input1[13],input2[13],carryout);
    carryout = next_carryout;
    
    next_carryout=CarryOut(input1[14],input2[14],carryout);
    output[14]=Sum(input1[14],input2[14],carryout);
    carryout = next_carryout;
   
    next_carryout=CarryOut(input1[15],input2[15],carryout);
    output[15]=Sum(input1[15],input2[15],carryout);
    
    
    return output;
}

bool* negate16(bool* output, bool input[16])
{
    bool temp[16];
    temp[0]=Not(input[0]);
    temp[1]=Not(input[1]);
    temp[2]=Not(input[2]);
    temp[3]=Not(input[3]);
    temp[4]=Not(input[4]);
    temp[5]=Not(input[5]);
    temp[6]=Not(input[6]);
    temp[7]=Not(input[7]);
    temp[8]=Not(input[8]);
    temp[9]=Not(input[9]);
    temp[10]=Not(input[10]);
    temp[11]=Not(input[11]);
    temp[12]=Not(input[12]);
    temp[13]=Not(input[13]);
    temp[14]=Not(input[14]);
    temp[15]=Not(input[15]);
    
    
    bool one[16];
    one[0]=true;
    one[1]=false;
    one[2]=false;
    one[3]=false;
    one[4]=false;
    one[5]=false;
    one[6]=false;
    one[7]=false;
    one[8]=false;
    one[9]=false;
    one[10]=false;
    one[11]=false;
    one[12]=false;
    one[13]=false;
    one[14]=false;
    one[15]=false;
    
    add16(output,temp,one);
    return output;
}

bool* multu(bool* output, bool input1[8], bool input2[8])
{
    bool temp[8];
    temp[0]=input2[0];
    temp[1]=input2[0];
    temp[2]=input2[0];
    temp[3]=input2[0];
    temp[4]=input2[0];
    temp[5]=input2[0];
    temp[6]=input2[0];
    temp[7]=input2[0];
    
    bool* one=new bool[8];
    and8(one,temp,input1);
    
    bool a[16];
    a[15]=false;
    a[14]=false;
    a[13]=false;
    a[12]=false;
    a[11]=false;
    a[10]=false;
    a[9]=false;
    a[8]=false;
    a[7]=one[7];
    a[6]=one[6];
    a[5]=one[5];
    a[4]=one[4];
    a[3]=one[3];
    a[2]=one[2];
    a[1]=one[1];
    a[0]=one[0];
    
    
    temp[0]=input2[1];
    temp[1]=input2[1];
    temp[2]=input2[1];
    temp[3]=input2[1];
    temp[4]=input2[1];
    temp[5]=input2[1];
    temp[6]=input2[1];
    temp[7]=input2[1];
    bool* two=new bool[8];
    and8(two,temp,input1);
    bool b[16];
    b[15]=false;
    b[14]=false;
    b[13]=false;
    b[12]=false;
    b[11]=false;
    b[10]=false;
    b[9]=false;
    b[8]=false;
    b[7]=two[7];
    b[6]=two[6];
    b[5]=two[5];
    b[4]=two[4];
    b[3]=two[3];
    b[2]=two[2];
    b[1]=two[1];
    b[0]=two[0];
    shiftLeft16(b, b);
    add16(output, a,b);
  
    
    temp[0]=input2[2];
    temp[1]=input2[2];
    temp[2]=input2[2];
    temp[3]=input2[2];
    temp[4]=input2[2];
    temp[5]=input2[2];
    temp[6]=input2[2];
    temp[7]=input2[2];
    bool* three=new bool[8];
    and8(three,temp,input1);
    a[15]=false;
    a[14]=false;
    a[13]=false;
    a[12]=false;
    a[11]=false;
    a[10]=false;
    a[9]=false;
    a[8]=false;
    a[7]=three[7];
    a[6]=three[6];
    a[5]=three[5];
    a[4]=three[4];
    a[3]=three[3];
    a[2]=three[2];
    a[1]=three[1];
    a[0]=three[0];
    
    shiftLeft16(a,a);
    shiftLeft16(a,a);
    add16(output,output,a);


    temp[0]=input2[3];
    temp[1]=input2[3];
    temp[2]=input2[3];
    temp[3]=input2[3];
    temp[4]=input2[3];
    temp[5]=input2[3];
    temp[6]=input2[3];
    temp[7]=input2[3];
    bool* four=new bool[8];
    and8(four,temp,input1);
    a[15]=false;
    a[14]=false;
    a[13]=false;
    a[12]=false;
    a[11]=false;
    a[10]=false;
    a[9]=false;
    a[8]=false;
    a[7]=four[7];
    a[6]=four[6];
    a[5]=four[5];
    a[4]=four[4];
    a[3]=four[3];
    a[2]=four[2];
    a[1]=four[1];
    a[0]=four[0];
    shiftLeft16(a,a);
    shiftLeft16(a,a);
    shiftLeft16(a,a);
    add16(output,output,a);
 
    
    temp[0]=input2[4];
    temp[1]=input2[4];
    temp[2]=input2[4];
    temp[3]=input2[4];
    temp[4]=input2[4];
    temp[5]=input2[4];
    temp[6]=input2[4];
    temp[7]=input2[4];
    bool* five=new bool[8];
    and8(five,temp,input1);
    a[15]=false;
    a[14]=false;
    a[13]=false;
    a[12]=false;
    a[11]=false;
    a[10]=false;
    a[9]=false;
    a[8]=false;
    a[7]=five[7];
    a[6]=five[6];
    a[5]=five[5];
    a[4]=five[4];
    a[3]=five[3];
    a[2]=five[2];
    a[1]=five[1];
    a[0]=five[0];
    shiftLeft16(a,a);
    shiftLeft16(a,a);
    shiftLeft16(a,a);
    shiftLeft16(a,a);
    add16(output,output,a);
    
    temp[0]=input2[5];
    temp[1]=input2[5];
    temp[2]=input2[5];
    temp[3]=input2[5];
    temp[4]=input2[5];
    temp[5]=input2[5];
    temp[6]=input2[5];
    temp[7]=input2[5];
    bool* six=new bool[8];
    and8(six,temp,input1);
    a[15]=false;
    a[14]=false;
    a[13]=false;
    a[12]=false;
    a[11]=false;
    a[10]=false;
    a[9]=false;
    a[8]=false;
    a[7]=six[7];
    a[6]=six[6];
    a[5]=six[5];
    a[4]=six[4];
    a[3]=six[3];
    a[2]=six[2];
    a[1]=six[1];
    a[0]=six[0];
    shiftLeft16(a,a);
    shiftLeft16(a,a);
    shiftLeft16(a,a);
    shiftLeft16(a,a);
    shiftLeft16(a,a);
    add16(output,output,a);
    
    temp[0]=input2[6];
    temp[1]=input2[6];
    temp[2]=input2[6];
    temp[3]=input2[6];
    temp[4]=input2[6];
    temp[5]=input2[6];
    temp[6]=input2[6];
    temp[7]=input2[6];
    bool* seven=new bool[8];
    and8(seven,temp,input1);
    a[15]=false;
    a[14]=false;
    a[13]=false;
    a[12]=false;
    a[11]=false;
    a[10]=false;
    a[9]=false;
    a[8]=false;
    a[7]=seven[7];
    a[6]=seven[6];
    a[5]=seven[5];
    a[4]=seven[4];
    a[3]=seven[3];
    a[2]=seven[2];
    a[1]=seven[1];
    a[0]=seven[0];
    shiftLeft16(a,a);
    shiftLeft16(a,a);
    shiftLeft16(a,a);
    shiftLeft16(a,a);
    shiftLeft16(a,a);
    shiftLeft16(a,a);
    add16(output,output,a);
    
    temp[0]=input2[7];
    temp[1]=input2[7];
    temp[2]=input2[7];
    temp[3]=input2[7];
    temp[4]=input2[7];
    temp[5]=input2[7];
    temp[6]=input2[7];
    temp[7]=input2[7];
    bool* eight=new bool[8];
    and8(eight,temp,input1);
    a[15]=false;
    a[14]=false;
    a[13]=false;
    a[12]=false;
    a[11]=false;
    a[10]=false;
    a[9]=false;
    a[8]=false;
    a[7]=eight[7];
    a[6]=eight[6];
    a[5]=eight[5];
    a[4]=eight[4];
    a[3]=eight[3];
    a[2]=eight[2];
    a[1]=eight[1];
    a[0]=eight[0];
    shiftLeft16(a,a);
    shiftLeft16(a,a);
    shiftLeft16(a,a);
    shiftLeft16(a,a);
    shiftLeft16(a,a);
    shiftLeft16(a,a);
    shiftLeft16(a,a);
    add16(output,output,a);
    
    
    return output;
}
bool* mult(bool* output, bool input1[8], bool input2[8])
{
    bool sign1=input1[7];
    bool* neg=new bool[8];
    negateb(neg, input1);
    bool* in1=new bool[8];
    mux(in1,sign1,neg,input1);
    bool sign2=input2[7];
    negateb(neg, input2);
    bool* in2=new bool[8];
    mux(in2, sign2, neg, input2);
    
    
    bool temp[8];
    temp[0]=in2[0];
    temp[1]=in2[0];
    temp[2]=in2[0];
    temp[3]=in2[0];
    temp[4]=in2[0];
    temp[5]=in2[0];
    temp[6]=in2[0];
    temp[7]=in2[0];
    
    bool* one=new bool[8];
    and8(one,temp,in1);
    
    bool a[16];
    a[15]=false;
    a[14]=false;
    a[13]=false;
    a[12]=false;
    a[11]=false;
    a[10]=false;
    a[9]=false;
    a[8]=false;
    a[7]=one[7];
    a[6]=one[6];
    a[5]=one[5];
    a[4]=one[4];
    a[3]=one[3];
    a[2]=one[2];
    a[1]=one[1];
    a[0]=one[0];
    
    
    temp[0]=in2[1];
    temp[1]=in2[1];
    temp[2]=in2[1];
    temp[3]=in2[1];
    temp[4]=in2[1];
    temp[5]=in2[1];
    temp[6]=in2[1];
    temp[7]=in2[1];
    bool* two=new bool[8];
    and8(two,temp,in1);
    bool b[16];
    b[15]=false;
    b[14]=false;
    b[13]=false;
    b[12]=false;
    b[11]=false;
    b[10]=false;
    b[9]=false;
    b[8]=false;
    b[7]=two[7];
    b[6]=two[6];
    b[5]=two[5];
    b[4]=two[4];
    b[3]=two[3];
    b[2]=two[2];
    b[1]=two[1];
    b[0]=two[0];
    shiftLeft16(b, b);
    add16(output, a,b);
    
    
    temp[0]=in2[2];
    temp[1]=in2[2];
    temp[2]=in2[2];
    temp[3]=in2[2];
    temp[4]=in2[2];
    temp[5]=in2[2];
    temp[6]=in2[2];
    temp[7]=in2[2];
    bool* three=new bool[8];
    and8(three,temp,in1);
    a[15]=false;
    a[14]=false;
    a[13]=false;
    a[12]=false;
    a[11]=false;
    a[10]=false;
    a[9]=false;
    a[8]=false;
    a[7]=three[7];
    a[6]=three[6];
    a[5]=three[5];
    a[4]=three[4];
    a[3]=three[3];
    a[2]=three[2];
    a[1]=three[1];
    a[0]=three[0];
    
    shiftLeft16(a,a);
    shiftLeft16(a,a);
    add16(output,output,a);
    
    
    temp[0]=in2[3];
    temp[1]=in2[3];
    temp[2]=in2[3];
    temp[3]=in2[3];
    temp[4]=in2[3];
    temp[5]=in2[3];
    temp[6]=in2[3];
    temp[7]=in2[3];
    bool* four=new bool[8];
    and8(four,temp,in1);
    a[15]=false;
    a[14]=false;
    a[13]=false;
    a[12]=false;
    a[11]=false;
    a[10]=false;
    a[9]=false;
    a[8]=false;
    a[7]=four[7];
    a[6]=four[6];
    a[5]=four[5];
    a[4]=four[4];
    a[3]=four[3];
    a[2]=four[2];
    a[1]=four[1];
    a[0]=four[0];
    shiftLeft16(a,a);
    shiftLeft16(a,a);
    shiftLeft16(a,a);
    add16(output,output,a);
    
    
    temp[0]=in2[4];
    temp[1]=in2[4];
    temp[2]=in2[4];
    temp[3]=in2[4];
    temp[4]=in2[4];
    temp[5]=in2[4];
    temp[6]=in2[4];
    temp[7]=in2[4];
    bool* five=new bool[8];
    and8(five,temp,in1);
    a[15]=false;
    a[14]=false;
    a[13]=false;
    a[12]=false;
    a[11]=false;
    a[10]=false;
    a[9]=false;
    a[8]=false;
    a[7]=five[7];
    a[6]=five[6];
    a[5]=five[5];
    a[4]=five[4];
    a[3]=five[3];
    a[2]=five[2];
    a[1]=five[1];
    a[0]=five[0];
    shiftLeft16(a,a);
    shiftLeft16(a,a);
    shiftLeft16(a,a);
    shiftLeft16(a,a);
    add16(output,output,a);
    
    temp[0]=in2[5];
    temp[1]=in2[5];
    temp[2]=in2[5];
    temp[3]=in2[5];
    temp[4]=in2[5];
    temp[5]=in2[5];
    temp[6]=in2[5];
    temp[7]=in2[5];
    bool* six=new bool[8];
    and8(six,temp,in1);
    a[15]=false;
    a[14]=false;
    a[13]=false;
    a[12]=false;
    a[11]=false;
    a[10]=false;
    a[9]=false;
    a[8]=false;
    a[7]=six[7];
    a[6]=six[6];
    a[5]=six[5];
    a[4]=six[4];
    a[3]=six[3];
    a[2]=six[2];
    a[1]=six[1];
    a[0]=six[0];
    shiftLeft16(a,a);
    shiftLeft16(a,a);
    shiftLeft16(a,a);
    shiftLeft16(a,a);
    shiftLeft16(a,a);
    add16(output,output,a);
    
    temp[0]=in2[6];
    temp[1]=in2[6];
    temp[2]=in2[6];
    temp[3]=in2[6];
    temp[4]=in2[6];
    temp[5]=in2[6];
    temp[6]=in2[6];
    temp[7]=in2[6];
    bool* seven=new bool[8];
    and8(seven,temp,in1);
    a[15]=false;
    a[14]=false;
    a[13]=false;
    a[12]=false;
    a[11]=false;
    a[10]=false;
    a[9]=false;
    a[8]=false;
    a[7]=seven[7];
    a[6]=seven[6];
    a[5]=seven[5];
    a[4]=seven[4];
    a[3]=seven[3];
    a[2]=seven[2];
    a[1]=seven[1];
    a[0]=seven[0];
    shiftLeft16(a,a);
    shiftLeft16(a,a);
    shiftLeft16(a,a);
    shiftLeft16(a,a);
    shiftLeft16(a,a);
    shiftLeft16(a,a);
    add16(output,output,a);
    
    temp[0]=in2[7];
    temp[1]=in2[7];
    temp[2]=in2[7];
    temp[3]=in2[7];
    temp[4]=in2[7];
    temp[5]=in2[7];
    temp[6]=in2[7];
    temp[7]=in2[7];
    bool* eight=new bool[8];
    and8(eight,temp,in1);
    a[15]=false;
    a[14]=false;
    a[13]=false;
    a[12]=false;
    a[11]=false;
    a[10]=false;
    a[9]=false;
    a[8]=false;
    a[7]=eight[7];
    a[6]=eight[6];
    a[5]=eight[5];
    a[4]=eight[4];
    a[3]=eight[3];
    a[2]=eight[2];
    a[1]=eight[1];
    a[0]=eight[0];
    shiftLeft16(a,a);
    shiftLeft16(a,a);
    shiftLeft16(a,a);
    shiftLeft16(a,a);
    shiftLeft16(a,a);
    shiftLeft16(a,a);
    shiftLeft16(a,a);
    add16(output,output,a);
    bool sign=XOR(sign1,sign2);
    bool* neg16=new bool[16];
    negate16(neg16, output);
    mux16(output,sign,neg16,output);
    
    return output;
}






bool* divu(bool* output, bool input1[8], bool input2[8])
{
    
    bool in1[16];
    in1[0]=input1[0];
    in1[1]=input1[1];
    in1[2]=input1[2];
    in1[3]=input1[3];
    in1[4]=input1[4];
    in1[5]=input1[5];
    in1[6]=input1[6];
    in1[7]=input1[7];
    in1[8]=false;
    in1[9]=false;
    in1[10]=false;
    in1[11]=false;
    in1[12]=false;
    in1[13]=false;
    in1[14]=false;
    in1[15]=false;
    
    bool in2[16];
    in2[0]=false;
    in2[1]=false;
    in2[2]=false;
    in2[3]=false;
    in2[4]=false;
    in2[5]=false;
    in2[6]=false;
    in2[7]=false;
    in2[8]=input2[0];
    in2[9]=input2[1];
    in2[10]=input2[2];
    in2[11]=input2[3];
    in2[12]=input2[4];
    in2[13]=input2[5];
    in2[14]=input2[6];
    in2[15]=input2[7];
    
    shiftRight16(in2, in2);
    bool greater=greaterthan16(in1,in2);
    output[7]=greater;
    bool* temp=new bool[16];
    bool* sub=new bool[16];
    negate16(temp,in2);
    add16(sub,temp,in1);
    mux16(in1,greater,sub,in1);
    shiftRight16(in2, in2);
    
    greater=greaterthan16(in1,in2);
    output[6]=greater;
    negate16(temp,in2);
    add16(sub,temp,in1);
    mux16(in1,greater,sub,in1);
    shiftRight16(in2, in2);
    
    greater=greaterthan16(in1,in2);
    output[5]=greater;
    negate16(temp,in2);
    add16(sub,temp,in1);
    mux16(in1,greater,sub,in1);
    shiftRight16(in2, in2);
    
    greater=greaterthan16(in1,in2);
    output[4]=greater;
    negate16(temp,in2);
    add16(sub,temp,in1);
    mux16(in1,greater,sub,in1);
    shiftRight16(in2, in2);
    
    greater=greaterthan16(in1,in2);
    output[3]=greater;
    negate16(temp,in2);
    add16(sub,temp,in1);
    mux16(in1,greater,sub,in1);
    shiftRight16(in2, in2);
    
    greater=greaterthan16(in1,in2);
    output[2]=greater;
    negate16(temp,in2);
    add16(sub,temp,in1);
    mux16(in1,greater,sub,in1);
    shiftRight16(in2, in2);
    
    greater=greaterthan16(in1,in2);
    output[1]=greater;
    negate16(temp,in2);
    add16(sub,temp,in1);
    mux16(in1,greater,sub,in1);
    shiftRight16(in2, in2);
    
    greater=greaterthan16(in1,in2);
    output[0]=greater;
    negate16(temp,in2);
    add16(sub,temp,in1);
    mux16(in1,greater,sub,in1);
    
    output[8]=in1[0];
    output[9]=in1[1];
    output[10]=in1[2];
    output[11]=in1[3];
    output[12]=in1[4];
    output[13]=in1[5];
    output[14]=in1[6];
    output[15]=in1[7];
    return output;
}





bool* div(bool* output, bool input1[8], bool input2[8])
{
    
    bool sign1=input1[7];
    bool* neg=new bool[8];
    negateb(neg, input1);
    bool* inp1=new bool[8];
    mux(inp1,sign1,neg,input1);
    bool sign2=input2[7];
    negateb(neg, input2);
    bool* inp2=new bool[8];
    mux(inp2, sign2, neg, input2);
    
    bool in1[16];
    in1[0]=inp1[0];
    in1[1]=inp1[1];
    in1[2]=inp1[2];
    in1[3]=inp1[3];
    in1[4]=inp1[4];
    in1[5]=inp1[5];
    in1[6]=inp1[6];
    in1[7]=inp1[7];
    in1[8]=false;
    in1[9]=false;
    in1[10]=false;
    in1[11]=false;
    in1[12]=false;
    in1[13]=false;
    in1[14]=false;
    in1[15]=false;
    
    bool in2[16];
    in2[0]=false;
    in2[1]=false;
    in2[2]=false;
    in2[3]=false;
    in2[4]=false;
    in2[5]=false;
    in2[6]=false;
    in2[7]=false;
    in2[8]=inp2[0];
    in2[9]=inp2[1];
    in2[10]=inp2[2];
    in2[11]=inp2[3];
    in2[12]=inp2[4];
    in2[13]=inp2[5];
    in2[14]=inp2[6];
    in2[15]=inp2[7];
    
    shiftRight16(in2, in2);
    bool greater=greaterthan16(in1,in2);
    output[7]=greater;
    bool* temp=new bool[16];
    bool* sub=new bool[16];
    negate16(temp,in2);
    add16(sub,temp,in1);
    mux16(in1,greater,sub,in1);
    shiftRight16(in2, in2);
    
    greater=greaterthan16(in1,in2);
    output[6]=greater;
    negate16(temp,in2);
    add16(sub,temp,in1);
    mux16(in1,greater,sub,in1);
    shiftRight16(in2, in2);
    
    greater=greaterthan16(in1,in2);
    output[5]=greater;
    negate16(temp,in2);
    add16(sub,temp,in1);
    mux16(in1,greater,sub,in1);
    shiftRight16(in2, in2);
    
    greater=greaterthan16(in1,in2);
    output[4]=greater;
    negate16(temp,in2);
    add16(sub,temp,in1);
    mux16(in1,greater,sub,in1);
    shiftRight16(in2, in2);
    
    greater=greaterthan16(in1,in2);
    output[3]=greater;
    negate16(temp,in2);
    add16(sub,temp,in1);
    mux16(in1,greater,sub,in1);
    shiftRight16(in2, in2);
    
    greater=greaterthan16(in1,in2);
    output[2]=greater;
    negate16(temp,in2);
    add16(sub,temp,in1);
    mux16(in1,greater,sub,in1);
    shiftRight16(in2, in2);
    
    greater=greaterthan16(in1,in2);
    output[1]=greater;
    negate16(temp,in2);
    add16(sub,temp,in1);
    mux16(in1,greater,sub,in1);
    shiftRight16(in2, in2);
    
    greater=greaterthan16(in1,in2);
    output[0]=greater;
    negate16(temp,in2);
    add16(sub,temp,in1);
    mux16(in1,greater,sub,in1);
    
    output[8]=in1[0];
    output[9]=in1[1];
    output[10]=in1[2];
    output[11]=in1[3];
    output[12]=in1[4];
    output[13]=in1[5];
    output[14]=in1[6];
    output[15]=in1[7];
    
    bool sign=XOR(sign1,sign2);
    bool* neg16=new bool[16];
    bool quotient[8];
    quotient[0]=output[0];
    quotient[1]=output[1];
    quotient[2]=output[2];
    quotient[3]=output[3];
    quotient[4]=output[4];
    quotient[5]=output[5];
    quotient[6]=output[6];
    quotient[7]=output[7];
    negateb(quotient, quotient);
    
    bool remainder[8];
    remainder[0]=output[8];
    remainder[1]=output[9];
    remainder[2]=output[10];
    remainder[3]=output[11];
    remainder[4]=output[12];
    remainder[5]=output[13];
    remainder[6]=output[14];
    remainder[7]=output[15];
    printValue(remainder);
    negateb(remainder,remainder);
    
    neg16[0]=quotient[0];
    neg16[1]=quotient[1];
    neg16[2]=quotient[2];
    neg16[3]=quotient[3];
    neg16[4]=quotient[4];
    neg16[5]=quotient[5];
    neg16[6]=quotient[6];
    neg16[7]=quotient[7];
    neg16[8]=remainder[0];
    neg16[9]=remainder[1];
    neg16[10]=remainder[2];
    neg16[11]=remainder[3];
    neg16[12]=remainder[4];
    neg16[13]=remainder[5];
    neg16[14]=remainder[6];
    neg16[15]=remainder[7];
    
    mux16(output,sign,neg16,output);
    
    return output;
}
