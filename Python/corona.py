from turtle import *
import turtle



bgcolor('black')
turtle.goto(0,200)
color('green')
turtle.speed(speed=0)

hideturtle()


b = 0

while b < 195:

	right(b)

	forward(b * 3)

	b = b + 0.5
	
turtle.exitonclick()
