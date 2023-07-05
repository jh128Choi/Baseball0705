#include "pch.h"
#include "../BaseBall/baseball.cpp"

class BaseballFixture : public testing::Test
{
public:
	Baseball game;
	void assertIllegalArgument(string guessNumber)
	{
		// game.guess() ���� �� exception�� �߻��ؾ� PASS
		try
		{
			game.guess(guessNumber);
			FAIL();
		}
		catch (exception e)
		{
			// PASS
		}
	}
};

TEST_F(BaseballFixture, ThrowExceptionWhenInvalidCase) {
	assertIllegalArgument("12");
	assertIllegalArgument("12s");
	assertIllegalArgument("121");
}