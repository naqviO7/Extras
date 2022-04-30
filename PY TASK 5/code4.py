description="""
	First I have crated function called automate. 
	It takes directory path and folder name as arguement.
	It checks if folder with the given name is already created or not.
	If folder name is already there, it will delete that folder.
	If its not peresent it will create folder and inside this folder it will create two more folders.
	It will ceate 5 files and put some text in them.
	It will zip the folder and place 5 copies of it to the other created folder. 
"""

import os
import shutil
from pathlib import Path

def automate(dirpath,folname):
	dpath=Path(dirpath)/folname
	if dpath.exists() and dpath.is_dir():
		shutil.rmtree(dpath)
		print('Previous Directory deleted')
		Path(f"{path}/Backup").mkdir(parents=True,exist_ok=True)
		Path(f"{path}/Working").mkdir(parents=True,exist_ok=True)

		Path(f"{path}/Working/pics").mkdir(parents=True,exist_ok=True)
		Path(f"{path}/Working/docs").mkdir(parents=True,exist_ok=True)
		Path(f"{path}/Working/movies").mkdir(parents=True,exist_ok=True)

		print('Directories and Subdirectories created.')

		Path(f"{path}/Working/docs/school").mkdir(parents=True,exist_ok=True)
		Path(f"{path}/Working/docs/party").mkdir(parents=True,exist_ok=True)

		file1=Path(f"{path}/Working/docs/CORONAVIRUS.txt")
		file2=Path(f"{path}/Working/docs/DANGEROURS.txt")
		file3=Path(f"{path}/Working/docs/KEEPSAFE.txt")
		file4=Path(f"{path}/Working/docs/STAYHOME.txt")
		file5=Path(f"{path}/Working/docs/HYGIENE.txt")

		f1=open(file1,"w")
		f1.write("This is corrona virus file")
		f1.close()
		
		f2=open(file2,"w")
		f2.write("This is dangerours file")
		f2.close()
		
		f3=open(file3,"w")
		f3.write("This is safe file")
		f3.close()

		f4=open(file4,"w")
		f4.write("Stay at your home")
		f4.close()
		
		f5=open(file5,"w")
		f5.write("helo world")
		f5.close()

		print('\nFiles are created in docs folder')

	else:
		path=os.path.join(dirpath,folname)
		os.mkdir(path)
		print("Directory '% s' created" % folname)

		Path(f"{path}/Backup").mkdir(parents=True,exist_ok=True)
		Path(f"{path}/Working").mkdir(parents=True,exist_ok=True)

		Path(f"{path}/Working/pics").mkdir(parents=True,exist_ok=True)
		Path(f"{path}/Working/docs").mkdir(parents=True,exist_ok=True)
		Path(f"{path}/Working/movies").mkdir(parents=True,exist_ok=True)

		print('Directories and Subdirectories created.')

		Path(f"{path}/Working/docs/school").mkdir(parents=True,exist_ok=True)
		Path(f"{path}/Working/docs/party").mkdir(parents=True,exist_ok=True)

		file1=Path(f"{path}/Working/docs/CORONAVIRUS.txt")
		file2=Path(f"{path}/Working/docs/DANGEROURS.txt")
		file3=Path(f"{path}/Working/docs/KEEPSAFE.txt")
		file4=Path(f"{path}/Working/docs/STAYHOME.txt")
		file5=Path(f"{path}/Working/docs/HYGIENE.txt")

		f1=open(file1,"w")
		f1.write("This is corrona virus file")
		f1.close()
		
		f2=open(file2,"w")
		f2.write("This is dangerours file")
		f2.close()
		
		f3=open(file3,"w")
		f3.write("This is safe file")
		f3.close()

		f4=open(file4,"w")
		f4.write("Stay at your home")
		f4.close()
		
		f5=open(file5,"w")
		f5.write("helo world")
		f5.close()

		print('\nFiles are created in docs folder')


def lowercase(path):
	for file in os.listdir(path):
		os.rename(path+file,path+file.lower())

	then=os.listdir(path)
	print(f'Files are converted to Lowercase: {then}')


def archive(path):
	shutil.make_archive('pyarch','zip',path)
	print('Zip Directory Created')


if __name__ == '__main__':
	dirpath=input('Enter directory path: ')
	folname=input('Enter folder name: ')

	automate(dirpath,folname)

	#for the first time running this code comment below code
	path=input('Enter Path: ')
	lowercase(path)
	archive(path)
