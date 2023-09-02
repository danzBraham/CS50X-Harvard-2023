import sys

names = ["Zidan", "Abraham", "John", "David", "Ana", "Thomas"]
name = input("Name: ")

if name in names:
    print("Found.")
    sys.exit(0)

print("Not found.")
sys.exit(1)