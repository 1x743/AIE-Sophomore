import pandas as pd
import numpy as np
from sklearn.decomposition import PCA
import matplotlib.pyplot as plt

# โหลดข้อมูล X และ Y
try:
    x_data = pd.read_csv('data/dataX.csv', header=None)
    y_data = pd.read_csv('data/dataY.csv', header=None)
except FileNotFoundError:
    print("Error: ไม่พบไฟล์ dataX.csv หรือ dataY.csv")
    exit()

# รวมข้อมูล X และ Y
data = pd.DataFrame({'X': x_data[0], 'Y': y_data[0]})

# ตรวจสอบข้อมูล
print("ข้อมูลที่รวมกัน:")
print(data.head())

# สร้าง PCA
pca = PCA(n_components=2)
principal_components = pca.fit_transform(data)

# Flip the second principal component to flip the plot vertically
principal_components[:, 1] = -principal_components[:, 1]

# สร้าง DataFrame สำหรับผลลัพธ์ PCA
principal_dataframe = pd.DataFrame(data=principal_components, columns=['PC1', 'PC2'])

# แสดงสัดส่วนความแปรปรวน
explained_variance_ratio = pca.explained_variance_ratio_
print("Explained Variance Ratio:", explained_variance_ratio)

# พล็อตข้อมูล PCA
plt.figure(figsize=(8, 6))
plt.scatter(principal_dataframe['PC1'], principal_dataframe['PC2'], alpha=0.7, color='green', marker='.')
plt.title('PCA')
plt.grid(True)
plt.show()