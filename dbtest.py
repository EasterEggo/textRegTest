import sys
import os
table = "registers.data"


def hlp():
    print("dbtest.py - v0.0.1\ntool for editing a file\n---")
    print("ls      list the contents of the file")
    print("write   write the contents to the file")
    print("clear   clear the contents of the file")
    print("edit    edit the contents of the file")


def ls():
    read = open(table, "r")
    print(read.read())
    read.close()


def edit():
    os.system("vim registers.data")


def write():
    wrt = open(table, "a")
    getin = input("write the data separated by spaces:")
    data = getin + "\n"
    wrt.write(data)
    print("successfully appended data!\n")
    print("-------------------- {table} --------------------\n")
    wrt.close()
    ls()


def clear():
    era = open(table, "w")
    era.write("")
    era.close()


def main():
    if (sys.argv[1] == "ls"):
        ls()
    elif (sys.argv[1] == "write"):
        write()
    elif (sys.argv[1] == "clear"):
        clear()
    elif (sys.argv[1] == "help"):
        hlp()
    elif (sys.argv[1] == "edit"):
        edit()
    else:
        print("ERROR! Command not found!\n\n")
        hlp()


main()
