import pandas as pd

df = pd.read_csv("Входен тест за ФМИ IoT 2021.csv")

print( ";".join( df['email'].unique()))
