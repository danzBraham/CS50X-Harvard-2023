from cs50 import SQL


def main():
    db = SQL("sqlite:///favorites.db")

    favorite = input("Favorite: ").capitalize()
    db.execute("BEGIN TRANSACTION")
    rows = db.execute(
        "SELECT COUNT(*) AS total FROM favorites WHERE problem = ?", favorite
    )
    db.execute("COMMIT")
    print(rows[0])


if __name__ == "__main__":
    main()
