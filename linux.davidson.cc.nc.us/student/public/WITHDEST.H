// filename: withdest.h
#ifndef WITHDEST_H
#define WITHDEST_H

class withDestructor {
public:
  withDestructor(char* initText);
  ~withDestructor();
private:
  char* my_chars;
};

#endif

