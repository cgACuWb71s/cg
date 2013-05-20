#pragma once

struct vector
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

    vector();
    vector(vector const& v);
    vector(float const& x, float const& y, float const& z);
    
    vector&
    operator=(vector const& v);
    vector&
    operator+=(vector const& v);
    vector&
    operator-=(vector const& v);
    vector&
    operator*=(float const& f);
    vector&
    operator/=(float const& f);
};

vector
operator+(vector const& a, vector const& b);
vector
operator-(vector const& a, vector const& b);
vector
operator*(vector const& a, float const& f);
vector
operator/(vector const& a, float const& f);

float
len(vector const& b);

vector
cross(vector const& a, vector const& b);

vector
norm(vector const& b);
