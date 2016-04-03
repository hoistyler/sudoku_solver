#include <iostream>
#include <vector>

using namespace std;

typedef int sudoku_element;

static void PrintNumberArray(const int *numbers, const int size)
{
    for (int i = 0; i < size; ++i)
    {
        cout << numbers[i];
    }
}

class Sudoku
{
    public:
        //Sudoku(); // not needed
        Sudoku(const vector<int> &numbers);
        ~Sudoku();
        void Print() const;
        bool Validate_All() const;
    private:
        vector<sudoku_element> sudoku_;
        int* GetRow(int rowNum) const;
        int* GetColumn(int colNum) const;
        int* GetBox(int boxNum) const;
        bool ValidateNumbers(int *numbers) const;
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

bool Sudoku::Validate_All() const
{
    bool res = true;

    // Validate rows
    for (int i = 0; i < 9; ++i)
    {
        int *numbers = GetRow(i);

        cout << "Row " << i + 1 << " numbers: ";
        PrintNumberArray(numbers, 9);
        cout << endl;

        ValidateNumbers(numbers);
    }

    // Validate columns
    for (int i = 0; i < 9; ++i)
    {
        int *numbers = GetColumn(i);

        cout << "Column " << i + 1 << " numbers: ";
        PrintNumberArray(numbers, 9);
        cout << endl;

        ValidateNumbers(numbers);
    }

    // Validate boxes
    for (int i = 0; i < 9; ++i)
    {
        int *numbers = GetBox(i);

        cout << "Box " << i + 1 << " numbers: ";
        PrintNumberArray(numbers, 9);
        cout << endl;

        ValidateNumbers(numbers);
    }

    return res;
}


int* Sudoku::GetRow(int rowNum) const
{
    static int numbers[9];
    int startIndex = rowNum * 9;

    for (int i = 0; i < 9; ++i)
    {
        numbers[i] = sudoku_[startIndex + i];
    }

    return &(numbers[0]);
}

int* Sudoku::GetColumn(int colNum) const
{
    static int numbers[9];
    for (int i = 0; i < 9; ++i)
    {
        numbers[i] = sudoku_[colNum + (i * 9)];
    }

    return &(numbers[0]);
}

int* Sudoku::GetBox(int boxNum) const
{
    static int numbers[9];
    int startIndexes[9] = {0, 3, 6, 27, 30, 33, 54, 57, 60};
    int startIndex = startIndexes[boxNum];

    int index = startIndex;
    int offset = 0;
    for (int i = 0; i < 9; ++i)
    {
        if ( i == 3 || i == 6) 
        {
            index += 9;
            offset = 0;
        }

        numbers[i] = sudoku_[index + offset];
        offset++;
    }

    return &(numbers[0]);
}


bool Sudoku::ValidateNumbers(int *numbers) const
{
    bool res = true;
    int numberPool[9] = { 0,0,0,0,0,0,0,0,0 }; // used to validate line

    for (int i = 0; i < 9; ++i)
    {
        // numbers[] is 1 to 9
        numberPool[numbers[i] - 1] = numbers[i];
    }

    for (int i = 0; i < 9; ++i)
    {
        if (!numberPool[i])
        {
            res = false;
            cout << "Missing : " << i + 1 << endl;
        }
    }

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

    my_sudoku.Validate_All();
    
    my_sudoku.Print();

    return 0;

error_out:
    cout << "ERROR!" << endl;
    return 1;
}
