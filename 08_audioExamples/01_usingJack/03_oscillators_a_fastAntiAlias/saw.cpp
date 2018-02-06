#include "saw.h"
#define OUTPUT_SAWWAVE 0

//Constructors and destructor
Saw::Saw(double samplerate) : Saw(samplerate, 0, 0) {}

Saw::Saw(double samplerate, double frequency) :
  Saw(samplerate, frequency, 0) {}

Saw::Saw(double samplerate, double frequency, double phase) :
  Oscillator (samplerate, frequency, phase),
  phaseIncrement(frequency / samplerate * 5.0),
  smoothY(0) {
    //phaseIncrement, using a factor 5, which alters the smoothing.
    //TODO -> research aliasing with and without this factor
  }

Saw::~Saw() {}

//override calculate method
//this method contains the sample calculation
void Saw::calculate()
{
  //add 0.5 to phase, to allow a regular sawwave
  //(starting at 0, -> 1, -1 -> 0 )
  wPhase = phase + 0.5;
  //we want values between: [0.0, 1.0], so wrap it
  if(wPhase > 1) wPhase -= 1;

  //calculate the pure sawwave
  sample = wPhase * 2 - 1;

  //we want to apply smoothing to prevent aliasing
  //TODO - add comments to explain
  if(wrappedPhase < phaseIncrement) {
    smoothY = wrappedPhase / phaseIncrement;
    smoothY = smoothY + smoothY - smoothY * smoothY - 1.0;
  } else if (wrappedPhase > 1.0 - phaseIncrement) {
    smoothY = (wrappedPhase - 1.0) / phaseIncrement;
    smoothY = smoothY + smoothY + smoothY * smoothY + 1.0;
  } else {
    smoothY = 0;
  }
  sample -= smoothY;
#if OUTPUT_SAWWAVE
  static int i = 0;
  if(i < 1000) std::cout << "\n" << i << "\t" << sample;
  i++;
#endif
}
