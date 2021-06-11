#pragma once

class TimeUtil {
    public:
        static TimeUtil& getInstance();

        void update();

        bool hasTimePassed(int ms) const;
    private:
        TimeUtil();

        int frameCount;
        int msBetweenFrames;
};


