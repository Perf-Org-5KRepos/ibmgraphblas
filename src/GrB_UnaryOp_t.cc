/*
 * Licensed to the Apache Software Foundation (ASF) under one
 * or more contributor license agreements.  See the NOTICE file
 * distributed with this work for additional information
 * regarding copyright ownership.  The ASF licenses this file
 * to you under the Apache License, Version 2.0 (the
 * "License"); you may not use this file except in compliance
 * with the License.  You may obtain a copy of the License at
 *
 *   http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing,
 * software distributed under the License is distributed on an
 * "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
 * KIND, either express or implied.  See the License for the
 * specific language governing permissions and limitations
 * under the License.
 */

#include "IBM_GraphBLAS.hh"
#include <assert.h>

GrB_UnaryOp_t::GrB_UnaryOp_t
(
   GrB_Type     D_out,
   GrB_Type     D_in,
   void (*F)(void*, const void*)
)
{
    _D_out = D_out;
    _D_in  = D_in;
    _F     = F;
    _valid = true;
}

GrB_UnaryOp_t::~GrB_UnaryOp_t
(
)
{
}

bool GrB_UnaryOp_t::valid
(
) const
{
    return _valid;
}

GrB_Type GrB_UnaryOp_t::D_in
(
) const
{
    return _D_in;
}

GrB_Type GrB_UnaryOp_t::D_out
(
) const
{
    return _D_out;
}

void GrB_UnaryOp_t::f
(
    void        *out,
    const void  *in
) const
{
    return _F(out,in);
}
