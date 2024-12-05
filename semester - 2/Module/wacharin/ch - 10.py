import cv2
import numpy as np
from matplotlib import pyplot as plt

# Load the A letter image in grayscale
print("My ID is: 6610110096")
image = cv2.imread("Image for Testing/letter_A.jpg", cv2.IMREAD_GRAYSCALE)

# Convert to binary using thresholding
_, binary_image = cv2.threshold(image, 155, 255, cv2.THRESH_BINARY_INV)

# Define a kernel
kernel = np.ones((10, 10), np.uint8)

# Apply Dilation
dilated_image = cv2.dilate(binary_image, kernel, iterations=3)

# Apply Erosion
eroded_image = cv2.erode(binary_image, kernel, iterations=3)

# Apply Opening (Erosion followed by Dilation)
opening_image = cv2.morphologyEx(binary_image, cv2.MORPH_OPEN, kernel)

# Apply Closing (Dilation followed by Erosion)
closing_image = cv2.morphologyEx(binary_image, cv2.MORPH_CLOSE, kernel)

# Display all results
titles = [
    'Original Image', 'Binary Image', 
    'Dilated Image', 'Eroded Image',
    'Opening Image', 'Closing Image'
]
images = [image, binary_image, dilated_image, eroded_image, opening_image, closing_image]

plt.figure(figsize=(15, 8))
for i in range(6):
    plt.subplot(2, 3, i + 1)
    plt.imshow(images[i], 'gray')
    plt.title(titles[i])
    plt.xticks([])
    plt.yticks([])

plt.tight_layout()
plt.show()
