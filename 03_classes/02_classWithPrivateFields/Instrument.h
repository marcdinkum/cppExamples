#ifndef H_INSTRUMENT
#define H_INSTRUMENT

#include <iostream>

//class declaration
class Instrument {
public:
  //member functions a.k.a. methods
  void makeSound();
  void setSound(std::string aSound);
  std::string getSound();

private:
  //member variables a.k.a. fields
  std::string sound;
};
//NOTE: always use a semicolon at end of class declaration



#endif
