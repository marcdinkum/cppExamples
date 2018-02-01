#include "simpleSynth.h"

/*---------------- CONSTRUCTORS / DESTRUCTOR ----------------*/
//constructor - calls the other constructor with midiPitch = 0
SimpleSynth::SimpleSynth(double samplerate)
  : SimpleSynth(samplerate, 0) {}

//using 0 as init value for midiPitch and sine frequency value
SimpleSynth::SimpleSynth(double samplerate, float midiPitch)
  : Synth(samplerate, midiPitch), sine(samplerate, 0) {}

//destructor - delete s object, set pointer to nullptr
SimpleSynth::~SimpleSynth() {}

/*---------------- PUBLIC METHODS ----------------*/
//returns the current sample
double SimpleSynth::getSample() {
  //TODO add amplitude
  return sine.getSample();
}

//TODO - should we add a clock object with listeners, instead of using tick?
//updates sample, 'tick'
void SimpleSynth::tick() { sine.tick(); }


/*---------------- PRIVATE METHODS ----------------*/
//set the synth's frequency
void SimpleSynth::updateFrequency() {
  sine.setFrequency((double)frequency);
}
