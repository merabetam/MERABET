
#include "jpg.h"
#include "mnist.h"
#include <limits.h>
#include <time.h>
float dist(float* v1, float* v2){
	int i;
	float d=0;
	for (int i=0; i<784; i++){
		d+= (v1[i]-v2[i])*(v1[i]-v2[i]);		
	}
	return d;
}

float linear_classifier(float* w, float* x){
	float d=0;
	for (int i=0; i<784; i++){
		d+= w[i]*x[i];
	}if (d>=0) {return 1;
	}return -1;
}


int main(){
	srand(time(NULL));
 	float gamma =0.01;
	float** images = read_mnist("train-images.idx3-ubyte");
	float* labels = read_labels("train-labels.idx1-ubyte");
	float** test_images = read_mnist("t10k-images.idx3-ubyte");
	float* test_labels = read_labels("t10k-labels.idx1-ubyte");
	float* w = new float[784];
	for (int i=0; i<784; i++) {
		w[i]=(float) rand()*2/INT_MAX-1; 	
	}

for(int i=0;i<60000;i++){
	printf("%u\n",i);	
	int prediction = linear_classifier (w, images[i] 	);
	
	int verite= (labels[i]==1) ? 1 :-1;
if (verite!= prediction){
printf("erreur \n");
for(int j=0;j<784;j++) w[j]=w[j] + gamma*verite*images [i] [j] ;
}
	}
float E=0;


    for(int i=0; i<10000; i++) {
		printf("%u\n", i);
		int NN;
		int inference	= linear_classifier (w, test_images[i] 	);
		save_jpg(test_images[i], 28, 28, "%u/%u.jpg", inference, i);
		
		//if (inference != test_labels[i]){ 
			if ( (inference==1 && test_labels[i]!=1 ) || (inference == -1 && test_labels[i]==1)) E++;
		
			
		
	printf ("erreur= %0.2f%%\n", (E*100)/i);
	}

    return 0;
}
