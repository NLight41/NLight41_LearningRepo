#include <iostream>
#include <cmath>
#include <chrono> 
#include <vector>
#include <functional>
// HLOA v0.0.1_AdaptiveTest  
// 03.21.2025 by NLight41  
using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::function;
using std::fabs;
 

// ==== �ѼƼҲ� ==== 
struct Parameters {
	double param1;
	double param2;  	
};

// �䴩���P�����ը�� (�w�]�� sin ���) 
double simulationFunction(const Parameters &p, const function<double(const Parameters&)> &func) {
	return func(p);
}

// ���� ���ը�� (�Y / �D�Y)
double convexFunction(const Parameters &p) {
	return fabs(p.param1 * p.param1 + p.param2 * p.param2 - 100);
}
double nonConvexFunction(const Parameters &p) {
	return fabs(p.param1 * sin(p.param2) + 10 - 100);
}

// �����t���k�p���� (ver 2.) 
void computeGradient(const Parameters &p, Parameters &grad, const function<double(const Parameters&)> &func, double delta = 1e-5){
	Parameters p_temp = p;
	double f0 = simulationFunction(p, func);
	
	p_temp.param1 += delta;
	double f1 = simulationFunction(p_temp, func);
	grad.param1 = (f1 - f0) / delta;
	p_temp.param1 = p.param1;	// ���m 
	
	
	p_temp.param2 += delta;
	double f2 = simulationFunction(p_temp, func);
	grad.param2 = (f2 - f0) / delta;
	
}


// ==== HLOA core ====
Parameters  adaptiveHoloLoopOptimizer(Parameters initParams, double learningRate, double momentumFactor, double holoFactor, double threshold, int maxIterations, const function<double(const Parameters&)> &func) {
	Parameters p = initParams;
	Parameters grad{0.0, 0.0};
	Parameters momentum{0.0, 0.0};	// �O�s�W�@������װʶq��  
	
	double prevError = simulationFunction(p, func);
	double currError = prevError;
	int iteration = 0;
	
	
	while (currError > threshold && iteration < maxIterations) {
		
		computeGradient(p, grad, func);
		
		// �ʶq��s : �N��e����� �P �W�@�����ժ���� ����ҿĦX 
		momentum.param1 = momentumFactor * momentum.param1 + (1 - momentumFactor) * grad.param1;
		momentum.param2 = momentumFactor * momentum.param2 + (1 - momentumFactor) * grad.param2;
		
		// �����^�X�վ� : �ھڱ���ܤƶq�վ��ק�s�t�� ��sfabs 
		double errorDiff = currError - prevError;
		double holoAdjustment = holoFactor * fabs(errorDiff);
		
		// ��s�Ѽ� : �N �ʶq �P �����^�X�ܦ] ���X��A�i���פU����s 
		p.param1 -= learningRate * (momentum.param1 + holoAdjustment);
		p.param2 -= learningRate * (momentum.param2 + holoAdjustment);
		
		// ��s�~�t�� �� ���N���� 
		prevError = currError;
		currError = simulationFunction(p, func);
		iteration++;
		
		// ��X��e���N���p�A�Ω� �l�ܪ��� �� ��K�վ�  
		cout << "Iteration: " << iteration
			 << ", Error: " << currError 
			 << ", param1: " << p.param1
			 << ", param2: " << p.param2 << endl; 
				
	}
	
	return p;	
}



// ==== �Ѽƿ�J�t�� ==== 
void inputParameters(Parameters &initParams, double &learningRate, double &momentumFactor, double &holoFactor, double &threshold, int &maxIterations) {
	cout << "�]�w��l�Ѽ� (param1 param2): " ;
	cin >> initParams.param1 >> initParams.param2;
	cout << "�]�w�ǲ߲v: " ;
	cin >> learningRate;
	cout << "�]�w�ʶq�ܼ�: " ;
	cin >> momentumFactor;
	cout << "�]�w�����^�X�ܼ�: " ;
	cin >> holoFactor;
	cout << "�]�w�~�t�֭�: " ;
	cin >> threshold;
	cout << "�]�w�̤j���N����: " ; 
	cin >> maxIterations;
		
}

 
int main() {
	// ��J�Ѽ� 
	Parameters initialParams;
	double learningRate, momentumFactor, holoFactor, threshold;
	int maxIterations;
	inputParameters(initialParams, learningRate, momentumFactor, holoFactor, threshold, maxIterations);
	 
	int choice;
	function<double(const Parameters&)> selectedFunction;
	cout << "��ܥؼШ��: (1) �Y��� (2) �D�Y���: ";
	cin >> choice;
	
	if (choice == 1) {
		selectedFunction = convexFunction;
		cout << "�ϥΥY���: f(x, y) = |x^2 + y^2 - 100|" << endl;
	} else {
		selectedFunction = nonConvexFunction;
		cout << "�ϥΫD�Y���: f(x, y) = |x * sin(y) + 10 - 100|" << endl;
	}
	
	
	// �p�� �[��ʯ� 
	auto start = std::chrono::high_resolution_clock::now();
	Parameters optimized = adaptiveHoloLoopOptimizer(initialParams, learningRate, momentumFactor, holoFactor, threshold, maxIterations, selectedFunction);
	auto end = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double> elapsed = end - start;
	
	cout << "\n�̨ΤƧ���! " << endl;
	cout << "param1: " << optimized.param1 << ", param2: " << optimized.param2 << endl;
	cout << "Time elapsed: " << elapsed.count() << " seconds." << endl;
	
	return 0;
		
}




 




 
