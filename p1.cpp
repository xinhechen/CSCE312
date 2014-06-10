#include <iostream>
#include "p1.h"
#include "basic_functions.h"

using namespace std;
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
    

    
    
