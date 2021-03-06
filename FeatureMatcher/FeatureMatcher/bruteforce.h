/*
 * Copyright (c) 2012. The Regents of the University of California. All rights reserved.
 * Licensed pursuant to the terms and conditions available for viewing at:
 * http://opensource.org/licenses/BSD-3-Clause
 *
 * File: bruteforce.h
 * Author: Jonathan Ventura
 * Last Modified: 11.17.2012
 */

#ifndef BRUTE_FORCE_NN_H
#define BRUTE_FORCE_NN_H

#include "nn.h"

#ifdef __linux__
#include <CL/opencl.h>
#else
#include <OpenCL/opencl.h>
#endif

namespace vrlt {
/**
 * \addtogroup FeatureMatcher
 * @{
 */

    /**
     * \brief Brute force nearest neighbor implementation.  Uses OpenCL for speedup.
     */
    class BruteForceNN : public NN
    {
    public:
        int N;
        unsigned char *data;
        float *float_data;
        
        cl_device_id device_id;
        cl_context context;
        
        cl_mem data_mem;
        
        int response_buf_size;
        cl_mem response_buf_mem;
        
        cl_program dists_program;
        
        void compileProgram( cl_program prog );
        
        BruteForceNN();
        ~BruteForceNN();
        
        virtual void setData( int _N, unsigned char *_data );
        
        void findconsistentnn( int num_queries, unsigned char *queries, int *neighbors, unsigned int *distances_sq );
        
        void findnn( int num_queries, unsigned char *queries, int *neighbors, unsigned int *distances_sq );
        void findknn( int num_queries, unsigned char *queries, int k, int *neighbors, unsigned int *distances_sq );
        
        void getDistances( size_t num_queries, unsigned char *queries, unsigned int *stored_distsqs );
    };

/**
 * @}
 */
}

#endif
