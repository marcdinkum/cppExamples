#include "Instrument.h"

Instrument::Instrument() {
 std::cout << "______ Instrument - ";
 std::cout << "inside constructor Instrument()\n";
}

Instrument::Instrument(std::string aSound, std::string playablePart) {
 std::cout << "______ Instrument - ";
 std::cout << "inside constructor Instrument(std::string aSound, std::string playablePart)\n";
 _sound = aSound;
 _playablePart = playablePart;
}

//the deconstructor will be called when object is destroyed
//can be used to free up memory that was used to create the object
//or e.g. close an output file
Instrument::~Instrument() {
  std::cout << "______ Instrument - ";
  std::cout << "inside destructor\n";
}

void Instrument::makeSound() {
  std::cout << "On \"" << _playablePart << "\" ";
  std::cout << "a sound is produced: \"";
  std::cout << _sound << "\"" << std::endl;
}

void Instrument::setSound(std::string aSound) {
  //check if string is not empty
  if(aSound.size() > 0) {
    _sound = aSound;
  }
}

std::string & Instrument::playablePart() {
  return _playablePart;
}

std::string Instrument::getSound() {
  return _sound;
}
