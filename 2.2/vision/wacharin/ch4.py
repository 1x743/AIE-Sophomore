import numpy as np
import cv2
from matplotlib import pyplot as plt

print("My ID is:6610110096")
img = cv2.imread("Image for Testing/green.jpg")
color = ('b','g','r')

imSize = img.shape
width = imSize[0]
height = imSize[1]
imGray = np.uint8(np.zeros((width, height)))

for i in range(width):
    for j in range(height):
        blue, green, red = img[i, j]
        imGray[i, j] = np.mean([red, green, blue])

cv2.imshow('Gray', imGray)
cv2.waitKey(0)
cv2.destroyAllWindows()
