# Question Number 2 - Merge Big Files

#try and except block for exception handelling
try:
    data = data2 = ""
    #file1
    print('Opeing names_set1.txt in Reading Mode!')
    try:
        with open('names_set1.txt') as file1:
	        data = file1.read()
        print('names_set1.txt is Oppened and data is read!\n')
    except:
        print('names_set1.txt cannot be Oppened!')
    
    #file2    
    print('Opeing names_set2.txt in Reading Mode!')
    try:
        with open('names_set2.txt') as file2:
	        data2 = file2.read()
        print('names_set2.txt is Oppened and data is read!\n')
    except:
        print('names_set2.txt cannot be Oppened!')
    
    #merging data
    data += data2
    #writing merged data in file
    print('Merging names of files in lower text!')
    with open ('mergednames.txt', 'w') as file3:
	    file3.write(data.lower())
    
except:
    print('Files cannot be Merged!')