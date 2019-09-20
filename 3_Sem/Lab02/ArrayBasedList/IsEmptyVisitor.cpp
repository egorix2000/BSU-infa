#include "IsEmptyVisitor.h"

void IsEmptyVisitor::visit(List &ref) {
    value = (ref.size() == 0);
}