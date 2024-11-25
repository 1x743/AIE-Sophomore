# import cv2
# import numpy as np

# # Load the background and object images in grayscale
# background = cv2.imread('Image for Testing/background.jpg', cv2.IMREAD_GRAYSCALE)
# object_img = cv2.imread('Image for Testing/object.jpg', cv2.IMREAD_GRAYSCALE)

# # Resize the object image to match the background dimensions (if needed)
# object_img = cv2.resize(object_img, (background.shape[1], background.shape[0]))

# # Perform background subtraction (preserving direction of subtraction)
# foreground = cv2.subtract(background, object_img)  # This avoids absolute difference

# # Display the result
# cv2.imshow('Background Subtracted Image', foreground)
# cv2.waitKey(0)
# cv2.destroyAllWindows()


import cv2
print("My ID is:6610110096")
# Read the background and object images
img_bg = cv2.imread('Image for Testing/background.jpg')
img = cv2.imread('Image for Testing/object.jpg')


# Set up and feed background subtractor (cf. tutorial linked in question)
backSub = cv2.createBackgroundSubtractorMOG2() 
_ = backSub.apply(img_bg)
mask = backSub.apply(img)

# Morphological opening and closing to improve mask
mask_morph = cv2.morphologyEx(mask, cv2.MORPH_OPEN, cv2.getStructuringElement(cv2.MORPH_ELLIPSE, (21, 21)))
mask_morph = cv2.morphologyEx(mask_morph, cv2.MORPH_CLOSE, cv2.getStructuringElement(cv2.MORPH_ELLIPSE, (21, 21)))

# Generate output
output = cv2.bitwise_and(img, img, mask=mask_morph)

cv2.imshow('output', output)
cv2.waitKey(0)
cv2.destroyAllWindows()