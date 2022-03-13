#include <QApplication>
#include <QImage>
#include <QObject>
#include <QLabel>
#include <QTimer>
#include <iostream>
#include <math.h>
#include <stdint.h>

void generate_rfrakt(QImage& image, double ofx, double ofy, double z)
{
  for(int y = 1; y < image.height(); ++y)
  {
    for(int x = 0; x < image.width(); ++x)
    {
      double xi = ((static_cast<double>(x) / image.width()) - 0.5) * z + ofx;
      double yi = ((static_cast<double>(y) / image.height()) - 0.5) * z + ofy;

      // using sin() here gives more pleasing results, but isn't
      // necessary for the effect
      double px = false ? xi * yi : sin(xi * yi);

      uint8_t c = static_cast<int>(((px + 1.0)/2.0) * 255);
      image.setPixel(x, y, qRgb(c, c, c));
    }
  }
}

int main(int argc, char** argv)
{
  QApplication app(argc, argv);

  double ofx = 0;
  double ofy = 0;
  double z = 2;

  QImage image(512, 512, QImage::Format_RGB32);
  generate_rfrakt(image, ofx, ofy, z);

  QLabel label;
  label.setPixmap(QPixmap::fromImage(image));
  label.show();

  QTimer timer;
  QObject::connect(&timer, &QTimer::timeout,
                   [&]{
                     z *= 1.01;
                     //ofx += 1.01;
                     //ofy += 1.01;
                     generate_rfrakt(image, ofx, ofy, z);
                     label.setPixmap(QPixmap::fromImage(image));
                   });
  timer.start(1000 / 24.0);

  return app.exec();
}

/* EOF */
