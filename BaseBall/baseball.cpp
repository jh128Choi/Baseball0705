#include <stdexcept>

using namespace std;

struct GuessResult
{
	bool solved;
	int strikes;
	int balls;
};

class Baseball
{
public:
	explicit Baseball(const string& question)
		: question(question)
	{
	}

	bool isDuplicatedNumber(const string& guessNumber)
	{
		return guessNumber[0] == guessNumber[1] ||
			guessNumber[1] == guessNumber[2] ||
			guessNumber[2] == guessNumber[0];
	}

	void assertIllegalArgument(const string& guessNumber)
	{
		if (guessNumber.length() != 3)
		{
			throw length_error("Must be three letters.");
		}

		for (char ch : guessNumber)
		{
			if (ch >= '0' && ch <= '9')
				continue;
			throw invalid_argument("Must be number");
		}

		if (isDuplicatedNumber(guessNumber))
		{
			throw invalid_argument("Must not have the same number");
		}
	}

	int getStrikes(const string& guessNumber)
	{
		int strike = 0;
		for (int i = 0; i < 3; ++i)
		{
			if (guessNumber[i] == question[i])
			{
				strike++;
			}
		}
		return strike;
	}

	int getBalls(const string& guessNumber)
	{
		int ball = 0;
		for (int i = 0; i < 3; ++i)
		{
			if (guessNumber[i] == question[(i + 2) % 3])
			{
				ball++;
			}
			if (guessNumber[i] == question[(i + 1) % 3])
			{
				ball++;
			}
		}
		return ball;
	}

	GuessResult guess(const string& guessNumber)
	{
		assertIllegalArgument(guessNumber);
		if (guessNumber == question)
		{
			return { true, 3, 0 };
		}

		int strike = getStrikes(guessNumber);
		int ball = getBalls(guessNumber);
		
		return { false, strike, ball };
	}

private:
	string question;
};