/* Copyright (C) 2012-2017 IBM Corp.
 * This program is Licensed under the Apache License, Version 2.0
 * (the "License"); you may not use this file except in compliance
 * with the License. You may obtain a copy of the License at
 *   http://www.apache.org/licenses/LICENSE-2.0
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License. See accompanying LICENSE file.
 */
#ifndef _MULTIAUTOMORPH_H
#define _MULTIAUTOMORPH_H

class Ctxt; // forward decleration

//! A virtual class to handle call-backs to get the output of multiAutomorph.
class AutomorphHandler {
public:
  virtual bool handle(std::unique_ptr<Ctxt>& ctxt, long amt) {return true;}
          // returns false to stop processing, true otherwise
  virtual ~AutomorphHandler() {}
};
/* Applications will derive from this class a handler that actually
 * does something with the "rotated" cipehrtexts. The AutomorphHandler
 * class above can also be used by itself as a do-nothing processor
 * for debugging, or to calculate the required automorphisms (see
 * automorphVals in numbTh.h)
 *
 * Upon calling handle, the multiAutomorph routine has ownership of
 * Ctxt object. The application can take ownership, e.g., by calling
 * ctxt.swap(...) or std::move(ctxt), and then the application must
 * make sure that it frees the object when it no longer needs it.
 */
#endif // _MULTIAUTOMORPH_H