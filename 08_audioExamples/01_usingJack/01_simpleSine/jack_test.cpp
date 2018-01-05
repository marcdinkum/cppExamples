#include <iostream>
#include <thread>
#include "jack_module.h"
#include "math.h"
#include "unistd.h"

/*
 * With this abstraction module we don't need to know JACK's buffer size
 *   but we can independently determine our own block sizes
 */
unsigned long anachunksize=2048;
unsigned long synthchunksize=1024;

float *anabuffer = new float [anachunksize];
float *synthbuffer = new float [synthchunksize];


JackModule jack;

unsigned long samplerate=44100; // default

/*
 * play function generates audio samples and writes these to JACK
 */
static void play(unsigned long nframes)
{
  unsigned nplayed=0;
  double phase=0;

  do {

    // generate a chunk of samples
    for(unsigned long i=0; i<synthchunksize; i++){
      synthbuffer[i]=0.4*sin(phase);
      phase += 880*2*M_PI/(double)samplerate;
    } // for

    jack.writeSamples(synthbuffer,synthchunksize);
    nplayed+=synthchunksize;
  } while(nplayed < nframes);

} // play()



/*
 * analysis function reads audio samples from JACK for further processing
 */
static void analysis(unsigned long nframes)
{
  unsigned nread=0;

  do {
    jack.readSamples(anabuffer,anachunksize);

    // write incoming audio as text to stdout
    for(unsigned long frame=0; frame<anachunksize; frame++){
      std::cout << anabuffer[frame] << std::endl;
    }

    nread+=anachunksize;
  } while(nread < nframes);

} // analysis()



int main(int argc,char **argv)
{

  jack.init(argv[0]); // use program name as JACK client name
  jack.autoConnect();

  samplerate=jack.getSamplerate();
  std::cerr << "Samplerate: " << samplerate << std::endl;

  std::thread playThread(play,samplerate*5);
  std::thread analysisThread(analysis,samplerate*5);

  playThread.join();
  analysisThread.join();

  jack.end();

  return 0;
} // main()

