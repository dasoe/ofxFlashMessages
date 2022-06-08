#pragma once

#include <ofMain.h>


class flashMessage {
    public:
        int duration;
        int startedAt;
        string text;
        int logLevel;
        int alpha = 1;
};

class ofxFlashMessages {

public:
    void add(string message);
    void add(string message, int logLevel);
    void add(string message, float seconds);
    void add(string message, double seconds);
    void add(string message, float seconds, int logLevel);

    bool isExpired(flashMessage& messageToCheck);

    void update();
    void draw();
    void draw(int _width);
    
    unsigned long flashMessageTimer, actualTime;
    vector <flashMessage*> messages;
};
