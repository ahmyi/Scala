// Copyright (c) 2018-2021, The Scala Project
//
// All rights reserved.
//
// Redistribution and use in source and binary forms, with or without modification, are
// permitted provided that the following conditions are met:
//
// 1. Redistributions of source code must retain the above copyright notice, this list of
//    conditions and the following disclaimer.
//
// 2. Redistributions in binary form must reproduce the above copyright notice, this list
//    of conditions and the following disclaimer in the documentation and/or other
//    materials provided with the distribution.
//
// 3. Neither the name of the copyright holder nor the names of its contributors may be
//    used to endorse or promote products derived from this software without specific
//    prior written permission.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY
// EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
// MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL
// THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
// SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
// PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
// INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,
// STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF
// THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
//
// Parts of this file are originally copyright (c) 2012-2013 The Cryptonote developers

#pragma once

#include <boost/filesystem.hpp>
#include <algorithm>
#include <map>
#include <vector>
#include <string>
#include <fstream>

#include "common/util.h"
#include "misc_log_ex.h"
#include "crypto/hash.h"
#include "cryptonote_config.h"
#include "net/http_client.h"
#include "rapidjson/document.h"
#include "rapidjson/istreamwrapper.h"

#if defined(WIN32) || defined(_WIN32) || defined(__WIN32__) || defined(__NT__)
    #include "libipfs-windows.h"
#elif  defined(__APPLE__)
    #include "libipfs-macos-x64.h"
#else
    #include "libipfs-linux.h"
#endif

using namespace rapidjson;
using namespace std::chrono_literals;

typedef std::map<uint64_t, std::pair<std::string, std::string>> CheckPointListType;

namespace cryptonote
{
  /**
   * @brief A container for getting data from the Diardi network
   *
   * Diardi is the network of notary nodes that publishes checkpoints on
   * a periodic basis, functions defined here will fetch data from diardi
   * from there and make it available for the daemon.
   */
  class diardi
  {
      public:
        /**
         * @brief default constructor
        */
        diardi();
        /**
         * @brief Get a large list of historical static checkpoints from IPFS
         *
         * @param ipfsDisabled whether the local IPFS node is disabled or not
         * @param nettype the network type
         *
         * @return a map of type CheckPointListType which contains all the checkpoints
         *
         *
        */

        CheckPointListType get_historical_checkpoints(bool ipfsEnabled, cryptonote::network_type nettype);

        /**
         * @brief Get a diardi maintainers address, pre V8
         *
         * @param height the height for which the maintainer address is needed
         *
         * @return string containing the address
         *
         *
        */
       
        std::string get_diardi_maintainer_pre_v8(uint64_t height);

        /**
         * @brief Resolve an IPNS name
         *
         * @param ipns_name the IPNS name to resolve
         *
         * @return string containing the IPFS hash
         *
         *
        */

        char* resolve_ipns(const char* ipns_name) {
          char* ipfs_path = ResolveIPNSName((char*)ipns_name);
          return ipfs_path;
        }

        static char* download_ipfs_file(const char* ipfs_hash, const char* download_path) {
          char* run_get = IpfsGet((char*)ipfs_hash, (char*)download_path);
          return run_get;
        }

        static const std::vector<std::string> diardi_v1_addresses;

      private:
        /**
         * @brief Get downaload path diardi files
         *
         *
         * @return a char pointer to the path
         *
         *
        */

        std::string get_download_path(cryptonote::network_type nettype);

        static const std::vector<std::string> offline_seed_list;
        static const std::vector<std::string> offline_ban_list;
        static const std::string seed_list_ipns_name;
        static const std::string ban_list_ipns_name;

        static const std::string checkpoints_ipns_name_mainnet;
        static const std::string checkpoints_ipns_name_testnet;
        static const std::string checkpoints_ipns_name_stagenet;

        static const CheckPointListType offline_checkpoints_mainnet;
        static const CheckPointListType offline_checkpoints_testnet;
        static const CheckPointListType offline_checkpoints_stagenet;
  };
}