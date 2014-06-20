#include <iostream>
#include "basic_functions.h"
using namespace std;
int functionCount=0;
bool And(bool a, bool b)
{
    functionCount++;
    return a&&b;
}

bool Or (bool a, bool b)
{
    functionCount++;
    return a||b;
}

bool Not(bool a)
{
    functionCount++;
    return !a;
}

void printFunctionCount()
{
    cout<<"the function count is "<<functionCount<<"\n";
}

void print(bool a)
{
    cout<<a<<"\n";
}
void resetFunctionCount()
{
    functionCount=0;
}



bool getValue(bool byte[8], int offset)
{
    bool value=byte[offset];
    return value;
}

void writeValue(bool* byte, int offset, bool value)
{
    byte[offset]=value;
}

void printValue(bool byte[8])
{
    cout<<byte[7]<<byte[6]<<byte[5]<<byte[4]<<byte[3]<<byte[2]<<byte[1]<<byte[0]<<'\n';
}

void printValueInDecimal(bool byte[8])
{
    int value=1*byte[0]+2*byte[1]+4*byte[2]+8*byte[3]+16*byte[4]+32*byte[5]+64*byte[6]+128*byte[7];
    cout<<"the value in decimal is "<<value<<"\n";
}

