#include <iostream>
#include <vector>
#include <conio.h>
#include <cstdlib>
#include <ctime>
#include <thread>
#include <chrono>
#include <windows.h>  // For Beep()

using namespace std;

// ... (Bird, Pipe classes unchanged) ...

class Game {
    // ... same as before ...

    void update() {
        bird.update();

        for (auto &pipe : pipes) {
            pipe.update();
        }

        if (!pipes.empty() && pipes[0].x < 0) {
            pipes.erase(pipes.begin());
            score++;
        }

        if (pipes.empty() || pipes.back().x < 12) {
            pipes.push_back(Pipe(20, rand() % 6 + 2));
        }

        bool collision = false;
        for (auto &pipe : pipes) {
            if (pipe.x == 5) {
                if (bird.y < pipe.gapY || bird.y > pipe.gapY + 2) {
                    collision = true;
                }
            }
        }
        if (bird.y == 0 || bird.y == 10) collision = true;

        if (collision) {
            // Play beep sound
            Beep(750, 500); // frequency 750Hz, duration 500ms

            // Bird-tone curse message
            cout << "\n\nBird says: 'Caw! You smashed me! Squawk!!'\n";

            gameOver = true;
        }
    }

    void draw() {
        for (int y = 0; y <= 10; y++) {
            for (int x = 0; x <= 20; x++) {
                if (bird.y == y && x == 5) {
                    cout << "🐦";  // If your console supports Unicode bird emoji
                }
                else if (isPipeAt(x, y)) {
                    cout << "|";
                }
                else {
                    cout << " ";
                }
            }
            cout << endl;
        }
        cout << "Score: " << score << endl;
        cout << "Press SPACE to flap" << endl;
    }
};





int main() {
    Game game;
    game.run();
    return 0;
}
