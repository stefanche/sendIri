-- Keep a log of any SQL queries you execute as you solve the mystery.
-- DATE: 28.7 TIME OF CRIME: 10:15; SUSPECT called someone as they were leaving for less than a minute, plans to leave with a plane tommorow,
-- got into a car and drove away. Suspect withdrawed money from the Leggett Street's ATM
-- Crime description
SELECT * FROM crime_scene_reports WHERE month= 7 AND day= 28 AND street= 'Humphrey Street';
-- Details from the three witnesses where id= id's from the crime_scene_reports
SELECT * FROM interviews WHERE id IN (SELECT id FROM crime_scene_reports WHERE month= 7 AND day= 28 AND street= 'Humphrey Street');
-- No Foreign Key present. Must create another query based on the transcript.
SELECT * FROM interviews WHERE transcript LIKE '%bakery%' AND month= 7;
-- bakery security logs looking for a plate number from the date and time
SELECT * FROM bakery_security_logs WHERE day= 28 AND month= 7 AND hour=10 AND minute<25 AND minute>15;
-- getting names from plate numbers
SELECT name FROM people WHERE license_plate IN (SELECT license_plate FROM bakery_security_logs WHERE day= 28 AND month= 7 AND hour=10 AND minute<25 AND minute>15);
--getting call logs from names
SELECT caller, receiver, duration FROM phone_calls WHERE day= 28 AND duration <60 AND caller IN
(SELECT phone_number FROM people WHERE license_plate IN
(SELECT license_plate FROM bakery_security_logs WHERE day= 28 AND month= 7 AND hour=10 AND minute<25 AND minute>15));

--getting the names of the possible acomplice
SELECT name FROM people WHERE phone_number IN (SELECT receiver FROM phone_calls WHERE day= 28 AND duration <60 AND caller IN
(SELECT phone_number FROM people WHERE license_plate IN
(SELECT license_plate FROM bakery_security_logs WHERE day= 28 AND month= 7 AND hour=10 AND minute<25 AND minute>15)));

-- getting the names of the suspects that called someone on 28th for less than a minute
SELECT name FROM people WHERE phone_number IN (SELECT caller FROM phone_calls WHERE day= 28 AND duration <60 AND caller IN
(SELECT phone_number FROM people WHERE license_plate IN
(SELECT license_plate FROM bakery_security_logs WHERE day= 28 AND month= 7 AND hour=10 AND minute<25 AND minute>15)));

-- Eugen withdrew money from the ATM on legget street. Getting the account nr
SELECT account_number FROM bank_accounts WHERE person_id IN (SELECT id FROM people WHERE name= 'Eugene');

-- Getting bank accounts of suspects based on plate nr
SELECT account_number FROM bank_accounts WHERE person_id IN(
SELECT id FROM people WHERE license_plate IN
(SELECT license_plate FROM bakery_security_logs WHERE day= 28 AND month= 7 AND hour=10 AND minute<25 AND minute>15));

-- Getting transactions from Leggett Street from the persons that had licence plates

SELECT * FROM atm_transactions WHERE atm_location= 'Leggett Street' AND day= 28 AND month= 7 AND account_number IN
(SELECT account_number FROM bank_accounts WHERE person_id IN(
SELECT id FROM people WHERE license_plate IN
(SELECT license_plate FROM bakery_security_logs WHERE day= 28 AND month= 7 AND hour=10 AND minute<25 AND minute>15)));

-- Getting names from account numbers in Leggett Street

SELECT account_number FROM atm_transactions WHERE atm_location= 'Leggett Street' AND day= 28 AND month= 7 AND account_number IN
(SELECT account_number FROM bank_accounts WHERE person_id IN(
SELECT id FROM people WHERE license_plate IN
(SELECT license_plate FROM bakery_security_logs WHERE day= 28 AND month= 7 AND hour=10 AND minute<25 AND minute>15)));

-- Getting the names from the persons that left parking and withdrew money from the atm on legged street
SELECT name FROM bank_accounts JOIN people ON bank_accounts.person_id= people.id WHERE account_number IN
(SELECT account_number FROM atm_transactions WHERE atm_location= 'Leggett Street' AND day= 28 AND month= 7 AND account_number IN
(SELECT account_number FROM bank_accounts WHERE person_id IN(
SELECT id FROM people WHERE license_plate IN
(SELECT license_plate FROM bakery_security_logs WHERE day= 28 AND month= 7 AND hour=10 AND minute<25 AND minute>15)))) AND people.id IN
(SELECT id FROM people WHERE phone_number IN (SELECT caller FROM phone_calls WHERE day= 28 AND duration <60 AND caller IN
(SELECT phone_number FROM people WHERE license_plate IN
(SELECT license_plate FROM bakery_security_logs WHERE day= 28 AND month= 7 AND hour=10 AND minute<25 AND minute>15))));

-- Bruce and Diana the two suspects. Query for getting all the info about them
SELECT * FROM bank_accounts JOIN people ON bank_accounts.person_id= people.id WHERE account_number IN
(SELECT account_number FROM atm_transactions WHERE atm_location= 'Leggett Street' AND day= 28 AND month= 7 AND account_number IN
(SELECT account_number FROM bank_accounts WHERE person_id IN(
SELECT id FROM people WHERE license_plate IN
(SELECT license_plate FROM bakery_security_logs WHERE day= 28 AND month= 7 AND hour=10 AND minute<25 AND minute>15)))) AND people.id IN
(SELECT id FROM people WHERE phone_number IN (SELECT caller FROM phone_calls WHERE day= 28 AND duration <60 AND caller IN
(SELECT phone_number FROM people WHERE license_plate IN
(SELECT license_plate FROM bakery_security_logs WHERE day= 28 AND month= 7 AND hour=10 AND minute<25 AND minute>15))));

-- Getting info of possible acomplice

SELECT name FROM people WHERE phone_number IN (SELECT receiver FROM phone_calls WHERE day= 28 AND duration <60 AND caller IN
(SELECT phone_number FROM people WHERE name= 'Bruce'));

--number of flights on 29.07

SELECT * FROM flights WHERE day=29 AND month= 7;
-- Getting info about who flew

SELECT * from passengers JOIN flights ON flights.id= passengers.flight_id WHERE flights.day= 29 AND flights.month= 7 AND passport_number IN
(SELECT passport_number FROM people WHERE name= 'Diana' OR name= 'Bruce');

-- Getting info about the destination
SELECT * FROM airports WHERE id= 4;