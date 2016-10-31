/*
* @author Matthew Clayton
* @date 31 October 2016
* @assign.ment Lab 8 Ohm's Law
* @descrip.tion
* This file contains the code for Part 1 of the Ohm's Law lab (L8)
* for EECE1080C. This file handles a situation involving one
* resistor and one DC input voltage source, then uses these values
* to calculate the current and power values.
*
* This program does not handle non-numerical input.
*/

#include <iostream>
using namespace std;

class Ohms1 {
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
  Ohms1();
  Ohms1(double, double);
  // deconstructor
  ~Ohms1();
};

// constructors
Ohms1::Ohms1(void) {
  cout << "Enter voltage (volts): ";
  cin >> voltage;
  cout << "Enter resistance (ohms): ";
  cin >> resistance;
  current = voltage / resistance;
  power = voltage * current;
}

Ohms1::Ohms1(double volts, double resistor) {
  voltage = volts;
  resistance = resistor;
  current = voltage / resistance;
  power = voltage * current;
}

// deconstructor
Ohms1::~Ohms1(void) {
  cout << "Circuit Destroyed" << endl;
}

// setters
void Ohms1::setVoltage(double volt) {
  voltage = volt; // sets voltage
}

void Ohms1::setResistance(double resist) {
  resistance = resist; // sets resistance
}

// utility, unclear if wanted voltage and
// current to be parameters or just accessed
void Ohms1::utility() {
  current = getVoltage() / getResistance();
  power = getVoltage() * current;
}

// display
void Ohms1::display(void) {
  cout << "Voltage (volts): " << getVoltage() << endl;
  cout << "Resistance (ohms): " << getResistance() << endl;
  cout << "Current (amps): " << getCurrent() << endl;
  cout << "Power (watts): " << getPower() << endl;
}
