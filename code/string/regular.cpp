#include <include>
using namespace std;
int match(const char *str, const char *pattern)
{
    if(*str=='\0' && *pattern=='\0') return 0;
    if(*str!='\0' && *pattern=='\0') return -1;
    if(*pattern!='*'){
        if((*str!='\0' && *str=*pattern) || (*str!='\0' && *pattern=='?')) return match(str+1,pattern+1);
        else return false;        
    }
    else{
        if(*str!='\0'){
            return match(str+1,pattern) || match(str,pattern+1);
        }      
    }
    //TODO:
}