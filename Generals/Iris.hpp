#ifndef IRIS
#define IRIS

#include <vector>
#include <string>
#include <iostream>
#include <cmath>
using namespace std;
/**
 * @brief 
 * This class is responsible for the Iris flower.
 */
class Iris {
	vector<double> characters;
	string m_type;
public:
	/**
	 * @brief Construct a new Iris object.
	 * 
	 */
	Iris();

	/**
	 * @brief Set the params with string of data.
	 * 
	 * @param data (the string).
	 * @param comma (the comma between the params).
	 */
	void setWithString(string data, char comma);

	/**
	 * @brief Set the type of the object.
	 * 
	 * @param type (the type).
	 */
	void setType(string type);
	
	/**
	 * @brief this func outputs the type of the iris.
	 * 
	 * @return string (the type of the iris).
	 */
	string type();

	/**
	 * @brief this func classify the iris (by KNN).
	 * 
	 * @param irises (the classified irises).
	 * @param k (the k of the KNN).
	 * @param length (the amount of the classified irises).
	 * @param distanceFunc (the distance func).
	 * @return string (the type).
	 */
	string classify(Iris* irises, int k, int length, double (Iris::*distanceFunc)(Iris));
	
	/**
	 * @brief this func returns the euclidean distance between
	 * this iris and other.
	 * 
	 * @param checking (the other iris).
	 * @return double (the euclidean distance).
	 */
	double euclideanDistance(Iris checking);
    
	/**
	 * @brief this func returns the manhattan distance between
	 * this iris and other.
	 * 
	 * @param checking (the other iris).
	 * @return double (the euclidean distance).
	 */
	double manhattanDistance(Iris checking);
    
	/**
	 * @brief this func returns the chebyshev distance between
	 * this iris and other.
	 * 
	 * @param checking (the other iris).
	 * @return double (the chebyshev distance).
	 */
	double chebyshevDistance(Iris checking);
	
	/**
	 * @brief The function turns a string of irises to an array of irises.
	 * 
	 * @param data The string of irises.
	 * @param counter The amount of irises.
	 * @return Iris* The array of irises returned.
	 */
	static Iris* stringToIrises(string data, int &counter);

	/**
	 * @brief This func returns the vector of the characthers of the Iris.
	 * 
	 * @return vector<double> (the vector).
	 */
	vector<double> characts();
};

#endif // IRIS