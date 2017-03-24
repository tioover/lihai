#include <vector>
#include "prime.h"

const usize max = 100000000;
bool comp[max] = {false};
usize prime_buf[max];


usize euler(usize n) {
    // 当前素数个数。
    usize pn = 0;

    for (usize i = 2; i < max; i++) {
        if (!comp[i]) {
            prime_buf[pn] = i;
            pn++;
            if (pn == n) return prime_buf[pn - 1];
        }

        for (usize j = 0; j < pn; j++) {
            if (i * prime_buf[j] > max) break;
            comp[i * prime_buf[j]] = true;
            if (i % prime_buf[j] == 0) break;
        }
    }
    return 0;
}


usize prime_n(usize n) {
    return euler(n);
}
