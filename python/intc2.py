import sys
import requests
from PyQt5.QtCore import QTimer
from PyQt5.QtWidgets import QApplication, QLabel

# Create the application and the label
app = QApplication(sys.argv)
label = QLabel("Intel stock value: N/A")

# Show the label
label.show()

def update_value():
    # Send a GET request to Yahoo Finance
    r = requests.get("https://finance.yahoo.com/quote/INTC")

    print (r.content)

    # Extract the stock value
    value = extract_value(r.content)


    # Update the label text
    label.setText("Intel stock value: {}".format(value))

def extract_value(content):
    # Parse the HTML content and extract the value
    # ...

    from bs4 import BeautifulSoup

    # Parse the HTML content
    soup = BeautifulSoup(content, "html.parser")
    #print(soup)

    # Find the element that contains the current stock value
    value_element = soup.find("div", {"class": "Miw(100px) T(6px) C($linkActiveColor) Pos(r) Fz(s) Fw(500) D(ib) Translate3d($zero3dTranslate) Ta(start)"}).find("span")
    value_element = value_element.findNext("span")

    print(value_element)

    # Extract the stock value
    value = value_element.text

    # Print the stock value
    print("Intel stock value: {}".format(value))

    return value

# Create a timer to update the value every 5 seconds
timer = QTimer()
timer.timeout.connect(update_value)
timer.start(3000)  # 5000 milliseconds = 5 seconds
update_value()

# Run the application loop
sys.exit(app.exec_())
