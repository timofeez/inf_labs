// I - 1
// V - 5
// X - 10
// L - 50
// C - 100
// D - 500
// M - 1000

00, ,<,00

// определение правого числа

00,I,<,0_1
00,V,<,0_5
00,X,<,0_10
00,L,<,0_50
00,C,<,0_100
00,D,<,0_500
00,M,<,0_1000


// определение левого числа для правого числа = I
0_1, ,<,0_1

0_1,I,>,semi_right_1_1
0_1,V,>,semi_right_5_1
0_1,X,>,semi_right_10_1
0_1,L,>,semi_right_50_1
0_1,C,>,semi_right_100_1
0_1,D,>,semi_right_500_1
0_1,M,>,semi_right_1000_1

//определение левого числа для правого числа = V
0_5, ,<,0_5

0_5,I,>,semi_right_5_1
0_5,V,>,semi_right_5_5
0_5,X,>,semi_right_10_5
0_5,L,>,semi_right_50_5
0_5,C,>,semi_right_100_5
0_5,D,>,semi_right_500_5
0_5,M,>,semi_right_1000_5

// определение левого числа для правого числа = X
0_10, ,<,0_10

0_10,I,>,semi_right_10_1
0_10,V,>,semi_right_10_5
0_10,X,>,semi_right_10_10
0_10,L,>,semi_right_50_10
0_10,C,>,semi_right_100_10
0_10,D,>,semi_right_1000_5
0_10,M,>,semi_right_1000_10

// определение левого числа для правого числа = L
0_50, ,<,0_50

0_50,I,>,semi_right_50_1
0_50,V,>,semi_right_50_5
0_50,X,>,semi_right_50_10
0_50,L,>,semi_right_500_5
0_50,C,>,semi_right_1000_5
0_50,D,>,semi_right_500_50
0_50,M,>,semi_right_1000_50

// определение левого числа для правого числа = С
0_100, ,<,0_100

0_100,I,>,semi_right_100_1
0_100,V,>,semi_right_100_5
0_100,X,>,semi_right_100_10
0_100,L,>,semi_right_1000_5
0_100,C,>,semi_right_1000_10
0_100,D,>,semi_right_1000_50

// определение левого числа для правого числа = D
0_500, ,<,0_500

0_500,I,>,semi_right_500_1
0_500,V,>,semi_right_500_5
0_500,X,>,semi_right_1000_5
0_500,L,>,semi_right_500_50
0_500,C,>,semi_right_1000_50

// определение левого числа для правого числа = M
0_1000, ,<,0_1000

0_1000,I,>,semi_right_1000_1
0_1000,V,>,semi_right_1000_5
0_1000,X,>,semi_right_1000_10
0_1000,L,>,semi_right_1000_50

// перевод коретки вправо и переход к результату

semi_right_1_1, ,>,semi_right_1_1
semi_right_1_1,I,>,right_1_1
right_1_1, ,>,result_1_1

semi_right_5_1, ,>,semi_right_5_1
semi_right_5_1,I,>,right_5_1
semi_right_5_1,V,>,right_5_1
right_5_1, ,>,result_5_1

semi_right_10_1, ,>,semi_right_10_1
semi_right_10_1,I,>,right_10_1
semi_right_10_1,X,>,right_10_1
right_10_1, ,>,result_10_1

semi_right_50_1, ,>,semi_right_50_1
semi_right_50_1,I,>,right_50_1
semi_right_50_1,L,>,right_50_1
right_50_1, ,>,result_50_1

semi_right_100_1, ,>,semi_right_100_1
semi_right_100_1,I,>,right_100_1
semi_right_100_1,C,>,right_100_1
right_100_1, ,>,result_100_1

semi_right_500_1, ,>,semi_right_500_1
semi_right_500_1,I,>,right_500_1
semi_right_500_1,D,>,right_500_1
right_500_1, ,>,result_500_1

semi_right_1000_1, ,>,semi_right_1000_1
semi_right_1000_1,I,>,right_1000_1
semi_right_1000_1,M,>,right_1000_1
right_1000_1, ,>,result_1000_1

semi_right_5_5, ,>,semi_right_5_5
semi_right_5_5,V,>,right_5_5
right_5_5, ,>,result_5_5

semi_right_10_5, ,>,semi_right_10_5
semi_right_10_5,V,>,right_10_5
semi_right_10_5,X,>,right_10_5
right_10_5, ,>,result_10_5

semi_right_50_5, ,>,semi_right_50_5
semi_right_50_5,V,>,right_50_5
semi_right_50_5,L,>,right_50_5
right_50_5, ,>,result_50_5

semi_right_100_5, ,>,semi_right_100_5
semi_right_100_5,V,>,right_100_5
semi_right_100_5,C,>,right_100_5
right_100_5, ,>,result_100_5

semi_right_500_5, ,>,semi_right_500_5
semi_right_500_5,V,>,right_500_5
semi_right_500_5,L,>,right_500_5
semi_right_500_5,D,>,right_500_5
right_500_5, ,>,result_500_5

semi_right_1000_5, ,>,semi_right_1000_5
semi_right_1000_5,V,>,right_1000_5
semi_right_1000_5,D,>,right_1000_5
semi_right_1000_5,X,>,right_1000_5
semi_right_1000_5,L,>,right_1000_5
semi_right_1000_5,C,>,right_1000_5
semi_right_1000_5,M,>,right_1000_5
right_1000_5, ,>,result_1000_5

semi_right_10_10, ,>,semi_right_10_10
semi_right_10_10,X,>,right_10_10
right_10_10, ,>,result_10_10

semi_right_50_10, ,>,semi_right_50_10
semi_right_50_10,X,>,right_50_10
semi_right_50_10,L,>,right_50_10
right_50_10, ,>,result_50_10

semi_right_100_10, ,>,semi_right_100_10
semi_right_100_10,X,>,right_100_10
semi_right_100_10,C,>,right_100_10
right_100_10, ,>,result_100_10

semi_right_1000_10, ,>,semi_right_1000_10
semi_right_1000_10,X,>,right_1000_10
semi_right_1000_10,C,>,right_1000_10
semi_right_1000_10,M,>,right_1000_10
right_1000_10, ,>,result_1000_10

semi_right_500_50, ,>,semi_right_500_50
semi_right_500_50,L,>,right_500_50
semi_right_500_50,D,>,right_500_50
right_500_50, ,>,result_500_50

semi_right_1000_50, ,>,semi_right_1000_50
semi_right_1000_50,L,>,right_1000_50
semi_right_1000_50,C,>,right_1000_50
semi_right_1000_50,D,>,right_1000_50
semi_right_1000_50,M,>,right_1000_50
right_1000_50, ,>,result_1000_50

// вывод результата и переход к финальному состоянию

result_1_1, ,I,final
result_5_1, ,V,final
result_10_1, ,X,final
result_50_1, ,L,final
result_100_1, ,C,final
result_500_1, ,D,final
result_1000_1, ,M,final
result_5_5, ,X,long_result_5_5
result_10_5, ,L,final
result_50_5, ,C,long_result_50_5
result_100_5, ,D,final
result_500_5, ,M,long_result_500_5
result_1000_5, ,M,long_result_1000_5
result_10_10, ,C,final
result_50_10, ,D,final
result_100_10, ,M,final
result_1000_10, ,M,long_result_1000_10
result_500_50, ,M,long_result_500_50
result_1000_50, ,M,long_result_1000_50

// вывод результатов длиной больше одной ячейки

long_result_5_5,X,>,long_result_5_5
long_result_5_5, ,X,long_result_5_5_p2
long_result_5_5_p2,X,>,long_result_5_5_p2
long_result_5_5_p2, ,V,final

long_result_50_5,C,>,long_result_50_5
long_result_50_5, ,C,long_result_50_5_p2
long_result_50_5_p2,C,>,long_result_50_5_p2
long_result_50_5_p2, ,L,final

long_result_500_5,M,>,long_result_500_5
long_result_500_5, ,M,long_result_500_5_p2
long_result_500_5_p2,M,>,long_result_500_5_p2
long_result_500_5_p2, ,D,final

long_result_1000_5,M,>,long_result_1000_5
long_result_1000_5, ,M,long_result_1000_5_p2
long_result_1000_5_p2,M,>,long_result_1000_5_p2
long_result_1000_5_p2, ,M,long_result_1000_5_p3
long_result_1000_5_p3,M,>,long_result_1000_5_p3
long_result_1000_5_p3, ,M,long_result_1000_5_p4
long_result_1000_5_p4,M,>,long_result_1000_5_p4
long_result_1000_5_p4, ,M,final

long_result_1000_10,M,>,long_result_1000_10
long_result_1000_10, ,M,long_result_1000_10_p2
long_result_1000_10_p2,M,>,long_result_1000_10_p2
long_result_1000_10_p2, ,M,long_result_1000_10_p3
long_result_1000_10_p3,M,>,long_result_1000_10_p3
long_result_1000_10_p3, ,M,long_result_1000_10_p4
long_result_1000_10_p4,M,>,long_result_1000_10_p4
long_result_1000_10_p4, ,M,long_result_1000_10_p5
long_result_1000_10_p5,M,>,long_result_1000_10_p5
long_result_1000_10_p5, ,M,long_result_1000_10_p6
long_result_1000_10_p6,M,>,long_result_1000_10_p6
long_result_1000_10_p6, ,M,long_result_1000_10_p7
long_result_1000_10_p7,M,>,long_result_1000_10_p7
long_result_1000_10_p7, ,M,long_result_1000_10_p8
long_result_1000_10_p8,M,>,long_result_1000_10_p8
long_result_1000_10_p8, ,M,long_result_1000_10_p9
long_result_1000_10_p9,M,>,long_result_1000_10_p9
long_result_1000_10_p9, ,M,final

long_result_500_50,M,>,long_result_500_50
long_result_500_50, ,M,long_result_500_50_p2
long_result_500_50_p2,M,>,long_result_500_50_p2
long_result_500_50_p2, ,M,long_result_500_50_p3
long_result_500_50_p3,M,>,long_result_500_50_p3
long_result_500_50_p3, ,M,long_result_500_50_p4
long_result_500_50_p4,M,>,long_result_500_50_p4
long_result_500_50_p4, ,M,long_result_500_50_p5
long_result_500_50_p5,M,>,long_result_500_50_p5
long_result_500_50_p5, ,M,long_result_500_50_p6
long_result_500_50_p6,M,>,long_result_500_50_p6
long_result_500_50_p6, ,M,long_result_500_50_p7
long_result_500_50_p7,M,>,long_result_500_50_p7
long_result_500_50_p7, ,M,long_result_500_50_p8
long_result_500_50_p8,M,>,long_result_500_50_p8
long_result_500_50_p8, ,M,long_result_500_50_p9
long_result_500_50_p9,M,>,long_result_500_50_p9
long_result_500_50_p9, ,M,long_result_500_50_p10
long_result_500_50_p10,M,>,long_result_500_50_p10
long_result_500_50_p10, ,M,long_result_500_50_p11
long_result_500_50_p11,M,>,long_result_500_50_p11
long_result_500_50_p11, ,M,long_result_500_50_p12
long_result_500_50_p12,M,>,long_result_500_50_p12
long_result_500_50_p12, ,M,long_result_500_50_p13
long_result_500_50_p13,M,>,long_result_500_50_p13
long_result_500_50_p13, ,M,long_result_500_50_p14
long_result_500_50_p14,M,>,long_result_500_50_p14
long_result_500_50_p14, ,M,long_result_500_50_p15
long_result_500_50_p15,M,>,long_result_500_50_p15
long_result_500_50_p15, ,M,long_result_500_50_p16
long_result_500_50_p16,M,>,long_result_500_50_p16
long_result_500_50_p16, ,M,long_result_500_50_p17
long_result_500_50_p17,M,>,long_result_500_50_p17
long_result_500_50_p17, ,M,long_result_500_50_p18
long_result_500_50_p18,M,>,long_result_500_50_p18
long_result_500_50_p18, ,M,long_result_500_50_p19
long_result_500_50_p19,M,>,long_result_500_50_p19
long_result_500_50_p19, ,M,long_result_500_50_p20
long_result_500_50_p20,M,>,long_result_500_50_p20
long_result_500_50_p20, ,M,long_result_500_50_p21
long_result_500_50_p21,M,>,long_result_500_50_p21
long_result_500_50_p21, ,M,long_result_500_50_p22
long_result_500_50_p22,M,>,long_result_500_50_p22
long_result_500_50_p22, ,M,long_result_500_50_p23
long_result_500_50_p23,M,>,long_result_500_50_p23
long_result_500_50_p23, ,M,long_result_500_50_p24
long_result_500_50_p24,M,>,long_result_500_50_p24
long_result_500_50_p24, ,M,final

long_result_1000_50,M,>,long_result_1000_50
long_result_1000_50, ,M,long_result_1000_50_p2
long_result_1000_50_p2,M,>,long_result_1000_50_p2
long_result_1000_50_p2, ,M,long_result_1000_50_p3
long_result_1000_50_p3,M,>,long_result_1000_50_p3
long_result_1000_50_p3, ,M,long_result_1000_50_p4
long_result_1000_50_p4,M,>,long_result_1000_50_p4
long_result_1000_50_p4, ,M,long_result_1000_50_p5
long_result_1000_50_p5,M,>,long_result_1000_50_p5
long_result_1000_50_p5, ,M,long_result_1000_50_p6
long_result_1000_50_p6,M,>,long_result_1000_50_p6
long_result_1000_50_p6, ,M,long_result_1000_50_p7
long_result_1000_50_p7,M,>,long_result_1000_50_p7
long_result_1000_50_p7, ,M,long_result_1000_50_p8
long_result_1000_50_p8,M,>,long_result_1000_50_p8
long_result_1000_50_p8, ,M,long_result_1000_50_p9
long_result_1000_50_p9,M,>,long_result_1000_50_p9
long_result_1000_50_p9, ,M,long_result_1000_50_p10
long_result_1000_50_p10,M,>,long_result_1000_50_p10
long_result_1000_50_p10, ,M,long_result_1000_50_p11
long_result_1000_50_p11,M,>,long_result_1000_50_p11
long_result_1000_50_p11, ,M,long_result_1000_50_p12
long_result_1000_50_p12,M,>,long_result_1000_50_p12
long_result_1000_50_p12, ,M,long_result_1000_50_p13
long_result_1000_50_p13,M,>,long_result_1000_50_p13
long_result_1000_50_p13, ,M,long_result_1000_50_p14
long_result_1000_50_p14,M,>,long_result_1000_50_p14
long_result_1000_50_p14, ,M,long_result_1000_50_p15
long_result_1000_50_p15,M,>,long_result_1000_50_p15
long_result_1000_50_p15, ,M,long_result_1000_50_p16
long_result_1000_50_p16,M,>,long_result_1000_50_p16
long_result_1000_50_p16, ,M,long_result_1000_50_p17
long_result_1000_50_p17,M,>,long_result_1000_50_p17
long_result_1000_50_p17, ,M,long_result_1000_50_p18
long_result_1000_50_p18,M,>,long_result_1000_50_p18
long_result_1000_50_p18, ,M,long_result_1000_50_p19
long_result_1000_50_p19,M,>,long_result_1000_50_p19
long_result_1000_50_p19, ,M,long_result_1000_50_p20
long_result_1000_50_p20,M,>,long_result_1000_50_p20
long_result_1000_50_p20, ,M,long_result_1000_50_p21
long_result_1000_50_p21,M,>,long_result_1000_50_p21
long_result_1000_50_p21, ,M,long_result_1000_50_p22
long_result_1000_50_p22,M,>,long_result_1000_50_p22
long_result_1000_50_p22, ,M,long_result_1000_50_p23
long_result_1000_50_p23,M,>,long_result_1000_50_p23
long_result_1000_50_p23, ,M,long_result_1000_50_p24
long_result_1000_50_p24,M,>,long_result_1000_50_p24
long_result_1000_50_p24, ,M,long_result_1000_50_p25
long_result_1000_50_p25,M,>,long_result_1000_50_p25
long_result_1000_50_p25, ,M,long_result_1000_50_p26
long_result_1000_50_p26,M,>,long_result_1000_50_p26
long_result_1000_50_p26, ,M,long_result_1000_50_p27
long_result_1000_50_p27,M,>,long_result_1000_50_p27
long_result_1000_50_p27, ,M,long_result_1000_50_p28
long_result_1000_50_p28,M,>,long_result_1000_50_p28
long_result_1000_50_p28, ,M,long_result_1000_50_p29
long_result_1000_50_p29,M,>,long_result_1000_50_p29
long_result_1000_50_p29, ,M,long_result_1000_50_p30
long_result_1000_50_p30,M,>,long_result_1000_50_p30
long_result_1000_50_p30, ,M,long_result_1000_50_p31
long_result_1000_50_p31,M,>,long_result_1000_50_p31
long_result_1000_50_p31, ,M,long_result_1000_50_p32
long_result_1000_50_p32,M,>,long_result_1000_50_p32
long_result_1000_50_p32, ,M,long_result_1000_50_p33
long_result_1000_50_p33,M,>,long_result_1000_50_p33
long_result_1000_50_p33, ,M,long_result_1000_50_p34
long_result_1000_50_p34,M,>,long_result_1000_50_p34
long_result_1000_50_p34, ,M,long_result_1000_50_p35
long_result_1000_50_p35,M,>,long_result_1000_50_p35
long_result_1000_50_p35, ,M,long_result_1000_50_p36
long_result_1000_50_p36,M,>,long_result_1000_50_p36
long_result_1000_50_p36, ,M,long_result_1000_50_p37
long_result_1000_50_p37,M,>,long_result_1000_50_p37
long_result_1000_50_p37, ,M,long_result_1000_50_p38
long_result_1000_50_p38,M,>,long_result_1000_50_p38
long_result_1000_50_p38, ,M,long_result_1000_50_p39
long_result_1000_50_p39,M,>,long_result_1000_50_p39
long_result_1000_50_p39, ,M,long_result_1000_50_p40
long_result_1000_50_p40,M,>,long_result_1000_50_p40
long_result_1000_50_p40, ,M,long_result_1000_50_p41
long_result_1000_50_p41,M,>,long_result_1000_50_p41
long_result_1000_50_p41, ,M,long_result_1000_50_p42
long_result_1000_50_p42,M,>,long_result_1000_50_p42
long_result_1000_50_p42, ,M,long_result_1000_50_p43
long_result_1000_50_p43,M,>,long_result_1000_50_p43
long_result_1000_50_p43, ,M,long_result_1000_50_p44
long_result_1000_50_p44,M,>,long_result_1000_50_p44
long_result_1000_50_p44, ,M,long_result_1000_50_p45
long_result_1000_50_p45,M,>,long_result_1000_50_p45
long_result_1000_50_p45, ,M,long_result_1000_50_p46
long_result_1000_50_p46,M,>,long_result_1000_50_p46
long_result_1000_50_p46, ,M,long_result_1000_50_p47
long_result_1000_50_p47,M,>,long_result_1000_50_p47
long_result_1000_50_p47, ,M,long_result_1000_50_p48
long_result_1000_50_p48,M,>,long_result_1000_50_p48
long_result_1000_50_p48, ,M,long_result_1000_50_p49
long_result_1000_50_p49,M,>,long_result_1000_50_p49
long_result_1000_50_p49, ,M,final

// завершение программы при любых выходных данных

final,I,>,final
final,V,>,final
final,X,>,final
final,L,>,final
final,C,>,final
final,D,>,final
final,M,>,final


 final, ,#,final    