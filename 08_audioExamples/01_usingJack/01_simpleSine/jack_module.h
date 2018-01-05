/*
#
# 2017 Marc Groenewegen
# (altered by Ciska Vriezenga)
#
*/

#include <string>
#include <jack/jack.h>


class JackModule
{
public:
  JackModule();
  ~JackModule();
  int init();
  int init(std::string clientName);
  unsigned long getSamplerate();
  void autoConnect();
  void end();
private:
  static int _wrap_jack_process_cb(jack_nframes_t nframes,void *arg);
  int onProcess(jack_nframes_t nframes);
  jack_client_t *client;
  const char **ports;
  unsigned long frames_pushed;
  unsigned long frames_popped;
};
