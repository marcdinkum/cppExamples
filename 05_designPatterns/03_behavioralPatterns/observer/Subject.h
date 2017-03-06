#include <list>
#include "Observer.h"

#ifndef SUBJECT_H
#define SUBJECT_H

class Subject {
public:
  virtual ~Subject();

  virtual void attach(Observer* observer);
  virtual void detach(Observer* observer);
  virtual void notify();

protected:
  Subject();
private:
  std::list<Observer*> _observers;
};

#endif
