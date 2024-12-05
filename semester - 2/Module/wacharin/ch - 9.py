# import cv2


# averaged_image = cv2.blur(image, (9, 9))

# print("My ID is: 6610110096")
# cv2.imshow('Blurred Image', averaged_image)
# cv2.waitKey(0)
# cv2.destroyAllWindows()

import cv2
import numpy as np

print("My ID is: 6610110096")
# อ่านภาพ
image = cv2.imread("Image for Testing/green.jpg", cv2.IMREAD_GRAYSCALE)

# กำหนด Prewitt Kernel สำหรับตรวจจับขอบในแนวนอนและแนวตั้ง
kernel_x = np.array([[1, 0, -1], [1, 0, -1], [1, 0, -1]])
kernel_y = np.array([[1, 1, 1], [0, 0, 0], [-1, -1, -1]])

# ใช้ Convolution กับ kernel
prewitt_x = cv2.filter2D(image, -1, kernel_x)
prewitt_y = cv2.filter2D(image, -1, kernel_y)

# Convert to float32
prewitt_x = prewitt_x.astype(np.float32)
prewitt_y = prewitt_y.astype(np.float32)

# คำนวณ magnitude ของ gradient
magnitude = cv2.magnitude(prewitt_x, prewitt_y)

# คำนวณ angle ของ gradient
angle = cv2.phase(prewitt_x, prewitt_y, angleInDegrees=True)

# แปลง magnitude กลับเป็น 8-bit image
magnitude = cv2.convertScaleAbs(magnitude)

# แสดงผล
cv2.imshow('Prewitt Edge Detection - Magnitude', magnitude)
cv2.imshow('Prewitt Edge Detection - Angle', angle)
cv2.waitKey(0)
cv2.destroyAllWindows()