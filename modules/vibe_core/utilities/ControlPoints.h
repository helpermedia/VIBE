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

namespace vibe
{
    class ControlPoints
    {
    public:
        ControlPoints();
        ~ControlPoints();

        /** Get all points. */
        const juce::Array<juce::Point<int>>& getPoints() const;

        /** Adds a point. */
        void add(const juce::Point<int>& point, bool setSelected = false);

        /** Removes a point. */
        //void deletePoint(const juce::Point<int>& point);

        /** Removes a point based on index value. */
        void erase(int index);

        /* Sets new X and Y coordinate for point at given index. */
        void setXY(int x, int y, int index);

        /* Sets new Y coordinate for point at given index. */
        void setY(int y, int index);

        /** Sets point selected. */
        void setSelected(const juce::Point<int>& point);

        /** Sets point selected based on index value. */
        void setSelected(int index);

        /** Get index of selected point. */
        int getIndexSelected() const;

        /** Get index of point close to position. */
        int getIndexCloseBy(int x, int y, int margin) const;

        /** Get total of all points. */
        int getTotal() const;

        /** Set maximum number of points. */
        void setMax(int max);

        /** Get maximum possible number of points. */
        int getMax() const;

    private:
        /** The points array. */
        juce::Array<juce::Point<int>> points;

        /** The index of the selected point. */
        int indexSelected;

        /** The maximum number of points. */
        int max;
        
        /** Sorts the points based on the X position,
            X is used as midi in value (ranging from 0 to 127) and will be transformed to Y. */
        void sort();

        /** Comparator for sorting points based on their x-coordinate. */
        struct PointComparator
        {
            int compareElements(const juce::Point<int> &p1, const juce::Point<int> &p2) const;
        };

        JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(ControlPoints)
    }; // class ControlPoints
} // namespace vibe
