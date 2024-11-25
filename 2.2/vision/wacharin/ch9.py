import cv2

image = cv2.imread("Image for Testing/for average background subtraction/ajboy.jpg")

averaged_image = cv2.blur(image, (9, 9))

print("My ID is: 6610110096")
cv2.imshow('Blurred Image', averaged_image)
cv2.waitKey(0)
cv2.destroyAllWindows()