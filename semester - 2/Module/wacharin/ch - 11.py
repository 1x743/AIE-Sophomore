import cv2
import numpy as np

# Load an image
print("My ID is: 6610110096")
image = cv2.imread("Image for Testing/for average background subtraction/ajboy.jpg")

# Get image dimensions
rows, cols, _ = image.shape

# Define the transformation matrices
# 1. Scaling (zoom in/out)
sx, sy = 1.5, 1.5  # Scale factors
scaling_matrix = np.array([[sx, 0, 0],
                           [0, sy, 0]], dtype=np.float32)

scaled_image = cv2.warpAffine(image, scaling_matrix, (int(cols * sx), int(rows * sy)))

# 2. Rotation (e.g., 45 degrees)
angle = 45  # Degrees
rotation_center = (cols // 2, rows // 2)
rotation_matrix = cv2.getRotationMatrix2D(rotation_center, angle, scale=1)

rotated_image = cv2.warpAffine(image, rotation_matrix, (cols, rows))

# 3. Translation (e.g., tx=100, ty=50)
tx, ty = 100, 50  # Translation in x and y directions
translation_matrix = np.array([[1, 0, tx],
                                [0, 1, ty]], dtype=np.float32)

translated_image = cv2.warpAffine(image, translation_matrix, (cols + tx, rows + ty))

# Display and save results
cv2.imshow("Original Image", image)
cv2.imshow("Scaled Image", scaled_image)
cv2.imshow("Rotated Image", rotated_image)
cv2.imshow("Translated Image", translated_image)

cv2.waitKey(0)
cv2.destroyAllWindows()
