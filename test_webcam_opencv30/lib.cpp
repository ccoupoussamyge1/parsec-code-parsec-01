#include "lib.h"

////////////////RED TO YELLOW///////////////////////////////////////////////////////////////
Mat seuillage(Mat frame){
using namespace cv;
float nr = 0;

	while(1){
			

	    // If the frame is empty, break immediately
	   		// if (frame.empty())
	    	 	// break;

		for (int i=0;i<frame.rows;i++)
		{
           	 for (int j=0;j<frame.cols;j++)
		{
		        uchar r,v,b;
		        b=frame.at<Vec3b>(i,j)[0];
		        v=frame.at<Vec3b>(i,j)[1];
		        r=frame.at<Vec3b>(i,j)[2];
		        nr=r/sqrt((r*r)+(b*b)+(v*v));
		if(nr>0.7)
		    {
		        frame.at<Vec3b>(i,j)[0]=0;
		        frame.at<Vec3b>(i,j)[1]=r;
		        frame.at<Vec3b>(i,j)[2]=r;
		    }
	     else{
		    frame.at<Vec3b>(i,j)[0]=b;
		    frame.at<Vec3b>(i,j)[1]=v;
		    frame.at<Vec3b>(i,j)[2]=r;
		}
		return (frame);
	}
	}
}
}
///////////////////////////////////////////////////////////////////////////////////////

Mat det_contour(Mat frame)
{
	Mat frame_out,frame_grayt;

	cvtColor(frame,frame_grayt,CV_BGR2GRAY);
	frame_out.create(frame.rows,frame.cols,CV_8UC1);

	    // If the frame is empty, break immediately
	    

		for (int i=1;i<frame.rows;i++)
		{
			for (int j=1;j<frame.cols;j++)
			{
				short temp;
				temp = (-1)*(short)frame_grayt.at<uchar>(i,j-1)+(-1)*(short)frame_grayt.at<uchar>(i-1,j)+(-1)*(char)frame_grayt.at<uchar>(i,j+1)+(-1)*(short)frame_grayt.at<uchar>(i+1,j)+4*(short)frame_grayt.at<uchar>(i,j);

				frame_out.at<uchar>(i,j)=(uchar)abs(temp);

		if(frame_out.at<uchar>(i,j)>23) frame_out.at<uchar>(i,j)=255;
		else { frame_out.at<uchar>(i,j)=0;
			}

			}
		}
	return (frame_out);
}
