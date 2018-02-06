#include "pulse.h"

#define OUTPUT_PULSEWAVE 1

//Constructors and destructor
Pulse::Pulse(double samplerate) : Pulse(samplerate, 0, 0) {}

Pulse::Pulse(double samplerate, double frequency) :
  Pulse(samplerate, frequency, 0) {}

//default pulseWidth = 0.5
Pulse::Pulse(double samplerate, double frequency, double phase) :
  Oscillator (samplerate, frequency, phase), pulseWidth(0.5) {}

Pulse::~Pulse() {}

//override calculate method
//this method contains the sample calculation
void Pulse::calculate()
{
  //NOTE - creating a pure pulse wave -> ALIASING ISSUES!!!
  sample = phase < pulseWidth ? 1 : -1;
  //write output pulsewave to console
  #if OUTPUT_PULSEWAVE
    static int i = 0;
    if(i < 1000) std::cout << "\n" << i << "\t" << sample;
    i++;
  #endif
}

void Pulse::setPulseWidth(float pulseWidth)
{
  if(pulseWidth > 0 && pulseWidth < 1) {
    this->pulseWidth = pulseWidth;
  }
  else {
    std::cout << "'nPulse::setPulseWidth - "
      << "incorrect pulseWidth passed, keep value between 0 & 1\n";
  }
}


float Pulse::getPulseWidth()
{
  return pulseWidth;
}
