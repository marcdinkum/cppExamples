#ifndef _PULSE_H_
#define _PULSE_H_
#include "oscillator.h"

class Pulse : public Oscillator
{
public:

  //constructors and destructor
  Pulse(double samplerate);
  Pulse(double samplerate, double frequency);
  Pulse(double samplerate, double frequency, double phase);
  ~Pulse();
  //prevent the default constructor to be generated
  Pulse() = delete;

  //override calculate
  //this method contains the sample calculation
  void calculate();
  void setPulseWidth(float pulseWidth);
  float getPulseWidth();
/*
  NOTE: we could use a seperate calculate method
  in that case -> overriding getSample is not necessary.
*/
private:
  //pulse width
  float pulseWidth;
};

#endif
