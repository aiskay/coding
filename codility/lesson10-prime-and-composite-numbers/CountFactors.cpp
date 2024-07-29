int solution(int N) {
    // write your code in C++14 (g++ 6.2.0)
    int ans = 0;
    for(long long i = 1; i*i <= N; ++i){
        if(N%i == 0){
            if(i*i == N) ans += 1;
            else ans += 2;
        } 
    }

    return ans;
}