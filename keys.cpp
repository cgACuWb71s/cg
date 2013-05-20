#include "main.hpp"

#include <iostream>
#include <cassert>

bool old_keys_down[128];
bool keys_down[128];
bool keys_up[128];

namespace
{
    void
    keyboard_down_func(unsigned char key, int, int)
    {
	keys_down[key]=true;
    }

    void
    keyboard_up_func(unsigned char key, int, int)
    {
	keys_up[key]=true;
    }
}

bool
key_down(char const& key)
{
    assert(key >= 0);
    return keys_down[static_cast<unsigned char>(key)];
}

bool
key_released(char const& key)
{
    assert(key >= 0);
    return !key_down(key) && old_keys_down[static_cast<unsigned char>(key)];
}

void
tick_keys()
{
    for(unsigned char c=0;c!=sizeof(keys_down)/sizeof(keys_down[0]);++c)
    {
	old_keys_down[c]=keys_down[c] || keys_up[c];
	if(keys_up[c])
	{
	    keys_down[c]=false;
	    keys_up[c]=false;
	}	
    }
}

void
init_keys()
{
    glutKeyboardFunc(keyboard_down_func);
    glutKeyboardUpFunc(keyboard_up_func);
}
