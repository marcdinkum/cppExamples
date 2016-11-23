#include "Instrument.h"

int main() {
  //create an Instrument object
  Instrument myInstrument;

  //line below would not work, because sound is a private field
  //myInstrument.sound = "Ding";

  //set the sound field by the use of setter
  myInstrument.setSound("Ding");
  //print the content of the sound field to console, by the use of getter
  std::cout << "myInstrument.sound contains: \"";
  std::cout << myInstrument.getSound() << "\"" << std::endl;

  //call the makeSound method 'make a sound into the console'
  myInstrument.makeSound();

  //exit the programm
  return 0;
}
