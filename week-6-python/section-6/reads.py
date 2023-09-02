import csv

books = []

with open("books.csv", encoding="utf-8-sig") as file:
    file_reader = csv.DictReader(file)
    for row in file_reader:
        books.append(row)

for book in books:
    print(book)