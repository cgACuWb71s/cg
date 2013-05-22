#pragma once

struct vector3
{
    union
    {
	float c[3];
	struct
	{
	    float x;
	    float y;
	    float z;
	};
    };

    vector3();
    vector3(vector3 const& v);
    vector3(float const& x, float const& y, float const& z);
    
    vector3&
    operator=(vector3 const& v);
    vector3&
    operator+=(vector3 const& v);
    vector3&
    operator-=(vector3 const& v);
    vector3&
    operator*=(float const& f);
    vector3&
    operator/=(float const& f);
};

vector3
operator+(vector3 const& a, vector3 const& b);
vector3
operator-(vector3 const& a, vector3 const& b);
vector3
operator*(vector3 const& a, float const& f);
vector3
operator/(vector3 const& a, float const& f);

float
len(vector3 const& b);

vector3
cross(vector3 const& a, vector3 const& b);

vector3
norm(vector3 const& b);
