#ifndef TIMER_H
#define TIMER_H

#include <chrono>

/**
 * @brief A simple timer class for measuring durations.
 *
 * This class provides functionality to measure elapsed time using
 * high-resolution clock provided by the C++ <chrono> library.
 */
class Timer {
public:
    /**
     * @brief Constructs a Timer object.
     *
     * Initializes the start and end time points.
     */
    Timer() : startTime(), endTime() {}

    /**
     * @brief Starts the timer.
     *
     * Records the current time as the start time.
     */
    void start();

    /**
     * @brief Stops the timer.
     *
     * Records the current time as the end time.
     */
    void stop();

    /**
     * @brief Gets the duration of elapsed time in seconds.
     *
     * @return The duration of elapsed time in seconds.
     */
    double getDurationInSeconds() const;

    /**
     * @brief Gets the duration of elapsed time in milliseconds.
     *
     * @return The duration of elapsed time in milliseconds.
     */
    long long getDurationInMilliseconds() const;

    /**
     * @brief Gets the duration of elapsed time in microseconds.
     *
     * @return The duration of elapsed time in microseconds.
     */
    long long getDurationInMicroseconds() const;

private:
    std::chrono::time_point<std::chrono::high_resolution_clock> startTime, endTime;
};

#endif // TIMER_H
