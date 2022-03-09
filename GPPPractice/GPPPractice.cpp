
#include <iostream>
#include <vector>
#include <format>

enum room_info
{
    empty,
    wall,
    start,
    finish,
    MAX
};

std::vector<std::vector<room_info>> createBoard()
{
    return std::vector<std::vector<room_info>>({
        {start, wall, empty, empty, empty},
        {empty, empty, empty, wall, empty},
        {empty, wall, empty, wall, empty},
        {empty, wall, wall, wall, finish}
    });
}

void printBoard(std::vector<std::vector<room_info>> board)
{
    for (const auto& r : board)
    {
        for (int c : r)
        {
            std::cout << c << ",";
        }
        std::cout << std::endl;
    }
}
int main(int argc, char* argv[])
{
    auto board = createBoard();
    printBoard(board);
    int cur_row = 0;
    int cur_col = 0;

    std::printf("%s %s!", "Hello", "World");
    // while(board[cur_row][cur_col] != finish)
    // {
    // }
    return 0;
}
