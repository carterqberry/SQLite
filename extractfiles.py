#carter quesenberry sqlite project 11 part 3:
import os
import re
import sys
import zipfile

# check if the correct number of command line arguments are provided:
if len(sys.argv) != 3:
    print("Usage: python3 extractfiles.py <zip_file> <regex_pattern>")
    sys.exit(1)

# extract files from a zip file based on a regex pattern:
def extract_files(zip_file, pattern):
    count = 0
    with zipfile.ZipFile(zip_file, 'r') as zf:
        for member in zf.infolist():
            basename = os.path.basename(member.filename)
            if re.match(pattern, basename):
                zf.extract(member)
                count += 1
    return count

def main():
    zip_file = sys.argv[1]
    pattern = sys.argv[2]

    count = extract_files(zip_file, pattern)
    print(f"{count} files extracted")

if __name__ == "__main__":
    main()
