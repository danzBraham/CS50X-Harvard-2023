books = []

# Add three books to your shelf
for i in range(3):
    book = {}
    book["title"] = input("Title: ").strip().capitalize()
    book["Author"] = input("Author: ").strip().capitalize()

    books.append(book)

# Print book titles
for book in books:
    print(book["title"])