import pandas as pd
import numpy as np
from sklearn.decomposition import PCA

# โหลดข้อมูล X และ Y
x_data = pd.read_csv('data/dataX.csv', header=None)
y_data = pd.read_csv('data/dataY.csv', header=None)

# รวมข้อมูล
data = pd.DataFrame({'X': x_data[0], 'Y': y_data[0]})

# คำนวณ Covariance Matrix
cov_matrix = np.cov(data.T)

# สร้าง PCA
pca = PCA(n_components=2)
pca.fit(data)

# ค่าความแปรปรวน (Variance)
explained_variance = pca.explained_variance_

# ค่า Eigenvalues และ Eigenvectors
eigenvalues = explained_variance
eigenvectors = pca.components_

# แสดงผล
print("Covariance \n", cov_matrix)
print("\nEigenvalues \n", eigenvalues)
print("\nEigenvectors \n", eigenvectors)