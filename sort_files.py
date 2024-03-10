import os
import shutil

src_folder = "./src"

def sort_files():
    for file in os.listdir(src_folder):
        fpath = os.path.join(src_folder, file)
        if os.path.isfile(fpath):
            sort_file(fpath)

def sort_file(file_path):
    file_name = os.path.basename(file_path)
    new_folder = determine_folder(file_name)
    if new_folder:
        new_path = os.path.join(src_folder, new_folder, file_name)
        os.makedirs(os.path.dirname(new_path), exist_ok=True)
    
        shutil.move(file_path, new_path)
        print(f"Moved {file_name} to {new_folder}")
    else:
        print(f"Skipping {file_name} - No matching folder found")

def determine_folder(file_name):
    try:
        if "_" in file_name:
            file_number = int(file_name.split('_')[0])
        else:
            file_number = int(file_name.split('.')[0])
        folder_number = (file_number // 10) * 10
        return f"{folder_number}-{folder_number + 9}"
    except:
        return None

if __name__ == "__main__":
    
    sort_files()
