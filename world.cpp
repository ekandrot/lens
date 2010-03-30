#include "thing.h"
#include "world.h"

void World::init( const std::string &fileName ) {
    Group *group = new Group;
    thing_ = group;

//    Sphere *s;

//    s = new Sphere( 1.0f );

    group->add( new Sphere( 1.0f, Vector<float>( -1.5, 0, 0 ), Color<float>( 1,0,0,1) ) );
    group->add( new Sphere( 0.5f, Vector<float>( 2.0f, 0.2f, 0.2f ), Color<float>(0,1,0,1) ) );
    group->add( new Sphere( 1.5f, Vector<float>( 0.0f, 2.2f, -0.2f ), Color<float>(0,0,1,1) ) );
    group->add( new Sphere( 1.0f ) );
}


