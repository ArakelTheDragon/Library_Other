import os

folder_path = '/path/to/folder' # Initialized path to the folder
prefix = 'prefix_' # Initialized prefix for files to be shown
new_prefix = 'new_prefix_' # Initialized new prefix for files

# print("Enter path to folder") This is unneeded
folder_path=input("Enter path to folder: ")
prefix=input("Enter a file prefix to search for: ")
new_prefix=input("Enter a new file prefix: ")

for filename in os.listdir(folder_path):
    if filename.startswith(prefix):
        new_filename = filename.replace(prefix, new_prefix)
        print(new_filename)
        os.rename(os.path.join(folder_path, filename), os.path.join(folder_path, new_filename))
        
print("\nVisit www.sa.free.bg to support our work!")
