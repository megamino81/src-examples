import requests
from bs4 import BeautifulSoup

# Send a GET request to the website
r = requests.get("https://www.weather.com")

# Parse the HTML content
soup = BeautifulSoup(r.content, "html.parser")
print(soup)

# Find the element that contains the current temperature
temp_element = soup.find("span", {"class": "temperature"})

# Extract the temperature value
print(temp_element)

temp = temp_element.text

# Print the temperature
print("Temperature: {}".format(temp))

