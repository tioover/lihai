#include "bitmap.h"
#include "types.h"

class Bitmap {
    u64 data = 0;
public:
    void add(u32 x) {
        data ^= 1 << x;
    }
    bool get(u32 x) {
        return (data & 1 << x) != 0;
    }
};
