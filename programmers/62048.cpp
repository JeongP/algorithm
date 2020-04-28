using namespace std;

long long solution(int w,int h)
{
	long long answer = 1;
    long long sum = (long long) w * (long long) h;
    long long start = (w > h) ? h : w;
    long long gcd = 0;
    for(start;start>=0;start--) {
        if( w%start == 0 && h%start ==0) {
            gcd = start;
            break;
        }
    }
    answer = sum - gcd * ((h/gcd)+(w/gcd)-1);
	return answer;
}