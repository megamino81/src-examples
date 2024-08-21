import requests
from bs4 import BeautifulSoup

# Send a GET request to the website
r = requests.get("https://finance.yahoo.com/quote/INTC")

# Parse the HTML content
soup = BeautifulSoup(r.content, "html.parser")
#print(soup)

# Find the element that contains the current stock value
value_element = soup.find("div", {"class": "Miw(100px) T(6px) C($linkActiveColor) Pos(r) Fz(s) Fw(500) D(ib) Translate3d($zero3dTranslate) Ta(start)"}).find("span")
value_element = value_element.findNext("span")

print(value_element)

# Extract the stock value
value = value_element.text

# Print the stock value
print("Intel stock value: {}".format(value))

