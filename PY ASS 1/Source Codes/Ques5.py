#Question Number 5 - Reading Bus Route Data

def displaybusfile():
    count=0
    print('Opeining BusRoute250.txt in Reading Mode!')
    try:
        with open('BusRoute250.txt','rt') as file:
            print('Displaying Bus Route Data...')
            content=file.readlines()
            for line in content:
                count = count + 1
                print("Line{}: {}".format(count, line.strip()))
    except:
        print('BusRoute250.txt cannot be Oppened!')
        
displaybusfile()        