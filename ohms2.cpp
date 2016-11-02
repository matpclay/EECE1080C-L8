/*
* @author Matthew Clayton
* @date 1 November 2016
* @assign.ment Lab 8 Ohm's Law
* @descrip.tion
* This file contains code for Task 2 of L8. This program
* allows for 'unlimited' resistors by using the vector class. The
* program outputs total power, series current, voltage source, and
* power and resistance for each resistor. Task 2 implements a
* multi-node DC CKT Simulator.
*
* KNOWN ISSUES:
*
* This program does not handle non-numerical input.
*
*/

#include <iostream>
#include <vector>
using namespace std;

class Ohms2 {
  vector<double> resistors;
  vector<double> powerConsumption;
  vector<double> voltageAcross;
  double sourceVoltage;
  double seriesCurrent;
  double totalPower;
  double resistance;
  double totalResistance = 0;
public:
  void setup();
  void utility();
  void display();
  void resistorUtility();
};

void Ohms2::setup() {
  // get source voltage
  cout << "Input source voltage (volts): ";
  cin >> sourceVoltage;
  cout << endl;
  // get resistor(s)
  cout << "Input resistor values. At any time, enter a negative value to stop adding resistors.\n" << endl;
  while (resistance >= 0) {
    cout << "Input resistor value (ohms): ";
    cin >> resistance;
    if (resistance >= 0) {
      resistors.push_back(resistance);
      cout << endl;
    } else {
      break;
    }
  }
  cout << endl;
}

void Ohms2::utility() {
  // get total resistance
  for (int k = 0; k < resistors.size(); k++) {
    totalResistance += resistors.at(k);
  }
  // get series current and total power consumption
  seriesCurrent = sourceVoltage / totalResistance;
  totalPower = seriesCurrent * sourceVoltage;
}

void Ohms2::resistorUtility() {
  for (int n = 0; n < resistors.size(); n++) {
    voltageAcross.push_back(resistors.at(n) * seriesCurrent);
    powerConsumption.push_back(seriesCurrent * voltageAcross.at(n));
  }
}

void Ohms2::display() {
  cout << "Voltage Source: " << sourceVoltage << " volts" << endl;
  cout << "Series Current: " << seriesCurrent << " amps" << endl;
  cout << "Total Power: " << totalPower << " watts" << endl;
  cout << endl;
  // output voltage drop and power dissipation for each resistor
  for (int d = 0; d < resistors.size(); d++) {
    cout << "R" << (d+1) << endl;
    cout << "Resistance: " << resistors.at(d) << " ohms" << endl;
    cout << "Voltage Drop: " << voltageAcross.at(d) << " volts" << endl;
    cout << "Power Dissipation: " << powerConsumption.at(d) << " watts" << endl;
    cout << endl;
  }
}



int main() {
  Ohms2 circuit; // create circuit
  circuit.setup(); // setup circuit
  circuit.utility(); // utilities
  circuit.resistorUtility();
  circuit.display(); // display values

  return 0;
}
