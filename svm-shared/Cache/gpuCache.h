//
// Created by shijiashuai on 2016/12/16.
//

#ifndef MASCOT_SVM_GPUCACHE_H
#define MASCOT_SVM_GPUCACHE_H


#include "cache.h"
#include "../HessianIO/deviceHessianOnFly.h"
#include "../../mascot/svmParam.h"

class GpuCache {
public:
    GpuCache(const SvmProblem &problem, const SVMParam &param);
    ~GpuCache();
    void enable(int i, int j, const SvmProblem &subProblem);
    void getHessianRow(int rowIndex, float_point *devHessianRow);
    void disable(int i, int j);
private:
    const SvmProblem &problem;
    const SvmProblem *subProblem;
    const SVMParam &param;
    vector<float_point*> devSharedCache;
    vector<float_point*> hostSharedCache;
    vector<CLATCache*> sharedCacheStrategy;
    vector<int> numOfElementEachRowInCache;
    vector<size_t> sizeOfEachRowInCache;
    vector<int> cacheSize;

    float_point *devUniqueCache;
    CLATCache *uniqueCacheStrategy;
    size_t sizeOfEachRowInUniqueCache;
    int numOfElementEachRowInUniqueCache;
    DeviceHessianOnFly* hessianCalculator;
};


#endif //MASCOT_SVM_GPUCACHE_H