import turtle as t

t.bgcolor("black")
t.color("pink")
t.speed(0)

# 실제 펜이 돌아가는 반복문
for i in range(200):
    t.forward(i*2)
    t.left(100)
t.done()
