import requests

def get_exchange_rate(date, from_currency, to_currency):
    api_key = "3bab025d21d2f20d0c031d4a"
    url = f"https://v6.exchangerate-api.com/v6/{api_key}/{date}/pair/{from_currency}/{to_currency}"
    response = requests.get(url)
    if response.status_code != 200:
        raise Exception("Unable to get exchange rate.")
    rate = response.json()['conversion_rate']
    return float(rate)

def convert_currency(amount, from_currency, to_currency, date):
    rate = get_exchange_rate(date, from_currency, to_currency)
    converted_amount = amount * rate
    return converted_amount

# Exchange rate API requires an API key, which you can get for free at https://www.exchangerate-api.com/
# Once you have your API key, replace "YOUR_API_KEY_HERE" with your actual API key

current_salary = float(input("Enter your current salary in PKR: "))
from_currency = "PKR"
to_currency = "USD"

# Conversion for November 2022
november_salary = convert_currency(current_salary, from_currency, to_currency, "2022-11-01")
print(f"Your salary in November 2022: ${november_salary:.2f}")

# Conversion for December 2022
december_salary = convert_currency(current_salary, from_currency, to_currency, "2022-12-01")
print(f"Your salary in December 2022: ${december_salary:.2f}")

# Conversion for January 2023
january_salary = convert_currency(current_salary, from_currency, to_currency, "2023-01-01")
print(f"Your salary in January 2023: ${january_salary:.2f}")

# Conversion for February 2023
february_salary = convert_currency(current_salary, from_currency, to_currency, "2023-02-01")
print(f"Your salary in February 2023: ${february_salary:.2f}")

# Conversion for March 2023
march_salary = convert_currency(current_salary, from_currency, to_currency, "2023-03-01")
print(f"Your salary in March 2023: ${march_salary:.2f}")
