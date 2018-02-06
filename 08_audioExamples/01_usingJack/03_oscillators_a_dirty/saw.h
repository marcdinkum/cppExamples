#ifndef _SAW_H_
#define _SAW_H_
#include "oscillator.h"

class Saw : public Oscillator
{
public:

  //constructors and destructor
  Saw(double samplerate);
  Saw(double samplerate, double frequency);
  Saw(double samplerate, double frequency, double phase);
  ~Saw();
  //prevent the default constructor to be generated
  Saw() = delete;

  //override calculate
  //this method contains the sample calculation
  void calculate();

/*
  NOTE: we could use a seperate calculate method
  in that case -> overriding getSample is not necessary.
*/
private:
  //wrapped phase, used to offset the phase 0.5 before calculating sawwave
  double wPhase;

};

#endif
