void main() {
    const int FIRST_K = 100;
    int s = 0;
    for(int i=0;i<FIRST_K+1;i++)
        s+=i;
    s*=s;
    for(int i=0;i<FIRST_K+1;i++)
        s-=i*i;
    printf("%i",s); // 25164150
}
