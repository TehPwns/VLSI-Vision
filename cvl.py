import numpy as np
import copy
import cv2
import picamera
import math
import io
import numpy as np

def getClusterImage(I):
    #Put in Mx3 column and convert to np.float32
    Z = I.reshape((-1,3))
    Z = np.float32(Z)

    # define criteria, number of clusters(2) and apply kmeans()
    criteria = (cv2.TERM_CRITERIA_EPS + cv2.TERM_CRITERIA_MAX_ITER, 10, 10.0)
    ret,label,center=cv2.kmeans(Z,2,criteria,10,cv2.KMEANS_RANDOM_CENTERS)

    # Now convert back into uint8, and make original image
    #label = ~label.astype(bool)
    res2  = np.uint8(label.reshape(I.shape[0], I.shape[1])) * 255
    return res2

def getCorners(I):
	corns = cv2.goodFeaturesToTrack(I, 4, 0.50, 50, None, None, 20)
	return corns
	
def distance(p0, p1):
	return math.sqrt((p1[0] - p0[0])**2 + (p1[1] - p0[1])**2)

def classifyLego(corns):
	print corns
	if(len(corns) == 4):
		#We want distances between all pairs of corns
		lengths = []
		for i in range(0, len(corns)):
			for j in range(i+1, len(corns)):
				lengths.append(distance(corns[i][0], corns[j][0]))

		#Sort and remove the largest two distances, these 
		#are the distances between diagonal corners
		lengths.sort()
		lengths.pop()
		lengths.pop()
		print lengths
		
		#Ratio of longest and shortest lengths classifies our lego
		ratio = lengths[len(lengths)-1] / lengths[0]
		return ratio;
	return 0;

cap = cv2.VideoCapture(0)
camera = picamera.PiCamera()

def getImage(cam):
	stream = io.BytesIO()
	cam.capture(stream, format='jpeg')
	data = np.fromstring(stream.getvalue(), dtype=np.uint8)
	return cv2.imdecode(data,1)

if __name__ == '__main__':
	while True:
		im = getImage(camera)
		im = cv2.medianBlur(im,5)
		imk = getClusterImage(im)
		corns = getCorners(imk)
		print(classifyLego(corns))
		
		for corn in corns:
			cv2.circle(im, (corn[0][0],corn[0][1]), 20, (255,0,0))
			
		cv2.imshow('image', im)
		cv2.imshow('image2', imk)
		cv2.waitKey(100)
