basicsal1=int(input('Enter Basic Salary:'))
basicsal2=int(input('Enter Basic Salary:'))
basicsal3=int(input('Enter Basic Salary:'))
basicsal4=int(input('Enter Basic Salary:'))
basicsal5=int(input('Enter Basic Salary:'))

basicsalary=[basicsal1,basicsal2,basicsal3,basicsal4,basicsal5]

incentiverate=float(input('Enter Incentive Rate: '))

netsal1 = incentiverate * basicsal1
netsal2 = incentiverate * basicsal2
netsal3 = incentiverate * basicsal3
netsal4 = incentiverate * basicsal4
netsal5 = incentiverate * basicsal5

netsalary=[netsal1,netsal2,netsal3,netsal4,netsal5]

print('Basic Salary',basicsalary)
print('Net Salary',netsalary)