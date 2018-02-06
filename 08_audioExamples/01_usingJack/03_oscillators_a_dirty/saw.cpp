#include "saw.h"
#define OUTPUT_SAWWAVE 1

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
  //NOTE - creating a pure sine wave -> ALIASING ISSUES!!! 
  //add 0.5 to phase, to allow a regular sawwave
  //(starting at 0, -> 1, -1 -> 0 )
  wPhase = phase + 0.5;
  //we want values between: [0.0, 1.0], so wrap it
  if(wPhase > 1) wPhase -= 1;

  //calculate the pure sawwave
  sample = wPhase * 2 - 1;

  //write output sawwave to console
  #if OUTPUT_SAWWAVE
    static int i = 0;
    if(i < 1000) std::cout << "\n" << i << "\t" << sample;
    i++;
  #endif
}
