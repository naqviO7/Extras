filghtid=int(input('enter flight id: '))
adultprice=int(input('enter adult price: '))
childprice=int(input('enter child price: '))
numberof_adultpassengers=int(input('enter number of adult passengers: '))
numberof_childepassengers=int(input('enter number of child passengers: '))

discount=int(input('enter amount of discount: '))

totalprice=(adultprice*numberof_adultpassengers)+ (childprice*numberof_childepassengers)
totalpayable=totalprice-discount

print('total price calculated:',totalprice)
print('total payable amount:',totalpayable)