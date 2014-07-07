//
//  p3.cpp
//  CSCE312
//Let 0 (00000000) = ADD
//Let 1 (00000001)= SUB
//Let 2 (00000010)= NEG
//Let 3 (00000011)= EQ
//Let 4 (00000100)= LT
//Let 5 (00000101)= GT
//Let 6 (00000110)= AND
//Let 7 (00000111)= OR
//Let 8 (00001000)= SLL
//Let 9 (00001001)= SRL
//Let 10 (00001010)= MULTU
//Let 11 (00001011)= MULT
//Let 12 (00001100)= DIVU
//Let 13 (00001101)= DIV
//Let 16 (00010000)= ADDU
//Let 17 (00010001)= SUBU


#include "basic_functions.h"
#include "p2.h"
#include "p1.h"
#include "p3.h"
#include "p4.h"
#include "p5.h"
#include "p6.h"
bool* mux16(bool* output, bool operation, bool input1[16], bool input2[16])
{
    output[0]=Mux(operation,input1[0],input2[0]);
    output[1]=Mux(operation,input1[1],input2[1]);
    output[2]=Mux(operation,input1[2],input2[2]);
    output[3]=Mux(operation,input1[3],input2[3]);
    output[4]=Mux(operation,input1[4],input2[4]);
    output[5]=Mux(operation,input1[5],input2[5]);
    output[6]=Mux(operation,input1[6],input2[6]);
    output[7]=Mux(operation,input1[7],input2[7]);
    output[8]=Mux(operation,input1[8],input2[8]);
    output[9]=Mux(operation,input1[9],input2[9]);
    output[10]=Mux(operation,input1[10],input2[10]);
    output[11]=Mux(operation,input1[11],input2[11]);
    output[12]=Mux(operation,input1[12],input2[12]);
    output[13]=Mux(operation,input1[13],input2[13]);
    output[14]=Mux(operation,input1[14],input2[14]);
    output[15]=Mux(operation,input1[15],input2[15]);
    return output;
}
bool* alu(bool op_code[8], bool* output, bool input1[8], bool input2[8])
{
    
    bool temp[8];
    temp[0]=0;
    temp[1]=0;
    temp[2]=0;
    temp[3]=0;
    temp[4]=0;
    temp[5]=0;
    temp[6]=0;
    temp[7]=0;
    bool overflow = false;
    bool* x=new bool[8];
    bool addfxn=equal(op_code,temp);
    
    try {
        add(x,input1,input2);
    } catch (...) {
        if (addfxn)
            overflow = true;
    }
    mux(output,addfxn,x,output);//ADD=0(00000000)
    
    temp[0]=1;
    bool subfxn=equal(op_code,temp);
    
    try {
        sub(x,input1,input2);
    } catch (...) {
        if (subfxn)
            overflow = true;
    }
    mux(output,subfxn,x,output);  //SUB=1(00000001)
    
    temp[0]=0;
    temp[1]=1;
    bool negfxn=equal(op_code,temp);
    negateb(x,input1);
    mux(output,negfxn,x,output); //NEG=2(00000010)
    
    temp[0]=1;
    bool eqfxn=equal(op_code,temp);
    equal(x,input1,input2);
    mux(output,eqfxn,x,output); //EQ=3(00000011)
    
    temp[2]=1;
    temp[1]=0;
    temp[0]=0;
    bool ltfxn=equal(op_code,temp);
    lessthan(x,input1,input2);
    mux(output,ltfxn,x,output); //LT=4(00000100)
    
    temp[0]=1;
    bool gtfxn=equal(op_code,temp);
    greaterthan(x,input1,input2);
    mux(output,gtfxn,x,output); //GT=5(00000101)
    
    temp[0]=0;
    temp[1]=1;
    bool andfxn=equal(op_code,temp);
    and8(x,input1,input2);
    mux(output,andfxn,x,output); //AND=6(00000110)
    
    temp[0]=1;
    bool orfxn=equal(op_code,temp);
    or8(x,input1,input2);
    mux(output,orfxn,x,output); //OR=7(00000111)
    
    temp[3]=1;
    temp[2]=0;
    temp[1]=0;
    temp[0]=0;
    
    bool sllfxn=equal(op_code,temp);
    shiftLeft(x,input1);
    mux(output,sllfxn,x,output);
    shiftLeft(x,x);
    mux(output,sllfxn,x,output);//SLL=8(00001000)
    
    temp[0]=1;
    bool srlfxn=equal(op_code,temp);
    shiftRight(x,input1);
    mux(output,srlfxn,x,output);
    shiftRight(x,x);
    mux(output,srlfxn,x,output);//SRL=9(00001001)
    
    temp[0]=0;
    temp[1]=1;
    bool multufxn=equal(op_code,temp);
    multu(x,input1,input2);
    mux16(output,multufxn,x,output); //MULTU=10(00001010)
    
    temp[0]=1;
    bool multfxn=equal(op_code,temp);
    mult(x,input1,input2);
    mux16(output,multfxn,x,output); //MULT=11(00001011)
    
    temp[2]=1;
    temp[1]=0;
    temp[0]=0;
    bool divufxn=equal(op_code,temp);
    divu(x,input1,input2);
    mux16(output,divufxn,x,output); //DIV=12(00001100)
    
    temp[0]=1;
    bool divfxn=equal(op_code,temp);
    div(x,input1,input2);
    mux16(output,divfxn,x,output); //DIVU=13(00001101)
    
    temp[4]=1;
    temp[3]=0;
    temp[2]=0;
    temp[1]=0;
    temp[0]=0;
    bool addufxn=equal(op_code,temp);
    addu(x,input1,input2);
    mux(output,addufxn,x,output); //ADDU=16(00010000)
    
    temp[0]=1;
    bool subufxn=equal(op_code,temp);
    subu(x,input1,input2);
    mux(output,subufxn,x,output); //SUBU=17(00010001)
    
    
    if (overflow)
        throw "overflow";
    
    return output;
    
    
}
