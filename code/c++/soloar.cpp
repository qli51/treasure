#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
using namespace std;
class Body{
private:
	string name;
	string obit;
	double mass;
	double radius;
	double x;
	double y;
	double z;
public:
	Body(string Name,string Obit,double Mass,double Radius,double X){
		name=Name;
		obit=Obit;
		mass=Mass;
		radius=Radius;
		x=X;
		y=0;
		z=0;
	}
	friend ostream& operator<<(ostream& out,Body a);
};
ostream& operator<<(ostream& out,Body a){
	out<<"name:  "<<a.name<<",obit:  "<<a.obit<<",mass:  "<<a.mass<<",radius:  "<<a.radius<<",distance(x):  "<<a.x;
}
class SolarSystem{
private:
  vector<Body> bodies;
  string dat;
 public:
 	SolarSystem(string Dat){
 		dat=Dat;
 		ifstream f(dat); 
 		string A,B;
 		double C,D,E;
 		string line;
	while(!f.eof()){
		getline(f,line);
		istringstream linestr(line);
		linestr>>A>>B>>C>>D>>E;
		double x=(D+E)/2;
		double y=0;
		double z=0;
		bodies.push_back(Body(A,B,C,D,x));
 	}
 }
 friend ostream& operator<<(ostream& out,SolarSystem a);
 };
 ostream& operator<<(ostream& out,SolarSystem a){
 		for(int i=1;i<a.bodies.size();i++){
 		out<<a.bodies[i]<<endl;
 	}
 	return out;
 }
int main() {
  SolarSystem s("solarsystem.dat");
  cout << s; // print out each body with name, mass, etc...
 }