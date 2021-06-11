#include <ctime>
#include <iostream>
#include "TimeUtil.h"
#include "GameConstants.h"

TimeUtil::TimeUtil() {
    frameCount = 0;
    msBetweenFrames = 1000 / GameConstants::targetFPS;
}

TimeUtil& TimeUtil::getInstance() {
    static TimeUtil instance;
    return instance;
}

void TimeUtil::update() {
    frameCount += msBetweenFrames;
}

bool TimeUtil::hasTimePassed(int ms) const {
    return clock() % ms < msBetweenFrames;
}