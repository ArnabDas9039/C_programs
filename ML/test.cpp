#include<stdio.h>
#include<math.h>
#define output 9
#define input 9
#define move 9
float gamerules(int cm);
int count=0;
int board[3][3];
float wb[output][input+1][move]/*={{{2.700090, -3.242493, -3.206730, -3.129244, -3.194809, -2.920628, -2.662838, -2.376735, -2.254918, },
{-4.118681, 10.335445, -1.436472, -1.281500, -1.168251, -1.096725, -1.055002, -0.950694, -0.858307, },
{-1.525879, -2.861023, 10.290742, -1.481175, -1.457334, -1.147389, -1.002848, -1.007318, -0.932813, },
{-0.703335, -1.740456, -1.847744, 9.924173, -1.567602, -1.430511, -1.269579, -1.308322, -1.088530, },
{-0.590086, -1.555681, -1.838803, -1.949072, 9.620190, -1.603365, -1.481175, -1.281500, -1.356006, },
{-0.619888, -1.561642, -1.662970, -1.680851, -1.740456, 9.053946, -1.585484, -1.537800, -1.373887, },
{-0.476837, -1.448393, -1.627207, -1.597404, -1.531839, -1.668930, 8.451939, -1.558661, -1.397729, },
{-0.512600, -1.478195, -1.680851, -1.680851, -1.686811, -1.680851, -1.537800, 7.872283, -1.531839, },
{-0.566244, -1.376867, -1.579523, -1.704693, -1.645088, -1.817942, -1.764297, -1.567602, 7.426739, },
{-6.413460, -4.786253, -4.494190, -4.354119, -4.324317, -4.181266, -3.907084, -3.716350, -3.367290, },
},
{{-6.431341, -0.196695, 1.394749, 1.280010, 1.914054, 1.870096, 2.454221, 1.844764, 1.511723, },
{0.616908, -10.168552, 0.905991, 0.822544, 1.138449, 1.350045, 1.293421, 1.060963, 1.001358, },
{1.403689, 1.469254, -10.716915, 1.168251, 1.454353, 1.299381, 1.221895, 1.245737, 1.078844, },
{0.843406, 1.293421, 1.144409, -10.535121, 1.291931, 1.199543, 1.314282, 1.206249, 1.145899, },
{0.649691, 1.409650, 1.022220, 1.078844, -9.659678, 1.379848, 1.549721, 1.186505, 1.210719, },
{0.518560, 1.388788, 1.019239, 0.977516, 1.436472, -9.281933, 1.457334, 1.217425, 1.266599, },
{0.530481, 1.460314, 1.108646, 1.174212, 1.391768, 1.385808, -8.764863, 1.242757, 1.290441, },
{0.798702, 1.394749, 1.013279, 1.136959, 1.367927, 1.356006, 1.387298, -8.599461, 1.318753, },
{0.622869, 1.481175, 1.204014, 1.224875, 1.403689, 1.299381, 1.344085, 1.364946, -8.401275, },
{-7.206202, -6.347895, -6.386638, -6.282330, -5.858392, -5.732477, -5.361438, -5.274266, -5.067140, },
},
{{6.991625, -2.776086, -0.831485, -4.552305, -4.646182, -4.044175, -3.847480, -4.656985, -3.935769, },
{-1.680851, 6.008148, 4.538894, -3.349781, -0.080466, -3.525615, -4.467368, -1.814961, -5.388260, },
{-1.952052, -7.481873, 7.805228, 0.613928, 2.452731, -1.084805, -3.792346, -1.092628, -5.256012, },
{-2.354383, -3.799796, -3.112853, 14.582276, 2.381206, -0.625849, -1.218915, -0.177324, -2.260506, },
{-1.680851, -2.223253, -3.118813, -1.203641, 14.075637, -1.126155, -1.319870, 0.250712, -2.124533, },
{-1.192093, -1.776218, -3.011525, -1.978874, -0.312924, 13.126433, -1.356006, 0.163913, -2.011657, },
{-1.487136, -1.829863, -3.302097, -2.264977, -0.652671, -3.992021, 13.001262, 0.284612, -1.920760, },
{-1.454353, -2.169609, -3.769994, -2.372265, -0.423193, -3.045797, -1.679361, 12.911856, -1.600385, },
{-1.376867, -2.175570, -3.278255, -2.473593, -0.280142, -2.819300, -1.800060, 0.140071, 13.026595, },
{-5.716085, -15.892088, -11.633336, -7.615984, -8.457899, -6.833673, -6.352365, -7.182732, -6.173923, },
},
{{-7.331371, 3.057718, -0.798702, 2.197921, 4.429743, 4.638731, 4.113465, 3.838912, 3.914535, },
{1.025200, -12.819469, 6.523728, 4.649162, 1.767278, 1.743436, 1.659989, 0.500679, 1.370907, },
{0.986457, 0.149012, -8.086861, 2.050400, -2.082065, -0.439584, 0.181794, -0.501797, 0.555813, },
{0.920892, 2.679229, 3.917515, -8.313358, 2.647936, -1.524389, -0.586361, -0.990927, 0.156462, },
{0.914931, 2.311170, 1.361966, 2.273917, -11.301785, -2.041459, -1.142919, -1.487508, -0.423193, },
{0.792742, 2.017617, 0.096858, 2.738833, 2.455711, -13.327599, -1.013279, -1.472235, -0.718236, },
{0.935793, 1.958013, 0.018626, 2.650917, 1.232326, -0.067055, -13.735145, -1.432002, -0.658631, },
{0.905991, 2.184510, -0.011176, 3.205240, 0.759214, -0.314415, 0.080466, -15.636160, -0.968575, },
{0.980496, 2.196431, 0.365078, 3.370643, 0.417233, -0.530481, -0.065565, -1.227856, -13.454258, },
{-6.878376, -7.790327, -22.001562, -10.560453, -12.787060, -10.576843, -10.953844, -11.863932, -10.029971, },
},
{{7.015467, -5.228817, -6.504357, -4.054234, 0.715256, -3.311038, -4.357472, -1.673400, -2.524629, },
{-1.493096, 5.429983, 4.547834, -4.774332, 0.640750, -5.114079, -1.196563, -3.865361, -2.911687, },
{-1.579523, -1.971424, 9.849669, -5.726889, 1.737475, -3.293157, 0.619516, -1.832843, -2.038851, },
{-1.633167, -1.651049, -2.489984, 10.108204, 3.014505, -4.908442, 1.476705, -1.297891, -1.356006, },
{-1.671910, -1.111254, -3.713369, -9.522960, 11.701881, -1.784787, 2.304465, -0.518560, -0.862032, },
{-1.680851, -0.789762, -2.926588, -5.110353, 0.947714, 14.168023, 2.503395, -0.354648, -0.566244, },
{-1.654029, -0.542402, -2.723932, -3.810599, 0.925362, -3.038347, 13.340637, -0.540912, -0.581518, },
{-1.633167, -0.473484, -2.098083, -3.771857, 0.204146, -2.957508, 1.085549, 13.583898, -0.543147, },
{-1.484156, -0.452995, -2.142787, -3.755093, 0.458956, -2.646446, 1.361966, -1.305342, 12.619794, },
{-5.266070, -12.063980, -11.789799, -19.541010, -9.860098, -6.839633, -7.903948, -7.785857, -8.115544, },
},
{{-7.396936, 4.196167, 1.719594, 6.749481, -0.949204, 3.953278, 3.799796, 7.640570, 2.004206, },
{1.183152, -10.100007, 6.839633, 9.679049, 2.779067, 1.662970, 0.014901, 11.517107, -0.959635, },
{1.114607, 2.366304, -5.218388, -1.575798, 2.865493, 1.636147, -0.431389, 11.053681, -1.513958, },
{1.126528, 1.981854, 1.963973, -11.920927, 3.251433, 1.433492, -1.665950, 10.179728, -3.217161, },
{1.215935, 1.749396, 1.844764, -1.684576, -7.878242, 0.257790, -2.191961, 9.827316, -3.375113, },
{1.084805, 1.910329, 1.662970, 3.212690, 6.055832, -12.631716, -3.027916, 9.103865, -4.205108, },
{1.171231, 1.588464, 1.277030, 3.129989, 1.652539, 1.712143, -16.169994, 9.638071, -3.495812, },
{1.046062, 1.743436, 0.903010, 3.025681, 3.150105, 2.685189, -1.872331, -0.841916, -2.753735, },
{1.105666, 1.704693, 0.990927, 2.935529, 3.616512, 3.257394, -1.727045, 10.219216, -14.939905, },
{-6.684661, -5.847216, -17.458200, -19.524248, -17.417963, -13.533234, -12.075901, -8.700042, -9.448827, },
},
{{7.206202, -6.577373, -7.067621, -1.047552, -0.619888, -4.822016, -2.449751, -7.607043, -2.172962, },
{-1.195073, 4.562736, 4.459918, -2.500415, 2.592802, -5.850196, -0.523031, -4.258752, -0.004470, },
{-1.448393, -2.437830, 9.274483, -4.126132, -0.452995, -5.938113, -0.049174, -1.424551, 0.226125, },
{-1.406670, -2.557039, -4.343688, 14.895203, 4.449487, -4.982948, 0.064075, -1.370906, 0.914931, },
{-1.364946, -2.330542, -3.077090, -6.122887, 19.127131, -5.413591, 0.734627, -0.464916, 1.430511, },
{-1.579523, -1.582503, -3.921986, -1.594424, 4.175305, 9.988248, 1.245737, 0.172853, 1.823902, },
{-1.475215, -1.320243, -3.483891, -0.663102, 2.381206, -6.383657, 11.062620, -0.363588, 2.534315, },
{-1.415610, -1.111627, -3.588200, -1.016259, 1.719594, -5.975366, -0.074506, 12.971461, 1.806021, },
{-1.525879, -1.090765, -3.705919, -1.029670, 1.552701, -7.776917, -0.554323, -0.886620, 11.643396, },
{-5.385280, -12.257695, -11.809171, -24.420025, -19.553303, -12.905896, -9.298325, -7.963180, -8.353962, },
},
{{-8.112192, 5.233288, 4.155933, 2.621114, 0.386312, 5.438924, 0.996143, 10.583178, -4.327297, },
{1.201034, -10.985136, 6.057322, 0.925362, 2.297759, 4.836917, -2.264231, 11.171400, -7.957220, },
{1.260638, 1.859665, -4.646182, 2.339482, 1.764670, 4.811584, -3.227592, 10.031835, -9.582937, },
{1.296401, 1.218915, 1.631677, -9.703636, 2.075731, 4.309416, -2.289563, 10.494887, -9.132921, },
{1.195073, 1.114607, 2.247095, 0.101328, -13.524670, 5.486608, -2.790987, 9.611249, -10.101498, },
{1.063943, 0.730157, 4.123151, 0.655651, 3.021955, -7.779896, -1.842529, 10.135025, -9.199977, },
{1.177192, 1.046062, 3.746152, -1.326203, 0.894442, 4.793704, -13.068317, 9.742752, -9.569526, },
{1.165271, 0.995398, 4.570187, -1.591444, 1.122057, 3.699958, -2.390146, 1.852214, -9.769201, },
{1.171231, 1.052022, 4.155933, -2.193451, 1.405552, 2.975762, -2.939999, 10.696426, -20.767748, },
{-6.172061, -5.608797, -19.341707, -19.040705, -20.648163, -15.248356, -12.639164, -11.623279, -14.339388, },
},
{{7.164478, -1.329184, -3.851950, -2.910196, 2.267957, -8.424372, 8.051097, 11.293591, -15.783682, },
{-2.083182, 9.441376, -4.562736, -3.711879, 2.132356, -7.141381, 3.449619, 11.329353, -9.900331, },
{-0.846386, 0.667572, 3.010035, -6.733835, 2.597272, -8.518249, 3.275275, 10.739267, -6.717071, },
{-1.022220, -0.417233, -2.603233, 4.933774, 0.968575, -9.433180, 3.352762, 10.734797, -6.943941, },
{-0.256300, -1.206994, -0.891089, -0.600517, 7.343292, -10.847301, 3.218651, 10.560453, -6.932765, },
{-0.312924, -1.195073, -0.426173, -2.223253, 3.293157, 2.057105, 2.992153, 10.620058, -6.875769, },
{-0.151992, -1.326203, -0.669062, -2.589822, 3.522635, -7.582456, 5.090237, 10.620058, -6.800518, },
{-0.384450, -1.364946, -0.704825, -2.884865, 3.784895, -8.340925, 3.312529, 10.906158, -7.120520, },
{-0.053644, -1.505017, -0.384450, -2.853572, 3.835559, -8.458644, 3.261865, 10.652840, -1.745299, },
{1.528859, 2.419949, -11.202693, -17.836689, -16.081333, -12.301653, -15.315414, -16.568602, -14.215335, },
},}*/;
int a[input]/*={4, 3, 1, 7, 0, 6, 8, 2, 5}*/;
float a1[input][move], b1[output][move], b2[output][move];
float gradc[output][input+1][move];
void restart(){
	for(int cm=0; cm<move; cm++){
		for(int i=0; i<output; i++){
			a[i]=-1;
			a1[i][cm]=0;
			b1[i][cm]=0;
		}
	}
}
void display(){
	for(int i=0; i<3; i++){
		for(int j=0; j<3; j++){
			printf("%d",board[i][j]);
		}
	}
}
void displaya1(/*int cm*/){
	printf("\nDisplaying a1 ...\n");
	for(int cm=0; cm<move; cm++){
	for(int j=0; j<input; j++){
		printf("%f ",a1[j][cm]);
	}printf("\n");
	}
}
void displayb(){
	printf("\nDisplaying b1 ...\n");
	for(int cm=0; cm<move; cm++){
		for(int i=0; i<output; i++){
			printf("%f ",b1[i][cm]);
		}
		printf("\n");
	}
}
void displayb2(){
	printf("\nDisplaying b2 ...\n");
	for(int cm=0; cm<move; cm++){
		for(int i=0; i<output; i++){
			printf("%f ",b2[i][cm]);
		}
		printf("\n");
	}
}
void displaywb(){
	printf("\nDisplaying wb ...\n");
	printf("{");
	for(int cm=0; cm<move; cm++){
		printf("{");
		for(int j=0; j<=input; j++){
			printf("{");
			for(int i=0; i<output; i++){
				printf("%f, ",wb[i][j][cm]);
			}
			printf("},\n");
		}
		printf("},\n");
	}
	printf("}\n");
}
void createb2(){
	for(int cm=0; cm<move; cm++){
		for(int i=0; i<output; i++){
			b2[i][cm]=0;
		}
	}
	for(int i=0; i<output; i++){
		b2[i][a[i]]=1;
		if(gamerules(8)==1){
			printf("\nLost");
			b2[i][a[i]]=-1;
		}
	}
}
void createa1(int cm){
	for(int j=0; j<input; j++){
		if((a[j]==cm && cm%2==0) || a1[j][cm-1]==1){
			//printf("\nX is in place.");
			a1[j][cm]=1;
		}
		else if((a[j]==cm && cm%2!=0) || a1[j][cm-1]==-1){
			//printf("\nO is in place.");
			a1[j][cm]=-1;
		}
	}
	//displaya1(cm);
}
float calculateb(int i, int cm){//cm is current move number
	float sum=0;
	for(int j=0; j<input; j++){
		sum=sum+(a1[j][cm]*wb[i][j][cm]);
	}
	return 1/(1+exp(-(sum+wb[i][9][cm])));
}
void createb1(int cm){
	for(int i=0; i<output; i++){
		b1[i][cm]=calculateb(i, cm);
	}
	//displayb();
}
float costfunction(int cm){
	float c=0;
	for(int i=0; i<output; i++){
		c=c+pow((b1[i][cm]-b2[i][cm]),2);
	}
	//printf("\nCost = %f",c);
	return c;
}
void gradientc(){
	float c1[move];
	float c2[move];
	for(int cm=0; cm<move; cm++){
		c1[cm]=costfunction(cm);
		for(int j=0; j<=input; j++){
			for(int i=0; i<output; i++){
				float x=wb[i][j][cm], y=b1[i][cm];
				wb[i][j][cm]=wb[i][j][cm]+0.00001;
				b1[i][cm]=calculateb(i, cm);
				c2[cm]=costfunction(cm);
				gradc[i][j][cm]=(c2[cm]-c1[cm])/0.00001;
				wb[i][j][cm]=x;
				b1[i][cm]=y;	
			}
		}
	}
}
void backprop(){
	for(int cm=0; cm<move; cm++){
		createa1(cm);
		createb1(cm);
	}
	createb2();
	displaya1();
	displayb();
	gradientc();
	for(int cm=0; cm<move; cm++){
		for(int j=0; j<=input; j++){
			for(int i=0; i<output; i++){
				wb[i][j][cm]=wb[i][j][cm]-gradc[i][j][cm];	
			}
		}
	}
	//displayb2();
	//displaywb();
	for(int cm=0; cm<move; cm++){
		createb1(cm);
		for(int j=0; j<input; j++){
			a1[j][cm]=0;
		}
	}
}
void arrayconvert(int *array){
	int t=0;
	for(int i=0; i<3; i++){
		for(int j=0; j<3; j++){
			if(array[t]%2==0){
				board[i][j]=array[t];
			}
			else{
				board[i][j]=(-1)*array[t];
			}
			t++;
		}
	}
}
float gamerules(int cm){
	//printf("\nEntered gamerules.");
	for(int i=0; i<9; i=i+3){
		//printf("\nHorizontal loop at %d",i);
		if(a1[i][cm]==a1[i+1][cm] && a1[i][cm]==a1[i+2][cm] && a1[i][cm]!=0){
			//printf("\nHorizontal win");
			return a1[i][cm];
		}
	}
	for(int i=0; i<3; i++){
		//printf("\nVertical loop at %d",i);
		if(a1[i][cm]==a1[i+3][cm] && a1[i][cm]==a1[i+6][cm]&& a1[i][cm]!=0){
			//printf("\nVertical win");
			return a1[i][cm];
		}
	}
	//printf("\nChecking diagonal");
	if((a1[0][cm]==a1[4][cm]&& a1[0][cm]==a1[8][cm] && a1[0][cm]!=0) || (a1[2][cm]==a1[4][cm] && a1[2][cm]==a1[6][cm] && a1[2][cm]!=0)){
		//printf("\nDiagonal win");
		return a1[4][cm];
	}
	return 0;
}
void permute(int *array, int start, int end) {
	if (start==end) {
		for (int i=0; i<end; i++) {
			a[i]=array[i];
		}
		printf("\n%d",count);
		backprop();
		count++;
	} 
	else {
    // Recursively permute the array, starting at the next index.
    	for (int i = start; i < end; i++) {
		    int temp = array[start];
		    array[start] = array[i];
		    array[i] = temp;
		    permute(array, start + 1, end);
		    temp = array[start];
		    array[start] = array[i];
		    array[i] = temp;
	    }
	}
}
void allgames(){
	int array[9];
	for(int i=0; i<9; i++){
		array[i]=i;
	}
	//permute(array, 0, 9);
	for (int i=0; i<9; i++) {
		a[i]=array[i];
	}
	printf("\n%d",count);
	backprop();
	count++;
	array[6]=8; array[8]=6;
	for (int i=0; i<9; i++) {
		a[i]=array[i];
	}
	printf("\n%d",count);
	backprop();
	count++;
	array[0]=2; array[2]=0;
	for (int i=0; i<9; i++) {
		a[i]=array[i];
	}
	printf("\n%d",count);
	backprop();
	count++;
	array[6]=6; array[8]=8;
	for (int i=0; i<9; i++) {
		a[i]=array[i];
	}
	printf("\n%d",count);
	backprop();
	count++;
	printf("\n%d",count);
	backprop();
	count++;
	array[0]=0; array[2]=8; array[8]=2;
	for (int i=0; i<9; i++) {
		a[i]=array[i];
	}
	printf("\n%d",count);
	backprop();
	count++;
	array[6]=0; array[0]=6;
	for (int i=0; i<9; i++) {
		a[i]=array[i];
	}
	printf("\n%d",count);
	backprop();
	count++;
	array[2]=2; array[8]=8;
	for (int i=0; i<9; i++) {
		a[i]=array[i];
	}
	printf("\n%d",count);
	backprop();
	count++;
	printf("Training completed.");
	displaywb();
}
void notloose(){
	if(gamerules(8)==1){
		//not loose
	}
}
void play(int cm){
	int index=-1;;
	createb1(cm);
	displayb();
	float MAX=0;
	for(int i=0; i<output; i++){
		if(a1[i][cm]!=0){
			continue;
		}
		if(b1[i][cm]>MAX){
			MAX=b1[i][cm];
			index=i;
		}
	}
	//return index;
	printf("My move is: %d\n",index);
	a[index]=cm;
	createa1(cm);
	displaya1();
}
void result(){
	printf("\nResult of the match is: %f",gamerules(7));
}
int main(){
	int x, y;
	//manual training
	//printf("Training starts with two games.... \n");
	/*for(int i=0; i<3; i++){
		for(int j=0; j<3; j++){
			printf("Enter the value at [%d][%d]: ",i,j);
			scanf("%d",&board[i][j]);
		}
		printf("\n");
	}*/
	//Draw match
	/*board[0][0]=5;	board[0][1]=-4;	board[0][2]=-2;
	board[1][0]=-8;	board[1][1]=1;	board[1][2]=7;
	board[2][0]=9;	board[2][1]=3;	board[2][2]=-6;*/
	// x wins
	/*board[0][0]=5;	board[0][1]=-2;	board[0][2]=-4;
	board[1][0]=7;	board[1][1]=1;	board[1][2]=0;
	board[2][0]=3;	board[2][1]=0;	board[2][2]=-6;*/
	//o wins
	//result();{4, 3, 1, 7, 0, 6, 8, 2, 5}
	/*a[0]=4; a[1]=3; a[2]=1; a[3]=7; a[4]=0; a[5]=6; a[6]=8; a[7]=2; a[8]=5;
	for(int t=362880; t>0; t--){
		backprop();
		printf("%d\n",362880-t);
	}
	/*a[0]=4; a[1]=1; a[2]=3; a[3]=6; a[4]=2; a[5]=8; a[6]=0; a[7]=7; a[8]=5;
	for(int t=10; t>0; t--){
		backprop();
	}*/
	//backprop();
	//printf("Trained the model 1 time.");
	printf("Automatic training starts....");
	allgames();
	while(1){
		printf("\nLet the game begin.... \n");
		restart();
		displaya1();
		printf("Enter your 1st move: ");
		//scanf("%d %d",&x,&y);
		scanf("%d",&x);
		a[x]=0;
		createa1(0);
		displaya1();
		if(x==9 /*&& y==3*/){
			break;
		}
		board[x][y]=0;
		play(1);
		printf("Enter your 2nd move: ");
		//scanf("%d %d",&x,&y);
		scanf("%d",&x);
		a[x]=2;
		createa1(2);
		board[x][y]=2;
		play(3);
		printf("Enter your 3rd move: ");
		//scanf("%d %d",&x,&y);
		scanf("%d",&x);
		a[x]=4;
		createa1(4);
		board[x][y]=4;
		play(5);
		printf("Enter your 4th move: ");
		//scanf("%d %d",&x,&y);
		scanf("%d",&x);
		a[x]=6;
		createa1(6);
		board[x][y]=6;
		play(7);
		/*printf("Enter your 5th move: ");
		scanf("%f %f",&x,&y);
		board[x][y]=8;
		//play();*/
		result();
	}
	return 0;
}
