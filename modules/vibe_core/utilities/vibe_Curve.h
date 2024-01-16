/**
 * @file    vibe_Curve.h
 * @brief   This class creates a curve based on a set of control points.
 * @author  Marcel Ritsema
 *
 * The Curve class provides methods to add, delete, and modify control points,
 * which are automatically sorted based on their x-coordinate.
 * Based on CurveType and control points, the curve is returned as Path.
 */

#pragma once

namespace vibe
{
    enum class CurveType
    {
        Linear,     // y = mx + c (also used for Piecewise Linear Interpolation)
        Quadratic,  // y = ax^2 + bx + c
        Cubic,      // y = ax^3 + bx^2 + cx + d
        //Bezier,
        //CatmullRom,
        //Hermite,
    };

    class Curve
    {
    public:
        Curve();
        ~Curve();

        /** Get all control points. */
        const juce::Array<juce::Point<float>>& getPoints() const;

        /** Get control point. */
        const juce::Point<float> &getPoint(int index) const;

        /** Adds a control point. */
        void addPoint(const juce::Point<float> &point);

        /** Adds a control point. */
        void addPoint(const juce::Point<int> &point);

        /** Adds a control point. */
        void addPoint(float x, float y);

        /** Adds a control point. */
        void addPoint(int x, int y);

        /** Removes a control point based on index value. */
        void erasePoint(int index);

        /* Sets new X and Y coordinate for a control point at given index. */
        void setPointXY(float x, float y, int index);

        /* Sets new X and Y coordinate for a control point at given index. */
        void setPointXY(int x, int y, int index);

        /* Sets new Y coordinate for a control point at given index. */
        void setPointY(float y, int index);

        /* Sets new Y coordinate for a control point at given index. */
        void setPointY(int y, int index);

        /** Get index of control point close to given position. */
        int getIndexPointNearby(int x, int y, int margin) const;

        /** Get index of control point close to given position. */
        int getIndexPointNearby(float x, float y, int margin) const;

        /** Get maximum possible number of control points. */
        int getPointsMax() const;

        /** Get the curve type. */
        CurveType getCurveType();

        /** Set the curve type. */
        void setCurveType(CurveType curveType);

        /** Get (curved) path. */
        const juce::Path& getPath() const;

    private:
        /** The curve type. */
        CurveType cType;

        /** The points array. */
        juce::Array<juce::Point<float>> points;

        /** The maximum number of control points. */
        int pointsMax;

        /** The (curved) path. */
        juce::Path path;

        /** Sorts the points based on the X position. */
        void sortPoints();

        /** Creates the path based on type and points. */
        void createPath();

        /** Comparator for sorting points based on their x-coordinate. */
        struct PointComparator
        {
            int compareElements(const juce::Point<float> &p1, const juce::Point<float> &p2) const;
        };

        JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(Curve)
    }; // class Curve
} // namespace vibe
