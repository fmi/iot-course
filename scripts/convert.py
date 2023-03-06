import pandas as pd

df = pd.read_csv("applicants.csv")

unique_emails = [x.strip() for x in df['email'].unique()]
print(len(unique_emails))
print( ";".join( unique_emails ))