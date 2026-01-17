#pragma once

#include <chrono>

class Timer {
public:
    Timer();

    void start();

    double stop();

    double elapsed() const;

    double elapsed_seconds() const;
    double elapsed_microseconds() const;
    double elapsed_nanoseconds() const;

    void reset();

    bool is_running() const;

private:
    std::chrono::high_resolution_clock::time_point start_time_;
    std::chrono::high_resolution_clock::time_point end_time_;
    bool running_;
};
