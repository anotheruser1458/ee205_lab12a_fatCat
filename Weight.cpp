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

Weight::Weight() noexcept {

}

Weight::Weight(float newWeight) {

}

Weight::Weight(UnitOfWeight newUnitOfWeight) noexcept {

}

Weight::Weight(float newWeight, UnitOfWeight newUnitOfWeight) {

}

Weight::Weight(float newWeight, float newMaxWeight) {

}

Weight::Weight(UnitOfWeight newUnitOfWeight, float newMaxWeight) {

}

float Weight::getWeight() const noexcept {
    return 0;
}

void Weight::setMaxWeight(float newMaxWeight) {

}

Weight::Weight(float newWeight, UnitOfWeight newUnitOfWeight, float newMaxWeight) {

}

bool Weight::isWeightKnown() const noexcept {
    return false;
}

bool Weight::hasMaxWeight() const noexcept {
    return false;
}

float Weight::getWeight(UnitOfWeight weightUnits) const noexcept {
    return 0;
}

float Weight::getMaxWeight() const noexcept {
    return 0;
}

UnitOfWeight Weight::getWeightUnit() const noexcept {
    UnitOfWeight result;
    return result;
}

void Weight::setWeight(float newWeight) {

}

void Weight::setWeight(float newWeight, UnitOfWeight weightUnits) {

}

bool Weight::isWeightValid(float checkWeight) const noexcept {
    return false;
}

bool Weight::validate() const noexcept {
    return false;
}

void Weight::dump() const noexcept {

}

bool Weight::operator==(const Weight &rhs_Weight) const {
    return false;
}

bool Weight::operator<(const Weight &rhs_Weight) const {
    return false;
}

Weight &Weight::operator+=(float rhs_addToWeight) {
}

float Weight::fromKilogramToPound(float kilogram) noexcept {
    return 0;
}

float Weight::fromPoundToKilogram(float pound) noexcept {
    return 0;
}

float Weight::fromSlugToPound(float slug) noexcept {
    return 0;
}

float Weight::fromPoundToSlug(float pound) noexcept {
    return 0;
}

float Weight::convertWeight(float fromWeight, UnitOfWeight fromUnit, UnitOfWeight toUnit) noexcept {
    return 0;
}
