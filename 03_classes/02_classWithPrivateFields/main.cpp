#include "Instrument.h"


/*
 * The class Instrument contains the private field sound.
 * A private field cannot be accesed or viewed from outside the class.
 * Only the class itself (and friends) can acces private members.
 *
 * ------ HANDS-ON TIPS ------
 * • Try accessing the field 'sound' directly inside the main function:
 * myInstrument.sound;
 * And before running make, what do you expect to happen?
 *
 * • Move the field 'sound' below the 'public' acces specifier. Can you acces
 * it directly from the main?
 * ---------------------------
 */


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
