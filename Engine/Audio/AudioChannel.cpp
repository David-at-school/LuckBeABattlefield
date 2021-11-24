#include "AudioChannel.h"

namespace luck
{
	bool AudioChannel::IsPlaying()
	{
		if (channel == nullptr) return false;
		bool isPlaying;
		channel->isPlaying(&isPlaying);

		return isPlaying;
	}

	void AudioChannel::Stop()
	{
		if (IsPlaying())
		{
			channel->stop();
		}
	}
	void AudioChannel::SetPitch(float pitch)
	{
		if (IsPlaying())
		{
			channel->setPitch(pitch);
		}
	}

	void AudioChannel::SetVolume(float volume)
	{
		if (IsPlaying())
		{
			channel->setVolume(volume);
		}
	}

	float AudioChannel::GetPitch()
	{
		float pitch = 0.0f;
		if (IsPlaying())
		{
			channel->getPitch(&pitch);
		}
		return pitch;
	}

	float AudioChannel::GetVolume()
	{
		float volume = 0.0f;
		if (IsPlaying())
		{
			channel->getVolume(&volume);
		}
		return volume;
	}
}