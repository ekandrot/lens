#include <iostream>
#include <typeinfo>
#include "glut.h"
#include "thing.h"
#include "render.h"


void Render::init( void ) {
    glLoadIdentity();
    glNewList( 1, GL_COMPILE );
        glutSolidSphere( 1.0f, 50, 50 );
    glEndList();
    displayListBegin = 10;
    displayListEnd = 10;
}


void Render::set_camera( const Camera& camera ) {
}


void Render::parse_thing( const Thing *thing ) {
    if (typeid(*thing) == typeid(Group)) {
        const Group *g = dynamic_cast<const Group*>( thing );
        for (std::vector<Thing*>::const_iterator i=g->things().begin(); i!=g->things().end(); ++i) {
            parse_thing( *i );
        }
    } else if (typeid(*thing) == typeid(Sphere)) {
        const Sphere *s = dynamic_cast<const Sphere*>( thing );
        float radius = s->radius();
        glNewList( displayListEnd++, GL_COMPILE );
            glPushMatrix();
            glTranslatef( s->location().x, s->location().y, s->location().z );
            glScalef( radius, radius, radius );
            glColor4f( s->color().r, s->color().g, s->color().b, s->color().a );
            glCallList( 1 );
            glPopMatrix();
        glEndList();
    }
}


void Render::set_world( const World& world ) {
    glLoadIdentity();

    const Thing *thing = world.thing();
    parse_thing( thing );

}


void Render::render( void ) {
    for (int i=displayListBegin; i<displayListEnd; ++i) {
        glCallList( i );
    }
}
