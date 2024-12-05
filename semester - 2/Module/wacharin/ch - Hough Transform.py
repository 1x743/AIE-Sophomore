import cv2
import numpy as np

# Read the image
planets = cv2.imread('Image for Testing/planets.jpg')

# Resize the image
resized_planets = cv2.resize(planets, (570, 470))  # Resize to 570x470 pixels

# Convert to grayscale
gray_img = cv2.cvtColor(resized_planets, cv2.COLOR_BGR2GRAY)

# Apply median blur
img = cv2.medianBlur(gray_img, 5)

# Convert back to BGR
cimg = cv2.cvtColor(img, cv2.COLOR_GRAY2BGR)

# Detect circles using Hough Transform
circles = cv2.HoughCircles(img, cv2.HOUGH_GRADIENT, 1, 50,
                           param1=200, param2=20, minRadius=30, maxRadius=95)
if circles is not None:
    circles = np.uint16(np.around(circles))

    # Draw the detected circles
    for i in circles[0, :]:
        # Draw the outer circle
        cv2.circle(resized_planets, (i[0], i[1]), i[2], (0, 255, 0), 2)
        # Draw the center of the circle
        cv2.circle(resized_planets, (i[0], i[1]), 2, (0, 0, 255), 3)

# Save and display the result
cv2.imwrite("planets_circles.jpg", resized_planets)
cv2.imshow("HoughCircles", resized_planets)
cv2.waitKey()
cv2.destroyAllWindows()