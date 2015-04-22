#include <QApplication>
#include <QImage>
#include <QObject>
#include <QLabel>
#include <QTimer>
#include <iostream>
#include <math.h>
#include <stdint.h>

void generate_rfrakt(QImage& image, float z)
{
  for(int y = 1; y < image.height(); ++y)
  {
    for(int x = 0; x < image.width(); ++x)
    {
      double px = sin(x * y * z);
      uint8_t c = static_cast<int>(((px + 1.0)/2.0) * 255);
      image.setPixel(x, y, qRgb(c, c, c));
    }
  }
}

int main(int argc, char** argv)
{
  QApplication app(argc, argv);

  double z = 1000.01;

  QImage image(512, 512, QImage::Format_RGB32);
  generate_rfrakt(image, z);

  QLabel label;
  label.setPixmap(QPixmap::fromImage(image));
  label.show();

  QTimer timer;
  QObject::connect(&timer, &QTimer::timeout,
                   [&]{
                     z += 0.001;
                     generate_rfrakt(image, z);
                     label.setPixmap(QPixmap::fromImage(image));
                   });
  timer.start(1000 / 24.0);

  return app.exec();
}

/* EOF */
