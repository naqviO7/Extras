#Question Number 3 - Pattern

Rows={
    1:10,2:22,3:11,4:41,5:64,
    6:9,7:0,8:110,9:31,10:100
}

try:
    numofrow=int(input('Enter Row Number: '))
    if numofrow >10:
        print('Index',numofrow,'is Not Present!')
    else:
        if numofrow in Rows:
            print('Value Present at',numofrow,'is',Rows[numofrow])
except:
    print('Invalid Rows!\n')    