#include <iostream>
#include <string>
#include <iomanip>      // std::setprecision
#include "Vaccination.h"

using std::string;
using std::endl;
using std::cout;

bool testAnswer(const string &nameOfTest, double received, double expected);

template <typename T>
bool testAnswer(const string &nameOfTest, const T& received, const T& expected);


int main() {
  {
    cout << "Testing with small data files ..." << endl;
    Vaccination vac;
    vac.readPopulationFile("CA_population_5.txt");
    vac.readVaccinationsFile("CA_vaccinations_5.txt");
    vac.printFile();
    testAnswer("vaccination rate of Los_Angeles_County", vac.vaccinationRate("Los_Angeles_County"), 0.5725512);
    testAnswer("vaccination rate of Orange_County", vac.vaccinationRate("Orange_County"), 0.592653701);
    testAnswer("vaccination rate of Mendocino_County", vac.vaccinationRate("Mendocino_County"), -1);
    testAnswer("vaccination rate of San_Bernardino_County", vac.vaccinationRate("San_Francisco_County"), -1);
  }
  {
    cout << "Testing with large data files ..." << endl;
    Vaccination vac;
    vac.readPopulationFile("CA_population.txt");
    vac.readVaccinationsFile("CA_vaccinations.txt");
    vac.printFile();
    testAnswer("vaccination rate of Mendocino_County", vac.vaccinationRate("Mendocino_County"), 0.546592681);
    testAnswer("vaccination rate of San_Francisco_County", vac.vaccinationRate("San_Francisco_County"), 0.722195618);
    testAnswer("vaccination rate of Orange_County", vac.vaccinationRate("Orange_County"), 0.592653701);
    testAnswer("vaccination rate of Los_Angeles_County", vac.vaccinationRate("Los_Angeles_County"), 0.5725512);
    testAnswer("vaccination rate of Unknown_County", vac.vaccinationRate("Unknown_County"), -1);
  }
  return (0);
}

template <typename T>
bool testAnswer(const string &nameOfTest, const T& received, const T& expected) {
  if (received == expected) {
    cout << "PASSED " << nameOfTest << ": expected and received " << received << endl;
    return true;
  }
  cout << "FAILED " << nameOfTest << ": expected " << expected << " but received " << received << endl;
  return false;
}

bool testAnswer(const string &nameOfTest, double received, double expected) {
  if ((received - expected) > -0.01 && (received - expected) < 0.01) {
    cout << "PASSED " << std::setprecision(9) << nameOfTest << ": expected and received " << received << endl;
    return true;
  }
  cout << "FAILED " << std::setprecision(9) << nameOfTest << ": expected " << expected << " but received " << received << endl;
  return false;
}
