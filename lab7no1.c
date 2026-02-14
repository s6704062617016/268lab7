#include <stdio.h>

double functionM(void);
int functionN(int n, double x);
double functionO(double, int, double, int);
double functionP(int a, int n, int b, int c);

int main(void){
    int a = 0, b = 0, c = 0, d = 0, e = 0;
    double r = 0.0, s = 0.0, t = 0.0, u = 0.0, v = 0.0;

    /* a) */
    printf("%lf\n", functionM());
    // ? ถูก: เรียก functionM ได้ปกติ (คืน double)

    /* b) */
    a = functionM();
    // ? ได้แต่มีการแปลง double  int (ทศนิยมจะหาย)
    printf("a = %d\n", a);

    /* c) */
    b = functionN(a, b);
    // ? ถูก: functionN(int,double)  b เป็น int ทศนิยมจะถูกตัด
    printf("b = %d\n", b);

    /* d) */
    r = functionO(r, a, s, b);
    // ? ถูก: ชนิดข้อมูลตรง
    printf("r = %lf\n", r);

    /* e) */
    // s = functionP(a, b, c, d, e);
    // ? ผิด (ของเดิม): ส่ง 5 ตัว แต่ functionP รับ 4 ตัว
    printf("s = %lf\n", s);

    /* f) */
    u = functionM();
    // ? ถูก
    printf("u = %lf\n", u);

    /* g) */
    c = d + functionN((int)r, s);
    // ? เดิมผิด: ส่ง r เป็น double
    // ? แก้แล้ว: cast r เป็น int ให้ตรง prototype
    printf("c = %d\n", c);

    /* h) */
    t = s * functionO(r, a, r, a);
    // ? ถูก
    printf("t = %lf\n", t);

    /* i) */
    a = (int)v + functionP((int)r, (int)s, (int)t, (int)t);
    // ? เดิมผิด: ส่ง double ให้ functionP(int,int,int,int)
    // ? แก้แล้ว: cast เป็น int ครบ
    printf("a = %d\n", a);

    /* j) */
    printf("%lf\n",
        functionP(functionN(a, a), (int)s, (int)t, (int)(t+r)));
    // ? เดิมผิด: s,t,r เป็น double
    // ? แก้แล้ว: cast เป็น int ก่อนส่ง

    /* k) */
    v = functionP(functionN(a, a), (int)s, (int)t, (int)(t+r));
    // ? เดิมผิด: ชนิด argument ไม่ตรง
    // ? แก้แล้ว: cast ให้ตรง
    printf("v = %lf\n", v);

    return 0;
}

double functionM(void){
    double ans = 1 + 1;
    return ans; 
}

int functionN(int n, double x){
    return n + x;
}

double functionO(double a, int b, double c, int d){
    return a + b + c + d;
}

double functionP(int a, int n, int b, int c){
    return a * n * b * c;
}

