import csv
import sqlite3


def main():
    # Use a context manager for the database connection
    with sqlite3.connect("roster.db") as connection:
        cursor = connection.cursor()

        # Create the database schema
        create_schema(cursor)

        # Read students.csv and populate students and houses lists
        with open("students.csv") as file:
            reader = csv.DictReader(file)
            students = []
            houses = []
            for row in reader:
                name = row["student_name"]
                house = row["house"]
                head = row["head"]

                students.append((name, house))
                if (house, head) not in houses:
                    houses.append((house, head))

        # Insert students and houses into their respective tables
        add_students_query = "INSERT INTO students (student_name, house) VALUES (?, ?)"
        cursor.executemany(add_students_query, students)

        add_houses_query = "INSERT INTO houses (house, head) VALUES (?, ?)"
        cursor.executemany(add_houses_query, houses)

        # Insert assignments data using a single query
        assigments_query = """
            INSERT INTO assignments (student_id, house_id)
            SELECT students.id, houses.id
            FROM students
            JOIN houses ON students.house = houses.house
        """
        cursor.execute(assigments_query)

        # Drop the 'house' column from the 'students' table
        cursor.execute("ALTER TABLE students DROP COLUMN house")

        connection.commit()


def create_schema(cursor):
    # Function to create the database schema
    with open("schema.sql") as file:
        cursor.executescript(file.read())


if __name__ == "__main__":
    main()
