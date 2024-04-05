from sklearn.preprocessing import MinMaxScaler
import numpy as np
import pandas as pd
import matplotlib.pyplot as plt
age=np.array([1,9,23,84,32,94,12,43,84,21,46,97,21,48,15])
df=pd.DataFrame(age,columns=["Age"])
scaler=MinMaxScaler()
b=scaler.fit_transform(df)
plt.plot(b)