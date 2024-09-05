people = {
    "zidan": "1234567891",
    "abra": "9876543219",
    "john": "123454321",
}

name = input("Name: ").lower()

if name in people:
    print(f"Number: {people[name]}")
else:
    print("Not Found")
