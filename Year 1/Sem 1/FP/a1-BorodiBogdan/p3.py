# Solve the problem from the third set here

print("Enter the current date below:")
current_year = input("Enter the year: " )
current_month = input("Enter the month: " )
current_day = input("Enter the day: " )

print("Enter your birth date below")
birth_year = input("Enter the year: " )
birth_month = input("Enter the month: " )
birth_day = input("Enter the day: " )

#---------TESTING THE INPUT-----------
try:
    birth_year = int(birth_year)
    birth_month = int(birth_month)
    birth_day = int(birth_day)
    current_year = int(current_year)
    current_month = int(current_month)
    current_day = int(current_day)
except:
    print("invalid input")
    exit()

month_days = [0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]

if(birth_year < 0 or current_year < 0):
    print("invalid input")
    exit()
elif(birth_month > 12 or birth_month <= 0 or current_month > 12 or current_month <= 0):
    print("invalid input")
    exit()
elif(birth_day > month_days[birth_month] or current_day > month_days[current_month] or current_day <= 0 or birth_day <= 0):
    print("invalid input")
    exit()
elif(current_year < birth_year):
    print("invalid input")
    exit()
elif(current_year == birth_year and birth_month > current_month):
    print("invalid input")
    exit()
elif(current_year == birth_year and birth_month == current_month and birth_day > current_day):
    print("invalid input")
    exit()
#--------------DONE TESTING THE INPUT-------------

number_of_days = 0

#check the exception
if(current_year == birth_year):
    for month_index in range (birth_month + 1, current_month - 1):
        number_of_days += month_days[month_index]
    number_of_days = number_of_days + (month_days[birth_month] - birth_day) + current_day

    print("You are: " + str(number_of_days) + " days old")
    exit()

#first let's add the days from the current year

number_of_days = current_day

for month_index in range(1, current_month):
    number_of_days += month_days[month_index]

#now let's add the days from the birth year

number_of_days += (month_days[birth_month] - birth_day)

for month_index in range(birth_month + 1, 13):
    number_of_days += month_days[month_index]


#let's check if the birth_year or the current_year is a leap one

if(birth_year % 4 == 0):
    if(birth_month <= 2):
        number_of_days += 1

if(current_year % 4 == 0):
    if(current_month >= 2):
        number_of_days += 1

#now let's add the other years

leap_years = int((current_year - birth_year - 1) / 4)

number_of_days += 365 * (current_year - birth_year - 1)
number_of_days += leap_years

print("You are: " + str(number_of_days) + " days old")
exit()
