#include "synth.h"

/*---------------- CONSTRUCTORS / DESTRUCTOR ----------------*/
//constructor - calls the other constructor with midiPitch = 0
Synth::Synth(double samplerate)
  : Synth(samplerate, 0) {}

//using 0 as init value for midiPitch and sine frequency value
Synth::Synth(double samplerate, float midiPitch)
  : samplerate(samplerate), midiPitch(midiPitch) {}

//destructor - delete s object, set pointer to nullptr
Synth::~Synth() {}

/*---------------- PUBLIC METHODS ----------------*/
//set the synth's pitch, using midi values.
void Synth::setMidiPitch(float midiPitch)
{
  //if midiPitch changes less then 1 cents, do not update the midiPitch
  if(midiPitch < this->midiPitch - 0.005 || midiPitch > this->midiPitch + 0.005){
    setFrequency(mtof(midiPitch));
  }//end if
}

//returns the current midiPitch
float Synth::getMidiPitch()
{
  return midiPitch;
}

/*---------------- PRIVATE METHODS ----------------*/
//set the synth's frequency
void Synth::setFrequency(float frequency) {
  //do not except frequencies below 0 and above nyquist
  if(frequency > 0 || frequency < 0.5 * samplerate) {
    this->frequency = frequency;
    //call updateFrequency method to allow derived classes to update frequency
    updateFrequency();
  }
  else {
    std::cout << "\nSynth::setFrequency - "
      << "values above nyquist aren't allowed\n";
  }
}

//translates midi to frequency
float Synth::mtof(float midiPitch)
{
  return pow(2.0,(midiPitch-69.0)/12.0) * 440.0;
}
