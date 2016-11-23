#include "Instrument.h"

/*
 * @method makeSound - prints object.sound to console
 */
void Instrument::makeSound() {
  std::cout << "A sound is produced: \"";
  std::cout << sound << "\"" << std::endl;
}


/*
 * @method setSound - setter method for sound field
 */
void Instrument::setSound(std::string aSound) {
  //check if string is not empty
  if(aSound.size() > 0) {
    sound = aSound;
  }
}

/*
 * @method getSound - getter method for sound field, returns sound
 */
std::string Instrument::getSound() {
  return sound;
}
