#pragma once
#include <memory>
#include "types.h"

namespace SQU {
	namespace Comm {

		enum ComponentType {
			Main,
			Operator,
			Envelop,
			Filter,
			LFO
		};

		enum ParameterType {
			//====================
			// Main
			ComponentActivation,
			Volume,
			MonoLegato,
			Portamento,
			//====================
			// Operator
			Pitch,
			Pan,
			WaveTable,
			//====================
			// Envelope
			Attack,
			Decay,
			Sustain,
			Release,
			//====================
			// Filter
			Type,
			Slope,
			Frequency,
			Quality
		};

		struct SynthEmilionMessage
		{
			SynthEmilionMessage() {}
			~SynthEmilionMessage() {}

			union ParameterValue {
				ParameterValue() {}
				~ParameterValue() {}
				int		intValue;
				double	doubleValue;
				bool	boolValue;
				wavetable_ptr wavetableType;
			};

			ComponentType component;
			int componentNumber;
			ParameterType parameter;
			ParameterValue parameterValue;
		};

	}
}

