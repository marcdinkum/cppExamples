#include "simpleSynth.h"

/*---------------- CONSTRUCTORS / DESTRUCTOR ----------------*/
//constructor - calls the other constructor with midiPitch = 0
SimpleSynth::SimpleSynth(double samplerate)
  : SimpleSynth(samplerate, 0) {}

//using 0 as init value for midiPitch and sine frequency value
SimpleSynth::SimpleSynth(double samplerate, float midiPitch)
  : Synth(samplerate, midiPitch), sine(samplerate, 0) {
    //We need to set midiPitch in derived class,
    //because of pure virtual updateFrequency method, which will be called
    //the derived class first needs to be initialized.
    setMidiPitch(midiPitch);
  }

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
