#ifndef H_INSTRUMENT
#define H_INSTRUMENT

#include <iostream>

//class declaration
class Instrument {
public:
//__ member functions a.k.a. methods __
  void makeSound();
  //setter and getter function - aSound field
  void setSound(std::string aSound);
  std::string getSound();

private:
//__ member variables a.k.a. fields __
  std::string sound;
};




#endif
