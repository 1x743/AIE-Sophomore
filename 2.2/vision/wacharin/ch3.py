import numpy as np
import cv2
from matplotlib import pyplot as plt
print("My ID is: 6610110096")
img = cv2.imread("Image for Testing/green.jpg")
color = ('b','g','r')
cv2.imshow('banana',img)
print('Image size:',img.shape)
blue, green, red = img[200, 85]
print('Red color is:', red)
print('Green color is:', green)
print('Blue color is:', blue)
cv2.waitKey(0)
cv2.destroyAllWindows()