#include <include>
using namespace std;
    bool isNumeric(char* string)
    {
        bool sign=false,decimal=false,hasE=false;
        for(int i=0;i<strlen(string);i++){
            if(string[i]=='e' || string[i]=='E'){
                if(i==0 || i==strlen(string)-1) return false;
                if(hasE) return false;
                hasE=true;
            }
            else if(string[i]=='+' ||string[i]=='-'){
                if(string[i-1]!='e' && string[i-1]!='E' && i!=0) return false;
                sign=true;
            }
            else if(string[i]=='.'){
                if(hasE || decimal) return false;
                decimal=true;
            }
            else{
                if(string[i]<'0' || string[i]>'9') return false;
            }
        }
        return true;               
    }