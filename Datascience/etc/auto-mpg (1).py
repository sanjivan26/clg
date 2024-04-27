import streamlit as st
import pandas as pd
import pickle as pk
df = pd.read_csv('auto-mpg.csv')
st.title('SIMPLE CALCULATOR')
t=st.text_input("enter the operator")
x=st.number_input("enter x:")
y=st.number_input("enter y:")
if(t=='+'):
    st.write(f"SUM: {x+y}")
if(t=='-'):
    st.write(f"DIFFERENCE : {x-y}")
if(t=='*'):
    st.write(f"MULTIPLICATION :{x*y}")
if(t=='/'):
    st.write(f"DIVISION {x/y}")



'''imported_model = pk.load(open('auto-mpg.pkl','rb'))

X_test=[[1, 1, 2, 1, 2, 3,2]]
st.write(f"prediction : {imported_model.predict(X_test)[0][0]}")
'''