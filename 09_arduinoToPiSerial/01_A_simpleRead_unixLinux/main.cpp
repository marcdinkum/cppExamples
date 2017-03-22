#include <unistd.h>
#include <iostream>

//NOTE ****  ONLY WORKS ON UNIX / LINUX ****

int main()
{
  //size of the buffer we use to read the serial data with
  static constexpr int bufSize = 2;
  //create char buffer to use to read the serial values
  //retrieve from -128 up to 127, or use unsigned char -> 0 : 255
  char buffer[bufSize];
  //create int buffer to hold int values (transform char to int)
  int sensorVal[bufSize];

  //set serial port
  const char* devicename = "/dev/cu.usbmodem1411";

  /*
   * pointer to file, on UNIX / LINUX we can read serial data from a port as if
   * port is a file.
   */
  FILE* file = fopen(devicename,"r");

  if(file==NULL)
  { //if there is no serial port
    printf("Unable to open device %s\n",devicename);
    exit(1);
  }//if

  while(1) {
    //read serial data
    fread(&buffer,bufSize,1,file);

    std::cout << std::endl;
    //fill buffer with serial data
    for(int i = 0; i < bufSize; i++){
      sensorVal[i] = buffer[i];
      std::cout << sensorVal[i] << ", ";
    }
    usleep(1);
  }

}
