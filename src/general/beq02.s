movz x1,#1
movz x2,#2
cmp x1,x2
b.eq foo
movz x3,#3
foo:
movz x4,#4


and x0, x0, x0
