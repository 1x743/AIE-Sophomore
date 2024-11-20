import numpy as np
import cv2
from matplotlib import pyplot as plt
print("My ID is: 6610110096")
img = cv2.imread("Image for Testing/banana Green.jpg")
b_channel, g_channel, r_channel = cv2.split(img)

# แสดงผลภาพแต่ละ Channel ในรูปแบบ Grayscale
cv2.imshow("Blue Channel", b_channel)  # Channel สีฟ้า
cv2.imshow("Green Channel", g_channel)  # Channel สีเขียว
cv2.imshow("Red Channel", r_channel)