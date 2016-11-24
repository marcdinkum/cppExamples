#ifndef H_INSTRUMENT
#define H_INSTRUMENT

#include <iostream>

class Instrument {
public:
  void makeSound();
  //setter and getter function - aSound field
  void setSound(std::string aSound);
  std::string getSound();
  std::string & playablePart();

//a base class protected member will be accessible for a derived class
protected:
  Instrument();
  /*
   * inside a function declaration you can set a default argument
   * when the constructor below is called, with only the first string,
   * playablePart is set to "an unknown part"
   */
  Instrument(std::string sound, std::string playablePart = "an unknown part");
  //destructor
  ~Instrument();

private:
  /*
   * giving a leading underscore to private data members is a convention
   * that is used by some programmers to remind you they are private
   */
  std::string _sound;
  std::string _playablePart;
};




#endif
