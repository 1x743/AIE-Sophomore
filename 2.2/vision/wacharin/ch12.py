import numpy as np
import cv2
import math

print("My ID is: 6610110096")
# อ่านภาพ
image = cv2.imread("Image for Testing/for average background subtraction/ajboy.jpg")

# Get the dimensions of the image
(h, w) = image.shape[:2]

# Calculate the center of the image
center = (w // 2, h // 2)

# Define the rotation angle
degree = 45
rad = math.radians(degree)
cost = math.cos(rad)
sint = math.sin(rad)

# Define the rotation matrix
tmatrix = np.float32([[cost, -sint, (1 - cost) * center[0] + sint * center[1]], 
                      [sint, cost, (1 - cost) * center[1] - sint * center[0]]])

# Apply the rotation matrix to the image
rotated = cv2.warpAffine(image, tmatrix, (w, h))

# แสดงผล
cv2.imshow('Rotated Image', rotated)
cv2.waitKey(0)
cv2.destroyAllWindows()