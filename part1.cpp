#include <iostream>
using namespace std;
    static int functionCount=0;
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
        cout<<a;
    }
    void resetFunctionCount()
    {
        functionCount=0;
    }
    
    bool XOR(bool a, bool b)
    {
        bool na=Not(a);
        bool nb=Not(b);
        bool nab=And(na,b);
        bool nba=And(nb,a);
        bool ans=Or(nab,nba);
        return ans;
    }
    
    bool Mux(bool operation, bool output_if_true, bool output_if_false)
    {
        bool no=Not(operation);
        bool oa=And(operation,output_if_true);
        bool nob=And(no,output_if_false);
        bool ans=Or(oa,nob);
        return ans;
    }
    
    bool Sum(bool a, bool b)
    {
        return XOR(a,b);
    }
    
    bool Sum(bool a, bool b, bool c)
    {
        return XOR(a,XOR(b,c));
    }
    
    bool CarryOut(bool a, bool b, bool c)
    {
        bool ab=And(a,b);
        bool ac=And(a,c);
        bool bc=And(b,c);
        bool ans=Or(ab,Or(ac,bc));
        return ans;
    }
    
    bool Equal(bool a, bool b)
    {
        return Not(XOR(a,b));
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
        cout<<byte[0]<<byte[1]<<byte[2]<<byte[3]<<byte[4]<<byte[5]<<byte[6]<<byte[7];
    }
    
    void printValueInDecimal(bool byte[8])
    {
        int value=1*byte[7]+2*byte[6]+4*byte[5]+8*byte[4]+16*byte[3]+32*byte[2]+64*byte[1]+128*byte[0];
        cout<<"the value in decimal is "<<value<<"\n";
    }
    
    
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
        output[7]=Sum(input1[7],input2[7]);
        bool carryout=CarryOut(input1[7],input2[7],'0');
        output[6]=Sum(input1[6],input2[6],carryout);
        carryout=CarryOut(input1[6],input2[6],carryout);
        output[5]=Sum(input1[5],input2[5],carryout);
        carryout=CarryOut(input1[5],input2[5],carryout);
        output[4]=Sum(input1[4],input2[4],carryout);
        carryout=CarryOut(input1[4],input2[4],carryout);
        output[3]=Sum(input1[3],input2[3],carryout);
        carryout=CarryOut(input1[3],input2[3],carryout);
        output[2]=Sum(input1[2],input2[2],carryout);
        carryout=CarryOut(input1[2],input2[2],carryout);
        output[1]=Sum(input1[1],input2[1],carryout);
        carryout=CarryOut(input1[1],input2[1],carryout);
        output[0]=Sum(input1[0],input2[0],carryout);
        return output;
    }
    bool* negate(bool* output, bool input[8])
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
        one[0]='0';
        one[1]='0';
        one[2]='0';
        one[3]='0';
        one[4]='0';
        one[5]='0';
        one[6]='0';
        one[7]='1';
        addu(output,temp,one);
        return output;
    }
    bool* subu(bool* output, bool input1[8], bool input2[8])
    {
        bool* negb=new bool[8];
        negate(negb,input2);
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
        bool sign=sub[0];
        return Or(sign,equal(input1,input2));
    }
    bool greaterthan(bool input1[8], bool input2[8]) //(return 0 if false)
    {
        bool* sub=new bool[8];
        subu(sub,input1,input2);
        bool opposite=Not(sub[0]);
        return Or(opposite,equal(input1,input2));
    }
    bool* equal(bool* output, bool input1[8], bool input2[8])// (return 11111111 if two values are the same)
    {
        bool* sub=new bool[8];
        subu(sub,input1,input2);
        negate(output,sub);
        return output;
    }
    bool* lessthan(bool* output, bool input1[8], bool input2[8]) //(return 00000000 if false)
    {
        bool o=lessthan(input1,input2);
        output[0]=o;
        output[1]=o;
        output[2]=o;
        output[3]=o;
        output[4]=o;
        output[5]=o;
        output[6]=o;
        output[7]=o;
        return output;
    }
    bool* greaterthan(bool* output, bool input1[8], bool input2[8])//(return 00000000 if false)
    {
        bool o=greaterthan(input1,input2);
        output[0]=o;
        output[1]=o;
        output[2]=o;
        output[3]=o;
        output[4]=o;
        output[5]=o;
        output[6]=o;
        output[7]=o;
        return output;
        
    }
    bool* annd(bool* output, bool input1[8], bool input2[8])//(bitwise and)
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
    bool* oor(bool* output, bool input1[8], bool input2[8])//(bitwise or)
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
        output[0]=input[1];
        output[1]=input[2];
        output[2]=input[3];
        output[3]=input[4];
        output[4]=input[5];
        output[5]=input[6];
        output[6]=input[7];
        output[7]='0';
        return output;
    }
    bool* shiftRight(bool* output, bool input[8])
    {
        output[0]='0';
        output[1]=input[0];
        output[2]=input[1];
        output[3]=input[2];
        output[4]=input[3];
        output[5]=input[4];
        output[6]=input[5];
        output[7]=input[6];
        return output;
    }



