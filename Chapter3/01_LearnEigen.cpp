/*
 * 目标：已知旋转向量定义为沿着 z 轴旋转 45°
 * 下面按照该定义用 Eigen 实现旋转向量、旋转矩阵和四元数及其之间的相互转换
 * */

#include <iostream>
#include <cmath>
#include <Eigen/Core>
#include <Eigen/Geometry>
using namespace std;

int main() {
  // 旋转向量（轴角）：沿着 z 轴旋转 45°
  Eigen::AngleAxisd rotation_vector(M_PI / 4, Eigen::Vector3d(0, 0, 1));
  cout << "旋转向量的旋转轴 = \n" << rotation_vector.axis() << "\n 旋转向量角度 = " << rotation_vector.angle() << endl;

  // 旋转矩阵：沿着 z 轴旋转 45°
  Eigen::Matrix3d rotation_matrix = Eigen::Matrix3d::Identity();
  rotation_matrix << 0.707, -0.707, 0,
      0.707, 0.707, 0,
      0, 0, 1;
  cout << "旋转矩阵 = \n" << rotation_matrix << endl;

  // 四元数：沿着 z 轴旋转 45°
  Eigen::Quaterniond quat = Eigen::Quaterniond(0, 0, 0.383, 0.924);
  cout << "四元数的输出方法 1：四元数 = \n" << quat.coeffs() << endl;
  // 请注意coeffs的顺序是(x,y,z,w),w为实部，前三者为虚部
  cout << "四元数的输出方法 2：四元数 = \n" << quat.x() << " " << quat.y() << " " << quat.z() << " " << quat.w() << endl;

  // 1. 将旋转矩阵转化为其他形式
  rotation_vector.fromRotationMatrix(rotation_matrix);
  cout << "旋转矩阵转换为旋转向量方法 1：旋转轴 = \n" << rotation_vector.axis() << "\n 旋转角度 = "
       << rotation_vector.angle() << endl;
  // 注意：fromRotationMatrix 参数只适用于将旋转矩阵转换为旋转向量
  // 不适用于将旋转矩阵转换为四元数，因为四元数的旋转轴不唯一

  rotation_vector = rotation_matrix;
  cout << "旋转矩阵转换为旋转向量方法 2：旋转轴 = \n" << rotation_vector.axis() << "\n 旋转角度 = "
       << rotation_vector.angle() << endl;

  rotation_vector = Eigen::AngleAxisd(rotation_matrix);
  cout << "旋转矩阵转换为旋转向量方法 3：旋转轴 = \n" << rotation_vector.axis() << "\n 旋转角度 = "
       << rotation_vector.angle() << endl;

  quat = Eigen::Quaterniond(rotation_matrix);
  cout << "旋转矩阵转换为四元数方法 1：Q =\n" << quat.coeffs() << endl;

  quat = rotation_matrix;
  cout << "旋转矩阵转换为四元数方法 2：Q =\n" << quat.coeffs() << endl;

  // 2. 将旋转向量转化为其他形式
  cout << "旋转向量转换为旋转矩阵方法 1：旋转矩阵 R=\n" << rotation_vector.matrix() << endl;
  cout << "旋转向量转换为旋转矩阵方法 2：旋转矩阵 R=\n" << rotation_vector.toRotationMatrix() << endl;
  quat = Eigen::Quaterniond(rotation_vector);
  // 请注意 coeffs 的顺序是 (x,y,z,w),w 为实部，前三者为虚部 （这里书里写错了）
  cout << "旋转向量转换为四元数： Q=\n" << quat.coeffs() << endl;

  // 3. 将四元数转换为其他形式
  rotation_vector = quat;
  cout << "四元数转换为旋转向量：旋转轴 = \n" << rotation_vector.axis() << "\n 旋转角度 = "
       << rotation_vector.angle() << endl;

  rotation_matrix = quat.matrix();
  cout << "四元数转换为旋转矩阵方法 1：旋转矩阵 =\n" << rotation_matrix << endl;

  rotation_matrix = quat.toRotationMatrix();
  cout << "四元数转换为旋转矩阵方法 2：旋转矩阵 =\n" << rotation_matrix << endl;

  return 0;
}