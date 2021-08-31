#ifndef VACCINATION_H
#define VACCINATION_H

/*My approach for this solution is creating a vector of class Vaccination as a private member
of class Vaccination, then the 2 read functions will try to store datas from the text file into my vector
which will hold the values for population and vaccination with the respected county. For my ReadVaccinationFIle, I try to compare if
the certain county already exist inside my vector, if it does I will store the vaccination number at that index of my Vaccination Vector,
otherwise I would push to the back of my vector as a new item. The VaccinationRate will loop through the vector and decide whether the county already exist
if it does, it next check if there are numbers for population and vaccination, if all these are true then the function will return the rate as a double, otherwise it will return -1

*/

#include <iostream>
#include <string>
#include <vector>

class Vaccination
{
	friend std::istream& operator>>(std::istream& stream, Vaccination& process);
	friend std::ostream& operator<<(std::ostream& stream, const Vaccination& process);
public:
		//Declarations
	Vaccination();		//create default Vaccination constructor

	void readPopulationFile(std::string);	//read file population by name

	void readVaccinationsFile(std::string);	//read file vaccination by name

	void printFile();

	double vaccinationRate(std::string);

	~Vaccination();		//destructor

private:
	
	std::string cty;	//county name
	int pop;	//population of the county
	int vac;	//fully vaccinated population of the county
	std::vector<Vaccination> vac_data;
};

#endif // !1


