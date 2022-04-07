cusotmername=input('Enter customer Name: ')
customeraddress=input('Enter customer Address: ')
amountofloan=int(input('Enter amount of loan: '))
print('\n')
fineonloan=0.0

if amountofloan > 650:
    fineonloan=0.075
    fine=fineonloan * amountofloan
    totalamount=fine+amountofloan
    print('Name of Customer: ',customername)
    print('Address of Customer: ',ccustomeraddress)
    print('Amount of Loan you Have Taken: ',amountofloan)
    print('Fine on Loan: ',fine)
    print('Total Amount of Loan: ', totalamount)

else:
    fineonloan=0.04
    fine=fineonloan * amountofloan
    totalamount=fine+amountofloan
    print('Name of Customer: ',customername)
    print('Address of Customer: ',ccustomeraddress)
    print('Amount of Loan you Have Taken: ',amountofloan)
    print('Fine on Loan: ',fine)
    print('Total Amount of Loan: ', totalamount)