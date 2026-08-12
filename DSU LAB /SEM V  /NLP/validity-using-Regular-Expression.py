# prompt: regular expression in simple way
import re

def check_email(email):
    pattern = r"^[a-zA-Z0-9_.+-]+@[a-zA-Z0-9-]+\.[a-zA-Z]{2,}$"
    match = re.match(pattern, email)
    return bool(match)

def check_phone_number(phone_number):
    pattern = r"^(\+\d{1,2}\s?)?\(?\d{3}\)?[\s.-]?\d{3}[\s.-]?\d{4}$"
    match = re.match(pattern, phone_number)
    return bool(match)

def check_date(date_str):
    pattern = r"^(0[1-9]|1[0-2])\/(0[1-9]|[12][0-9]|3[01])\/(19|20)\d{2}$"
    match = re.match(pattern, date_str)
    return bool(match)

email = "test@example.com"
print(f"'{email}' is a valid email: {check_email(email)}")

phone = "+1 (123) 456-7890"
print(f"'{phone}' is a valid phone number: {check_phone_number(phone)}")

date = "12/25/2024"
print(f"'{date}' is a valid date: {check_date(date)}")
