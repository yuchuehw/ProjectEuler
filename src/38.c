#include <stdio.h>
#include <stdbool.h>

int main() {
    int max_ = -1;

    for (int i = 1; i <= 10000; ++i) {
        int s = 0;
        bool l[11] = {false}; // Initialize all elements to false
        l[0] = true;

        for (int j = 1; j < 11; ++j) {
            int s_copy = s;
            int k = i * j;
            bool repeat = false;

            while (k) {
                s *= 10;
                if (l[k % 10]) {
                    repeat = true;
                    break;
                } else {
                    l[k % 10] = true;
                }
                k /= 10;
            }

            if (repeat) {
                max_ = (s_copy > max_) ? s_copy : max_;
                break;
            }
            s += i * j;
        }
    }

    printf("%d\n", max_);

    return 0;
}
