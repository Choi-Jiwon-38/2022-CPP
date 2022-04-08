#include <iostream>
using namespace std;

int main() {
    int t; // 테스트 케이스 
    int rpx1, rpy1, rqx1, rqy1; // 사각형 1
    int rpx2, rpy2, rqx2, rqy2; // 사각형 2
    int rpx3, rpy3, rqx3, rqy3; // 사각형 3 (1,2 겹치는 거)
    int overlap_length = 0; int overlap_area = 0; // 사각형 3의 길이 / 넓이
    int answer_length, answer_area; // 정답 길이 / 넓이
    
    cin >> t; // 테스트 케이스 수 입력
    
    for (int i = 0; i < t; i++) {
        cin >> rpx1 >> rpy1 >> rqx1 >> rqy1; // 사각형 1 정보 입력
        cin >> rpx2 >> rpy2 >> rqx2 >> rqy2; // 사각형 2 정보 입력

        answer_area = (rqx1 - rpx1) * (rqy1 - rpy1) + (rqx2 - rpx2) * (rqy2 - rpy2);
        answer_length = 2 * (rqx1 - rpx1 + rqy1 - rpy1 + rqx2 - rpx2 + rqy2 - rpy2);

        if ( !(rpy1 > rqy2 || rqx2 < rpx1 || rpy2 > rqy1 || rqx1 < rpx2) ) { // 중복되지 않는 경우
            rpx3 = max(rpx1, rpx2);
            rpy3 = max(rpy1, rpy2);
            rqx3 = min(rqx1, rqx2);
            rqy3 = min(rqy1, rqy2);

            overlap_length = 2 * (rqx3 - rpx3 + rqy3 - rpy3);
            overlap_area = (rqx3 - rpx3) * (rqy3 - rpy3);

            answer_length -= overlap_length;
            answer_area -= overlap_area;
        }

        cout << answer_area << " " << answer_length << endl;
    }
}