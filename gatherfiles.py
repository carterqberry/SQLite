#carter quesenberry sqlite project 11 part 2:
import os
import sqlite3
import sys
import zipfile

# check if the correct number of command line arguments is provided:
if len(sys.argv) < 3:
    print("Usage: python3 gatherfiles.py <database_file> <extension1> [<extension2> ...]")
    sys.exit(1)

# retrieve file names for a given extension from the database:
def retrieve_files(db_file, extension):
    conn = sqlite3.connect(db_file)
    cur = conn.cursor()
    query = "select path, fname from files where ext like ?"
    cur.execute(query, (extension,))
    files = cur.fetchall()
    conn.close()
    return files

# add files to a zip file:
def add_to_zip(zip_file, files):
    count = 0
    with zipfile.ZipFile(zip_file, 'w') as zf:
        for path, fname in files:
            full_path = os.path.join(path, fname)
            zf.write(full_path, arcname=os.path.relpath(full_path))
            count += 1
    return count

def main():
    db_file = sys.argv[1]
    extensions = sys.argv[2:]

    for ext in extensions:
        files = retrieve_files(db_file, f'%{ext}%')
        zip_file = f"{ext}.zip"
        count = add_to_zip(zip_file, files)
        print(f"{count} {ext} files gathered")

if __name__ == "__main__":
    main()
