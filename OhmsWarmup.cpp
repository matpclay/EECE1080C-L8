/*
* @author Matthew Clayton
* @date 31 October 2016
* @assign.ment Lab 8 Ohm's Law
* @descrip.tion
* This file contains the code for Part 1 of the Ohm's Law lab (L8)
* for EECE1080C. This file handles a situation involving one
* resistor and one DC input voltage source, then uses these values
* to calculate the current and power values. This program
* contains a constructor to get keyboard input, and an overloaded
* constructor to get parameterized input.
*
* This program does not handle non-numerical input.
*/

#include <iostream>
using namespace std;

class OhmsWarmup {
  // private members to store values
  double voltage;
  double resistance;
  double current;
  double power;
public:
  // getters and setters for voltage and resistance
  void setVoltage(double);
  void setResistance(double);
  double getVoltage() {return voltage;}
  double getResistance() {return resistance;}
  // unclear if getters are wanted for current and power
  double getCurrent() {return current;}
  double getPower() { return power;}
  // utility and display methods
  void utility();
  void display();
  // constructors
  OhmsWarmup();
  OhmsWarmup(double, double);
  // deconstructor
  ~OhmsWarmup();
};

// constructors
OhmsWarmup::OhmsWarmup(void) {
  cout << "Enter Voltage: ";
  cin >> voltage;
  cout << "Enter Resistance: ";
  cin >> resistance;
  current = voltage / resistance;
  power = voltage * current;
}

OhmsWarmup::OhmsWarmup(double volts, double resistor) {
  voltage = volts;
  resistance = resistor;
  current = voltage / resistance;
  power = voltage * current;
}

// deconstructor
OhmsWarmup::~OhmsWarmup(void) {
  cout << "Circuit Destroyed" << endl;
}

// setters
void OhmsWarmup::setVoltage(double volt) {
  voltage = volt; // sets voltage
}

void OhmsWarmup::setResistance(double resist) {
  resistance = resist; // sets resistance
}

// utility, unclear if wanted voltage and
// current to be parameters or just accessed
void OhmsWarmup::utility() {
  current = getVoltage() / getResistance();
  power = getVoltage() * current;
}

// display
void OhmsWarmup::display(void) {
  cout << "Circuit Parameters: " << endl;
  cout << "\tVoltage: " << getVoltage() << "ohm" << endl;
  cout << "\tResistance: " << getResistance() << "volts" << endl;
  cout << "\tCurrent: " << getCurrent() << "Amps" << endl;
  cout << "\tPower: " << getPower() << "Watts" << endl;
}

int main() {
  OhmsWarmup overload(10, 1);
  overload.display();

  OhmsWarmup standard;
  standard.display();

}
