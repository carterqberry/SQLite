#carter quesenberry sqlite project 11 part 1:
import os
import sys
import sqlite3

# check if the correct number of command line arguments is provided:
if len(sys.argv) != 2:
    print("Usage: python3 readfiles.py <directory>")
    sys.exit(1)

# get the file extension:
def get_extension(filename):
    _, ext = os.path.splitext(filename)
    return ext[1:]  # remove the dot from the extension

# connect to sqlite database:
conn = sqlite3.connect("files.db")
cur = conn.cursor()

# drop and create files table:
cur.execute('drop table if exists files')
cur.execute('create table if not exists files (ext text, path text, fname text)')

# walk through the directory tree and put file information into the database:
for root, _, files in os.walk(sys.argv[1]):
    for fname in files:
        ext = get_extension(fname)
        if ext:  # check if the file has an extension
            query = f"insert into files values (?, ?, ?)"
            cur.execute(query, (ext, os.path.abspath(root), fname))

# commit the changes and close connection:
conn.commit()
conn.close()

# output the result of the query to a text file:
conn = sqlite3.connect("files.db")
cur = conn.cursor()
cur.execute("select * from files")
with open("files-part1.txt", "w") as f:
    for row in cur.fetchall():
        f.write(str(row) + "\n")
conn.close()
