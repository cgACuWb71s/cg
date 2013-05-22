#include "vector3.hpp"

#include <cmath>

vector3::vector3():
    x(0),y(0),z(0)
{}

vector3::vector3(vector3 const& v):
    x(v.x),y(v.y), z(v.z)
{}
    
vector3&
vector3::operator=(vector3 const& v)
{
    x=v.x;
    y=v.y;
    z=v.z;
    return *this;
};

vector3
cross(vector3 const& a, vector3 const& b)
{
    return vector3(a.y*b.z-a.z*b.y,
		  a.z*b.x-a.x*b.z,
		  a.x*b.y-a.y*b.x);
}

vector3::vector3(float const& _x, float const& _y, float const& _z):
    x(_x),y(_y),z(_z)
{}

vector3
norm(vector3 const& v)
{
    return v/len(v);
}

float
len(vector3 const& v)
{
    return std::sqrt(v.x*v.x+v.y*v.y+v.z*v.z);
}

vector3
operator+(vector3 const& a, vector3 const& b)
{
    return vector3(a.x+b.x, a.y+b.y, a.z+b.z);
}

vector3
operator-(vector3 const& a, vector3 const& b)
{
    return a + (b*-1);
}

vector3
operator*(vector3 const& a, float const& f)
{
    return vector3(a.x*f, a.y*f, a.z*f);
}

vector3
operator/(vector3 const& a, float const& f)
{
    return a * (1/f);
}

vector3&
vector3::operator+=(vector3 const& v)
{
    *this=*this + v;
    return *this;
}

vector3&
vector3::operator-=(vector3 const& v)
{
    *this=*this - v;
    return *this;
}

vector3&
vector3::operator*=(float const& f)
{
    *this=*this*f;
    return *this;
}

vector3&
vector3::operator/=(float const& f)
{
    *this=*this/f;
    return *this;
}
