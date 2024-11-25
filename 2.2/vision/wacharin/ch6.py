import cv2

print("My ID is: 6610110096")
img = cv2.imread("Image for Testing/imageThresholding.jpg")
# Apply a binary threshold to the image
th, res = cv2.threshold(img,93,255, cv2.THRESH_BINARY)

cv2.imshow('Res', res)
cv2.waitKey(0)
cv2.destroyAllWindows()