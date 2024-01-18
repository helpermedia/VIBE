/**
 * @file    vibe_BaseSpline.cpp
 * @author  Marcel Ritsema
 */

#include "vibe_BaseSpline.h"

namespace vibe
{

    juce::Array<juce::Point<double>>& BaseSpline::getInterpolatedPoints()
    {
        if (iPoints.size() == 0)
            interpolate();

        return iPoints;
    }

} // namespace vibe
