#pragma


#include <stdexcept>
#include <iostream>
#include <iomanip>
#include <math.h>
#include <vector>

using std::vector;
using std::cin;
using std::cout;
using std::endl;


template <class T>
class qbVector
{
public:
	qbVector();
	qbVector(vector<T> inputData);
	~qbVector();

	// Funktion Return the dim of my vector
	int getNumDim();
	// Funktion to handl elements of the vector
	T GetElement(int index);

	// Overloaded operators
	qbVector<T> operator+ (const qbVector<T>& rhs) const;
	qbVector<T> operator- (const qbVector<T>& rhs) const;
	qbVector<T> operator* (const T& rhs) const;

	// Friend funktion
	//template <class U> friend qbVector operator* (const U &lhs, const qbVector<U>& rhs);
	template <class U>
	friend qbVector<U> operator*(const U& lhs, const qbVector<U>& rhs);

	// Static funktions
	static T dot(const qbVector<T>& a, const qbVector<T>& b);
	static qbVector<T> cross(const qbVector<T>& a, const qbVector<T>& b);

private:
	vector<T> m_VectorData;
	int m_nDims;

};



// Default constructor
template <class T>
qbVector<T>::qbVector()
{
	m_VectorData = vector<T>();
	m_nDims = 0;

}


// Constructor
template <class T>
qbVector<T>::qbVector(vector<T> inputData)
{
	m_nDims = inputData.size();
	m_VectorData = inputData;
}

// destructor
template <class T>
qbVector<T>::~qbVector()
{
	// For now we don´t need to do anything in the destructor
}


//***************************************************************************************************************
//									Fuction to Return Parameters												*
//***************************************************************************************************************

template <class T>
int qbVector<T>::getNumDim()
{
	return m_nDims;
}


//***************************************************************************************************************
//									Fuction to Handle Element of the Vector									    *
//***************************************************************************************************************

template <class T>
T  qbVector<T>::GetElement(int index)
{
	return m_VectorData[index];
}


//***************************************************************************************************************
//									Overloaded Operators												        *
//***************************************************************************************************************

template <class T>
qbVector<T> qbVector<T>::operator+ (const qbVector<T>& rhs) const
{
	// Check that the number of the dimensions match.
	if (m_nDims != rhs.m_nDims)
	{
		throw::std::invalid_argument("Vectro dimensions do not match.!");
	}
	vector<T> resultData;
	for (int i = 0; i < m_nDims; i++)
		resultData.push_back(m_VectorData.at(i) + rhs.m_VectorData.at(i));

	qbVector<T> result(resultData);
	return result;
}


template <class T>
qbVector<T> qbVector<T>::operator- (const qbVector<T>& rhs) const
{
	// Check that the number of the dimensions match.
	if (m_nDims != rhs.m_nDims)
	{
		throw::std::invalid_argument("Vectro dimensions do not match.!");
	}
	vector<T> resultData;
	for (int i = 0; i < m_nDims; i++)
		resultData.push_back(m_VectorData.at(i) - rhs.m_VectorData.at(i));


	qbVector<T> result(resultData);
	return result;
}


template <class T>
qbVector<T> qbVector<T>::operator* (const T &rhs) const
{
	// Perform scalar multiplication.
	vector<T> resultData;
	for (int i = 0; i < m_nDims; i++)
		resultData.push_back(m_VectorData.at(i) * rhs);

	qbVector<T> result(resultData);
	return result;
}


//***************************************************************************************************************
//									Friend Funkctions			    									        *
//***************************************************************************************************************

template <class T>

qbVector<T> operator*(const T &lhs, const qbVector<T> &rhs)
{
	// Perform scalar multiplication.
	vector<T> resultData;
	for (int i = 0; i < rhs.m_nDims; i++)
		resultData.push_back(lhs * rhs.m_VectorData.at(i));

	qbVector<T> result(resultData);
	return result;
}


//***************************************************************************************************************
//									Static Funkctions			    									        *
//***************************************************************************************************************

template <class T>
T qbVector<T>::dot(const qbVector<T>& a, const qbVector<T>& b)
{
	// Check that the number of the dimensions match.
	if (a.m_nDims != b.m_nDims)
	{
		throw::std::invalid_argument("Vectro dimensions do not match.!");
	}

	//Compute the dot product
	T CumulativeSum = static_cast<T>(0.0);
	for (int i = 0; i < a.m_nDims; i++)
		CumulativeSum += a.m_VectorData.at(i) * b.m_VectorData.at(i);

	return CumulativeSum;

}

template <class T>


qbVector<T> qbVector<T>::cross(const qbVector<T> &a, const qbVector<T> &b)
{
	// Check that the number of the dimensions match.
	if (a.m_nDims != b.m_nDims)
		throw::std::invalid_argument("Vectro dimensions do not match.!");

	// Check that the number of the dimensions is 3

	/*
	Althouh the cross-product is also defined for 7 dimenions,
	we are not going to consider the case at this time.

	*/

	if (a.m_nDims != 3)
		throw::std::invalid_argument("The cross-product can only be computed for the dimensional vectors!");

	//compute the cross product.


	vector<T> resultData;

	resultData.push_back((a.m_VectorData.at(1) * b.m_VectorData.at(2)) - (a.m_VectorData.at(2) * b.m_VectorData.at(1)));
	resultData.push_back(-((a.m_VectorData.at(0) * b.m_VectorData.at(2)) - (a.m_VectorData.at(2) * b.m_VectorData.at(0))));
	resultData.push_back((a.m_VectorData.at(0) * b.m_VectorData.at(1)) - (a.m_VectorData.at(1) * b.m_VectorData.at(0)));


	vector<T> result(resultData);
	return result;
}