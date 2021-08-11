#!/usr/bin/env python
from PIL import ImageFont
from PIL import Image
from PIL import ImageDraw
import pyqrcode
import png


def qrcode(o, cnt):
    x = str(o)
    q = pyqrcode.create(x, version=2)
    lx = len(x)
    cx = lx - 2
    #cx = 8
    subx = x[cx:lx]
    #subx = x
    q.png(str(cnt) + '-' + x + '.png', scale=2, module_color=[0,0,0,128], quiet_zone=6)
    img=Image.open(str(cnt) + '-' + x + '.png')
    W, H = img.size
    draw=ImageDraw.Draw(img)
    
    #draw.line((1,1, W-1,1), fill="black", width=1)
    #draw.line((W-1,1, W-1,H-1), fill="black", width=1)
    #draw.line((W-1,H-1, 1,H-1), fill="black", width=1)
    #draw.line((1,H-1, 1,1), fill="black", width=1)
    
    
    font = ImageFont.truetype("tahomabd.ttf", 12)
    w, h = draw.textsize(subx, font=font)
    
    draw.text(((W-w)/2,H-(h)),text=subx,font=font)
    img.save(str(cnt) + '-' + x + '.png')
    print(str(cnt) + '. GENETATING QRCODE OF ' + x)

with open('prod.txt', 'r') as f:
    wos = f.read().splitlines()

count=1
for i in wos:
    qrcode(i, count)
    count+=1

print(str(count-1) + ' QRCODE IS SUCCESSFULLY GENERATED')
