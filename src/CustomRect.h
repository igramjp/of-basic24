#pragma once
#include "ofxBox2d.h"

class CustomRect : public ofxBox2dRect {
    public:
        CustomRect(int num);
        void update();
    
        int num;
        ofSoundPlayer mySound;
        float soundSpeed;
        float amp;
        float lfo;
        float radius;
};
