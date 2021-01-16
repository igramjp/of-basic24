#include "CustomRect.h"

CustomRect::CustomRect(int _num) {
    num = _num;
    float notes[] = {1.0, 5.0/4.0, 4.0/3.0, 3.0/2.0};
    float base[] = {8.0, 4.0, 2.0, 1.0, 0.5};
    
    mySound.load("ambientSound.wav");
    soundSpeed = notes[num % 4] / base[num % 5];
    mySound.setSpeed(soundSpeed);
    mySound.setLoop(true);
    amp = 0;
    mySound.play();
    lfo = ofRandom(0.5, 2.0);
}

void CustomRect::update() {
    radius = sin(ofGetElapsedTimef() * 10.0 * lfo) * 20 + 40;
    float dist = ofDist(getPosition().x, getPosition().y, ofGetWidth()/2, ofGetHeight()/2);
    amp = (1.0 - dist/400.0) * 0.2;
    if (amp < 0) {
        amp = 0;
    }
    mySound.setVolume(amp);
}
