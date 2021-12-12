//Copyright (c) 2018-2021, The Monero Project
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

#include "diardi.h"

using namespace epee;

#undef SCALA_DEFAULT_LOG_CATEGORY
#define SCALA_DEFAULT_LOG_CATEGORY "diardi"

namespace cryptonote
{
    const std::vector<std::string> diardi::offline_seed_list = {
        "62.171.149.67:11811", 
        "164.68.117.160:11811"
    };
    const std::vector<std::string> diardi::offline_ban_list = {};
    const std::string diardi::seed_list_ipns_name = "seeds.scalaproject.io";
    const std::string diardi::ban_list_ipns_name = "bans.scalaproject.io";

    const std::string diardi::checkpoints_ipns_name_mainnet = "/ipns/static-checkpoints-mainnet.scalaproject.io";
    const std::string diardi::checkpoints_ipns_name_testnet = "/ipns/static-checkpoints-testnet.scalaproject.io";
    const std::string diardi::checkpoints_ipns_name_stagenet = "/ipns/static-checkpoints-stagenet.scalaproject.io";

    const std::vector<std::string> diardi::diardi_v1_addresses = {
        "SvjVucMW4PA968WJP7rXRr1fkRVch5q6rLnh86LkZCWFPJiDEB2vizX6VjMezJaKiCN2K1kVvAHDbUmiB1tPjZJP2hety4dnf",
        "SvjVucMW4PA968WJP7rXRr1fkRVch5q6rLnh86LkZCWFPJiDEB2vizX6VjMezJaKiCN2K1kVvAHDbUmiB1tPjZJP2hety4dnf",
        "Svkw5aecRCmgru6t4Jigi9KN3HrENz3VmFVtBmaGJhNVWmUGc6hv5P9Qhi6Uivns49BG1H6WBVWoY85Si8PdYcfN2umFos7KU",
        "Svkw5aecRCmgru6t4Jigi9KN3HrENz3VmFVtBmaGJhNVWmUGc6hv5P9Qhi6Uivns49BG1H6WBVWoY85Si8PdYcfN2umFos7KU",
        "SvkdzwcuUzy1p25pvipH5QB4usEGJ9aBB7ucPrg2fvoKQh8jW6wQnYYTdFsQ6Gg2uVPPLgWt1pzaKVa6zeTmfv3j2XLefxByh",
        "SvkdzwcuUzy1p25pvipH5QB4usEGJ9aBB7ucPrg2fvoKQh8jW6wQnYYTdFsQ6Gg2uVPPLgWt1pzaKVa6zeTmfv3j2XLefxByh",
        "SvjayKidE9SGRX2E5dJWdQbhVfq4nf4tQJkUQ5bBUdgALqiUewJfWQwbmptDEmKqeqc4tRb26duxe3483w2RZRXQ2MPKDzw3a",
        "SvkKGjieJuuMgxyCC3nXJUJDj2CuibeFRL6qan46zw8NCRMPyRtwehjjYG2qqekuUnCW5zmeu27fBLqn1xkQFRkc1wzscXzvo",
        "Svk7VUPASsbZhFErf8rEfuEEX94GWsSWKVS8GNAUDfH363EsSLZ58wd3rph8okcaFALthwMkQ4fWJBzYYjqA3Lk61McroQbno",
        "Svk7VUPASsbZhFErf8rEfuEEX94GWsSWKVS8GNAUDfH363EsSLZ58wd3rph8okcaFALthwMkQ4fWJBzYYjqA3Lk61McroQbno",
        "Svk7Uv5WsovHiooYMa9jtcSdgKJcBztLE5n8A8HSp7s8UXnMdVoNLBf2tKchEqW4Ma6wW27Rb2ntPQqrFZT26hhE25fenVvyp",
        "SvmCQeq1VL2GxLpQznvwF7eHCYd77j9V32fmVVzcfDUSJ4VU3sb5riBdCVYZmk3oVF4b6wqRhPbAbf5oWTC9EFUY16XcZ75cL",
        "SvkKRajEKEnhEUWFXMrHFdRxE7vmYJaifTRoGrNyDPksZqxWGm8NeJi6UaFXDbXVaGEVAiVYPHmsyaFNAcq5qGLR1BzriKyiM",
        "SvkL8FpayF6R4RucZC4L1wcuVFZwPAf52dECSrr2LiViGVGv3YVKnjz9rsfcxkVLJaTaB24JUico23bEjXtpkEMo1eyhRtk6Z",
        "SvjssTR8XNsRxGZeyFnXj9LvHD5c3EZM8XdquLZoBNjrKHcFN3KCzTR5L3yjTvoFCv9usqd9vFbkaiyqyJFFQw9g2KLoCyL6B",
        "SvkWYULscDkRuWZwuVAywHjpFMqVA3beZQPPVDBUiE6YUFwVL4LqTY348Yazdwwa6VbhhBLKTW295T5bPbizzF9837VDwp4bU"
    };


    const CheckPointListType diardi::offline_checkpoints_mainnet = {
        {0, {"3fa5c8976978f52ad7d8fc3663e902a229a232ef987fc11ca99628366652ba99", "0x1"}},
        {5, {"a9809cce2003e1e27ed2673510dfb5a7b9432d24f656aa71a9cb76612e8f2646", "0x8"}},
        {10000, {"4a220652f8fb723d1d627022b2fd556132d51915ad4f78964fda4ec071b89504","0x59850cb4947"}},
        {100000, {"d672d95b60d38f19c453cd80bb7a988254294b43c6ef3df62c57c771f1898f9e","0x29e93d705e6f"}},
        {150000, {"f83b8df79592aae7e2af08a443e55ef6080d598c852bdf14ffbed9875d30b309","0x5467acab0a47"}},
        {200000, {"880f163d881a4469877331cf02db4d54a0f34cae91e299a126dd2c326573a2d5","0xc6bb7244192e"}},
        {250000, {"6609b3b3a669cc870057d1aec263d6dcef823a0267ec907b5c883a7dfe4ef422","0x1465fc61b2db1"}},
        {300000, {"865d5004f3310a45f02618deb008cc8c797eb9905dbc523bcf5f418424bd6e13","0x1aa4090e31978"}},
        {350000, {"5b10177fa79463be1e7ee34e8e6ed604578c969ec2006f33a67903f760635c97","0x202ba7b5d263b"}},
    };

    const CheckPointListType diardi::offline_checkpoints_testnet = {};
    const CheckPointListType diardi::offline_checkpoints_stagenet = {};

    //---------------------------------------------------------------------------
    diardi::diardi()
    {}
    //---------------------------------------------------------------------------
    std::string diardi::get_download_path(cryptonote::network_type nettype) {
        boost::filesystem::path ipfs_path = tools::get_default_data_dir(true);
        std::string ipfs_path_str = ipfs_path.string();

        return ipfs_path_str;
    }
    //---------------------------------------------------------------------------
    CheckPointListType diardi::get_historical_checkpoints(bool ipfsEnabled, cryptonote::network_type nettype){
        CheckPointListType checkpoint_list;
        /* Remove network type check later */
        if(ipfsEnabled && nettype == cryptonote::network_type::MAINNET) {
            std::string file_name = 
            (nettype == cryptonote::network_type::MAINNET) ? 
            "checkpoints_historical_mainnet.json" : 
            (nettype == cryptonote::network_type::TESTNET) ?
            "checkpoints_testnet.json" :
            "checkpoints_stagenet.json";

            std::string download_path; 
            #ifdef WIN32
                download_path = diardi::get_download_path(nettype) + "\\" + file_name;
            #else
                download_path = diardi::get_download_path(nettype) + "/" + file_name;
            #endif

            const char* ipns_path = (nettype == cryptonote::network_type::MAINNET) ?
            checkpoints_ipns_name_mainnet.data() : 
            (nettype == cryptonote::network_type::TESTNET) ?
            checkpoints_ipns_name_testnet.data() :
            checkpoints_ipns_name_stagenet.data();

            char* ipfs_path = diardi::resolve_ipns(ipns_path);

            Document ipns_path_doc;
            ipns_path_doc.Parse(ipfs_path);
            std::string ipfs_parsed = ipns_path_doc["Message"].GetString();
            std::string ipfs_hash = ipfs_parsed.erase(0,6); /* remove "/ipfs/" */
            char* res_get = download_ipfs_file(ipfs_hash.data(), download_path.data());
             
            std::ifstream checkpoint_fs(download_path.data());
            IStreamWrapper isw(checkpoint_fs);
            Document checkpoint_stream_doc;
            checkpoint_stream_doc.ParseStream(isw);

            for (rapidjson::Value::ConstValueIterator itr = checkpoint_stream_doc.Begin();
            itr != checkpoint_stream_doc.End(); 
            ++itr) {
                if (itr->HasMember("height")) {
                    uint64_t height = (*itr)["height"].GetInt64();
                    std::string hash = (*itr)["hash"].GetString();
                    std::string difficulty = (*itr)["c_difficulty"].GetString();

                    checkpoint_list.insert(std::make_pair(height, std::make_pair(hash, difficulty)));
                }
            }

            return checkpoint_list;
        } else {
            switch(nettype) {
                case cryptonote::network_type::MAINNET:
                    return diardi::offline_checkpoints_mainnet;
                case cryptonote::network_type::TESTNET:
                    return diardi::offline_checkpoints_testnet;
                case cryptonote::network_type::STAGENET:
                    return diardi::offline_checkpoints_stagenet;
                default:
                    return {};
            }
        }
    }
    //---------------------------------------------------------------------------
    std::string diardi::get_diardi_maintainer_pre_v8(uint64_t height){
        std::vector<std::string>::const_iterator it = diardi::diardi_v1_addresses.begin();

        if((height % 16) == 0){
            std::advance(it, 15);
        }else {
            std::advance(it, (height % 16) - 1);
        }
        return *it;
    }
    //---------------------------------------------------------------------------

}