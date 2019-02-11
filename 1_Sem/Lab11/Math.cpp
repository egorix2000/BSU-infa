int calcGcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    return calcGcd(b, a % b);
}

int abs(int a) {
    if (a < 0) {
        a *= -1;
    }
    return a;
}
