#include <string>
#include "RationalFractionOperation.h"

RationalFractionOperation::RationalFractionOperation() {
    rf1_ = RationalFraction();
    rf2_ = RationalFraction();
}

RationalFractionOperation::RationalFractionOperation(const RationalFraction& rf1, const RationalFraction& rf2, Operator* op) {
    rf1_ = RationalFraction(rf1);
    rf2_ = RationalFraction(rf2);
    op_ = op;
}

RationalFractionOperation::RationalFractionOperation(const RationalFractionOperation& operation) {
    rf1_ = RationalFraction(operation.getRf1());
    rf2_ = RationalFraction(operation.getRf2());
    op_ = operation.getOperator();
}

RationalFraction RationalFractionOperation::execute() {
    return op_->calculate(rf1_, rf2_);
}

RationalFraction RationalFractionOperation::getRf1() const{
    return rf1_;
}

RationalFraction RationalFractionOperation::getRf2() const{
    return rf2_;
}

Operator* RationalFractionOperation::getOperator() const{
    return op_;
}

std::string RationalFractionOperation::toString() {
    std::string s = rf1_.toString() + " " + op_->toChar() + " " + rf2_.toString();
    return s;
}
