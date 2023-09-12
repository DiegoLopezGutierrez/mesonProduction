#include <chrono>
#include <ctime>
#include <algorithm>
#include <string>

std::string GetCurrentTimestamp() 
{
    // Get the current time
    auto now = std::chrono::system_clock::now();

    // Convert the time to a time_t (C-style time)
    std::time_t currentTime = std::chrono::system_clock::to_time_t(now);

    // Convert the time to a string in a desired format
    std::string timestamp = std::ctime(&currentTime);

    // Remove newline character from the timestamp
    timestamp.erase(std::remove(timestamp.begin(), timestamp.end(), '\n'), timestamp.end());

    // Replace spaces with underscores (or any other desired character)
    std::replace(timestamp.begin(), timestamp.end(), ' ', '_');

    return timestamp;
}
