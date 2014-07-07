//
//  p6.cpp
//  CSCE312
//
//  Created by Xinhe Chen on 6/22/14.
//  Copyright (c) 2014 Xinhe Chen. All rights reserved.
//
#include "basic_functions.h"
#include "p1.h"
#include "p2.h"
#include "p3.h"
#include "p4.h"
#include "p5.h"
#include "p6.h"
#include "test_utils.h"



bool registry[16][8];
bool instructionMemory[256][8];
bool dataMemory[16][8];
bool PC[8];
bool IR[32];

void initialize()
{
    for(int x=0;x<16;x++)
    {
        for(int y=0;y<8;y++)
        {
            registry[x][y]=false;
            dataMemory[x][y]=false;
        }
    }
    
    for(int x=0;x<256;x++)
    {
        for(int y=0;y<8;y++)
        {
            instructionMemory[x][y]=false;
        }
    }
    
    for(int x=0;x<16;x++)
    {
        for(int y=0;y<8;y++)
        {
            instructionMemory[x][y]=false;
        }
    }

    for(int x=0;x<8;x++)
        {
            PC[x]=false;
        }

    for(int x=0;x<16;x++)
    {
        IR[x]={false};
    }
}

int toDecimal(bool registerNum[8])
{
    int value=1*registerNum[0]+2*registerNum[1]+4*registerNum[2]+8*registerNum[3]+16*registerNum[4]+32*registerNum[5]+64*registerNum[6]+128*registerNum[7];
    return value;
}
bool* getRegistryValue(bool* output, bool registerNum[8])
{
    int decimal=toDecimal(registerNum);

        output[0]=registry[decimal][0];
        output[1]=registry[decimal][1];
        output[2]=registry[decimal][2];
        output[3]=registry[decimal][3];
        output[4]=registry[decimal][4];
        output[5]=registry[decimal][5];
        output[6]=registry[decimal][6];
        output[7]=registry[decimal][7];
  
    return output;
}
void setRegistryValue(bool registerNum[8], bool value[8])
{
    int decimal=toDecimal(registerNum);

    if(decimal!=0)
    {
        registry[decimal][0]=value[0];
        registry[decimal][1]=value[1];
        registry[decimal][2]=value[2];
        registry[decimal][3]=value[3];
        registry[decimal][4]=value[4];
        registry[decimal][5]=value[5];
        registry[decimal][6]=value[6];
        registry[decimal][7]=value[7];
    }
}

void incrementPC()
{
    bool increment[8];
    increment[0]=false;
    increment[1]=false;
    increment[2]=true;
    increment[3]=false;
    increment[4]=false;
    increment[5]=false;
    increment[6]=false;
    increment[7]=false;
    bool temp[8];
    add(temp,PC,increment);
    PC[0]=temp[0];
    PC[1]=temp[1];
    PC[2]=temp[2];
    PC[3]=temp[3];
    PC[4]=temp[4];
    PC[5]=temp[5];
    PC[6]=temp[6];
    PC[7]=temp[7];
    
}

void addPC(bool addressOffset[8])
{
   
    bool temp[8];
    add(temp,PC,addressOffset);
    PC[0]=temp[0];
    PC[1]=temp[1];
    PC[2]=temp[2];
    PC[3]=temp[3];
    PC[4]=temp[4];
    PC[5]=temp[5];
    PC[6]=temp[6];
    PC[7]=temp[7];
}

void instructionFetch()
{
    int pc=toDecimal(PC);
    IR[24]=instructionMemory[pc][0];
    IR[25]=instructionMemory[pc][1];
    IR[26]=instructionMemory[pc][2];
    IR[27]=instructionMemory[pc][3];
    IR[28]=instructionMemory[pc][4];
    IR[29]=instructionMemory[pc][5];
    IR[30]=instructionMemory[pc][6];
    IR[31]=instructionMemory[pc][7];
    
    
    IR[16]=instructionMemory[pc+1][0];
    IR[17]=instructionMemory[pc+1][1];
    IR[18]=instructionMemory[pc+1][2];
    IR[19]=instructionMemory[pc+1][3];
    IR[20]=instructionMemory[pc+1][4];
    IR[21]=instructionMemory[pc+1][5];
    IR[22]=instructionMemory[pc+1][6];
    IR[23]=instructionMemory[pc+1][7];


    IR[8]=instructionMemory[pc+2][0];
    IR[9]=instructionMemory[pc+2][1];
    IR[10]=instructionMemory[pc+2][2];
    IR[11]=instructionMemory[pc+2][3];
    IR[12]=instructionMemory[pc+2][4];
    IR[13]=instructionMemory[pc+2][5];
    IR[14]=instructionMemory[pc+2][6];
    IR[15]=instructionMemory[pc+2][7];
    

    IR[0]=instructionMemory[pc+3][0];
    IR[1]=instructionMemory[pc+3][1];
    IR[2]=instructionMemory[pc+3][2];
    IR[3]=instructionMemory[pc+3][3];
    IR[4]=instructionMemory[pc+3][4];
    IR[5]=instructionMemory[pc+3][5];
    IR[6]=instructionMemory[pc+3][6];
    IR[7]=instructionMemory[pc+3][7];
}

void parseInstructionInIR(bool* name,
                          bool* reg_out,
                          bool* reg_in1,
                          bool* reg_in2,
                          bool* imm16)
{
    bool rtype=Not(Or(false,Or(IR[31],Or(IR[30],Or(IR[29],Or(IR[28],Or(IR[27],IR[26])))))));
    
    if(rtype)
    {
        reg_in1[7]=false;
        reg_in1[6]=false;
        reg_in1[5]=false;
        reg_in1[4]=IR[25];
        reg_in1[3]=IR[24];
        reg_in1[2]=IR[23];
        reg_in1[1]=IR[22];
        reg_in1[0]=IR[21];
        
        reg_in2[7]=false;
        reg_in2[6]=false;
        reg_in2[5]=false;
        reg_in2[4]=IR[20];
        reg_in2[3]=IR[19];
        reg_in2[2]=IR[18];
        reg_in2[1]=IR[17];
        reg_in2[0]=IR[16];
        
        reg_out[7]=false;
        reg_out[6]=false;
        reg_out[5]=false;
        reg_out[4]=IR[15];
        reg_out[3]=IR[14];
        reg_out[2]=IR[13];
        reg_out[1]=IR[12];
        reg_out[0]=IR[11];
        
        
        name[0]=IR[0];
        name[1]=IR[1];
        name[2]=IR[2];
        name[3]=IR[3];
        name[4]=IR[4];
        name[5]=IR[5];
        name[6]=false;
        name[7]=false;
    }
    else
    {
        name[0]=IR[26];
        name[1]=IR[27];
        name[2]=IR[28];
        name[3]=IR[29];
        name[4]=IR[30];
        name[5]=IR[31];
        name[6]=false;
        name[7]=false;
        
        reg_out[0]=IR[16];
        reg_out[1]=IR[17];
        reg_out[2]=IR[18];
        reg_out[3]=IR[19];
        reg_out[4]=IR[20];
        reg_out[5]=false;
        reg_out[6]=false;
        reg_out[7]=false;
        
        imm16[0]=IR[0];
        imm16[1]=IR[1];
        imm16[2]=IR[2];
        imm16[3]=IR[3];
        imm16[4]=IR[4];
        imm16[5]=IR[5];
        imm16[6]=IR[6];
        imm16[7]=IR[7];
        imm16[8]=IR[8];
        imm16[9]=IR[9];
        imm16[10]=IR[10];
        imm16[11]=IR[11];
        imm16[12]=IR[12];
        imm16[13]=IR[13];
        imm16[14]=IR[14];
        imm16[15]=IR[15];
        
    }
}

// Load instructions from an input file stream.
// You may use any C++ provided features to implement this function.
void initializeInstructionMemory(std::ifstream& fp)
{
    //if (fp.is_open())
    //{
      //  std::string word;
        //int count=0;
        //while (fp >> word)
        //{
          //  getInstructionValue(instructionMemory[count], word);
            //count++;
            //instructionMemory[count]=atoi(word.c_str());
            
        //}
        
        //fp.close();
   // }
}

// Convert the name of an instruction (e.g. addu, lw) into its 8bit op code.
// You may use any C++ provided features to implement this function.
bool* getInstructionValue(bool* output, const std::string& instructionName)
{
    bool adder[8];
    adder[0]=true;
    adder[1]=false;
    adder[2]=false;
    adder[3]=false;
    adder[4]=false;
    adder[5]=false;
    adder[6]=false;
    adder[7]=false;
    
    output[0]=false;
    output[1]=false;
    output[2]=false;
    output[3]=false;
    output[4]=false;
    output[5]=false;
    output[6]=false;
    output[7]=false;
    int name=instructionName.compare("ADD");
    if(name==0)
        return output;
    add(output,output,adder);
    
    name=instructionName.compare("SUB");
    if(name==0)
        return output;
    add(output,output,adder);
    
    name=instructionName.compare("NEG");
    if(name==0)
        return output;
    add(output,output,adder);
    
    name=instructionName.compare("EQ");
    if(name==0)
        return output;
    add(output,output,adder);
    
    name=instructionName.compare("LT");
    if(name==0)
        return output;
    add(output,output,adder);
    
    name=instructionName.compare("GT");
    if(name==0)
        return output;
    add(output,output,adder);
    
    name=instructionName.compare("AND");
    if(name==0)
        return output;
    add(output,output,adder);
    
    name=instructionName.compare("OR");
    if(name==0)
        return output;
    add(output,output,adder);
    
    name=instructionName.compare("SLL");
    if(name==0)
        return output;
    add(output,output,adder);
    
    name=instructionName.compare("SRL");
    if(name==0)
        return output;
    add(output,output,adder);
    
    name=instructionName.compare("MULTU");
    if(name==0)
        return output;
    add(output,output,adder);
    
    name=instructionName.compare("MULT");
    if(name==0)
        return output;
    add(output,output,adder);
    
    name=instructionName.compare("DIVU");
    if(name==0)
        return output;
    add(output,output,adder);
    
    name=instructionName.compare("DIV");
    if(name==0)
        return output;
    add(output,output,adder);
    
    name=instructionName.compare("LW");
    if(name==0)
        return output;
    add(output,output,adder);
    
    name=instructionName.compare("SW");
    if(name==0)
        return output;
    add(output,output,adder);
    
    name=instructionName.compare("ADDU");
    if(name==0)
        return output;
    add(output,output,adder);
    
    name=instructionName.compare("SUBU");
    if(name==0)
        return output;

    return output;
}

// Read or write memory.
//
// When read is true and write is false, read the byte at the indicated memory
// location to the register indexed by registerNum.
//
// When write is true and read is false, write the content of the register
// indexed by registerNum to the indicated memory location.
//
// read and write should never be the same value.
//
// You may use if..else.. in mem() to choose from calling lw() or sw().
void mem(bool registerNum[8], bool memlocation[16], bool read, bool write)
{
    if(read==true)
        lw(registerNum,memlocation);
    else
        sw(registerNum,memlocation);
}
void lw(bool registerNum[8], bool memlocation[16])
{
    int regnum=toDecimal(registerNum);
    int memloc=toDecimal(memlocation);
    registry[regnum][0]=dataMemory[memloc][0];
    registry[regnum][1]=dataMemory[memloc][1];
    registry[regnum][2]=dataMemory[memloc][2];
    registry[regnum][3]=dataMemory[memloc][3];
    registry[regnum][4]=dataMemory[memloc][4];
    registry[regnum][5]=dataMemory[memloc][5];
    registry[regnum][6]=dataMemory[memloc][6];
    registry[regnum][7]=dataMemory[memloc][7];
}
void sw(bool registerNum[8], bool memlocation[16])
{
    int regnum=toDecimal(registerNum);
    int memloc=toDecimal(memlocation);
    dataMemory[memloc][0]=registry[regnum][0];
    dataMemory[memloc][1]=registry[regnum][1];
    dataMemory[memloc][2]=registry[regnum][2];
    dataMemory[memloc][3]=registry[regnum][3];
    dataMemory[memloc][4]=registry[regnum][4];
    dataMemory[memloc][5]=registry[regnum][5];
    dataMemory[memloc][6]=registry[regnum][6];
    dataMemory[memloc][7]=registry[regnum][7];
}

// The following functions are helpers to mem(), lw(), and sw(). They will also
// make P7 easier.
//
// You may use if..else.. in readOrWriteMem() to choose from calling readMem()
// or writeMem().
void readOrWriteMem(bool value[8], bool memlocation[8], bool read, bool write)
{
    if(read==true)
        readMem(value,memlocation);
    else
        writeMem(value,memlocation);
    
}
void readMem(bool value[8], bool memlocation[16])
{
    
}
void writeMem(bool value[8], bool memlocation[16])
{
    
}
