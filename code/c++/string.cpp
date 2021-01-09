#include <iostream>
using namespace std;
class String {
private:
    int len;
	char* s;
public:
	String(const char * str) {
		int count;
		for(count=0;str[count]!='\0';count++){
		}
	    s=new char[count];
	    for(int i=0;i<count;i++){
	    	s[i]=str[i];
	    }
	    len=count;
	}
	String(){
		len=0;
		s=nullptr;
	}
	~String() {
		delete [] s;
	}
	String(const String& orig) {
		len=orig.len;
		s=new char[orig.len];
		for(int i=0;i<orig.len;i++){
			s[i]=orig.s[i];
		}
	}
	String& operator=(const String& orig) {
		String copy(orig);
		this->len=copy.len;
		swap(this->s,copy.s);
		return *this;
		}
    String(String&& orig) {
    	len=orig.len;
    	s=orig.s;
    	orig.s=nullptr;
  }
    friend String operator+(const String& a,const String& b){
    	String result;
    	result.len=a.len+b.len;
    	result.s=new char[a.len+b.len];
    	for(int i=0;i<a.len;i++){
    		result.s[i]=a.s[i];
    	}
    	for(int i=a.len;i<a.len+b.len;i++){
    		result.s[i]=b.s[i-a.len];
    	}
    	return result;
    }
	friend ostream& operator<<(ostream& s, const String& str) {
		for(int i=0;i<str.len;i++){
			s<<str.s[i];
		}
		return s;
	}
};

int main(){
	String s = "abc";
	String s2 = "hello there";
	String s3 = s + s2; // "abchello there"
	String s4 = s3; // copy constructor
	cout<<s4<<endl;
	String s5;
	s5=s4;
	cout<<s5;
}