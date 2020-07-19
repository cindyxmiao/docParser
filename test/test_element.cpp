// Test framework
#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <string>

#include "element.h"

using namespace std;
using namespace testing;

TEST(BlobParserBasics, InitalizationHasCorrectValues)
{
	Element e(PARAGRAPH, "hello World!");
	EXPECT_THAT(e.getType(), Eq(PARAGRAPH));
	EXPECT_THAT(e.getText(), Eq("hello World!"));
}
