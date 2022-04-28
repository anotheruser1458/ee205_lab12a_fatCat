///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205_lab12a_fatCat - EE 205 - Spr 2022
///
/// @file Weight.h
/// @version 1.0
///
/// @author Maxwell Pauly <mgpauly@hawaii.edu>
/// @date   25_Apr_2022
///////////////////////////////////////////////////////////////////////////////
#ifndef EE205_LAB12A_FATCAT_WEIGHT_H
#define EE205_LAB12A_FATCAT_WEIGHT_H
#pragma once
#include <ostream>

enum UnitOfWeight {POUND, KILO, SLUG};

class Weight {
private:
    bool bIsKnown = false;
    bool bHasMax = false;
    enum UnitOfWeight unitOfWeight = POUND;
    float weight = UNKNOWN_WEIGHT;
    float maxWeight = UNKNOWN_WEIGHT;
    void setMaxWeight(float newMaxWeight);
    void setUnitOfWeight(UnitOfWeight newUnitOfWeight);

public:
    constexpr static const float UNKNOWN_WEIGHT = -1;
    constexpr static const float KILOS_IN_A_POUND = 0.453592;
    constexpr static const float SLUGS_IN_A_POUND = 0.031081;

    Weight() noexcept;
    explicit Weight(float newWeight);
    explicit Weight(UnitOfWeight newUnitOfWeight) noexcept;
    Weight(float newWeight, UnitOfWeight newUnitOfWeight);
    Weight(float newWeight, float newMaxWeight);
    Weight(UnitOfWeight newUnitOfWeight, float newMaxWeight);
    Weight(float newWeight, UnitOfWeight newUnitOfWeight, float newMaxWeight);
    bool isWeightKnown() const noexcept;
    bool hasMaxWeight() const noexcept;
    float getWeight() const noexcept;
    float getWeight(UnitOfWeight weightUnits) const noexcept;
    float getMaxWeight() const noexcept;
    UnitOfWeight getWeightUnit() const noexcept;
    void setWeight(float newWeight);
    void setWeight(float newWeight, UnitOfWeight weightUnits);
    bool isWeightValid(float checkWeight) const noexcept;
    bool validate() const noexcept;
    void dump() const noexcept;
    bool operator==(const Weight &rhs_Weight) const;
    bool operator<(const Weight &rhs_Weight) const;
    Weight & operator+=(float rhs_addToWeight);
    static float fromKilogramToPound(float kilogram) noexcept;
    static float fromPoundToKilogram(float pound) noexcept;
    static float fromSlugToPound(float slug) noexcept;
    static float fromPoundToSlug(float pound) noexcept;
    static float convertWeight(float fromWeight, UnitOfWeight fromUnit, UnitOfWeight toUnit) noexcept;

};

inline std::ostream &operator<<(std::ostream &os, UnitOfWeight unit) {
    switch (unit) {
        case POUND: os << "Pound"; break;
        case KILO: os << "Kilogram"; break;
        case SLUG: os << "Slug"; break;
        default:
            throw std::out_of_range("Not convertible to a string");
    }
    return os;
}

#endif //EE205_LAB12A_FATCAT_WEIGHT_H
