#include<stdio.h>
#include<cassert>
#include<cmath>


template <class elemType>
class example1{
	public:
		example1( elemType min, elemType max );
		example1( const elemType *array, int size );
		elemType& operator[]( int index );
		bool operator==( const example1& ) const;
		bool insert( const elemType*, int );
		bool insert( elemType );
		elemType min() const { return _min; };
		elemType max() const { return _max; };
		void min( elemType );
		void max( elemType );
		int count( elemType value ) const;
	private:
		int size;
		elemType *parray;
		elemType _min;
		elemType _max;
};

example1<double> test1(double a, double b);
example1<float> test2(float a, float b);
example1<char> test2(char a, char b);