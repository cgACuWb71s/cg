#pragma once

#include "vector.hpp"

#include <vector>

struct triangle
{
    vector pos[3];
    vector norm[3];
};

void
init_geometry();

std::size_t
get_num_geometries();

std::vector<triangle>
get_geometry(std::size_t index, bool sharp);
