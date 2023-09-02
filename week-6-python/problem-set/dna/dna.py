import csv
import sys


def main():
    # TODO: Check for command-line usage
    if len(sys.argv) != 3:
        sys.exit("Usage: python dna.py data.csv sequence.txt")

    csv_file = sys.argv[1]
    txt_file = sys.argv[2]

    if not csv_file.endswith(".csv"):
        sys.exit("Invalid CSV file")
    if not txt_file.endswith(".txt"):
        sys.exit("Invalid txt file")

    # TODO: Read database file into a variable
    database = read_database(csv_file)

    # TODO: Read DNA sequence file into a variable
    dna_sequence = read_dna_sequence(txt_file)

    # TODO: Find longest match of each STR in DNA sequence
    dna_list = {}
    for dna in database[0].keys():
        if dna != "name":  # Skip the "name" field
            dna_list[dna] = longest_match(dna_sequence, dna)

    # TODO: Check database for matching profiles
    print(matching_dna(database, dna_list))


def read_database(csv_file):
    database = []

    with open(csv_file) as file:
        reader = csv.DictReader(file)
        for row in reader:
            # Convert the values of DNA subsequence to integers
            for key in row:
                if key != "name":  # Skip the "name" field
                    row[key] = int(row[key])
            database.append(row)

    return database


def read_dna_sequence(txt_file):
    with open(txt_file) as file:
        return file.read()


def longest_match(sequence, subsequence):
    """Returns length of longest run of subsequence in sequence."""

    # Initialize variables
    longest_run = 0
    subsequence_length = len(subsequence)
    sequence_length = len(sequence)

    # Check each character in sequence for most consecutive runs of subsequence
    for i in range(sequence_length):
        # Initialize count of consecutive runs
        count = 0

        # Check for a subsequence match in a "substring" (a subset of characters) within sequence
        # If a match, move substring to next potential match in sequence
        # Continue moving substring and checking for matches until out of consecutive matches
        while True:
            # Adjust substring start and end
            start = i + count * subsequence_length
            end = start + subsequence_length

            # If there is a match in the substring
            if sequence[start:end] == subsequence:
                count += 1

            # If there is no match in the substring
            else:
                break

        # Update most consecutive matches found
        longest_run = max(longest_run, count)

    # After checking for runs at each character in sequence, return longest run found
    return longest_run


def matching_dna(database, dna_list):
    for data in database:
        if all(data[d] == dna_list[d] for d in dna_list):
            return data["name"]
    return "No match"


if __name__ == "__main__":
    main()
