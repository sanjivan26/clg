import sys
import os
import re

def main():

    # python3 program_name[0].py read_directory[1] write_directory[2]
    if len(sys.argv) != 3:
        print("Number of arguments is wrong !")
        return 0
    
    # Path in which the program is stored
    main_dir = os.getcwd()
    read_dir = sys.argv[1]
    write_dir = sys.argv[2]
    
    pattern = r'^[A-Za-z][A-Za-z0-9\.-_]*$'
    domain = '@snuchennai.edu.in'
    valid_special_characters = ['.', '-', '_']
    choice = 'y'
    
    try:
        os.chdir(read_dir) # Returns FileNotFoundError if read_dir is not found
        
        # Checks if there are 5 files in the read_dir
        if len(os.listdir()) != 5:
            raise TypeError
        
    except FileNotFoundError:
        print("Input folder not found !")
        return 0
    
    except TypeError:
        print("Number of files in the folder is invalid !")
        return 0
    
    # get the name of the files in the read_dir in a list
    read_files = os.listdir()
    
    # Go back (cd ..)
    os.chdir(main_dir)
    
    # check if write_dir is present the main folder.
    if write_dir in os.listdir():
        choice = input("Do you want to delete the output folder ? (y/n): ")

    if choice.lower() == 'n':
        print("Exited !")
        return 0
    
    # if write_dir in main folder, delete the contents of the folder. Hoping this doesn't contain more folders, coz os.remove takes only filenames are arg
    if write_dir in os.listdir():
        
        # cd write_dir
        os.chdir(write_dir)
        
        # Remove each file from the directory
        for name in os.listdir():
            # name is the name of the file in the write_dir
            os.remove(name)

    else:
        # Create a new dir with the same name if not found
        os.mkdir(write_dir)
    
    for name in read_files:
        
        # create empty list
        valid_usernames = list()
        
        # get the contents in the first read file using readlines() -> list of lines
        with open(f'{main_dir}\\{read_dir}\\{name}') as file:
           content = file.readlines()

        for username in content:
            valid = ''
            
            if(username in re.findall(username, pattern)):   # Returns list of words satisfying the condition
                valid += username + domain # if valid, add the domain name
                
            else: # if not valid, make it valid by removing the invalid characters
                for i in range(len(username)):
                    
                    # Check for the valid characters and add to valid
                    if username[i].isalnum() or username[i] in valid_special_characters:
                        valid += username[i]
                
                # once the username is valid, add the domain to it
                valid += domain
            
            # if you use this, the file in the write_dir will open n close for each username in the read_file for each file
            # with open(f'{main_dir}\\{write_dir}\\{name}', 'a') as file:
            #     file.write(f'{valid}\n')

            # Add this to a list, coz it open the write_dir file once for each file in read_dir
            valid_usernames.append(valid) # Prevents opening the file for each username

        # open the file in the write_dir with the same name as the file in the read_dir in append mode
        with open(f'{main_dir}\\{write_dir}\\{name}', 'a') as file:
            
            # Write each of the username in each line
            for name in valid_usernames:    
                file.write(f'{name}\n')
                
# Prevents the execute of the main function with we import this file to a different file
if __name__ == '__main__':
    main()
    
    
# Note:
# Instead of writing this in a function, we can use the exit() function in the global scope
# That 'might' be easier

# finally.... Varata Mame Durrrrr