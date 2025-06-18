# File Sorter (C++)

This is a simple C++ program that automatically organizes files in a directory by their file extensions. It scans the current directory, detects unique file extensions, and then creates corresponding folders (if they don’t already exist) to move the files into.

## How It Works

- Detects all files in the current directory
- Extracts the file extensions (e.g., `.txt`, `.jpg`, `.cpp`, etc.)
- Creates a folder for each unique extension
- Moves each file into its matching folder

## Example

Before Sorting:
```
file1.txt
file2.cpp
file3.txt
image1.jpg
image2.png
notes.docx
script.py
```

After Sorting:
```
/txt/file1.txt
/txt/file3.txt
/cpp/file2.cpp
/jpg/image1.jpg
/png/image2.png
/docx/notes.docx
/py/script.py
```

## Demo

| Before Sorting | After Sorting | Terminal Output |
|----------------|----------------|------------------|
| ![Before]() | ![After]() | ![Output]() |

## How to Run

Compile the program:
```
g++ -std=c++17 -o fileSorter fileSorter.cpp
```

Run the executable in the folder you want to sort:
```
./fileSorter
```

## Notes

- Only regular files are sorted — folders are ignored.
- Existing extension-named folders will not be overwritten.