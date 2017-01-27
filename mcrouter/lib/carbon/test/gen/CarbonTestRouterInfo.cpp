/*
 *  Copyright (c) 2017, Facebook, Inc.
 *  All rights reserved.
 *
 *  This source code is licensed under the BSD-style license found in the
 *  LICENSE file in the root directory of this source tree. An additional grant
 *  of patent rights can be found in the PATENTS file in the same directory.
 *
 */

/*
 *  THIS FILE IS AUTOGENERATED. DO NOT MODIFY IT; ALL CHANGES WILL BE LOST IN
 *  VAIN.
 *
 */
#include "CarbonTestRouterInfo.h"

#include <unordered_map>

#include <folly/Memory.h>
#include <folly/Range.h>
#include <folly/dynamic.h>

#include <mcrouter/routes/ExtraRouteHandleProviderIf.h>
#include <mcrouter/routes/McRouteHandleProvider.h>

#include <mcrouter/lib/routes/HashRoute.h>
#include <mcrouter/lib/routes/NullRoute.h>
#include <mcrouter/routes/AllAsyncRouteFactory.h>
#include <mcrouter/routes/AllFastestRouteFactory.h>
#include <mcrouter/routes/FailoverRoute.h>
#include <mcrouter/routes/HashRouteFactory.h>
#include <mcrouter/routes/LatestRoute.h>
#include <mcrouter/routes/LoggingRoute.h>
#include <mcrouter/routes/OperationSelectorRoute.h>
#include <mcrouter/routes/OutstandingLimitRoute.h>

#include <mcrouter/routes/McExtraRouteHandleProvider.h>

using namespace facebook::memcache;
using namespace facebook::memcache::mcrouter;

namespace carbon {
namespace test {

/* static */ CarbonTestRouterInfo::RouteHandleFactoryMap
CarbonTestRouterInfo::buildRouteMap() {
  RouteHandleFactoryMap map{
      {"AllAsyncRoute", &makeAllAsyncRoute<CarbonTestRouterInfo>},
      {"AllFastestRoute", &makeAllFastestRoute<CarbonTestRouterInfo>},
      {"HashRoute",
       [](RouteHandleFactory<RouteHandleIf>& factory,
          const folly::dynamic& json) {
         return makeHashRoute<CarbonTestRouterInfo>(factory, json);
       }},
      {"LatestRoute", &makeLatestRoute<CarbonTestRouterInfo>},
      {"LoggingRoute", &makeLoggingRoute<CarbonTestRouterInfo>},
      {"NullRoute", &makeNullRoute<CarbonTestRouteHandleIf>},
      {"OperationSelectorRoute",
       &makeOperationSelectorRoute<CarbonTestRouterInfo>},
  };
  return map;
}

/* static */
std::unique_ptr<ExtraRouteHandleProviderIf<CarbonTestRouterInfo>>
CarbonTestRouterInfo::buildExtraProvider() {
  return folly::make_unique<McExtraRouteHandleProvider<CarbonTestRouterInfo>>();
}

} // test
} // carbon
