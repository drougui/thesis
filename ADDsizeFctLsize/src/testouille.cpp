#include <cmath>
#include<iostream>
#include <fstream>
#include <sstream>

using namespace std;

int main()
{

	// NOMBRE DE VARIABLES			
	for (int nbvar=1;nbvar<41;nbvar++)
	{

		double nombre2vars_cst = (double) nbvar;

		stringstream ss;
		ss << nbvar;
		string nbvarString = ss.str();
		string beginningName = "MAXnbNodes_fctOf_Lsize_";// + nbvar + "VARS.txt";
		string endName = "VARS.txt";
		string nom = beginningName + nbvarString + endName;
		ofstream ADDsize(nom.c_str(), std::ios::out | std::ios::trunc );
  		if (ADDsize)
    		{

			ADDsize << "scaleSize" << " " 
				<< "MaxNbNodesPoss" << " " << "MaxNbNodes" << endl;
		
			// abscisse
			for (int TL=2;TL<301;TL++)
			{
				cout <<".";
				// TAILLE DE L 
				double tailleL = (double) TL;
				// NOMBRE D'ETATS
				double a = pow(2,nombre2vars_cst);
		
				// the number of leaves is equal 
				// to the number of states "nbstates", 
				// if #L>nbstates, #L otherwise
				double currentNbrNodes = min(tailleL,a);
	
				// totalNode stores the current number of nodes:
				// we start by the leaves (currentNbrNodes)
				// and add to totalNode the maximal number of nodes 
				// for each variable (level of the tree)
				// until the first variable of the three
				double totalNode = currentNbrNodes;
	
				// maximal number of nodes for the last level of the tree 
				// (at this level, a node is necessary if it has a TRUE/FALSE
				// result which is different of the other)
				double nombre = tailleL*(tailleL-1);

				// pour chaque variable
				for (double i=0;i<nombre2vars_cst-1;i++)
				{
					// 2^{NBvars-1-i}
					a = pow(2,nombre2vars_cst-1-i);

					// the number of nodes needed at the level 
					// nombre2vars_cst-i 
					// is equal to 
					// "a = number of maximal number of combinations 
					// using nombre2vars_cst-i variables"
					// if "currentNbrNodes 
					// = maximal number of nodes at this level 
					// given the maximal number of nodes 
					// at the previous level" > a, 
					// and to currentNbrNodes otherwise.
					currentNbrNodes = min(nombre,a);
					// we add this number to the maximal number of nodes 
					//of all the previous levels
					totalNode = totalNode + currentNbrNodes;
					// computation of the maximal number of combinations 
					// of two nodes of the current level
					nombre = nombre*(nombre-1);
				}
				// size of the scale -- max number of nodes 
				//           -- max number of nodes in quantitative settings
				if ((TL%10)==2)
					ADDsize << TL << " " << totalNode << " " << pow(2,nombre2vars_cst+1) - 1 << endl;
				// max number of nodes: 
				// S = 1 + 2^1 + 2^2 + ... + 2^{nbvar-1} + 2^nbvar
				/*
					S = S*(2-1) = 2*S - S = 2^{nbvar+1} - 1
				*/ 
		}
		cout << endl;
	}
	else
	{
		cout << "pbm writting in ADDsizeIsFctOfLsize.txt " << endl;
	}	
	ADDsize.close();
	}
	return 0;
}
