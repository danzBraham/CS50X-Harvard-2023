s = input("Do you agree? ")

# Using or
# if s == "Y" or s == "y":
#     print("Agreed.")
# elif s == "N" or s == "n":
#     print("Not agreed.")

# Using list
s = s.lower()
if s in ["y", "yes"]:
    print("Agreed.")
elif s in ["n", "no"]:
    print("Not agreed.")