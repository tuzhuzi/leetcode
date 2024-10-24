#include <cmath>

int countLayer(int f, int s) {
  int layer = 0;
  int ballCount = 1;
  bool layerColor = true;
  while (f >= 0 && s >= 0) {
    if (layerColor) {
      f -= ballCount;
    } else {
      s -= ballCount;
    }
    layerColor = !layerColor;
    ballCount++;
    if (f >= 0 && s >= 0) {
      layer++;
    }
    return layer;
  }
}

int maxHeightOfTriangle(int red, int blue) {
  return __max(countLayer(red, blue), countLayer(blue, red));
}