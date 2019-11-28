
#if defined(HAVE_LOG) && defined(HAVE_EXP)
#include<math.h>
#endif

float mysqrt(float x)
{
    float xhalf = 0.5f * x;

    int i = *(int *)&x;

    i = 0x5f3759df - (i >> 1); // 计算第一个近似根

    x = *(float *)&i;

    x = x * (1.5f - xhalf * x * x); // 牛顿迭代法

    return x;
}

float mycampute(float x)
{
#if defined(HAVE_LOG) && defined(HAVE_EXP)
  double result = exp(log(x) * 0.5);
  std::cout << "Computing sqrt of " << x << " to be " << result
            << " using log and exp" << std::endl;
#else
  double result = x;
#endif

  return result;
}



