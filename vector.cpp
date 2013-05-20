#include "vector.hpp"

#include <cmath>

vector::vector():
    x(0),y(0),z(0)
{}

vector::vector(vector const& v):
    x(v.x),y(v.y), z(v.z)
{}
    
vector&
vector::operator=(vector const& v)
{
    x=v.x;
    y=v.y;
    z=v.z;
    return *this;
};

vector
cross(vector const& a, vector const& b)
{
    return vector(a.y*b.z-a.z*b.y,
		  a.z*b.x-a.x*b.z,
		  a.x*b.y-a.y*b.x);
}

vector::vector(float const& _x, float const& _y, float const& _z):
    x(_x),y(_y),z(_z)
{}

vector
norm(vector const& v)
{
    return v/len(v);
}

float
len(vector const& v)
{
    return std::sqrt(v.x*v.x+v.y*v.y+v.z*v.z);
}

vector
operator+(vector const& a, vector const& b)
{
    return vector(a.x+b.x, a.y+b.y, a.z+b.z);
}

vector
operator-(vector const& a, vector const& b)
{
    return a + (b*-1);
}

vector
operator*(vector const& a, float const& f)
{
    return vector(a.x*f, a.y*f, a.z*f);
}

vector
operator/(vector const& a, float const& f)
{
    return a * (1/f);
}

vector&
vector::operator+=(vector const& v)
{
    *this=*this + v;
    return *this;
}

vector&
vector::operator-=(vector const& v)
{
    *this=*this - v;
    return *this;
}

vector&
vector::operator*=(float const& f)
{
    *this=*this*f;
    return *this;
}

vector&
vector::operator/=(float const& f)
{
    *this=*this/f;
    return *this;
}
