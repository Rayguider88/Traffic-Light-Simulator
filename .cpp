#include <iostream>
#include <thread>   // for sleep_for
#include <chrono>   // for seconds
using namespace std;

enum class TrafficLightState { RED, GREEN, YELLOW };

class TrafficLight {
private:
    TrafficLightState state;
    int greenDuration;
    int yellowDuration;
    int redDuration;

public:
    TrafficLight(int green, int yellow, int red)
        : greenDuration(green), yellowDuration(yellow), redDuration(red), state(TrafficLightState::RED) {}

    void runCycle() {
        while (true) {
            switch (state) {
                case TrafficLightState::RED:
                    displayState("RED");
                    this_thread::sleep_for(chrono::seconds(redDuration));
                    state = TrafficLightState::GREEN;
                    break;

                case TrafficLightState::GREEN:
                    displayState("GREEN");
                    this_thread::sleep_for(chrono::seconds(greenDuration));
                    state = TrafficLightState::YELLOW;
                    break;

                case TrafficLightState::YELLOW:
                    displayState("YELLOW");
                    this_thread::sleep_for(chrono::seconds(yellowDuration));
                    state = TrafficLightState::RED;
                    break;
            }
        }
    }

    void displayState(const string& color) {
        system("clear"); // Use "cls" if on Windows
        cout << "Traffic Light is now: " << color << endl;
        cout << "--------------------------" << endl;
    }
};

int main() {
    // Green: 5 sec, Yellow: 2 sec, Red: 5 sec
    TrafficLight light(5, 2, 5);
    light.runCycle();

    return 0;
}
