#!/usr/bin/env python
# coding: utf-8

# In[1]:

#
import pandas as pd
import numpy as np
from sklearn.model_selection import train_test_split
from sklearn.linear_model import LinearRegression
from sklearn.preprocessing import StandardScaler
from sklearn.preprocessing import LabelEncoder
from sklearn import metrics
from sklearn.metrics import mean_squared_error, r2_score
import matplotlib.pyplot as plt
import seaborn as sns
from sklearn.preprocessing import MinMaxScaler
from scipy import stats
import pickle


# In[2]:


df = pd.read_csv('diamonds.csv')


# In[3]:


df


# In[4]:


df.dropna(inplace = True)


# In[5]:


encoder = LabelEncoder()
l = [
    'cut',
    'color',
    'clarity'
]

for i in l:
    df[i] = encoder.fit_transform(df[i])


# In[6]:


df


# In[7]:


l = [
    'carat',
    'depth',
    'table',
    'price',
    'x', 'y', 'z'
]

# for i in l:
#     z_scores = stats.zscore(df[i])
#     threshold = 3
    
#     df2 = df[(z_scores < threshold) & (z_scores > -threshold)]

for i in l:
    Q1 = df[i].quantile(0.25)
    Q3 = df[i].quantile(0.75)
    IQR = Q3 - Q1
    
    df1 = df[(df[i] >= Q1-1.5*IQR) & (df[i] <= Q3 + 1.5*IQR)]


# In[8]:


df


# In[9]:


x = df.drop('price', axis = 1)
y = df['price']

x_train, x_test, y_train, y_test = train_test_split(x, y, random_state = 42, shuffle = True, test_size = 0.2)


# In[10]:


model = LinearRegression()
model.fit(x_train, y_train)


# In[11]:


train_score = model.score(x_train, y_train)
test_score = model.score(x_test, y_test)
print("Training set score:", train_score * 100)
print("Testing set score:", test_score * 100)

