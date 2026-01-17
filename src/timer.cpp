#include "timer.hpp"

Timer::Timer() : running_(false) {
    start();
}

void Timer::start() {
    start_time_ = std::chrono::high_resolution_clock::now();
    running_ = true;
}

double Timer::stop() {
    if (running_) {
        end_time_ = std::chrono::high_resolution_clock::now();
        running_ = false;
    }
    const auto duration = std::chrono::duration_cast<std::chrono::microseconds>(
        end_time_ - start_time_
    );
    return duration.count() / 1000.0;
}

double Timer::elapsed() const {
    const auto current_time =
        running_ ? std::chrono::high_resolution_clock::now() : end_time_;

    const auto duration = std::chrono::duration_cast<std::chrono::microseconds>(
        current_time - start_time_
    );
    return duration.count() / 1000.0;
}

double Timer::elapsed_seconds() const {
    return elapsed() / 1000.0;
}

double Timer::elapsed_microseconds() const {
    const auto current_time =
        running_ ? std::chrono::high_resolution_clock::now() : end_time_;

    const auto duration = std::chrono::duration_cast<std::chrono::microseconds>(
        current_time - start_time_
    );
    return static_cast<double>(duration.count());
}

double Timer::elapsed_nanoseconds() const {
    const auto current_time =
        running_ ? std::chrono::high_resolution_clock::now() : end_time_;

    const auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(
        current_time - start_time_
    );
    return static_cast<double>(duration.count());
}

void Timer::reset() {
    start_time_ = std::chrono::high_resolution_clock::now();
    end_time_ = start_time_;
    running_ = false;
}

bool Timer::is_running() const {
    return running_;
}
