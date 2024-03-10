import datetime

counter = 0
for year in range(1901,2001):
    for month in range(1,13):
        if datetime.datetime.strptime(f"{month}/1/{year}", "%m/%d/%Y").weekday() == 6:
            counter+=1
print(counter)
