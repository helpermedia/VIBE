/**
 * @file    ControlPoints.h
 * @brief   This class manages a collection of points which for example can be used for a curve.
 * @author  Marcel Ritsema
 *
 * The ControlPoints class provides methods to add, delete, and modify control points,
 * as well as retrieve information about the control points.
 * The class also supports sorting the control points based on their x-coordinate.
 */

#pragma once

#include <vibe_core/vibe_core.h>
#include <algorithm>

namespace vibe
{
    class ControlPoints
    {
    public:
        ControlPoints();
        ~ControlPoints();

        /** Get all points. */
        const juce::Array<juce::Point<float>>& getPoints() const;

        /** Adds a point. */
        void addPoint(const juce::Point<float>& point, bool setSelected = false);

        /** Removes a point. */
        //void deletePoint(const juce::Point<float>& point);

        /** Removes a point based on index value. */
        void deletePoint(int index);

        /* Sets new X and Y coordinate for point at given index. */
        void setPointXY(int x, int y, int index);

        /* Sets new Y coordinate for point at given index. */
        void setPointY(int y, int index);

        /** Sets point selected. */
        void setPointSelected(const juce::Point<float>& point);

        /** Sets point selected based on index value. */
        void setPointSelected(int index);

        /** Get index of selected point. */
        int getIndexPointSelected() const;

        /** Get index of point close to position. */
        int getIndexPointCloseBy(int x, int y, int margin) const;

        /** Get total of all points. */
        int getPointsTotal() const;

        /** Set maximum number of points. */
        void setPointsMax(int max);

        /** Get maximum possible number of points. */
        int getPointsMax() const;

        /** True if this is the first point. */
        bool isFirstPoint(const juce::Point<float>& point) const;

        /** True if this is the last point. */
        bool isLastPoint(const juce::Point<float>& point) const;

    private:
        /** The points array. */
        juce::Array<juce::Point<float>> points;

        /** The index of the selected point. */
        int indexPointSelected;

        /** The maximum number of points. */
        int maxPoints;

        /** Sorts the points based on the X position,
            X is used as midi in value (ranging from 0 to 127) and will be transformed to Y. */
        void sortPoints();

        //==============================================================================

        JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(ControlPoints)
    }; // class ControlPoints
} // namespace vibe
