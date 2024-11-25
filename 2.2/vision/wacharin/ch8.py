import cv2
import numpy as np

# Load the background images
background_images = []
for i in range(10):
    filename = f'Image for Testing/for average background subtraction/{i}.jpg'
    img = cv2.imread(filename)
    if img is not None:
        background_images.append(img)

# Compute the average background image
average_background = np.mean(background_images, axis=0).astype(np.uint8)

# Load the object image
object_image = cv2.imread('Image for Testing/for average background subtraction/ajboy.jpg')  # Adjust the path as needed

# Perform background subtraction
foreground_mask = cv2.absdiff(object_image, average_background)

# Convert the mask to grayscale
gray_foreground_mask = cv2.cvtColor(foreground_mask, cv2.COLOR_BGR2GRAY)

# Threshold the grayscale mask to get a binary mask
_, binary_mask = cv2.threshold(gray_foreground_mask, 50, 255, cv2.THRESH_BINARY)

# Display the results
cv2.imshow('Average Background', average_background)
cv2.imshow('Foreground Mask', gray_foreground_mask)
cv2.waitKey(0)
cv2.destroyAllWindows()