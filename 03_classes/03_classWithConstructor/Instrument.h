#ifndef H_INSTRUMENT
#define H_INSTRUMENT

#include <iostream>

class Instrument {
public:
  //constructor
  Instrument();
  //it is possible to overload the constructor to allow setting aSound string
  Instrument(std::string aSound);

  void makeSound();
  //setter and getter function - aSound field
  void setSound(std::string aSound);
  std::string getSound();

private:
  std::string sound;
};




#endif
