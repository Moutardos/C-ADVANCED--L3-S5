#! /usr/bin/python3

from ctypes import *
import timeit
from PIL import Image

img = "img/panda.png"
img2 = "img/Lenna.png"
img3 = "img/chat.png"

Pix_c = c_ubyte * 4
Img_c_line = Pix_c * 512
Img_c = Img_c_line * 512


def convert_bitmap_to_c(img):
    img_c = Img_c()
    bitmap = img.load()
    for i in range(512):
        for j in range(512):
            for k in range(4):
                img_c[i][j][k] = bitmap[i, j][k]
    return img_c


def rebuild_image(img_c, img):
    bitmap = img.load()
    for i in range(512):
        for j in range(512):
            bitmap[i, j] = (img_c[i][j][0], img_c[i][j][1], img_c[i][j][2], img_c[i][j][3])

image_libc = cdll.LoadLibrary("lib/lib_img.so")
 
class Picture :

    def __init__(self, file=None, img=None, img_c=None):
        if img == None :
            self.img = Image.open(file)
            self.img = self.img.convert('RGBA')
        else:
            self.img = img
        if img_c == None :
            self.img_c = convert_bitmap_to_c(self.img)
        else:
            self.img_c = img_c

    # Param function are functions from the shared library lib_img.so, check src/image_lib.c 
    def apply(self, function):
        function(self.img_c)
        self.rebuild_image()

    def average(self, img1, img2):
        image_libc.moyenne(self.img_c, img1.img_c, img2.img_c)
        self.rebuild_image()

    def remplacer_zone(self, x, y, couleur):
        image_libc.remplacer_zone(self.img_c, x, y, couleur)
        self.rebuild_image()

    def rebuild_image(self):
        rebuild_image(self.img_c, self.img)

    def show(self):
        self.img.show_close()

    def close(self):
        self.img.close()

    def show_close(self):
        self.img.show()
        self.img.close()


pic1 = Picture(img)
pic2 = Picture(img)
pic3 = Picture(img)
pic4 = Picture(img)
pic5 = Picture(img)
pic6 = Picture(img)
pic7 = Picture(img)
pic8 = Picture(img)
pic9 = Picture(img2)
pic10 = Picture(img)
pic11 = Picture(img)
pic12 = Picture(img)
pic13 = Picture(img)
pic14 = Picture(img)
pic15 = Picture(img)
pic16 = Picture(img)

pic1.apply(image_libc.niveaux_de_gris_moy)
pic2.apply(image_libc.niveaux_de_gris_luminance)
pic3.apply(image_libc.niveaux_de_gris_clarte)
pic4.apply(image_libc.tres_vert)
pic5.apply(image_libc.plus_rouge)
pic6.apply(image_libc.degrade_rouge_bleu)
pic7.apply(image_libc.lumiere_milieu)
pic8.average(pic9, pic10)
#pic9.remplacer_zone(100,100,[0,0,255,255])

pic1.show_close()
pic2.show_close()
pic3.show_close()
pic4.show_close()
pic5.show_close()
pic6.show_close()
pic7.show_close()
pic8.show_close()
pic9.show_close()