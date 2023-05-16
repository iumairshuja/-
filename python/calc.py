#Define a function
def calculator():
  #Take input from the user
  operation = input('''
Please type in the math operation you would like to complete:
+ for addition
- for subtraction
* for multiplication
/ for division
''')

#Take two numbers from the user
  number_1 = int(input('Please enter the first number: '))
  number_2 = int(input('Please enter the second number: '))

#Addition
  if operation == '+':
    print('{} + {} = '.format(number_1, number_2))
    print(number_1 + number_2)

#Subtraction
  elif operation == '-':
    print('{} - {} = '.format(number_1, number_2))
    print(number_1 - number_2)

#Multiplication
  elif operation == '*':
    print('{} * {} = '.format(number_1, number_2))
    print(number_1 * number_2)

#Division
  elif operation == '/':
    print('{} / {} = '.format(number_1, number_2))
    print(number_1 / number_2)

#Error
  else:
    print('You have not typed a valid operator, please run the program again.')

#Call the function
calculator()