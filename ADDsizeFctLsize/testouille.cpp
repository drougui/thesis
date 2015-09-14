#include <cmath>
#include<iostream>
#include <fstream>

using namespace std;

int main()
{
	ofstream ADDsize("ADDsizeIsFctOfLsize.txt", std::ios::out | std::ios::trunc );
  	if (ADDsize)
    	{
		for (double TL=2;TL<101;TL++)
		{
			cout << "ADDsizeIsFctOfLsize.txt file modification" << endl;
			double nombre2vars = 7; 
			double tailleL = TL;
			double a = pow(2,nombre2vars);
			//cout << a << endl;
	
			double currentNbrNodes = min(tailleL,a);
	
			double totalNode = currentNbrNodes;
	
			double nombre = tailleL*(tailleL-1);
			cout << currentNbrNodes << endl;
			for (double i=0;i<nombre2vars-1;i++)
			{
				a = pow(2,nombre2vars-1-i);
				currentNbrNodes = min(nombre,a);
				totalNode = totalNode + currentNbrNodes;
				nombre = nombre*(nombre-1);
				cout << currentNbrNodes << endl;
			}
			cout << "total: " << totalNode << endl;
			cout << "2pown-1: " << pow(2,nombre2vars+1) - 1 << endl;
			
			if (TL%10==2)	
			{
				ADDsize << TL << " " << totalNode << " " << pow(2,nombre2vars+1) - 1 << endl;
			}
		}
	}
	else
	{
		cout << "pbm writting in ADDsizeIsFctOfLsize.txt " << endl;
	}	
	cout << "AHHHHHHHHHHHHHHHHHH" << endl;
	ADDsize.close();
	return 0;
}
