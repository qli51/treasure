#include <iostream>
using namespace std;
class BadSize {
private:
	const char* filename;
	int lineNum;
public:
	BadSize(const char filename[], int lineNum) :
		filename(filename), lineNum(lineNum) {}
	friend ostream& operator <<(ostream& s, const BadSize& b) {
		return s << b.filename << ": " << b.lineNum << " size mismatch";
	}
};
class Matrix {
private:
	int rows, cols;
	double* m;
	static int count;
public:
	Matrix(int Rows, int Cols, double val){
		rows=Rows;
		cols=Cols;
		m=new double[Rows*Cols];
		for(int i=0;i<Rows*Cols;i++){
			m[i]=val;
		}
	}
	Matrix(){
		rows=0;
		cols=0;
		m=nullptr;
	}
	~Matrix(){
		delete [] m;
	}
	Matrix(const Matrix& orig){
		rows=orig.rows;
		cols=orig.cols;
		m=new double[orig.rows*orig.cols];
		for(int i=0;i<orig.rows*orig.cols;i++){
			m[i]=orig.m[i];
		}
	}
	Matrix(Matrix&& orig){
		rows=orig.rows;
		cols=orig.cols;
		m=orig.m;
		orig.m=nullptr;
	}
	Matrix& operator=(const Matrix& orig){
		Matrix copy(orig);
		this->cols=copy.cols;
		this->rows=copy.rows;
		swap(this->m,copy.m);
		return *this;
	}
	double& operator()(int i,int j) const{
		return m[(i-1)*cols+j-1];
	}
	static int getCount() {
    return count;
	}
    static Matrix scale(int n, double v) {
		Matrix a(n,n,0);
		for (int i = 0; i < n*n; i += n+1)
			a.m[i] = v;
		return a;
	}
	static Matrix identity(int n){
		Matrix a(n,n,0);
		for(int i=0;i<n*n;i+=n+1)
			a.m[i]=1;
		return a;
	}
	friend  Matrix operator +(const Matrix& left, const Matrix& right) {
		if (left.rows != right.rows || left.cols != right.cols){
			throw BadSize(__FILE__, __LINE__);
	    }
	    Matrix a;
	    a.cols=left.cols;
	    a.rows=left.rows;
	    a.m=new double[left.cols*left.rows];
	    for(int i=0;i<left.cols*left.rows;i++){
	    	a.m[i]=left.m[i]+right.m[i];
	    }
	    return a;
	}
	friend Matrix operator*(const Matrix& orig,double b){
		Matrix a;
		a.rows=orig.rows;
		a.cols=orig.cols;
		a.m=new double[orig.rows*orig.cols];
		for(int i=0;i<orig.rows*orig.cols;i++){
			a.m[i]=orig.m[i]*b;
		}
		return a;
	}
	friend Matrix operator*(const Matrix& left,const Matrix& right){
		if(left.rows!=right.cols){
			throw BadSize(__FILE__, __LINE__);
		}
		int s=0;
		Matrix result;
		result.rows=left.rows;
		result.cols=right.cols;
		result.m=new double[left.rows*right.cols];
		for(int i=0;i<left.rows;i++){
			for(int a=0;a<right.cols;a++){
				for(int j=0;j<left.cols;j++){
					s=s+left.m[i*left.cols+j]*right.m[j*right.cols+a];
				}
				result.m[i*result.cols+a]=s;
				s=0;
			}
		}
		return result;
	}
    friend ostream& operator<<(ostream& out,const Matrix& orig){
		for(int i=0;i<orig.rows;i++){
			for(int j=0;j<orig.cols;j++){
				out<<orig.m[i*orig.cols+j];
			}
			out<<endl;
		}
		return out;
	}
	friend istream& operator>>(istream& in,const Matrix& orig){
		for(int i=0;i<orig.rows*orig.cols;i++){
			in>>orig.m[i];
		}
		return in;
	}
};

int Matrix::count = 0;

int main() {
	Matrix m1 = Matrix::identity(4);
	Matrix m2 = m1 * 2.5; // scalar multiplication
	m2(1,3) = 5.5;
	Matrix m3 = m1 + m2;
	cout << m3 << '\n';
	Matrix m4 = m3; // copy constructor
	cout << m4 << '\n';
	cin >> m4;
	// optional: matrix mult 50%
	Matrix m5(2,3, 1.0);
	m5(1,2) = 2.0;
	Matrix m6(3, 4, 2.0);
	m6(2,1) = -1;
	m6(2,3) = -2;
	Matrix m7 = m5 * m6;
	cout << m7 << '\n';	
}