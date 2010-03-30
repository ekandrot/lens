#pragma once
#include <string>
#include "glut.h"
#include "camera.h"
#include "world.h"

class Render {
  public:
            Render() {}
            ~Render() {}

    void    init( void );
    void    render( void );

    void    set_camera( const Camera& camera );
    void    set_world( const World& world );

  private:
    void parse_thing( const Thing *thing );

    int displayListBegin, displayListEnd;
};
