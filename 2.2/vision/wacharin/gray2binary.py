import numpy as np
import cv2
from matplotlib import pyplot as plt

print("My ID is:4010323")
img = cv2.imread("Image for Testing/green.jpg")
color = ('b','g','r')

imSize = img.shape
width = imSize[0]
high = imSize[1]
imGray = np.uint8(np.zeros((width, high)))

# Convert to grayscale
for i in range(width):
    for j in range(high):
        imGray[i, j] = np.uint8((float(img[i, j, 0]) + float(img[i, j, 1]) + float(img[i, j, 2])) / 3.0)

print(imGray)

# Convert to binary
imBin = np.uint8(np.zeros((width, high)))
for i in range(width):
    for j in range(high):
        if imGray[i, j] > 200:
            imBin[i, j] = 255
        else:
            imBin[i, j] = 0

cv2.imshow('Gray', imGray)
cv2.imshow('Binary', imBin)
cv2.waitKey(0)
cv2.destroyAllWindows()