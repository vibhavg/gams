/**
 * Copyright (c) 2014 Carnegie Mellon University. All Rights Reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 * 
 * 1. Redistributions of source code must retain the above copyright notice,
 *    this list of conditions and the following acknowledgments and disclaimers.
 * 
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 * 
 * 3. The names "Carnegie Mellon University," "SEI" and/or "Software
 *    Engineering Institute" shall not be used to endorse or promote products
 *    derived from this software without prior written permission. For written
 *    permission, please contact permission@sei.cmu.edu.
 * 
 * 4. Products derived from this software may not be called "SEI" nor may "SEI"
 *    appear in their names without prior written permission of
 *    permission@sei.cmu.edu.
 * 
 * 5. Redistributions of any form whatsoever must retain the following
 *    acknowledgment:
 * 
 *      This material is based upon work funded and supported by the Department
 *      of Defense under Contract No. FA8721-05-C-0003 with Carnegie Mellon
 *      University for the operation of the Software Engineering Institute, a
 *      federally funded research and development center. Any opinions,
 *      findings and conclusions or recommendations expressed in this material
 *      are those of the author(s) and do not necessarily reflect the views of
 *      the United States Department of Defense.
 * 
 *      NO WARRANTY. THIS CARNEGIE MELLON UNIVERSITY AND SOFTWARE ENGINEERING
 *      INSTITUTE MATERIAL IS FURNISHED ON AN "AS-IS" BASIS. CARNEGIE MELLON
 *      UNIVERSITY MAKES NO WARRANTIES OF ANY KIND, EITHER EXPRESSED OR
 *      IMPLIED, AS TO ANY MATTER INCLUDING, BUT NOT LIMITED TO, WARRANTY OF
 *      FITNESS FOR PURPOSE OR MERCHANTABILITY, EXCLUSIVITY, OR RESULTS
 *      OBTAINED FROM USE OF THE MATERIAL. CARNEGIE MELLON UNIVERSITY DOES
 *      NOT MAKE ANY WARRANTY OF ANY KIND WITH RESPECT TO FREEDOM FROM PATENT,
 *      TRADEMARK, OR COPYRIGHT INFRINGEMENT.
 * 
 *      This material has been approved for public release and unlimited
 *      distribution.
 **/

/**
 * @file Region.h
 * @author James Edmondson <jedmondson@gmail.com>
 *
 * This file contains the definition of the region-prefixed MADARA variables
 **/

#ifndef   _GAMS_VARIABLES_REGION_H_
#define   _GAMS_VARIABLES_REGION_H_

#include <string>
#include <vector>

#include "gams/GAMS_Export.h"
#include "madara/knowledge/containers/Integer.h"
#include "madara/knowledge/containers/Native_Double_Vector.h"
#include "madara/knowledge/Knowledge_Base.h"

namespace gams
{
  namespace variables
  {
    /**
    * A container for region information
    **/
    class GAMS_Export Region
    {
    public:
      /**
       * Constructor
       **/
      Region ();

      /**
       * Destructor
       **/
      ~Region ();

      /**
       * Assignment operator
       * @param  rhs   values to copy
       **/
      void operator= (const Region & rhs);

      /**
       * Initializes variable containers
       * @param   knowledge    the knowledge base that houses the variables
       * @param   region_name  name of the region
       **/
      void init_vars (madara::knowledge::Knowledge_Base & knowledge,
        const std::string & region_name = "0");
      
      /**
       * Initializes variable containers
       * @param   knowledge  the variable context
       * @param   region_name  name of the region
       **/
      void init_vars (madara::knowledge::Variables & knowledge,
        const std::string & region_name = "0");

      /// the type of region (0 for arbitary convex polygon)
      madara::knowledge::containers::Integer type;

      /// vertices of the convex polygon
      std::vector<madara::knowledge::containers::Native_Double_Vector> vertices;

      /// region identifier
      std::string name;
    };
    
    /**
      * Initializes region containers
      * @param   variables    the variables to initialize
      * @param   knowledge    the knowledge base that houses the variables
      * @param   region_name  name of the region
      **/
    GAMS_Export void init_vars (Region & variables,
      madara::knowledge::Knowledge_Base & knowledge,
      const std::string & region_name = "0");
  }
}

#endif // _GAMS_VARIABLES_REGION_H_
