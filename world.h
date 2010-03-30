#pragma once
#include <string>
#include "glut.h"
#include "vector.h"
#include "thing.h"

class World {
  public:
    void init( const std::string &fileName );

    Thing* thing( void ) const    {return thing_;}
  private:
    Thing  *thing_;
};

