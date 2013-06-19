#include "main.hpp"
#include "geometry.hpp"

#include <cassert>
#include <sstream>
#include <fstream>
#include <iomanip>
#include <deque>
#include <vector>
#include <iostream>

namespace
{
    struct indexed_triangle
    {
	unsigned int i[3];
    };

    struct geometry
    {
    std::vector<vector3> vertices;
	std::vector<indexed_triangle> triangles;

	template<typename Vert, typename Trian>
	geometry(Vert const& v, Trian const& t):
	    vertices(v.begin(), v.end()),
	    triangles(t.begin(), t.end())
	{}

    vector3
	norm(indexed_triangle const& t) const
	{
	    return ::norm(
		cross(vertices[t.i[1]]-vertices[t.i[1]],
		      vertices[t.i[2]]-vertices[t.i[1]]));
	}
    };

    std::deque<geometry> geometries;
}


std::size_t
get_num_geometries()
{
    return geometries.size();
}

std::vector<triangle>
get_geometry(std::size_t index, bool sharp)
{
    assert(index < geometries.size());

    std::vector<triangle> result(geometries[index].triangles.size());

    std::vector<triangle>::iterator ri=result.begin();
    for(std::vector<indexed_triangle>::const_iterator i=geometries[index].triangles.begin();
	i!=geometries[index].triangles.end();
	++i, ++ri)
    {
	for(unsigned char c=0;c!=3;++c)
	{
	    ri->pos[c] = geometries[index].vertices[i->i[c]];
	}

	if(sharp)
	{
	    for(unsigned char c=0;c!=3;++c)
	    {
		ri->norm[c] = geometries[index].norm(*i);
	    }
	}
	else
	{
	    for(unsigned char c=0;c!=3;++c)
	    {
		unsigned int norm_count=0;
		for(std::vector<indexed_triangle>::const_iterator t=geometries[index].triangles.begin();
		    t!=geometries[index].triangles.end();
		    ++t)
		{
		    if(t->i[0]==i->i[c] ||
		       t->i[1]==i->i[c] ||
		       t->i[0]==i->i[c])
		    {
			ri->norm[c]+=geometries[index].norm(*t);
			++norm_count;
		    }
		}
		ri->norm[c]/=norm_count;
	    }	    
	}
    }
    
    return result;
}

void
init_geometry()
{
    unsigned int count=0;
    for(;;++count)
    {
	std::stringstream filename;
	filename << "./geometry/u" << std::setfill('0') << std::setw(2) << (count+1);
	
    std::deque<vector3> vertices;
	{
	    std::ifstream file((filename.str()+".vertices").c_str());
	    if(!file)
	    {
		break;
	    }
	    
	    while(file)
	    {
        vector3 current;
		for(unsigned char c=0;c!=3;++c)
		{
		    file >> current.c[c];
		}		
		vertices.push_back(current);
	    }
	}

	std::deque<indexed_triangle> triangles;
	{
	    std::ifstream file((filename.str()+".indices").c_str());
	    if(!file)
	    {
		break;
	    }

	    while(file)
	    {
		int a, b;
		file >> a >> b;
		for(;;)
		{
		    int i;
		    file >> i;
		    if(i==-1)
		    {
			break;
		    }

		    indexed_triangle t;
		    t.i[0]=static_cast<unsigned int>(a);
		    t.i[1]=static_cast<unsigned int>(b);
		    t.i[2]=static_cast<unsigned int>(i);
		    triangles.push_back(t);

            a=b;
		    b=i;
		}
	    }
	}

	geometries.push_back(geometry(vertices, triangles));
    }

    if(!count)
    {
	ERROR();
    }

    std::cout << "Read " << count << " models." << std::endl;
}
