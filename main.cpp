#include <iostream>
#include <gmock/gmock.h>
using namespace testing;
using namespace std;

std::string helloWorld (){
	return "hello world";
}
/*int main(int argc, const char * argv []){
	std::cout << helloWorld() <<std::endl;
	return 0;
}*/

TEST( BlobParserBasics, Vendor )
{
    EXPECT_THAT(helloWorld(), Eq("hello world"));
}
