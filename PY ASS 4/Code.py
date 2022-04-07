# class that is representing our enterpirse software
class Enterprise:
    #function to store client data
    def AddClient():      
        fp=open("EnterpriseData.txt","wt")
        
        name=input("Enter Client's Name: ")
        id=input("Enter Client's ID: ")
        address=input("Enter Client's Address: ")
        phone=input("Enter Client's Phone Number: ")
        category={
            "1":"Software","2":"Laptop","3":"Games",
            "4":"Office Tools","5":"Accessories"}
        print("Catagories Available: ",category)
        cat=input("Enter Catagory of User: ")
        
        fp.writelines("Client's Data\n")
        fp.write("ID: ")
        fp.write(id)
        fp.write("\tName: ")
        fp.write(name)
        fp.write("\tAddress: ")
        fp.write(address)
        fp.write("\tPhone: ")
        fp.write(phone)
        fp.write("\tCategory: ")
        fp.write(cat)
        fp.write("\n")
        print("Client is Added in",fp.name)
        fp.close()
         
        
    #new client function
    def AddNewClient():
        fp=open("EnterpriseData.txt","a")
        
        name=input("Enter Client's Name: ")
        id=input("Enter Client's ID: ")
        address=input("Enter Client's Address: ")
        phone=input("Enter Client's Phone Number: ")
        category={
            "1":"Software","2":"Laptop","3":"Games",
            "4":"Office Tools","5":"Accessories"}
        print("Catagories Available: ",category)
        cat=input("Enter Catagory of User: ")
        
        fp.writelines("Client's Data\n")
        fp.write("ID: ")
        fp.write(id)
        fp.write("\tName: ")
        fp.write(name)
        fp.write("\tAddress: ")
        fp.write(address)
        fp.write("\tPhone: ")
        fp.write(phone)
        fp.write("\tCategory: ")
        fp.write(cat)
        fp.write("\n")
        print("Client is Added in",fp.name)
        fp.close()
            
        
    #search client function
    def SearchClient():
        id=int(input("Enter Client's ID to Search: "))
        name=input("Enter Client's Name to Search: ")
                
        #reading content of file
        fp=open("EnterpriseData.txt","rt") 
        data=fp.readlines()
        
        if id==data and name==data:
            print("This Client is Present in File!")
        else:
            print("This Client is not Present in File!")
    

    #remove client function
    def RemoveClient(): 
        with open("EnterpriseData.txt","rt") as fp:
            data=fp.readlines()
        
        with open("EnterpriseData.txt","wt") as fp:
                print("Deloeting Clients Data is Present in File!")
                for line in data:
                    if line.strip('\n')!="ID: 190820":
                            fp.write(line)   
        print("Clients Data is Deleted!")

    def PrintDetails():
        print("Displaying Client's Data")
        with open("EnterpriseData.txt","r") as fp: 
            data=fp.readlines()
        
        print(data) 

    
#function to display menu
def Menu():       
    print("||====================================||")
    print("||         Enterpise System           ||")
    print("||====================================||")
    print("||1. Add Client Data                  ||")
    print("||2. Add New Client Data              ||")
    print("||3. Search for Client                ||")
    print("||4. Remove Data of File              ||")
    print("||5. Print Details of Any Client      ||")
    print("||6. Save Data into Text File         ||")
    print("||====================================||")
    
    #while loop take input from user 
    while(True):
        usrinput=int(input('Enter Key to Perform Option: '))
        if usrinput==1:
            en=Enterprise.AddClient()
        elif usrinput==2:
            en=Enterprise.AddNewClient()
        elif usrinput==3:
            en=Enterprise.SearchClient()
        elif usrinput==4:
            en=Enterprise.RemoveClient()
        elif usrinput==5:
            en=Enterprise.PrintDetails()
        elif usrinput==6:
            print("Data is Already Saved at Input!")
                       
        contd=input("Do You Want to Continue(Y/N): ")
        if contd=="n" or contd=="N":
            print("Quitting Enterprise Software\n")
            break

#calling main menu finction        
Menu()