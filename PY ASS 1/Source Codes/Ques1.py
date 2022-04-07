#Question Number 1 - Translating Messages

print('Opeing Abbreviations.txt in Reading Mode!\n')
try:
    with open('abbreviations.txt','rt') as file:
        content=file.read()
    print('Content present in abbreviations.txt\n')
    print('------------------------------\n')
    print(content)
    print('------------------------------\n') 
    try:
        message=input('Enter the message you want to Read: ').lower()
        isfound=file.find(message)
        if isfound != True:
            print('Message is Not Present i File!')
    except:
        print('Message is present in file\n')
except:
    print('File Open Error, File is Not Open Properly!\n')