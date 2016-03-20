#ifndef TIMER_H
#define TIMER_H

class Timer
{
  public:
    Timer();
    void start();
    void unpause();
    void pause();
    Uint32 get_ticks();
    void stop();

    Uint32 start_ticks;
    Uint32 paused_ticks;
    bool paused;
    bool started;
};
#endif
