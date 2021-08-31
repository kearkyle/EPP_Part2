#include "Vaccination.h"
#include <algorithm>
#include <fstream>
#include <string>

using namespace std;

std::istream& operator>>(std::istream& stream, Vaccination& vac)
{
	Vaccination check;
	//char delim = ',';
	stream >> check.cty >> check.pop >> check.vac;

	if (stream) vac = std::move(check);
	return stream;
}

std::ostream& operator<<(std::ostream& stream, const Vaccination& vac)
{
	stream << vac.cty << " " << vac.pop << " " << vac.vac;
	return stream;
}

Vaccination::Vaccination()
{
	cty = "default";
	pop = 0;
	vac = 0;
}

//read file population by name
void Vaccination::readPopulationFile(std::string filename) {
	std::ifstream fin(filename, std::ios::binary);
	Vaccination dummy;
	while (fin >> dummy.cty >> dummy.pop) {
		vac_data.push_back(dummy);
	}
	fin.close();
}	


//read file vaccination by name
void Vaccination::readVaccinationsFile(std::string filename) {
	std::ifstream fin(filename, std::ios::binary);
	Vaccination dummy;
	int n = vac_data.size();
	while (fin >> dummy.cty >> dummy.vac) {
		bool check = false;
		for (int i = 0; i < n; i++) {
			if (vac_data[i].cty == dummy.cty) {
				vac_data[i].vac = dummy.vac;
				check = true;
				break;
			}
		}
		if (check == false) vac_data.push_back(dummy);
	}
	fin.close();
}

void Vaccination::printFile() {
	int n = vac_data.size();
	for (int i = 0; i < n; i++) {
		cout << vac_data[i];
		cout << endl;
	}
	cout << endl;
}

double Vaccination::vaccinationRate(std::string county) {
	int n = vac_data.size();
	int found = 0;
	double result = 0;
	for (int i = 0; i < n; i++)
	{
		std::string mycounty = vac_data[i].cty;
		if (mycounty == county)
		{
			break;
			//result = (double)vac_data[i].vac / (double)vac_data[i].pop;
		}
		else {
			found++;
		}

	}
	if (found == n) result = -1;
	else result = (double)vac_data[found].vac / (double)vac_data[found].pop;
	return result;
}

Vaccination::~Vaccination()
{

}