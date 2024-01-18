/**
 * @file    vibe_BaseSpline.h
 * @brief   This abstract class serves as a base class for all spline classes.
 * @author  Marcel Ritsema
 *
 * The BaseSpline has interface methods for interpolation.
 */

#pragma once

namespace vibe
{
    class BaseSpline
    {
    public:
        /** Constructor. */
        BaseSpline(const juce::Array<juce::Point<float>> &points) : dPoints(points) {}

        /** Destructor. */
        virtual ~BaseSpline() {}

        /** Returns the interpolated y-coordinate for a given x-coordinate. */
        virtual double getY(const double x) = 0;

        /** Returns the interpolated x and y coordinates, which can be used to draw a curve. */
        virtual juce::Array<juce::Point<double>>& getInterpolatedPoints()
        {
            interpolate();
            return iPoints;
         }

    protected:
        /* Data points (Knots). */
        juce::Array<juce::Point<float>> dPoints;

        /* Interpolated points. */
        juce::Array<juce::Point<double>> iPoints;

        /** Interpolates the control points. */
        virtual void interpolate() = 0;

        /* Calculates the y-coordinate for a given x-coordinate. */
        virtual double calculateY(const double& x, const juce::Array<juce::Point<double>>& cPoints) = 0;

    private:
        JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(BaseSpline)

    }; // class BaseSpline
} // namespace vibe
