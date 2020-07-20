#ifndef COLLECTING_INPUT_H
#define COLLECTING_INPUT_H

#include "../include/ccs/decisiontaking.h"
#include "../include/ccs/Constants.h"
#include <string.h>

static float previous_velocity, current_velocity;

namespace Algorithm
{

using namespace std;

class Collecting_input 
{
  public:
    Collecting_input(){};
    message_pkg::msg::Custommsg collectinput(const message_pkg::msg::Custommsg);

  private:
    int brakestatus;
    float time;
};
}

#endif
