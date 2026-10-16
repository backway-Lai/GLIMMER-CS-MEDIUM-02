// 若相加不发生溢出返回 1，发生溢出返回 0
int is_safe(int x, int y) {

    int sum = x + y;
    int x_sign = (x >> 31) & 1;                  //判断符号，结果为1则是负数；结果为0则是整数。
    int y_sign = (y >> 31) & 1;
    int sum_sign = (sum >> 31) & 1;
    int result;

    // 请补全代码写在TO DO与END OD TO DO之间：
    //TO DO

    result = 1;

    if (x_sign & y_sign) {                       //同为1即均为负数
        if (!sum_sign) result = 0;
    }

    if (!(x_sign | y_sign)) {                    //同为0即均为正数
        if (sum_sign) result = 0;
    }

    //END OF TO DO

    return  result;
}