#pragma once
#include "glut.h"
#include "vector.h"

class Camera {
  public:
            Camera() : location_(0,0,0) {}
    void    init( const std::string &fileName ) {}
  private:
    Vector<float>   location_;
};
