import cv2

# Step 1: Read the image
image = cv2.imread("Image for Testing/for average background subtraction/ajboy.jpg")

# Step 2: Apply Gaussian Blur (Low Pass Filter)
averaged_image = cv2.blur(image, (9, 9))

# Optionally, display the image
cv2.imshow('Blurred Image', averaged_image)
cv2.waitKey(0)
cv2.destroyAllWindows()