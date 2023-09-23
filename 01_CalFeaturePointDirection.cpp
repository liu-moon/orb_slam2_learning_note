#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

#define HALF_PATCH_SIZE 5

void CreatePic();
static float IC_Angle(const Mat &image, Point2f pt, const vector<int> &u_max);

int main() {
  CreatePic();
  // 读取matrix_image.png图像
  Mat image = imread("matrix_image.png", IMREAD_GRAYSCALE);
  // 计算图像特征点的方向
  vector<int> v{5, 5, 4, 3, 2};
  float angle = IC_Angle(image, Point2f(5, 5), v);
  cout << angle << endl;
  return 0;
}
void CreatePic() {
  // 创建一个 11*11 的单通道图像
  Mat matrix(11, 11, CV_8UC1);
  // 填充矩阵
  for (int i = 0; i < matrix.rows; ++i) {
    for (int j = 0; j < matrix.cols; ++j) {
      matrix.at<uchar>(i, j) = i * matrix.cols + j + 1;
      // matrix.at<uchar>(i, j) = matrix.cols + j + 1;
    }
  }

  // 全0填充
  // matrix = Mat::zeros(11, 11, CV_8UC1);

  // 矩阵行列调换
  // matrix = matrix.t();
  // 矩阵旋转90度
  // flip(matrix, matrix, 1);
  // 打印矩阵
  cout << "matrix = \n" << matrix << endl;

  // 将矩阵转换为图像
  imshow("matrix", matrix);

  // 将图像保存到文件
  const string filename = "matrix_image.png"; // 保存为PNG格式的图像文件
  imwrite(filename, matrix);

  // 检查图像是否保存成功
  // 检查是否成功保存
  if (!matrix.empty()) {
    cout << "矩阵已保存为 " << filename << endl;
  } else {
    cerr << "保存矩阵为图像时出错" << endl;
  }
}

/**
 * @brief 这个函数用于计算特征点的方向，这里以返回角度作为方向
 * 计算特征点方向是为了使得提取的特征点具有旋转不变性
 * 方法是灰度质心法：以几何中心和灰度质心的连线作为该特征点的方向
 * @param[in] image     要进行操作的某层金字塔图像
 * @param[in] pt        当前特征点的坐标
 * @param[in] u_max     图像块的每一行的坐标边界 u_max
 * @return float        返回特征点的角度，范围为 [0,360)，精度为0.3°
 */
static float IC_Angle(const Mat &image, Point2f pt, const vector<int> &u_max) {
  // 图像的矩，前者按照图像块的 y 坐标加权，后者按照图像块的 x 坐标加权
  int m_01 = 0, m_10 = 0;

  // 获得这个特征点所在的图像块的中心点坐标灰度值的指针 center
  const uchar *center = &image.at<uchar>(cvRound(pt.y), cvRound(pt.x));

  // v=0 中心线的计算需要特殊对待
  // 由于是中心行 + 若干行对，因此 PATCH_SIZE 应该是一个奇数
  for (int u = -HALF_PATCH_SIZE; u <= HALF_PATCH_SIZE; ++u)
    // 注意，这里 center 下标 u 可以是负数。
    // 中心水平线上的像素按 x 坐标（u 坐标）加权
    m_10 += u * center[u];

  // 这里的 step1 表示这个图像一行包含的字节总数
  int step = (int) image.step1();
  // cout << step << endl;
  // 注意，这里以 v=0 中心线为坐标轴，每成对的两行之间对称地进行遍历，这样处理加快了计算速度
  for (int v = 1; v <= HALF_PATCH_SIZE; ++v) {
    // Proceed over the two lines
    // 本来m_01应该一列一列地计算，但由于对称及坐标x,y正负的原因，现在可以一次计算两行
    int v_sum = 0;
    // 获取某行像素横坐标的最大范围，注意这里的图像块是圆形的！
    int d = u_max[v];
    // 在坐标范围内挨个遍历像素，实际上一次遍历 2 个像素
    // 假设每次处理的两个点坐标，中心线下方为(x,y)，中心线上方为(x,-y)
    // 对于某次待处理的两个点：m_10 = Σ x*I(x,y) = x*I(x,y) + x*I(x,-y) = x*(I(x,y)+I(x,-y))
    // 对于某次待处理的两个点：m_01 = Σ y*I(x,y) = y*I(x,y) - y*I(x,-y) = y*(I(x,y)-I(x,-y))
    for (int u = -d; u <= d; ++u) {
      // 得到需要进行加运算和减运算的像素灰度值
      // val_plus：在中心线下方 x=u 时的像素灰度值
      // val_minus：在中心线上方 x=u 时的像素灰度值
      int val_plus = center[u + v * step], val_minus = center[u - v * step];
      // 在 v 轴(y轴)上，2 行像素灰度值之差
      v_sum += (val_plus - val_minus);
      // 在 u 轴(x轴)方向上用 u 坐标加权和(u 坐标也有正负符号)，相当于同时计算两行
      m_10 += u * (val_plus + val_minus);
    }
    // 将这一行上的和按照 y 坐标加权
    m_01 += v * v_sum;
  }

  // 为了加快速度，还使用了 fastAtan2() 函数，输出为 [0,360)，精度为 0.3°
  return fastAtan2((float) m_01, (float) m_10);
}


// 输出结果
/*
  matrix =
  [  1,   2,   3,   4,   5,   6,   7,   8,   9,  10,  11;
    12,  13,  14,  15,  16,  17,  18,  19,  20,  21,  22;
    23,  24,  25,  26,  27,  28,  29,  30,  31,  32,  33;
    34,  35,  36,  37,  38,  39,  40,  41,  42,  43,  44;
    45,  46,  47,  48,  49,  50,  51,  52,  53,  54,  55;
    56,  57,  58,  59,  60,  61,  62,  63,  64,  65,  66;
    67,  68,  69,  70,  71,  72,  73,  74,  75,  76,  77;
    78,  79,  80,  81,  82,  83,  84,  85,  86,  87,  88;
    89,  90,  91,  92,  93,  94,  95,  96,  97,  98,  99;
   100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110;
   111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 121]
  矩阵已保存为 matrix_image.png
  83.6553
 */