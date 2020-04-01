import numpy as np

numberOfDays = 20
model = np.array([[.5, .5, .25], [.25, 0., .25], [.25,.5,.5]])

# Reshaping to avoid zero order vectors.
today = np.array([1,0,0]).reshape(3,1)

for i in range(numberOfDays):
    print("Day {0}:\nToday's weather:\n{1}\n".format(i,today))
    tomorrow = model.dot(today) 
    today = tomorrow

# print(today.shape)