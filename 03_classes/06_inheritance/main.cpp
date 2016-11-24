#include "StringInstrument.h"

int main() {

  StringInstrument myStringInstrument("pling");

  myStringInstrument.makeSound();

  //exit the programm -> deconstructor Instrument objects will be called
  return 0;
}
