-- Keep a log of any SQL queries you execute as you solve the mystery.

-- Find crime scene description
SELECT description
FROM crime_scene_reports
WHERE year = 2021
AND month = 7
AND day = 28
AND street = 'Humphrey Street';

-- Analysis the transcript
SELECT transcript
FROM interviews
WHERE year = 2021
AND month = 7
AND day = 28;

-- Check activity and license plate on the bakery parking lots
SELECT activity, license_plate, minute
FROM bakery_security_logs
WHERE year = 2021
AND month = 7
AND day = 28
AND hour = 10;

-- Find person on the bakery parking lots around 10.15am to 10.25am
SELECT name, phone_number, passport_number
FROM people
WHERE license_plate IN (
    SELECT license_plate
    FROM bakery_security_logs
    WHERE year = 2021
    AND month = 7
    AND day = 28
    AND hour = 10
    AND minute > 15
    AND minute < 25
);

-- SUSPECTS on the bakery parking lots
-- Vanessa
-- Barry
-- Iman
-- Sofia
-- Luca
-- Diana
-- Kelsey
-- Bruce

-- Check atm transactions
SELECT account_number, transaction_type, amount
FROM atm_transactions
WHERE year = 2021
AND month = 7
AND day = 28
AND atm_location = 'Leggett Street';

-- Find person whose withdrawing money at Leggett Streets
SELECT name, phone_number, passport_number
FROM people AS p
    JOIN bank_accounts AS b
    ON b.person_id = p.id
WHERE account_number IN (
    SELECT account_number
    FROM atm_transactions
    WHERE year = 2021
    AND month = 7
    AND day = 28
    AND atm_location = 'Leggett Street'
    AND transaction_type = 'withdraw'
);

-- Match people withdrawing money with those parked at the bakery
SELECT name
FROM people
WHERE license_plate IN (
    SELECT license_plate
    FROM bakery_security_logs
    WHERE year = 2021
    AND month = 7
    AND day = 28
    AND hour = 10
    AND minute > 15
    AND minute < 25
)
AND name IN (
    SELECT name
    FROM people AS p
        JOIN bank_accounts AS b
        ON b.person_id = p.id
    WHERE account_number IN (
        SELECT account_number
        FROM atm_transactions
        WHERE year = 2021
        AND month = 7
        AND day = 28
        AND atm_location = 'Leggett Street'
        AND transaction_type = 'withdraw'
    )
);

-- SUSPECTS that are withdrawing money at Leggett Streets
-- Bruce
-- Diana
-- Iman
-- Luca

-- Find the caller
SELECT name
FROM people
WHERE phone_number IN (
    SELECT caller
    FROM phone_calls
    WHERE year = 2021
    AND month = 7
    AND day = 28
    AND duration < 60
    AND caller IN (
        SELECT phone_number
        FROM people
        WHERE name IN (
            SELECT name
            FROM people
            WHERE license_plate IN (
                SELECT license_plate
                FROM bakery_security_logs
                WHERE year = 2021
                AND month = 7
                AND day = 28
                AND hour = 10
                AND minute > 15
                AND minute < 25
            )
            AND name IN (
                SELECT name
                FROM people AS p
                    JOIN bank_accounts AS b
                    ON b.person_id = p.id
                WHERE account_number IN (
                    SELECT account_number
                    FROM atm_transactions
                    WHERE year = 2021
                    AND month = 7
                    AND day = 28
                    AND atm_location = 'Leggett Street'
                    AND transaction_type = 'withdraw'
                )
            )
        )
    )
);

-- Find the receiver
SELECT name
FROM people
WHERE phone_number IN (
    SELECT receiver
    FROM phone_calls
    WHERE year = 2021
    AND month = 7
    AND day = 28
    AND duration < 60
    AND caller IN (
        SELECT phone_number
        FROM people
        WHERE name IN (
            SELECT name
            FROM people
            WHERE license_plate IN (
                SELECT license_plate
                FROM bakery_security_logs
                WHERE year = 2021
                AND month = 7
                AND day = 28
                AND hour = 10
                AND minute > 15
                AND minute < 25
            )
            AND name IN (
                SELECT name
                FROM people AS p
                    JOIN bank_accounts AS b
                    ON b.person_id = p.id
                WHERE account_number IN (
                    SELECT account_number
                    FROM atm_transactions
                    WHERE year = 2021
                    AND month = 7
                    AND day = 28
                    AND atm_location = 'Leggett Street'
                    AND transaction_type = 'withdraw'
                )
            )
        )
    )
);

-- SUSPECTS Callers and Receivers
-- Diana -> Philip
-- Bruce -> Robin

-- Find The city the thief escaped to
SELECT city
FROM airports
WHERE id = (
    SELECT destination_airport_id
    FROM flights
    WHERE year = 2021
    AND month = 7
    AND day = 29
    AND origin_airport_id = (
        SELECT id
        FROM airports
        WHERE city = 'Fiftyville'
    )
    ORDER BY hour
    LIMIT 1
);

-- Find the thief
SELECT name
FROM people
WHERE passport_number = (
    SELECT passport_number
    FROM passengers
    WHERE flight_id = (
        SELECT id
        FROM flights
        WHERE year = 2021
        AND month = 7
        AND day = 29
        AND origin_airport_id = (
            SELECT id
            FROM airports
            WHERE city = 'Fiftyville'
        )
        ORDER BY hour
        LIMIT 1
    )
    AND passport_number IN (
        SELECT passport_number
        FROM people
        WHERE phone_number IN (
            SELECT caller
            FROM phone_calls
            WHERE year = 2021
            AND month = 7
            AND day = 28
            AND duration < 60
            AND caller IN (
                SELECT phone_number
                FROM people
                WHERE name IN (
                    SELECT name
                    FROM people
                    WHERE license_plate IN (
                        SELECT license_plate
                        FROM bakery_security_logs
                        WHERE year = 2021
                        AND month = 7
                        AND day = 28
                        AND hour = 10
                        AND minute > 15
                        AND minute < 25
                    )
                    AND name IN (
                        SELECT name
                        FROM people AS p
                            JOIN bank_accounts AS b
                            ON b.person_id = p.id
                        WHERE account_number IN (
                            SELECT account_number
                            FROM atm_transactions
                            WHERE year = 2021
                            AND month = 7
                            AND day = 28
                            AND atm_location = 'Leggett Street'
                            AND transaction_type = 'withdraw'
                        )
                    )
                )
            )
        )
    )
);

-- Find the accomplice
SELECT name
FROM people
WHERE phone_number = (
    SELECT receiver
    FROM phone_calls
    WHERE year = 2021
    AND month = 7
    AND day = 28
    AND duration < 60
    AND caller = (
        SELECT phone_number
        FROM people
        WHERE name = 'Bruce'
    )
);
