#pragma once
#include <fmod.hpp>

namespace luck
{
	class AudioChannel
	{
	public:
		AudioChannel() {}
		AudioChannel(FMOD::Channel* channel) : channel{ channel } {}

		bool IsPlaying();
		void Stop();

		void SetPitch(float pitch);
		void SetVolume(float volume);
		float GetPitch();
		float GetVolume();

	private:
		FMOD::Channel* channel{ nullptr };
	};
}