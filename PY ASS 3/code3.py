def DisplayComanyName():
    print('MMP Corporation')
    return

salary=0

def ComputeSalary():
    rateperday=int(input('Enter Rate per Day: '))
    daysworked=int(input('Enter Number of Days Worked: '))

    salary = rateperday * daysworked

    print(f"Your Salary for {daysworked} days is {salary}$s")

    return salary

def ComputeAllowance():
    
    allowance=int(input('Enter Amount of Allowance: '))
    if allowance >= 500:
        allgranted= 0.05 * salary
        totalsal= allgranted + salary
        
        print(f"Your Salary After Granting Allowance is {totalsal}$s")
        
    elif allowance < 500:
        allgranted= 0.02 * salary
        totalsal= allgranted + salary
        
        print(f"Your Salary After Granting Allowance is {totalsal}$s")

    return totalsal


def mainfunc():
    DisplayComanyName()
    ComputeSalary()
    ComputeAllowance()
    
mainfunc()