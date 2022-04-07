PurcahsePrcie=int(input('Enter Purchase Choice: '))
PurchaseItem=int(input('Enter Purchase Item: '))
Discount=0

TotalPrice=PurcahsePrcie*PurchaseItem

if PurchaseItem>100:
    Discount=0.20*PurcahsePrcie
    NetPrice=Discount
    
    print('Total Purchase Price:',TotalPrice)
    print('Price of 1 Item:',PurcahsePrcie)
    print('Discount Given:',Discount)
    print('Net Purchase Price: ',NetPrice)
else:
    Discount=0.10*PurcahsePrcie
    NetPrice=Discount
    
    print('Total Purchase Price:',TotalPrice)
    print('Price of 1 Item:',PurcahsePrcie)
    print('Discount Given:',Discount)
    print('Net Purchase Price: ',NetPrice)