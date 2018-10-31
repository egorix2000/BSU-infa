void enterArray(int *a, int n);

void readArrayFromFile(int *a, int n, std::ifstream& fin);

void printArray(int *a, int n);

void fillArrayRandom(int *a, int n);

void coutArrayInReverseOrder(int *a, int n);

bool comparator(int a, int b);

void sortArray(int *a, int n, bool (*comparator)(int, int) = ::comparator);

void insertSortArrayWithBinarySearch(int *a, int n);

void swapElements(int &a, int &b);

void fillArrayWithZeros(int *a, int n);

void reverseArray(int *a, int n);

int gcd(int a, int b);

int binarySearch(int *a, int n, int x);
