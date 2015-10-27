#include "Level.h"

Level::Level() {
    map =  {
        "#############^^#############",
        "#..........................#",
        "#.####.######..######.####.#",
        "#.#  #.#    #..#    #.#  #.#",
        "#.####.######..######.####.#",
        "#..........................#",
        "#.####.##.########.##.####.#",
        "#.####.##.########.##.####.#",
        "#......##....##....##......#",
        "######.##### ## #####.#####4",
        "     #.##### ## #####.#     ",
        "     #.##          ##.#     ",
        "     #.## #      # ##.#     ",
        " #####.## #      # ##.##### ",
        "L     .   # M  M #   .     R",
        " #####.## #      # ##.##### ",
        "     #.## #      # ##.#     ",
        "     #.##          ##.#     ",
        "     #.## ######## ##.#     ",
        "######.## ######## ##.######",
        "#............##............#",
        "#.####.#####.##.#####.####.#",
        "#.####.#####.##.#####.####.#",
        "#...##................##...#",
        "###.##.##.########.##.##.###",
        "###.##.##.########.##.##.###",
        "#......##....##....##......#",
        "#.##########.##.##########.#",
        "#.##########.##.##########.#",
        "#.............S............#",
        "############################"
    };
    char checkedSymbol;
    ghostNumber = 0;

    // Initialization of all map fields (locations)
    for ( int row = 0; row < MAP_HEIGHT; row++ ) {
        for ( int column = 0; column < MAP_WIDTH; column++ ) {
            checkedSymbol = map[row][column];

            switch ( checkedSymbol ) {
                case '#':
                    field[row][column] = new Location(row, column, new Wall());
                    break;
                case '.':
                    field[row][column] = new Location(row, column, new Coin(row, column, this));
                    break;
                case '^':
                    field[row][column] = new Location(row, column, new Exit(this));
                    break;
                case 'M':
                    ghosts[ghostNumber] = new Ghost(row, column, this);
                    field[row][column] = new Location(row, column, ghosts[ghostNumber]);
                    field[row][column]->placeGhost(ghosts[ghostNumber]);
                    ghostNumber += 1;
                    break;
                case 'S':
                    pacman = new Pacman(row, column, this);
                    field[row][column] = new Location(row, column, pacman);
                    field[row][column]->placePacman(pacman);
                    break;
                case 'L':
                    field[row][column] = new Location(row, column, new LeftPortal(row, column, this));
                    break;
                case 'R':
                    field[row][column] = new Location(row, column, new RightPortal(row, column, this));
                    break;
                default:
                    field[row][column] = new Location(row, column);
            }
        }
    }
}

Level::~Level() {
    for ( int row = 0; row < MAP_HEIGHT; row++ ) {
        for ( int column = 0; column < MAP_WIDTH; column++ ) {
            delete field[row][column];
        }
    }
}
Location* Level::getField(int row, int column) const {
    return field[row][column];
}

Ghost* Level::getGhosts() {
    return *ghosts;
}

void Level::moveAll() {
    pacman->move();
    for ( int i = 0; i < MAX_GHOSTS; i++ ) {
        if ( ghosts[i] != NULL) {
            ghosts[i]->move();
        }
    }
}

void Level::gameOver() {
    system("CLS");
    std::cout << *this << std::endl;
    std::cout << "GAME OVER!" << std::endl;
    std::cout << "Scores: " << pacman->getScores() << std::endl;
    Sleep(2000);
    exit(0);
}

std::ostream& operator<<(std::ostream& out, const Level& level) {
    system("CLS");
    for ( int row = 0; row < MAP_HEIGHT; row++ ) {
        for ( int column = 0; column < MAP_WIDTH; column++ ) {
            if ( level.getField(row, column)->getContent() != NULL ) {
                out << level.getField(row, column)->getContent()->getSign();
            } else {
                out << " ";
            }
        }
        out << '\n';
    }
    return out;
}
