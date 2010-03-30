#pragma once
#include <vector>
#include "vector.h"
#include "color.h"

class Thing {
  public:
    Thing() : location_(0,0,0) {}
    virtual ~Thing() {}

    void set_location( const Vector<float> &v ) {location_ = v;}

    Vector<float> location( void ) const {return location_;}

  protected:
    Vector<float>   location_;
};


class Group : public Thing {
  public:
    Group() {}
    virtual ~Group() {}

    void add( Thing *thing ) {things_.push_back( thing );}

    const std::vector<Thing*> *things( void ) const {return &things_;}

  private:
    std::vector<Thing*> things_;
};


class Sphere : public Thing {
  public:
    Sphere() : radius_(0), color_(1,1,1,1) {}
    Sphere( float radius ) : radius_(radius), color_(1,1,1,1) {}
    Sphere( float radius, const Vector<float> &v ) : radius_(radius), color_(1,1,1,1) {location_ = v;}
    Sphere( float radius, const Vector<float> &v, const Color<float> &c ) : radius_(radius), color_(c) {location_ = v;}
    virtual ~Sphere() {}

    float radius( void ) const {return radius_;}
    Color<float> color( void ) const {return color_;}

    void set_radius( float radius ) {radius_ = radius;}
    void set_color( const Color<float> &color ) {color_ = color;}

  private:
    float          radius_;
    Color<float>   color_;
};
