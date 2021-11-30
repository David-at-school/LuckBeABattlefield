#pragma once

namespace luck
{
	void SeedRandom(unsigned int seed);

	float Random();
	float RandomRange(float min, float max);

	int RandomInt();
	int RandomInt(int max);
	int RandomRangeInt(int min, int max);
}