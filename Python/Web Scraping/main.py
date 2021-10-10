import requests
from bs4 import BeautifulSoup
import pandas as pd

URL = "https://www.flipkart.com/washing-machines/fully-automatic-front-load~function/pr?sid=j9e%2Cabm%2C8qx&otracker=nmenu_sub_TVs%20%26%20Appliances_0_Fully%20Automatic%20Front%20Load"
page = requests.get(URL)

soup = BeautifulSoup(page.content, "html.parser")

products = []
prices = []

for i in soup.findAll('div', attrs={'class': '_4rR01T'}):
    name = i.text
    products.append(name)
for i in soup.findAll('div', attrs={'class': '_30jeq3 _1_WHN1'}):
    price = i.text
    prices.append(price)

df = pd.DataFrame({'Product Name': products, 'Price': prices})
df.to_csv('products.csv', index=False)
