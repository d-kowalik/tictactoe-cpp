class Game {
public:
    enum State {
        RUNNING=0,
        X_WON=1,
        O_WON=2,
        TIE=3,
        QUIT=4
    };

    State state;

    Game();
};