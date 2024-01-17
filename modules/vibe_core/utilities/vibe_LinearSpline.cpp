/**
 * @file    vibe_LinearSpline.cpp
 * @author  Marcel Ritsema
 */

#include "vibe_LinearSpline.h"

namespace vibe
{
    double LinearSpline::getY(const double x)
    {
        double y = 0.0;

        // Iterate over each segment.
        for (int i = 0; i < iPoints.size() - 1; i++)
        {
            // Check if x is within the segment.
            if (x >= iPoints[i].getX() && x <= iPoints[i + 1].getX())
            {
                y = calculateY(x, {iPoints[i], iPoints[i + 1]});
            }
        }

        return y;
    }

    double LinearSpline::calculateY(const double& x, const juce::Array<juce::Point<double>>& cPoints)
    {
        // Init.
        double y = 0.0f;

        // Check if there are two control points (start and end of segment).
        if (cPoints.size() == 2)
        {
            // Calculate the slope and y-intercept.
            float m = (cPoints[1].getY() - cPoints[0].getY()) / (cPoints[1].getX() - cPoints[0].getX());
            float c = cPoints[0].getY() - m * cPoints[0].getX();

            // Calculate the y-coordinate.
            y = m * x + c;
        }
        return y;
    }

    void LinearSpline::interpolate()
    {
        // The interpolate method creates a set of interpolated points,
        // for a Linear Spline simply the nodes are enough to draw a curve.
        for (auto &point : nPoints)
        {
            iPoints.add(point.toDouble()); // toDouble() creates a copy.
        }
    }

} // namespace vibe
