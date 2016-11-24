#include "StringInstrument.h"

int main() {

  StringInstrument myStringInstrument("pling");

  std::cout << std::endl;  
  myStringInstrument.makeSound();

  //exit the programm -> deconstructor Instrument objects will be called
  return 0;
}
