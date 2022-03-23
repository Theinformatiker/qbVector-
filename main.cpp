#include "qbVector.hpp"

using std::vector;
using std::cin;
using std::cout;
using std::endl;
template <class T>

void PrintVector(qbVector<T> myVec)
{
	int nrow = myVec.getNumDim();
	for (int i = 0; i < nrow; i++)
		cout << std::fixed << std::setprecision(3) << myVec.GetElement(i) << endl;

}

int main()
{
	cout << "code to test qbVector \n";
	//Create a Vector of the qbVector class
	vector<double> testData1 = { 1.0,2.0,3.0 };
	qbVector<double> testVector1(testData1);
	cout << "Create an initial instance of the class, with data (testVector1):" << endl;
	PrintVector(testVector1);
	cout << endl;

	qbVector<double> testVector2(vector<double>{2.0, 4.0, 6.0});
	cout << "Create an initial instance of the class, with data (testVector1):" << endl;
	PrintVector(testVector2);
	cout << endl;

	cout << "############################-Basic vector operation-#######################" << endl;
	cout << "Solution of vec1 + vec 2" << endl;
	
	cout << endl;

	qbVector<double> erg = testVector1 +  testVector2;
	PrintVector(erg);
	cout << endl;
	
	qbVector<double> erg2 = testVector1 - testVector2;
	cout << "Solution of vec1 - vec 2" << endl;
	PrintVector(erg2);
	cout << endl;

	qbVector<double> scalVector1 =  testVector1* 2.0;
	cout << "TestVecto1 * 2.0 soultion is: " << endl;
	PrintVector(scalVector1);
	cout << endl;

	cout << "#################################" << endl;

	qbVector<double> scalVector2 = 2.0 *testVector1;
	cout << "2.0 * TestVecto1 soultion is: " << endl;
	PrintVector(scalVector2);
	cout << endl;



	cout << "Test Static funktion" << endl;
	cout << "Dot Product of testVector1 and testVector2 " << endl;

	double dotProduct = qbVector<double>::dot(testData1, testVector2);
	cout << std::fixed << std::setprecision(3) << dotProduct << endl;

	cout << "Cross pruduct of TestVector1 and Testvector2" << endl;
	qbVector<double> crossPorduct1 = qbVector<double>::cross(testVector1, testVector2);
	PrintVector(crossPorduct1);

	cout << endl;
	cout << "Define a new testVectro which is ot parallel to the testVector1  \n";

	qbVector<double> testVector5( vector<double> { -1.0, 5.0, -3.2 });
	PrintVector(testVector5);
	cout << endl;

	cout << "Cross pruduct of TestVector1 and Testvector5" << endl;
	qbVector<double> crossPorduct2 = qbVector<double>::cross(testVector1, testVector5);
	PrintVector(crossPorduct2);

	cout << endl;

	cout << "Dot product of testVecto1 and  testVector5 " << endl;
	double dotProduct2 = qbVector<double>::dot(testVector1, testVector5);
	cout << std::fixed << std::setprecision(3) << dotProduct2 << endl;

	cout << endl;
	return 0;
}
