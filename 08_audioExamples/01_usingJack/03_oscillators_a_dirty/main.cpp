#include <iostream>
#include <thread>
#include <time.h>

#include "jack_module.h"
#include "sine.h"
#include "saw.h"
#include "square.h"
#include "pulse.h"


/*
 * This example plays the sine, saw and square oscillators
 *
 * ------ HANDS-ON TIPS ------
 * TODO - add HANDS-ON tips
 * ---------------------------
 */


int main(int argc,char **argv)
{
  //create a JackModule instance
  JackModule jack;

  // init the jack, use program name as JACK client name
  jack.init(argv[0]);

  //create a Sine instance
  Sine sine(jack.getSamplerate(), 220, 0);
  //create a Saw instance
  Saw saw(jack.getSamplerate(), 220, 0);
  //create a Square instance
  Square square(jack.getSamplerate(), 220, 0);
  //create a Pulse instance
  Pulse pulse(jack.getSamplerate(), 220, 0);
  //set the pulsewidth
  pulse.setPulseWidth(0.01);

  //create array of oscillator pointers and assign the four oscillators
  int numOscillators = 4;
  Oscillator **oscillators = new Oscillator*[numOscillators];
  oscillators[0] = &sine;
  oscillators[1] = &saw;
  oscillators[2] = &square;
  oscillators[3] = &pulse;


  //create variable to keep track of the current oscillator index
  int currentOscIndex = 0;
  //create an Oscillator pointer and assign a derived class to it.
  Oscillator *currentOscillator = oscillators[currentOscIndex];

  //retrieve the current time -> 'checkpoint'
  time_t checkpointTime = time(NULL);
  //assign a function to the JackModule::onProces
  jack.onProcess = [  &currentOscillator, &oscillators,
                      &numOscillators, &currentOscIndex,
                      &checkpointTime]
                    (jack_default_audio_sample_t *inBuf,
     jack_default_audio_sample_t *outBuf, jack_nframes_t nframes)
  {
    //loop through frames, retrieve sample of sine per frame
    for(int i = 0; i < nframes; i++) {
      //TODO check type of jack_default_audio_sample_t, double? or float?
      outBuf[i] = currentOscillator->getSample();
      currentOscillator->tick();
    }
    //NOTE: dirty time manangement, good enough to demonstrate polymorphism
    if(difftime(time(NULL), checkpointTime)) {
      //retrieve netx oscillator index
      currentOscIndex++;
      if(currentOscIndex >= numOscillators) currentOscIndex = 0;
      std::cout << "\nSwitching to other oscillator at index: "
        << currentOscIndex << "\n";

      //assign oscillator at this next index to currentOscillator
      //NOTE: clicks may occur!! 
      currentOscillator = oscillators[currentOscIndex];
      //reset time checkpoint
      checkpointTime = time(NULL);
    }
    return 0;
  };


  //
  jack.autoConnect();

  //keep the program running and listen for user input, q = quit
  std::cout << "\n\nPress 'q' when you want to quit the program.\n";
  bool running = true;
  while (running)
  {
      switch (std::cin.get())
      {
          case 'q':
            running = false;
            break;
      }
  }

  //end the program
  return 0;
} // main()
