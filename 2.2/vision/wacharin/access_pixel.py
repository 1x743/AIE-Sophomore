import numpy as np
import cv2
from matplotlib import pyplot as plt
img = cv2.imread("Image for Testing/green.jpg")
color = ('b','g','r')
cv2.imshow('banana',img)
print('Image size:',img.shape)
print('Color in pixel 200,85:',img[200,85])
