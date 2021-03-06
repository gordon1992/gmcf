#include "InclusionSetTable.h"

using namespace SBA;

void InclusionSetTable::add(unsigned int set_id,unsigned int elt, unsigned int value_to_add) {
    if (_set_tbl.count(set_id)==0) {
        _set_tbl[set_id] = new InclusionSet;
    }
    _set_tbl[set_id]->add(elt, value_to_add);
}
void InclusionSetTable::remove(unsigned int set_id,unsigned int elt) {
    if (_set_tbl.count(set_id)==0) {
        _set_tbl[set_id] = new InclusionSet;
    }
    _set_tbl[set_id]->remove(elt);
}
unsigned int InclusionSetTable::size(unsigned int set_id) {
    if (_set_tbl.count(set_id)==0) {
        _set_tbl[set_id] = new InclusionSet;
        return 0;
    } else {
        return _set_tbl[set_id]->size();
    }
}
unsigned int InclusionSetTable::count(unsigned int set_id,unsigned int elt) {
    if (_set_tbl.count(set_id)==0) {
        _set_tbl[set_id] = new InclusionSet;
        return 0;
    } else {
        return _set_tbl[set_id]->count(elt);
    }
}

unsigned int InclusionSetTable::takefirst(unsigned int set_id) {
    if (_set_tbl.count(set_id)==0) {
        return 0;
    } else {
        return _set_tbl[set_id]->takefirst();
    }
}

const std::vector<unsigned int>* InclusionSetTable::elts(unsigned int set_id) {
        return _set_tbl[set_id]->elts();
}

