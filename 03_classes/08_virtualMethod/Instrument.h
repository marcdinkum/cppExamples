#ifndef H_INSTRUMENT
#define H_INSTRUMENT

#include <iostream>

class Instrument {
public:
  std::string getName();
  virtual void makeSound();

//a base class protected member will be accessible for a derived class
protected:
  Instrument(std::string name);
  //destructor
  ~Instrument();

private:
  std::string name;
};




#endif
