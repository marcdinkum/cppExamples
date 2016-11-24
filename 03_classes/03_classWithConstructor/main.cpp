#include "Instrument.h"

int main() {
  //create an Instrument object
  Instrument myInstrument;

  //create another Instrument object, using the other constructor
  Instrument secondInstrument("Dong");

  //set the sound field by the use of setter
  myInstrument.setSound("Ding");
  //call the makeSound method 'make a sound into the console'
  myInstrument.makeSound();

  //secondInstrument.aSound is set in the constructor
  //therefor secontInstrument.makeSound will print 'Dong'
  secondInstrument.makeSound();

  //exit the programm
  return 0;
}
