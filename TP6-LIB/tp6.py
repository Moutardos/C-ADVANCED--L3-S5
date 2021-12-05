#! /usr/bin/python3

from ctypes import *
import timeit
from PIL import Image

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

image_libc = cdll.LoadLibrary("./basic_image_process.so")
img_c = convert_bitmap_to_c(img)
