#pragma once
#include "ui.h"

class Test
{
private:
    Controller service;

    void testRemove();
    void testMarkAndRetrieve();

public:
    void testAll();
};