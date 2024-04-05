import streamlit as st
import pandas as pd
import numpy as np


# set the app's title
st.title("Text Elements")
 
# header
st.header("Header in Streamlit")
 
# subheader
st.subheader("Subheader in Streamlit")
 
# markdown
# display text in bold formatting
st.markdown("**bold**")
# display text in italic formatting
st.markdown("_italics_")
print()
if st.button('Click here', help="Click to see the text change"):
    st.write('Hi there!')
else:
    st.write('Goodbye')

# check box
checked = st.checkbox('Click here')
if checked:
    st.write('Good job!')    

# radio button
lang = st.radio(
    "What's your favorite programming language?",
    ('C++', 'Python'))
 
if lang == 'C++':
    st.write('You selected C++.')
else:
    st.write('You selected Python.')
 
# slider
score = st.slider('Please specify your test score', 
                   min_value=0, max_value=100, value=10)
st.write("My test score is ", score)

dataset=pd.read_csv("datasets/titanic.csv")
df=pd.DataFrame(dataset)

