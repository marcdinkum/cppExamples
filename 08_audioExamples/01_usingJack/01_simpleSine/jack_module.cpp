/*
#
# 2017 Marc Groenewegen
# (altered by Ciska Vriezenga)
#
*/

#include <iostream>
#include <mutex>
#include <unistd.h> // usleep
//TEMP - remove
#include "math.h"
#include "jack_module.h"

// prototypes & globals
static void jack_shutdown(void *);
static jack_port_t *input_port,*output_port;


JackModule::JackModule()
{

} // JackModule()



JackModule::~JackModule()
{
  //deactivate jack and disconnect jack ports
  end();
} // ~JackModule()


int JackModule::init()
{
  return init("JackModule");
} // init()


int JackModule::init(std::string clientName)
{
  //open an external client session with a JACK server
  //TODO alter (jack_options_t)0, ->  jack_options_t.JackNullOption
  client = jack_client_open(clientName.c_str(),(jack_options_t)0,NULL);
  if( client == 0) {
    std::cout <<  "Unable to retrieve a JACK client. \n " <<
                  "Is the JACK server running?" << std::endl;
    return 1;
  }

  // install a shutdown callback
  jack_on_shutdown(client,jack_shutdown,0);
  // Install the callback wrapper
  jack_set_process_callback(client,_wrap_jack_process_cb,this);

  //Create an output and input port for the client.
  output_port =
    jack_port_register(client,"output",JACK_DEFAULT_AUDIO_TYPE,JackPortIsOutput,0);
  input_port =
    jack_port_register(client,"input",JACK_DEFAULT_AUDIO_TYPE,JackPortIsInput,0);

  //Tell the Jack server that the program is ready to start processing audio.
  if(jack_activate(client)) {
    std::cout << "Cannot activate client." << std::endl;
    return -1;
  } // if

  return 0;
} // init()

//returns the jack_clients samplerate
unsigned long JackModule::getSamplerate()
{
  return jack_get_sample_rate(client);
} // getSamplerate()


void JackModule::autoConnect()
{
  /*
   * Try auto-connect our output
   *
   * NB: JACK considers reading from an output and sending to an input
   */
  if((ports = jack_get_ports(client,"system",NULL,JackPortIsInput)) == NULL)
  {
    std::cout << "Cannot find any physical output ports" << std::endl;
    exit(1);
  }

  if(jack_connect(client,jack_port_name(output_port),ports[0]))
  {
    std::cout << "Cannot connect output ports" << std::endl;
  }

  if(jack_connect(client,jack_port_name(output_port),ports[1]))
  {
    std::cout << "Cannot connect output ports" << std::endl;
  }

  free(ports); // ports structure no longer needed

  /*
   * Try auto-connect our input
   */
  if((ports = jack_get_ports(client,NULL,NULL,JackPortIsPhysical|JackPortIsOutput)) == NULL)
  {
    std::cout << "Cannot find any physical capture ports" << std::endl;
    exit(1);
  }

  if(jack_connect(client,ports[0],jack_port_name(input_port)))
  {
    std::cout << "Cannot connect input ports" << std::endl;
  }

  free(ports); // ports structure no longer needed
} // autoConnect()

/* Deactivate jack and disconnect jack ports*/
void JackModule::end()
{
  jack_deactivate(client);
  jack_port_disconnect(client,input_port);
  jack_port_disconnect(client,output_port);
} // end()


/* allows to use a cpp function for the audio callback function */
int JackModule::_wrap_jack_process_cb(jack_nframes_t nframes,void *arg)
{
  return ((JackModule *)arg)->onProcess(nframes);
} // _wrap_jack_process_cb()


int JackModule::onProcess(jack_nframes_t nframes)
{
  /* in and out are seen from JACK's perspective
   * meaning that
   *    (audio input)
   *  - samples are read from the input and written into the input ringbuffer
   *
   *    (audio output)
   *  - samples are read from the output ringbuffer and written to the output
   */
  void *in = jack_port_get_buffer(input_port,nframes);
  void *out = jack_port_get_buffer(output_port,nframes);

  static double phase=0;
  static double outputSample;
  static double samplerate = getSamplerate();

  for(int i = 0; i < nframes; i++) {
    outputSample = 0.4*sin(phase);
    phase += 880*2*M_PI/samplerate;
    ((jack_default_audio_sample_t *)out)[i] = outputSample;
  }

  return 0;
} // onProcess()


/*
 * shutdown callback may be called by JACK
 */
static void jack_shutdown(void *arg)
{
  exit(1);
} // jack_shutdown()
