void enterTwoDimensionalArray(int** a, int n, int m);

void enterTwoDimensionalArrayFromFile(int** a, int n, int m, std::ifstream& fin);

void printTwoDimensionalArray(int **a, int n, int m);

bool hasEqualElements(int **a, int n);

void fillRandomTwoDimensionalArray(int **a, int n, int m);

void printTwoDimensionalBooleanArray(bool **a, int n);

void printFormattedTwoDimensionalArray(int **a, int n, int m, int width);

void printFormattedTwoDimensionalArrayToFile(int **a, int n, int m, int width, std::ofstream& fout);

int sumInRow(int **matrix, int n, int row);

int sumInColumn(int **matrix, int n, int column);

int sumInFirstDiagonal(int **matrix, int n);

int sumInSecondDiagonal(int **matrix, int n);

int translateIntoOneDemencionalArray(int** a, int* oneDemensionalA, int n, int m);
