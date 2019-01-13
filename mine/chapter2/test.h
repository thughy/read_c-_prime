#include<stdio.h>
#include<cassert>
#include<cmath>

class Matrix{
	public:
		// construction
		Matrix();
		Matrix(int dim1, int dim2);
		Matrix( const Matrix &p_mat);
		int* shape(){int MatShape[2]={_dim1, _dim2}; return MatShape;};
		int get_dim1() const {return _dim1;};
		int get_dim2() const {return _dim2;};

		int min();
		int max();
		int find(int value);
		bool operator==(const Matrix& mat);

		~Matrix(){ delete [] ia;};
	private:
		int _dim1;
		int _dim2;
		int _pnt_mat;
		int *ia;
};

Matrix::Matrix(){
	_dim1 = 5;
	_dim2 = 5;
	ia = new int[_dim1*_dim2];
	for(int i=0; i<_dim1; i++){
		for(int j=0; j<_dim2; j++){
			ia[i*_dim2+j] = 0;
		};
	};
};

Matrix::Matrix(int dim1, int dim2){
	assert(dim1 < 100 && dim1 > 1);
	assert(dim2 < 100 && dim2 > 1);
	_dim1 = dim1;
	_dim2 = dim2;
	ia = new int[dim1*dim2];
	for(int i=0; i<_dim1; i++){
		for(int j=0; j<_dim2; j++){
			ia[i*_dim2+j] = 0;
		};
	};
};

int Matrix::min(){
	int min_value = 0;
	int _cur;
	for(int i=0; i<this->_dim1;i++){
		for(int j=0; j<this->_dim2;j++){
			_cur = ia[i*_dim2+j];
			if(min_value < _cur){
				min_value = _cur;
			};
		};
	};
	return min_value;
};

bool Matrix::operator==(const Matrix& mat){
	if( mat.get_dim1() != _dim1){
		return false;
	};
	if( mat.get_dim2() != _dim2){
		return false;
	};
	for(int i=0; i<this->_dim1;i++){
		for(int j=0; j<this->_dim2;j++){
			if(ia[i*_dim2+j] != mat.ia[i*_dim2+j]){
				return false;
			};
		};
	};
	return true;
};


int main(){
	Matrix mat1, mat2;
	bool flag = mat1 == mat2;
	assert(mat1.max() == false);
	return 0;
};