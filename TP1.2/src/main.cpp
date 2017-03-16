
#include "jpg.h"
#include "mnist.h"

float dist(float* v1 , float* v2)
{
  	float distance =0;
	for(int i=0; i<784 ; i++){
		
		distance = (v1[i]-v2[i]*v1[i]-v2[i]);
	}
	return distance ;
	//return 
}



int main()
{
  
	
	float* labels = read_labels("train-labels.idx1-ubyte");
    float** images = read_mnist("train-images.idx3-ubyte");
	float** teste_images = read_mnist("t10k-images.idx3-ubyte");
    float mind =-1; 
	int inference,NN;
	int j , i;
	for(i=0; i<10000; i++) {
       	for(j=0; j<60000; j++) {
		 float d= dist(teste_images[i],images[j]);
		 if(d<mind || mind == -1){mind=d; NN=j;}
		}
}	 
inference = labels[NN];

        save_jpg(teste_images[i], 28, 28, "%u/%04u.jpg", inference, i);
    
    return 0;
}
