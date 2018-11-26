#define NUM_NOTES 10

class Melody
{
public:
  // constructor and destructor
  Melody();
  ~Melody();

  /*
   * getNote()
   * returns the note at the readIndex
   * returns -1 when there is no note available
   */
  int getNote();
  
  /*
   * addNote()
   * adds a note to the melody (only if 'spots' are available)
   */
  void addNote(int note);

private:
  // array of ints containing the note values
  int notes[NUM_NOTES];
  
  // read and write index pointing into the notes array
  int readIndex;
  int writeIndex;
};
