#Question Number 4
def AreaofCircle():
    radius=float(input('Enter Radius of Circle: '))
    pi=3.14

    areaof_Cricle=pi*radius*radius

    print('Area of Circle:',areaof_Cricle)

    return areaof_Cricle

AreaofCircle()

#Questin Number 3
def DifferentOperations():
    num1=int(input('Enter value of Number 1:'))
    num2=int(input('Enter value of Number 2:'))

    opeationsavailable="'+' , '-' , '*' "

    sum=num1+num2
    sub=num1-num2
    prod=num1*num2
    
    print(opeationsavailable)

    return print(f"Result of {opeationsavailable} of {num1} and {num2} are:",sum,sub,prod)

DifferentOperations()

#Question Number 1
sum=0
for j in range(5,26,5):
    sum=sum+j
    if j>=15:
        break
    print("Sum is",sum)

#Question Number 2
rows = 6
print('Pattern Printing!')
for num in range(rows):
    for i in range(num):
        print(num, end=" ")
    print(" ")