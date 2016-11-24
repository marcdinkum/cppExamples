#ifndef H_INSTRUMENT
#define H_INSTRUMENT

#include <iostream>

//class declaration
class Instrument {
public:
  //default constructor
  Instrument();
  //overloaded constructor
  Instrument(std::string aSound);
  //destructor
  ~Instrument();

  void makeSound();
  //setter and getter function - aSound field
  void setSound(std::string aSound);
  std::string getSound();

private:
  std::string sound;
};




#endif
