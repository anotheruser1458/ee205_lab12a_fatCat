///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205_lab12a_fatCat - EE 205 - Spr 2022
///
/// @file Weight.cpp
/// @version 1.0
///
/// @author Maxwell Pauly <mgpauly@hawaii.edu>
/// @date   25_Apr_2022
///////////////////////////////////////////////////////////////////////////////
#include "Weight.h"
#include <iostream>
#include <stdexcept>
using namespace std;

Weight::Weight() noexcept {

}

Weight::Weight(float newWeight) {
    setWeight(newWeight);
}

Weight::Weight(UnitOfWeight newUnitOfWeight) noexcept {
    setUnitOfWeight(newUnitOfWeight);
}

Weight::Weight(float newWeight, UnitOfWeight newUnitOfWeight) {
    setUnitOfWeight(newUnitOfWeight);
    setWeight(newWeight);
}


Weight::Weight(float newWeight, float newMaxWeight) {
    setMaxWeight(newMaxWeight);
    setWeight(newWeight);
}

Weight::Weight(UnitOfWeight newUnitOfWeight, float newMaxWeight) {
    setUnitOfWeight(newUnitOfWeight);
    setMaxWeight(newMaxWeight);
}

Weight::Weight(float newWeight, UnitOfWeight newUnitOfWeight, float newMaxWeight) {
    setUnitOfWeight(newUnitOfWeight);
    setMaxWeight(newMaxWeight);
    setWeight(newWeight);
}

float Weight::getWeight() const noexcept {
    if(bIsKnown)
        return Weight::weight;
    return UNKNOWN_WEIGHT;
}

void Weight::setMaxWeight(float newMaxWeight) {
    if(!isWeightValid(newMaxWeight)) {
        throw out_of_range("Weight not valid");
    }
    Weight::maxWeight = newMaxWeight;
    bHasMax = true;
}

bool Weight::isWeightKnown() const noexcept {
    return Weight::bIsKnown;
}

bool Weight::hasMaxWeight() const noexcept {
    return Weight::bHasMax;
}

float Weight::getWeight(UnitOfWeight weightUnits) const noexcept {
    if (!bIsKnown) {
        cout << "weight is not known";
        return UNKNOWN_WEIGHT;
    }
    return convertWeight(weight, unitOfWeight, weightUnits);
}

float Weight::getMaxWeight() const noexcept {
    if(bHasMax) {
        return Weight::maxWeight;
    }
    return UNKNOWN_WEIGHT;
}

UnitOfWeight Weight::getWeightUnit() const noexcept {
    return Weight::unitOfWeight;
}

void Weight::setWeight(float newWeight) {
    if(!isWeightValid(newWeight)) {
        throw out_of_range("Weight is not valid");
    }

    Weight::weight = newWeight;
    bIsKnown = true;
}

void Weight::setWeight(float newWeight, UnitOfWeight weightUnits) {
    float weightInPounds = convertWeight(newWeight, weightUnits, POUND);
    switch((int)Weight::unitOfWeight) {
        case POUND: setWeight(weightInPounds); break;
        case KILO: setWeight(convertWeight(weightInPounds, POUND, KILO)); break;
        case SLUG: setWeight(convertWeight(weightInPounds, POUND, SLUG)); break;
        default:
            throw out_of_range("Can't convert weight to specified unit");
    }
}

bool Weight::isWeightValid(float checkWeight) const noexcept {
    if (checkWeight <= 0) {
        return false;
    }
    if (hasMaxWeight()) {
        if (checkWeight > maxWeight) {
            return false;
        }
    }
    return true;
}

bool Weight::validate() const noexcept {
    if(!isWeightValid(Weight::weight)) {
        cout << "Weight is not healthy" << endl;
        return false;
    }
    cout << "Weight is healthy" << endl;
    return true;
}

void Weight::dump() const noexcept {
    cout << "==============================================" << endl;
    cout << "Weight  this                " << this << endl;
    cout << "Weight  isKnown             " << (isWeightKnown() ? "true":"false") << endl;
    cout << "Weight  weight              " << getWeight() << endl;
    cout << "Weight  unifOfWeight        " << getWeightUnit() << endl;
    cout << "Weight  hasMax              " << (bHasMax ? "true":"false") << endl;
    cout << "Weight  maxWeight           " << getMaxWeight() << endl;
}

bool Weight::operator==(const Weight &rhs_Weight) const {
    float w1, w2;

    if (weight == UNKNOWN_WEIGHT) {
        w1 = 0;
    } else {
        w1 = weight;
    }

    if (rhs_Weight.weight == UNKNOWN_WEIGHT) {
        w2 = 0;
    } else {
        w2 = rhs_Weight.weight;
    }
    return w1 == w2;
}

bool Weight::operator<(const Weight &rhs_Weight) const {
    float w1, w2;

    if (weight == UNKNOWN_WEIGHT) {
        w1 = 0;
    } else {
        w1 = weight;
    }

    if (rhs_Weight.weight == UNKNOWN_WEIGHT) {
        w2 = 0;
    } else {
        w2 = rhs_Weight.weight;
    }

    return w1 < w2;
}

Weight &Weight::operator+=(float rhs_addToWeight) {
    if (!bIsKnown) {
        throw out_of_range("Out of range");
    }
    float newWeight = weight += rhs_addToWeight;
    setWeight(newWeight);
}

float Weight::fromKilogramToPound(float kilogram) noexcept {
    return kilogram/KILOS_IN_A_POUND;
}

float Weight::fromPoundToKilogram(float pound) noexcept {
    return pound*KILOS_IN_A_POUND;
}

float Weight::fromSlugToPound(float slug) noexcept {
    return slug/SLUGS_IN_A_POUND;
}

float Weight::fromPoundToSlug(float pound) noexcept {
    return pound*SLUGS_IN_A_POUND;
}

float Weight::convertWeight(float fromWeight, UnitOfWeight fromUnit, UnitOfWeight toUnit) noexcept {
    float weightInPounds;
    switch(fromUnit) {
        case POUND: weightInPounds = fromWeight;
        break;
        case KILO: weightInPounds = fromKilogramToPound(fromWeight);
        break;
        case SLUG: weightInPounds = fromSlugToPound(fromWeight);
        break;
    }
    switch(toUnit) {
        case POUND: return weightInPounds;
        case KILO: return fromPoundToKilogram(weightInPounds);
        case SLUG: return fromPoundToSlug(weightInPounds);
    }
    return UNKNOWN_WEIGHT;
}

void Weight::setUnitOfWeight(UnitOfWeight newUnitOfWeight) {
    Weight::unitOfWeight = newUnitOfWeight;
}