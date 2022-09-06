#include "Iris.hpp"

Iris::Iris()
{
	m_type = "unIdentified";
}

void Iris::setWithString(string data, char comma)
{
	int i, j = 0;
	while ((i = data.find(comma, j)) != -1) {
		characters.push_back(stod(data.substr(j, i - j)));
		j = i + 1;
	}
	if (isdigit(data[j])) {
		characters.push_back(stod(data.substr(j)));
		return;
	}
	m_type = data.substr(j);
}

Iris* Iris::stringToIrises(string data, int &counter) {
	int i, j = 0;
	counter = 1;
	char comma = ' ';
	while ((i = data.find(comma, j)) != -1) {
		counter++;
		j = i + 1;
	}
	Iris* irises = new Iris[counter];
	j = 0;
	counter = 0;
	while ((i = data.find(comma, j)) != -1) {
		irises[counter].setWithString(data.substr(j, i - j), ',');
		counter++;
		j = i + 1;
	}
	irises[counter++].setWithString(data.substr(j), ',');
	return irises;
}

string Iris::classify(Iris* irises, int k, int length, double (Iris::* distanceFunc)(Iris)) {
	double* distances = new double[length];
	int* amountOfType = new int[3];
	for (int m = 0; m < 3; m++) {
		amountOfType[m] = 0;
	}
	int* indexOutOfUse = new int[k];
	int maxIndex = 0;
	bool flag = true;
	for (int i = 0; i < length; i++) {
		distances[i] = (this->*distanceFunc)(irises[i]);
		if (distances[i] > distances[maxIndex]) {
			maxIndex = i;
		}
	}
	/*
	* This loop is in charge of counting the number of each type of the closest k Irises.
	* It has an array that is responsible for the indexes already chosen and it checks for
	  all of the distances who is the shortest out of the indexes that was not chosen.
	*/
	for (int m = 0; m < k; m++) {
		int minIndex = maxIndex;
		for (int j = 0; j < length; j++) {
			for (int l = 0; l < m; l++) {
				if (indexOutOfUse[l] == j) {
					flag = false;
					break;
				}
			}
			if ((distances[j] < distances[minIndex]) && flag) {
				minIndex = j;
			}
			flag = true;
		}
		if (irises[minIndex].type().compare("Iris-setosa") == 0) {
			amountOfType[0]++;
		}
		if (irises[minIndex].type().compare("Iris-virginica") == 0) {
			amountOfType[1]++;
		}
		if (irises[minIndex].type().compare("Iris-versicolor") == 0) {
			amountOfType[2]++;
		}
		indexOutOfUse[m] = minIndex;
	}
	delete[] distances;
	delete[] indexOutOfUse;
	/*
	* The conditions are for the function to decide which type is suitable
	  to the Iris that we are checking.
	*/
	if ((amountOfType[0] > amountOfType[1]) && (amountOfType[0] > amountOfType[2])) {
		delete[] amountOfType;
		return "Iris-setosa";
	}
	else if ((amountOfType[1] > amountOfType[0]) && (amountOfType[1] > amountOfType[2])) {
		delete[] amountOfType;
		return "Iris-virginica";
	}
	else if ((amountOfType[2] > amountOfType[1]) && (amountOfType[2] > amountOfType[0])) {
		delete[] amountOfType;
		return "Iris-versicolor";
	}
	delete[] amountOfType;
	return "unIdentified";
}

string Iris::type() {
	return m_type;
}

void Iris::setType(string type) {
	m_type = type;
}

double Iris::euclideanDistance(Iris checking) {
	vector<double> others_chars = checking.characts();
	double sumOfDistances = 0.0;
	for (int i = 0; (i < characters.size()) && (i < others_chars.size()); i++) {
		sumOfDistances += pow(characters[i] - others_chars[i], 2);
	}
	// double dx = pow((this->cupLength() - checking.cupLength()), 2);
	// double dy = pow((this->cupWidth() - checking.cupWidth()), 2);
	// double dz = pow((this->petalWidth() - checking.petalWidth()), 2);
	// double dw = pow((this->petalLength() - checking.petalLength()), 2);
	return sqrt(sumOfDistances);
}

double Iris::manhattanDistance(Iris checking) {
	vector<double> others_chars = checking.characts();
	double sumOfDistances = 0.0;
	for (int i = 0; (i < characters.size()) && (i < others_chars.size()); i++) {
		sumOfDistances += abs(characters[i] - others_chars[i]);
	}
	return sumOfDistances;
}

double Iris::chebyshevDistance(Iris checking) {
	vector<double> others_chars = checking.characts();
	double maxOfDistances = 0.0;
	double currentDistance;
	for (int i = 0; (i < characters.size()) && (i < others_chars.size()); i++) {
		currentDistance = abs(characters[i] - others_chars[i]);
		if (currentDistance > maxOfDistances) {
			maxOfDistances = currentDistance;
		}
	}
	return maxOfDistances;
}

vector<double> Iris::characts() {
	return characters;
}
