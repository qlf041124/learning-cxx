#include "../exercise.h"
#include <numeric>

// READ: `std::accumulate` <https://zh.cppreference.com/w/cpp/algorithm/accumulate>

int main(int argc, char **argv) {
    using DataType = float;
    int shape[]{1, 3, 224, 224};
    // TODO: 调用 `std::accumulate` 计算：
    //       - 数据类型为 float；
    //       - 形状为 shape；
    //       - 连续存储；
    //       的张量占用的字节数
    // int size =
    // 1. 初始值设为 sizeof(DataType) (即 4 字节)
    // 2. 遍历 shape 数组，将每一维的大小乘上去
    int size = std::accumulate(std::begin(shape), std::end(shape), sizeof(DataType), 
                               [](int a, int b) { return a * b; });
    ASSERT(size == 602112, "4x1x3x224x224 = 602112");
    return 0;
}
