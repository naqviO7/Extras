#Question Number 4 - Date and Calender
import calendar

def displaycalender():
    date=int(input("Enter Date: "))
    if date > 31:
        print("Date of Month cannot be greater than 31!")
        exit()
    
    month=int(input("Enter Month: ")) 
    if month > 12:
        print("Months cannot be greater than 12!")
        exit()
    
    year=int(input("Enter Year: "))
    if year>2021:
        print("Current Year is 2021!")
        exit()
    # display the calendar
    print(calendar.month(year,month,date))

def isleapyear():
    year=int(input("Enter Year to check if it is a leap year: "))
    if calendar.isleap(year)==True:
        print(year,'is a Leap Year!')
    else:
        print(year,'is Not a Leap Year')

displaycalender()
isleapyear()