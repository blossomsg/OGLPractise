#include<iostream>
#include<array>  //for std::size()

int main() {
	long value_01{}; //empty variable
	long value_02{76}; //variable value
	long value_03{83}; //variable value
	//char proverb{ 'H' };
	//char* pproverbs{ "have a good day" }; //wrong
	const char* pproverb{ "Have a good day" };

	const char* pstars[]{
		"Fatty Arbuckle", "Clara Bow", "Lassie", "Slim Pickens", "Boris Karloff", "Mae West", "Oliver Hardy", "Greta Garbo"
	};

	//stream out memory value 
	auto* pvalue_01{&value_01};
	std::cout << pvalue_01 << std::endl; 

	//stream out by dereferencing the pointer
	auto* pvalue_02{ &value_02 };
	std::cout << *pvalue_02 << std::endl;

	//stream out variable within variable
	long vvalue_03{ value_03 };
	std::cout << vvalue_03 << std::endl;

	auto* ppproverb{ &pproverb };
	std::cout << *ppproverb << std::endl;

	std::cout << "Pick a lucky star! Ender a number between 1 and " << std::size(pstars) << ": ";
	size_t choice{};
	std::cin >> choice;

	if (choice >= 1 && choice <= std::size(pstars)) {
		std::cout << "Your lucky star is " << pstars[choice - 1] << std::endl;
	}
	else {
		std::cout << "Sorry, you haven't got a lucky star." << std::endl;
	}

	return 0;
}