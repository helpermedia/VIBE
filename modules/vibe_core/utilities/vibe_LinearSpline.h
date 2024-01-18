/**
 * @file    vibe_LinearSpline.h
 * @brief   This class implements a linear spline interpolation.
 * @author  Marcel Ritsema
 */

#pragma once

namespace vibe
{
    class LinearSpline : public BaseSpline
    {
    public:
        LinearSpline(const juce::Array<juce::Point<float>> &points) : BaseSpline(points) {}

        double getY(const double x);

    private:
        virtual void interpolate();

        double calculateY(const double &x, const juce::Array<juce::Point<double>> &cPoints);

        JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(LinearSpline)

    }; // class LinearSpline
} // namespace vibe
