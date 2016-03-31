#include <iostream>
#include <vector>

using namespace std;

typedef int sudoku_element;

class Sudoku
{
    public:
        //Sudoku(); // not needed
        Sudoku(const vector<int> &numbers);
        ~Sudoku();
        void Print() const;
        bool Validate_Line(int lineNum) const;
        bool Validate_Box(int boxNum) const;
    private:
        vector<sudoku_element> sudoku_;
};

/* Not needed
Sudoku::Sudoku()
{
    // Creates empty sudoku board..
    memset(sudoku_, 0, sizeof(sudoku_);
}
*/

Sudoku::Sudoku(const vector<int> &numbers)
{
    for (int i = 0; i < numbers.size(); ++i)
        sudoku_.push_back(numbers[i]);
}

Sudoku::~Sudoku()
{
    // Clear vector?
}

void Sudoku::Print() const
{
    cout << "------------------" << endl;
    for (int i = 0; i < sudoku_.size(); i++)
    {
        cout << sudoku_[i];

        if (!((i+1)%3)) cout << "|";
        else cout << " ";

        if (!((i+1)%9)) cout << endl;

        if (i == 26 || i == 53 || i == 80)
            cout << "------------------" << endl;
    }
}

bool Sudoku::Validate_Line(int lineNum) const
{
    bool res = true;

    return res;
}

bool Sudoku::Validate_Box(int boxNum) const
{
    bool res = true;

    return res;
}


int main(int argc, char* argv[])
{
    vector<int> input;

    if (argc != (81 + 1))
    {
        cout << "Invalid number of numbers!" << endl;
        return 1;
    }

    for (int i = 1; i < argc; ++i)
    {
        input.push_back(atoi(argv[i]));
    }

    Sudoku my_sudoku(input);

    my_sudoku.Print();

    return 0;

error_out:
    cout << "ERROR!" << endl;
    return 1;
}
