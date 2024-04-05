import streamlit as st

x=st.number_input("Enter the first number")
y=st.number_input("Enter the second number")

op=st.radio("Choose the operation",['+','-',"*",'/'])

if op=='+':
    ans=x+y
if op=='-':
    ans=x-y
if op=='*':
    ans=x*y
if op=='/':
    ans=x/y

out=str(x)+str(op)+str(y)+"="+str(ans)
st.latex(out)
