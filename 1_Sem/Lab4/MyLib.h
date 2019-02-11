void enterArray(int *a, int n);

void coutArray(int *a, int n);

void coutArrayInReverseOrder(int *a, int n);

bool comparator(int a, int b);

void sortArray(int *a, int n, bool (*comparator)(int, int) = ::comparator);

void swapElements(int &a, int &b);

void fillArrayWithZeros(int *a, int n);

void reverseArray(int *a, int n);

int gcd(int a, int b);
