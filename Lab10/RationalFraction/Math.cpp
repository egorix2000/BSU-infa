int calcGcd(int a, int b){
    if (b == 0){
        return a;
    }
    return calcGcd(b, a % b);
}
