#include <string>
#include "glut.h"
#include "pixmap.h"
#include "camera.h"
#include "world.h"
#include "render.h"


class MyGlut : public Glut {
  public:
    MyGlut() : Glut(false, true) {}

    virtual void init( int *argc, char **argv, int width, int height ) {
        Glut::init( argc, argv, width, height );
        //pixmap_.init( width, height );
        render_.init();

        camera_.init( "basic.camera" );
        render_.set_camera( camera_ );

        world_.init( "basic.world" );
        render_.set_world( world_ );
    }

    virtual void display_event( void ) {
        glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
        render_.render();
        //glDrawPixels( pixmap_.width(), pixmap_.height(), GL_RGBA, GL_UNSIGNED_BYTE, pixmap_.pixels() );
    }

    virtual void reshape_event( int width, int height ) {
        //pixmap_.resize( width, height, CLEAR );
        do_pixels();
        Glut::reshape_event( width, height );
    }

    void do_pixels( void ) {
        //render_.render( pixmap_.width(), pixmap_.height(), pixmap_.stride(), pixmap_.pixels() );
    }

  private:
    //Pixmap  pixmap_;
    Camera  camera_;
    World   world_;
    Render  render_;
};


int main( int argc, char **argv ) {
    MyGlut  glut;

    glut.init( &argc, argv, 512, 512 );
    //glut.do_pixels();

    // we use try/catch to clean up after glut's endless loop
    // in the glut or derived glut classes, we should throw rather than exit
    int     exitCode = 0;
    try {
        glut.loop();
    }
    catch (int e) {
        exitCode = e;
    }

    return exitCode;
}
