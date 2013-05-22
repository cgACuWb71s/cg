#pragma once

#include "vector3.hpp"

#include <vector>

struct triangle
{
    vector3 pos[3];
    vector3 norm[3];
};

void
init_geometry();

std::size_t
get_num_geometries();

std::vector<triangle>
get_geometry(std::size_t index, bool sharp);
