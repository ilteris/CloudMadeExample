/*
 *  LibUtils.h
 *  SponsoredPOIs
 *
 *  Created by Dmytro Golub on 10/16/09.
 *  Copyright 2009 CloudMade. All rights reserved.
 *
 */

#import "RMLatLong.h"

/*! \mainpage CloudMade iPhone API
 * The CloudMade iPhone API makes it easy for developers to build rich, interactive mapping applications on the iPhone. With this API you can:
 * \li Build applications that give users a rich mapping experience on the iPhone
 * \li Benefit from our scalable tile servers which deliver mobile optimized maps to your users
 * \li Easily integrate with the iPhone's location API to show your user's position in real time
 *
 * Using this API you can integrate maps from our tile servers into your applications. Just like our other APIs, we don't want to restrict the uses of this API - you are free to create applications that use our maps in any way like, as long as they comply with the terms of the iPhone SDK agreement.
 */


#define _BI(NAME) PathForBundleResource(NAME)
#define PRINTBBOX(BBox,MSG) printBBox(BBox,MSG)

#define CM_REQUEST_HEADER_NAME  @"X-ServiceSource"
#define CM_REQUEST_HEADER_VALUE @"CloudMadeIphoneLib"


NSString* PathForBundleResource(NSString* relativePath);
void printBBox(RMSphericalTrapezium,NSString*);