#include <iostream>
#include <math.h>
#include <cstdlib>
#include <fstream>

int* sort(double* distrib,unsigned size)
{
	int* order = new int[size];
	for (unsigned i=0; i<size; i++)
		order[i] = -1;
	bool* used_value = new bool[size];
	for (unsigned i=0; i<size; i++)
		used_value[i] = false;
	for (unsigned i=0; i<size; i++) // look for the i+1th element
	{
		//std::cout << "\ni:" << i << std::endl;
		unsigned index;
		double max;
		bool first = true;
		bool yes = false;
		bool next = false;
		for (unsigned j=0; j<size;j++)
		{
			//std::cout << "j:" << j << std::endl;
			if ( first && (!used_value[j]) )
			{
				//std::cout << "if1" << std::endl;
				max = distrib[j];
				index = j;
				first = false;	
				yes = true;	
			}
			if ( next && (!used_value[j]) )
			{
				//std::cout << "if2" << std::endl;
				if (max < distrib[j])
				{
					//std::cout << "if3: max=" << max << " distrib[" << j << "]=" << distrib[j] << std::endl; 
					max = distrib[j];
					index = j;
				}
			}
			if ( yes && (!used_value[j]) )
				next = true;
		}
		order[i] = index;
		used_value[index] = true;
		//std::cout << "order[" << i << "] = " << order[i] << std::endl;
	}
	delete [] used_value;
	return order;
}

int main()
{
	std::cout << "\ndrougui presents\n-- THE PIGNISTIC TRANSFORMATION --\n" << std::endl;
	
	unsigned distrib_size = 5;
	double* poss_distrib = new double[distrib_size]; 
	for (unsigned i=0;i<distrib_size;i++)
	{
		poss_distrib[i] = 1.0;	
	}
	poss_distrib[0]=0.0;
	poss_distrib[1]=0.2;
	poss_distrib[2]=1.0;
	poss_distrib[4]=0.0;
	for (unsigned i=0;i<distrib_size;i++)
	{
		std::cout << poss_distrib[i] << " ";
	}
	std::cout << "\n " << std::endl;

	// TRANSFORMATION:
	std::cout << "bla"<< std::endl;	
	double* prob_distrib = new double[distrib_size];
	std::cout << "bli"<< std::endl;	
	int* order = sort(poss_distrib,distrib_size);	
	for (unsigned i=0;i<distrib_size;i++)
	{
		std::cout << order[i] << " ";
	}
	std::cout << "\n" << std::endl;

	double * terms = new double[distrib_size];
	for (unsigned i=0;i<distrib_size-1;i++)
	{
		double denom = (double) i+1;
		terms[i] = (poss_distrib[order[i]] - poss_distrib[order[i+1]])/denom;
	}
	terms[distrib_size-1] = poss_distrib[order[distrib_size-1]]/(distrib_size);
		
	for (unsigned i=0;i<distrib_size;i++)
	{
		std::cout << terms[i] << " ";
	}
	std::cout << "\n" << std::endl;

	prob_distrib[order[distrib_size-1]] = terms[distrib_size-1];
	for (unsigned i=distrib_size-2; i<4294967295; i--)
	{
		std::cout << i << std::endl;
		prob_distrib[order[i]] = terms[i] + prob_distrib[order[i+1]]; 
	}

	double sum_distrib = 0.0;
	for (unsigned i=0;i<distrib_size;i++)
	{
		std::cout << prob_distrib[i] << " ";
		sum_distrib = sum_distrib + prob_distrib[i];
	}
	std::cout << std::endl;
	
	std::cout << "\nsum_distrib: " << sum_distrib << std::endl;	

	delete [] order;
	delete [] terms;

	std::ofstream fichier("plot4.txt", std::ios::out | std::ios::trunc);
	if(fichier)
	{
		fichier << "index proba possib" << std::endl;
		for (unsigned i=0;i<distrib_size;i++)
		{
			fichier << i << " " << prob_distrib[i] << " " << poss_distrib[i] << std::endl;
		}
		fichier.close();
	}
	else
		std::cerr << "Erreur à l'ouverture !" << std::endl;
	delete [] poss_distrib;
	delete [] prob_distrib;


	std::cout << "\n-- THE END --\n" << std::endl;
	return 0;
}
