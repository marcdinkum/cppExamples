#include "saw.h"

//Constructors and destructor
Saw::Saw(double samplerate) : Saw(samplerate, 0, 0) {}

Saw::Saw(double samplerate, double frequency) :
  Saw(samplerate, frequency, 0) {}

Saw::Saw(double samplerate, double frequency, double phase) :
  Oscillator (samplerate, frequency, phase) {}

Saw::~Saw() {}

//override calculate method
//this method contains the sample calculation
void Saw::calculate()
{
  //NOTE - wPhase
  //add 0.5 to phase, to allow a regular sawwave
  //(starting at 0, -> 1, -1 -> 0 )
  wPhase = phase + 0.5;
  //we want values between: [0.0, 1.0], so wrap it
  if(wPhase > 1) wPhase -= 1;

  //calculate the pure sawwave
  sample = phase * 2 - 1;
}
